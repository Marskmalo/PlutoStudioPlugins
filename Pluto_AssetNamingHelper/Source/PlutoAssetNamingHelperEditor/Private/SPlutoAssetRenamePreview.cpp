#include "SPlutoAssetRenamePreview.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetToolsModule.h"
#include "ContentBrowserModule.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Notifications/NotificationManager.h"
#include "IAssetTools.h"
#include "IContentBrowserSingleton.h"
#include "Misc/MessageDialog.h"
#include "Styling/AppStyle.h"
#include "Styling/SlateIconFinder.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SSearchBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SSplitter.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Views/SHeaderRow.h"
#include "Widgets/Views/SListView.h"
#include "Widgets/Views/STableRow.h"

#define LOCTEXT_NAMESPACE "SPlutoAssetRenamePreview"

namespace PlutoAssetRenamePreviewColumns
{
	const FName Include(TEXT("Include"));
	const FName CurrentName(TEXT("CurrentName"));
	const FName SuggestedName(TEXT("SuggestedName"));
	const FName Type(TEXT("Type"));
	const FName Referencers(TEXT("Referencers"));
	const FName Dependencies(TEXT("Dependencies"));
	const FName Risk(TEXT("Risk"));
}

FText FPlutoAssetRenamePreviewItem::GetRiskText() const
{
	if (!AuditResult.IsValid() || AuditResult->SuggestedName.IsEmpty())
	{
		return LOCTEXT("NoSafeSuggestion", "无安全建议");
	}
	return AuditResult->bRenameAllowed
		? LOCTEXT("ControlledFlow", "可进入受控流程")
		: LOCTEXT("ManualReview", "需人工确认");
}

FLinearColor FPlutoAssetRenamePreviewItem::GetRiskColor() const
{
	if (!AuditResult.IsValid() || AuditResult->SuggestedName.IsEmpty())
	{
		return FLinearColor(0.92f, 0.30f, 0.30f);
	}
	return AuditResult->bRenameAllowed
		? FLinearColor(0.35f, 0.80f, 0.42f)
		: FLinearColor(1.00f, 0.62f, 0.18f);
}

bool FPlutoAssetRenamePreviewItem::NeedsAttention() const
{
	return !AuditResult.IsValid() || AuditResult->SuggestedName.IsEmpty() || !AuditResult->bRenameAllowed;
}

namespace
{
	using FPreviewItemPtr = TSharedPtr<FPlutoAssetRenamePreviewItem>;

	class SPlutoAssetRenamePreviewRow final : public SMultiColumnTableRow<FPreviewItemPtr>
	{
	public:
		SLATE_BEGIN_ARGS(SPlutoAssetRenamePreviewRow) {}
			SLATE_ARGUMENT(FPreviewItemPtr, Item)
		SLATE_END_ARGS()

		void Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& OwnerTable)
		{
			Item = InArgs._Item;
			SMultiColumnTableRow<FPreviewItemPtr>::Construct(FSuperRowType::FArguments().Padding(FMargin(2.0f, 1.0f)), OwnerTable);
		}

		virtual TSharedRef<SWidget> GenerateWidgetForColumn(const FName& ColumnName) override
		{
			if (ColumnName == PlutoAssetRenamePreviewColumns::Include)
			{
				return SNew(SCheckBox)
					.IsEnabled(!Item->AuditResult->SuggestedName.IsEmpty())
					.ToolTipText(Item->AuditResult->SuggestedName.IsEmpty()
						? LOCTEXT("NoSuggestionIncludeTooltip", "该资产没有安全的建议名称，不能纳入重命名计划。")
						: LOCTEXT("IncludeTooltip", "决定执行重命名时是否处理该资产。"))
					.IsChecked_Lambda([RowItem = Item]() { return RowItem->bIncluded ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
					.OnCheckStateChanged_Lambda([RowItem = Item](ECheckBoxState State) { RowItem->bIncluded = State == ECheckBoxState::Checked; });
			}

			if (ColumnName == PlutoAssetRenamePreviewColumns::CurrentName)
			{
				const FAssetData& AssetData = Item->AuditResult->AssetData;
				return SNew(SHorizontalBox)
					+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(2.0f, 0.0f, 6.0f, 0.0f)
					[
						SNew(SImage)
						.Image(FSlateIconFinder::FindIconBrushForClass(AssetData.GetClass(), TEXT("ClassIcon.Object")))
						.DesiredSizeOverride(FVector2D(16.0f, 16.0f))
					]
					+ SHorizontalBox::Slot().FillWidth(1.0f).VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text(FText::FromName(AssetData.AssetName))
						.ToolTipText(FText::FromName(AssetData.PackageName))
					];
			}

			if (ColumnName == PlutoAssetRenamePreviewColumns::SuggestedName)
			{
				return SNew(STextBlock)
					.Text(Item->AuditResult->SuggestedName.IsEmpty()
						? LOCTEXT("NoSuggestion", "—")
						: FText::FromString(Item->AuditResult->SuggestedName));
			}

			if (ColumnName == PlutoAssetRenamePreviewColumns::Type)
			{
				return SNew(STextBlock).Text(FText::FromString(Item->AuditResult->AssetTypeLabel));
			}

			if (ColumnName == PlutoAssetRenamePreviewColumns::Referencers)
			{
				return SNew(STextBlock).Text(FText::AsNumber(Item->Referencers.Num())).Justification(ETextJustify::Center);
			}

			if (ColumnName == PlutoAssetRenamePreviewColumns::Dependencies)
			{
				return SNew(STextBlock).Text(FText::AsNumber(Item->Dependencies.Num())).Justification(ETextJustify::Center);
			}

			if (ColumnName == PlutoAssetRenamePreviewColumns::Risk)
			{
				return SNew(STextBlock).Text(Item->GetRiskText()).ColorAndOpacity(Item->GetRiskColor());
			}

			return SNullWidget::NullWidget;
		}

	private:
		FPreviewItemPtr Item;
	};

	FString JoinPackageNames(const TArray<FName>& Names)
	{
		if (Names.IsEmpty())
		{
			return TEXT("无");
		}

		TArray<FString> Lines;
		Lines.Reserve(Names.Num());
		for (const FName Name : Names)
		{
			Lines.Add(Name.ToString());
		}
		return FString::Join(Lines, TEXT("\n"));
	}
}

void SPlutoAssetRenamePreview::Construct(const FArguments& InArgs)
{
	OnRenameCompleted = InArgs._OnRenameCompleted;
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	for (const TSharedPtr<FPlutoAssetNamingAuditResult>& AuditResult : InArgs._Items)
	{
		if (!AuditResult.IsValid())
		{
			continue;
		}

		FPreviewItemPtr Item = MakeShared<FPlutoAssetRenamePreviewItem>();
		Item->AuditResult = AuditResult;
		AssetRegistryModule.Get().GetReferencers(AuditResult->AssetData.PackageName, Item->Referencers);
		AssetRegistryModule.Get().GetDependencies(AuditResult->AssetData.PackageName, Item->Dependencies);
		Item->bIncluded = !AuditResult->SuggestedName.IsEmpty() && AuditResult->bRenameAllowed;
		AllItems.Add(Item);
	}
	VisibleItems = AllItems;
	if (!VisibleItems.IsEmpty())
	{
		SelectedItem = VisibleItems[0];
	}

	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
		.Padding(8.0f)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight().Padding(0.0f, 0.0f, 0.0f, 8.0f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().FillWidth(1.0f)
				[
					SNew(SSearchBox)
					.HintText(LOCTEXT("SearchHint", "搜索当前名称、建议名称、类型、路径或问题"))
					.OnTextChanged(this, &SPlutoAssetRenamePreview::HandleSearchChanged)
				]
				+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(8.0f, 0.0f)
				[
					SNew(SCheckBox)
					.IsChecked_Lambda([this]() { return bAttentionOnly ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
					.OnCheckStateChanged_Lambda([this](ECheckBoxState State)
					{
						bAttentionOnly = State == ECheckBoxState::Checked;
						RefreshVisibleItems();
					})
					[
						SNew(STextBlock).Text(LOCTEXT("AttentionOnly", "仅显示需人工确认"))
					]
				]
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(2.0f, 0.0f, 0.0f, 8.0f)
			[
				SNew(STextBlock).Text(this, &SPlutoAssetRenamePreview::GetSummaryText).ColorAndOpacity(FSlateColor::UseSubduedForeground())
			]
			+ SVerticalBox::Slot().FillHeight(1.0f)
			[
				SNew(SSplitter).Orientation(Orient_Vertical)
				+ SSplitter::Slot().Value(0.68f).MinSize(250.0f)
				[
					SAssignNew(ListView, SListView<FPreviewItemPtr>)
					.ListItemsSource(&VisibleItems)
					.SelectionMode(ESelectionMode::Single)
					.OnGenerateRow(this, &SPlutoAssetRenamePreview::GenerateRow)
					.OnSelectionChanged(this, &SPlutoAssetRenamePreview::HandleSelectionChanged)
					.HeaderRow
					(
						SNew(SHeaderRow)
						+ SHeaderRow::Column(PlutoAssetRenamePreviewColumns::Include)
						.FixedWidth(48.0f)
						.HeaderContent()
						[
							SNew(SCheckBox)
							.ToolTipText(LOCTEXT("SelectAllTooltip", "纳入或排除当前筛选后可见且有建议名称的资产；横线表示只纳入了其中一部分。"))
							.IsChecked(this, &SPlutoAssetRenamePreview::GetSelectAllState)
							.OnCheckStateChanged(this, &SPlutoAssetRenamePreview::HandleSelectAllChanged)
						]
						+ SHeaderRow::Column(PlutoAssetRenamePreviewColumns::CurrentName).DefaultLabel(LOCTEXT("CurrentNameColumn", "当前名称")).FillWidth(0.21f)
						+ SHeaderRow::Column(PlutoAssetRenamePreviewColumns::SuggestedName).DefaultLabel(LOCTEXT("SuggestedNameColumn", "建议名称")).FillWidth(0.22f)
						+ SHeaderRow::Column(PlutoAssetRenamePreviewColumns::Type).DefaultLabel(LOCTEXT("TypeColumn", "资产类型")).FillWidth(0.15f)
						+ SHeaderRow::Column(PlutoAssetRenamePreviewColumns::Referencers).DefaultLabel(LOCTEXT("ReferencersColumn", "引用者")).FixedWidth(66.0f)
						+ SHeaderRow::Column(PlutoAssetRenamePreviewColumns::Dependencies).DefaultLabel(LOCTEXT("DependenciesColumn", "依赖")).FixedWidth(58.0f)
						+ SHeaderRow::Column(PlutoAssetRenamePreviewColumns::Risk).DefaultLabel(LOCTEXT("RiskColumn", "处理结论")).FillWidth(0.18f)
					)
				]
				+ SSplitter::Slot().Value(0.32f).MinSize(150.0f)
				[
					SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("Brushes.Recessed"))
					.Padding(10.0f)
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot().AutoHeight()
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot().FillWidth(1.0f).VAlign(VAlign_Center)
							[
								SNew(STextBlock).Text(this, &SPlutoAssetRenamePreview::GetDetailTitle).Font(FAppStyle::GetFontStyle("HeadingExtraSmall"))
							]
							+ SHorizontalBox::Slot().AutoWidth()
							[
								SNew(SButton)
								.Text(LOCTEXT("Locate", "在内容浏览器中定位"))
								.ToolTipText(LOCTEXT("LocateTooltip", "在内容浏览器中选中当前矩阵行对应的资产。"))
								.IsEnabled_Lambda([this]() { return SelectedItem.IsValid(); })
								.OnClicked(this, &SPlutoAssetRenamePreview::HandleLocateClicked)
							]
						]
						+ SVerticalBox::Slot().FillHeight(1.0f).Padding(0.0f, 8.0f, 0.0f, 0.0f)
						[
							SNew(SScrollBox)
							+ SScrollBox::Slot()
							[
								SNew(STextBlock).Text(this, &SPlutoAssetRenamePreview::GetDetailBody).AutoWrapText(true)
							]
						]
					]
				]
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(2.0f, 8.0f, 0.0f, 0.0f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().FillWidth(1.0f).VAlign(VAlign_Center).Padding(0.0f, 0.0f, 12.0f, 0.0f)
				[
					SNew(STextBlock).Text(this, &SPlutoAssetRenamePreview::GetSafetyNotice).ColorAndOpacity(FLinearColor(1.0f, 0.62f, 0.18f)).AutoWrapText(true)
				]
				+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center)
				[
					SNew(SButton)
					.ButtonStyle(FAppStyle::Get(), "PrimaryButton")
					.Text(this, &SPlutoAssetRenamePreview::GetRenameButtonText)
					.ToolTipText(LOCTEXT("ExecuteRenameTooltip", "使用 Unreal AssetTools 重命名已纳入的资产并更新可解析引用；执行前会再次确认。"))
					.IsEnabled_Lambda([this]() { return GetIncludedCount() > 0; })
					.OnClicked(this, &SPlutoAssetRenamePreview::HandleRenameClicked)
				]
			]
		]
	];

	if (ListView.IsValid() && SelectedItem.IsValid())
	{
		ListView->SetSelection(SelectedItem);
	}
}

TSharedRef<ITableRow> SPlutoAssetRenamePreview::GenerateRow(FPreviewItemPtr Item, const TSharedRef<STableViewBase>& OwnerTable)
{
	return SNew(SPlutoAssetRenamePreviewRow, OwnerTable).Item(Item);
}

void SPlutoAssetRenamePreview::HandleSelectionChanged(FPreviewItemPtr Item, ESelectInfo::Type SelectInfo)
{
	SelectedItem = Item;
}

void SPlutoAssetRenamePreview::HandleSearchChanged(const FText& NewText)
{
	SearchText = NewText.ToString();
	RefreshVisibleItems();
}

void SPlutoAssetRenamePreview::RefreshVisibleItems()
{
	VisibleItems.Reset();
	for (const FPreviewItemPtr& Item : AllItems)
	{
		if (bAttentionOnly && !Item->NeedsAttention())
		{
			continue;
		}

		const FPlutoAssetNamingAuditResult& Result = *Item->AuditResult;
		const TArray<FString> SearchFields =
		{
			Result.AssetData.AssetName.ToString(),
			Result.AssetData.PackageName.ToString(),
			Result.AssetTypeLabel,
			Result.Issue,
			Result.SuggestedName
		};
		const FString Searchable = FString::Join(SearchFields, TEXT(" "));
		if (!SearchText.IsEmpty() && !Searchable.Contains(SearchText, ESearchCase::IgnoreCase))
		{
			continue;
		}
		VisibleItems.Add(Item);
	}

	if (ListView.IsValid())
	{
		ListView->RequestListRefresh();
	}
}

FReply SPlutoAssetRenamePreview::HandleLocateClicked()
{
	if (!SelectedItem.IsValid())
	{
		return FReply::Handled();
	}

	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	ContentBrowserModule.Get().SyncBrowserToAssets({ SelectedItem->AuditResult->AssetData });
	return FReply::Handled();
}

ECheckBoxState SPlutoAssetRenamePreview::GetSelectAllState() const
{
	int32 EligibleCount = 0;
	int32 IncludedCount = 0;
	for (const FPreviewItemPtr& Item : VisibleItems)
	{
		if (!Item->AuditResult->SuggestedName.IsEmpty())
		{
			++EligibleCount;
			IncludedCount += Item->bIncluded ? 1 : 0;
		}
	}

	if (EligibleCount == 0 || IncludedCount == 0)
	{
		return ECheckBoxState::Unchecked;
	}
	return IncludedCount == EligibleCount ? ECheckBoxState::Checked : ECheckBoxState::Undetermined;
}

void SPlutoAssetRenamePreview::HandleSelectAllChanged(ECheckBoxState NewState)
{
	const bool bShouldInclude = NewState == ECheckBoxState::Checked;
	for (const FPreviewItemPtr& Item : VisibleItems)
	{
		if (!Item->AuditResult->SuggestedName.IsEmpty())
		{
			Item->bIncluded = bShouldInclude;
		}
	}
	if (ListView.IsValid())
	{
		ListView->RequestListRefresh();
	}
}

FReply SPlutoAssetRenamePreview::HandleRenameClicked()
{
	TArray<FPreviewItemPtr> ItemsToRename;
	for (const FPreviewItemPtr& Item : AllItems)
	{
		if (Item->bIncluded && !Item->AuditResult->SuggestedName.IsEmpty())
		{
			ItemsToRename.Add(Item);
		}
	}

	if (ItemsToRename.IsEmpty())
	{
		return FReply::Handled();
	}

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TSet<FString> TargetObjectPaths;
	TArray<FString> Conflicts;
	TArray<FAssetRenameData> RenameData;
	int32 ManualReviewCount = 0;

	for (const FPreviewItemPtr& Item : ItemsToRename)
	{
		const FPlutoAssetNamingAuditResult& Result = *Item->AuditResult;
		const FString PackagePath = Result.AssetData.PackagePath.ToString();
		const FString TargetObjectPath = FString::Printf(
			TEXT("%s/%s.%s"),
			*PackagePath,
			*Result.SuggestedName,
			*Result.SuggestedName);

		if (TargetObjectPaths.Contains(TargetObjectPath))
		{
			Conflicts.Add(FString::Printf(TEXT("多个资产计划使用同一名称：%s"), *TargetObjectPath));
			continue;
		}
		TargetObjectPaths.Add(TargetObjectPath);

		const FAssetData ExistingAsset = AssetRegistryModule.Get().GetAssetByObjectPath(FSoftObjectPath(TargetObjectPath));
		if (ExistingAsset.IsValid() && ExistingAsset.PackageName != Result.AssetData.PackageName)
		{
			Conflicts.Add(FString::Printf(TEXT("目标名称已存在：%s"), *TargetObjectPath));
			continue;
		}

		UObject* Asset = Result.AssetData.GetAsset();
		if (Asset == nullptr)
		{
			Conflicts.Add(FString::Printf(TEXT("资产加载失败：%s"), *Result.AssetData.PackageName.ToString()));
			continue;
		}

		RenameData.Emplace(Asset, PackagePath, Result.SuggestedName);
		ManualReviewCount += Result.bRenameAllowed ? 0 : 1;
	}

	if (!Conflicts.IsEmpty())
	{
		const int32 DisplayCount = FMath::Min(Conflicts.Num(), 8);
		TArray<FString> DisplayedConflicts;
		for (int32 Index = 0; Index < DisplayCount; ++Index)
		{
			DisplayedConflicts.Add(TEXT("• ") + Conflicts[Index]);
		}
		if (Conflicts.Num() > DisplayCount)
		{
			DisplayedConflicts.Add(FString::Printf(TEXT("……另有 %d 项"), Conflicts.Num() - DisplayCount));
		}

		FMessageDialog::Open(
			EAppMsgType::Ok,
			FText::FromString(TEXT("无法执行本次重命名，请先处理以下问题：\n\n") + FString::Join(DisplayedConflicts, TEXT("\n"))),
			LOCTEXT("RenameConflictTitle", "重命名检查未通过"));
		return FReply::Handled();
	}

	const FText ConfirmMessage = FText::Format(
		LOCTEXT("RenameConfirmation", "即将使用 Unreal AssetTools 重命名 {0} 个资产并更新可解析引用。\n其中 {1} 项被标记为需要人工确认。\n\n继续执行吗？"),
		FText::AsNumber(RenameData.Num()),
		FText::AsNumber(ManualReviewCount));
	if (FMessageDialog::Open(EAppMsgType::YesNo, ConfirmMessage, LOCTEXT("RenameConfirmationTitle", "确认执行资产重命名")) != EAppReturnType::Yes)
	{
		return FReply::Handled();
	}

	FAssetToolsModule& AssetToolsModule = FAssetToolsModule::GetModule();
	const bool bSucceeded = AssetToolsModule.Get().RenameAssets(RenameData);
	FNotificationInfo Notification(bSucceeded
		? FText::Format(LOCTEXT("RenameSucceeded", "已完成 {0} 项资产重命名，请检查并保存受影响资产。"), FText::AsNumber(RenameData.Num()))
		: LOCTEXT("RenameFailed", "资产重命名未完整完成，请查看输出日志并重新扫描确认结果。"));
	Notification.ExpireDuration = 6.0f;
	FSlateNotificationManager::Get().AddNotification(Notification);

	OnRenameCompleted.ExecuteIfBound();
	if (const TSharedPtr<SWindow> Window = FSlateApplication::Get().FindWidgetWindow(AsShared()))
	{
		Window->RequestDestroyWindow();
	}
	return FReply::Handled();
}

FText SPlutoAssetRenamePreview::GetSummaryText() const
{
	int32 AttentionCount = 0;
	for (const FPreviewItemPtr& Item : AllItems)
	{
		AttentionCount += Item->NeedsAttention() ? 1 : 0;
	}
	return FText::Format(
		LOCTEXT("Summary", "已选择 {0} 项 · 当前显示 {1} 项 · 纳入计划 {2} 项 · 需人工确认 {3} 项"),
		FText::AsNumber(AllItems.Num()),
		FText::AsNumber(VisibleItems.Num()),
		FText::AsNumber(GetIncludedCount()),
		FText::AsNumber(AttentionCount));
}

FText SPlutoAssetRenamePreview::GetRenameButtonText() const
{
	return FText::Format(LOCTEXT("ExecuteRename", "执行重命名（{0}）"), FText::AsNumber(GetIncludedCount()));
}

int32 SPlutoAssetRenamePreview::GetIncludedCount() const
{
	int32 IncludedCount = 0;
	for (const FPreviewItemPtr& Item : AllItems)
	{
		IncludedCount += Item->bIncluded && !Item->AuditResult->SuggestedName.IsEmpty() ? 1 : 0;
	}
	return IncludedCount;
}

FText SPlutoAssetRenamePreview::GetDetailTitle() const
{
	return SelectedItem.IsValid()
		? FText::FromName(SelectedItem->AuditResult->AssetData.AssetName)
		: LOCTEXT("SelectDetail", "选择一项查看详情");
}

FText SPlutoAssetRenamePreview::GetDetailBody() const
{
	if (!SelectedItem.IsValid())
	{
		return FText::GetEmpty();
	}

	const FPlutoAssetNamingAuditResult& Result = *SelectedItem->AuditResult;
	return FText::FromString(FString::Printf(
		TEXT("资产路径\n%s\n\n命名问题\n%s\n\n技术说明\n%s\n\n建议名称\n%s\n\n引用者（%d）\n%s\n\n依赖（%d）\n%s"),
		*Result.AssetData.PackageName.ToString(),
		*Result.Issue,
		*Result.TechnicalDetails,
		Result.SuggestedName.IsEmpty() ? TEXT("尚无安全建议") : *Result.SuggestedName,
		SelectedItem->Referencers.Num(),
		*JoinPackageNames(SelectedItem->Referencers),
		SelectedItem->Dependencies.Num(),
		*JoinPackageNames(SelectedItem->Dependencies)));
}

FText SPlutoAssetRenamePreview::GetSafetyNotice() const
{
	return LOCTEXT("SafetyNotice", "重命名会修改资产及可解析引用；完成后请检查结果并保存。工具不会自动清理 Redirector。需要人工确认的项目默认不纳入。");
}

#undef LOCTEXT_NAMESPACE
