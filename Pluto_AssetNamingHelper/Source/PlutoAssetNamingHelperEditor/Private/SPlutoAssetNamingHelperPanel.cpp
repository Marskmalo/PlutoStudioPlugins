#include "SPlutoAssetNamingHelperPanel.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetToolsModule.h"
#include "ContentBrowserModule.h"
#include "Framework/Docking/TabManager.h"
#include "Framework/Notifications/NotificationManager.h"
#include "HAL/FileManager.h"
#include "IAssetTools.h"
#include "IAssetTypeActions.h"
#include "IContentBrowserSingleton.h"
#include "Internationalization/Text.h"
#include "Misc/DateTime.h"
#include "Misc/FileHelper.h"
#include "Misc/MessageDialog.h"
#include "Misc/Paths.h"
#include "PlutoAssetNamingHelperEditorModule.h"
#include "Styling/AppStyle.h"
#include "Styling/SlateIconFinder.h"
#include "Widgets/Colors/SColorBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SSearchBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SSplitter.h"
#include "Widgets/Layout/SUniformGridPanel.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Widgets/Views/SHeaderRow.h"
#include "Widgets/Views/SListView.h"
#include "Widgets/Views/STableRow.h"

#define LOCTEXT_NAMESPACE "SPlutoAssetNamingHelperPanel"

namespace PlutoAssetNamingHelperColumns
{
	const FName Name(TEXT("Name"));
	const FName TypeOwner(TEXT("TypeOwner"));
	const FName Status(TEXT("Status"));
	const FName Issue(TEXT("Issue"));
	const FName Suggestion(TEXT("Suggestion"));
	const FName Action(TEXT("Action"));
}

namespace
{
	FString EscapeCsv(FString Value)
	{
		Value.ReplaceInline(TEXT("\""), TEXT("\"\""));
		return FString::Printf(TEXT("\"%s\""), *Value);
	}

	class SPlutoAssetNamingResultRow final : public SMultiColumnTableRow<TSharedPtr<FPlutoAssetNamingAuditResult>>
	{
	public:
		SLATE_BEGIN_ARGS(SPlutoAssetNamingResultRow) {}
			SLATE_ARGUMENT(TSharedPtr<FPlutoAssetNamingAuditResult>, Item)
			SLATE_ARGUMENT(TWeakPtr<SPlutoAssetNamingHelperPanel>, OwnerPanel)
		SLATE_END_ARGS()

		void Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& InOwnerTable)
		{
			Item = InArgs._Item;
			OwnerPanel = InArgs._OwnerPanel;
			SMultiColumnTableRow<TSharedPtr<FPlutoAssetNamingAuditResult>>::Construct(
				FSuperRowType::FArguments().Padding(FMargin(2.0f, 1.0f)),
				InOwnerTable);
		}

		virtual TSharedRef<SWidget> GenerateWidgetForColumn(const FName& ColumnName) override
		{
			if (ColumnName == PlutoAssetNamingHelperColumns::Name)
			{
				UClass* AssetClass = Item->AssetData.GetClass();
				const FSlateBrush* IconBrush = FSlateIconFinder::FindIconBrushForClass(AssetClass, TEXT("ClassIcon.Object"));
				return SNew(SHorizontalBox)
					+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(2.0f, 0.0f, 6.0f, 0.0f)
					[
						SNew(SImage).Image(IconBrush).DesiredSizeOverride(FVector2D(16.0f, 16.0f))
					]
					+ SHorizontalBox::Slot().FillWidth(1.0f).VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text(FText::FromName(Item->AssetData.AssetName))
						.ToolTipText(FText::FromName(Item->AssetData.PackageName))
					];
			}

			if (ColumnName == PlutoAssetNamingHelperColumns::TypeOwner)
			{
				return SNew(STextBlock)
					.Text(FText::FromString(Item->AssetTypeLabel + TEXT(" / ") + Item->OwnerLabel))
					.ToolTipText(FText::FromString(Item->AssetData.AssetClassPath.ToString()));
			}

			if (ColumnName == PlutoAssetNamingHelperColumns::Status)
			{
				const FLinearColor StatusColor = PlutoAssetNamingRules::GetStatusColor(Item->Status);
				return SNew(SBorder)
					.BorderImage(FAppStyle::GetBrush("WhiteBrush"))
					.BorderBackgroundColor(StatusColor.CopyWithNewOpacity(0.18f))
					.Padding(FMargin(6.0f, 2.0f))
					[
						SNew(STextBlock)
						.Text(PlutoAssetNamingRules::GetStatusText(Item->Status))
						.ColorAndOpacity(StatusColor)
					];
			}

			if (ColumnName == PlutoAssetNamingHelperColumns::Issue)
			{
				return SNew(STextBlock)
					.Text(FText::FromString(Item->Issue))
					.ToolTipText(FText::FromString(Item->TechnicalDetails));
			}

			if (ColumnName == PlutoAssetNamingHelperColumns::Suggestion)
			{
				return SNew(STextBlock)
					.Text(Item->SuggestedName.IsEmpty() ? LOCTEXT("KeepOrUnresolved", "—") : FText::FromString(Item->SuggestedName))
					.ToolTipText(Item->SuggestedName.IsEmpty()
						? LOCTEXT("NoSuggestionTooltip", "当前没有足够信息生成安全的建议名称。")
						: FText::FromString(Item->SuggestedName));
			}

			if (ColumnName == PlutoAssetNamingHelperColumns::Action)
			{
				return SNew(SButton)
					.ButtonStyle(FAppStyle::Get(), "SimpleButton")
					.Text(LOCTEXT("LocateAsset", "定位"))
					.ToolTipText(LOCTEXT("LocateAssetTooltip", "在内容浏览器中定位该资产。"))
					.OnClicked_Lambda([WeakOwner = OwnerPanel, RowItem = Item]()
					{
						if (const TSharedPtr<SPlutoAssetNamingHelperPanel> Owner = WeakOwner.Pin())
						{
							Owner->FocusAsset(RowItem);
						}
						return FReply::Handled();
					});
			}

			return SNullWidget::NullWidget;
		}

	private:
		TSharedPtr<FPlutoAssetNamingAuditResult> Item;
		TWeakPtr<SPlutoAssetNamingHelperPanel> OwnerPanel;
	};
}

void SPlutoAssetNamingHelperPanel::Construct(const FArguments& InArgs)
{
	EnabledStatuses.Add(EPlutoAssetNamingStatus::Compliant, true);
	EnabledStatuses.Add(EPlutoAssetNamingStatus::HistoricalException, true);
	EnabledStatuses.Add(EPlutoAssetNamingStatus::SuggestedMigration, true);
	EnabledStatuses.Add(EPlutoAssetNamingStatus::Protected, true);

	FPathPickerConfig PathPickerConfig;
	PathPickerConfig.DefaultPath = SelectedRootPath;
	PathPickerConfig.OnPathSelected = FOnPathSelected::CreateSP(this, &SPlutoAssetNamingHelperPanel::HandlePathSelected);
	PathPickerConfig.bAllowContextMenu = false;
	PathPickerConfig.bAllowClassesFolder = false;
	PathPickerConfig.bCanShowDevelopersFolder = true;
	PathPickerConfig.bShowFavorites = false;
	PathPickerConfig.bShowViewOptions = true;

	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	const TSharedRef<SWidget> PathPicker = ContentBrowserModule.Get().CreatePathPicker(PathPickerConfig);

	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
		.Padding(4.0f)
		[
			SNew(SSplitter)

			+ SSplitter::Slot().Value(0.20f).MinSize(230.0f)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight().Padding(8.0f, 6.0f)
				[
					SNew(STextBlock).Text(LOCTEXT("ScanScope", "扫描范围")).Font(FAppStyle::GetFontStyle("HeadingExtraSmall"))
				]
				+ SVerticalBox::Slot().FillHeight(1.0f).Padding(4.0f)
				[
					PathPicker
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(8.0f, 4.0f)
				[
					SNew(SCheckBox)
					.IsChecked(ECheckBoxState::Checked)
					.IsEnabled(false)
					.ToolTipText(LOCTEXT("RecursiveTooltip", "第一版固定递归扫描所选文件夹及其子文件夹。"))
					[
						SNew(STextBlock).Text(LOCTEXT("RecursiveFolders", "递归子文件夹"))
					]
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(8.0f, 8.0f)
				[
					SNew(SButton)
					.ButtonStyle(FAppStyle::Get(), "PrimaryButton")
					.HAlign(HAlign_Center)
					.Text(LOCTEXT("StartScan", "开始扫描"))
					.ToolTipText(LOCTEXT("StartScanTooltip", "只读取 Asset Registry 元数据，不加载或修改资产。"))
					.OnClicked(this, &SPlutoAssetNamingHelperPanel::HandleScanClicked)
				]
			]

			+ SSplitter::Slot().Value(0.18f).MinSize(220.0f)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight().Padding(8.0f, 6.0f)
				[
					SNew(STextBlock).Text(LOCTEXT("AssetTypes", "资产类型")).Font(FAppStyle::GetFontStyle("HeadingExtraSmall"))
				]
				+ SVerticalBox::Slot().FillHeight(1.0f).Padding(4.0f)
				[
					SNew(SScrollBox)
					+ SScrollBox::Slot()
					[
						SAssignNew(TypeFilterBox, SVerticalBox)
						+ SVerticalBox::Slot().AutoHeight().Padding(6.0f)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("ScanFirstForTypes", "扫描后会按 UE 资产类型生成筛选器。"))
							.AutoWrapText(true)
							.ColorAndOpacity(FSlateColor::UseSubduedForeground())
						]
					]
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(8.0f, 6.0f, 8.0f, 2.0f)
				[
					SNew(STextBlock).Text(LOCTEXT("NamingStatus", "命名状态")).Font(FAppStyle::GetFontStyle("HeadingExtraSmall"))
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(4.0f)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot().AutoHeight()[BuildStatusFilter(EPlutoAssetNamingStatus::Compliant)]
					+ SVerticalBox::Slot().AutoHeight()[BuildStatusFilter(EPlutoAssetNamingStatus::HistoricalException)]
					+ SVerticalBox::Slot().AutoHeight()[BuildStatusFilter(EPlutoAssetNamingStatus::SuggestedMigration)]
					+ SVerticalBox::Slot().AutoHeight()[BuildStatusFilter(EPlutoAssetNamingStatus::Protected)]
				]
			]

			+ SSplitter::Slot().Value(0.62f).MinSize(620.0f)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight().Padding(6.0f)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot().FillWidth(1.0f)
					[
						SNew(SSearchBox)
						.HintText(LOCTEXT("SearchHint", "搜索资产名称、路径、问题或建议名称"))
						.OnTextChanged(this, &SPlutoAssetNamingHelperPanel::HandleSearchChanged)
					]
					+ SHorizontalBox::Slot().AutoWidth().Padding(6.0f, 0.0f, 0.0f, 0.0f)
					[
						SNew(SButton)
						.ButtonStyle(FAppStyle::Get(), "SimpleButton")
						.Text(LOCTEXT("Documentation", "使用文档"))
						.ToolTipText(LOCTEXT("DocumentationTooltip", "打开插件内置的 Markdown 使用文档。"))
						.OnClicked(this, &SPlutoAssetNamingHelperPanel::HandleDocumentationClicked)
					]
					+ SHorizontalBox::Slot().AutoWidth().Padding(6.0f, 0.0f, 0.0f, 0.0f)
					[
						SNew(SButton).Text(LOCTEXT("Rescan", "重新扫描")).OnClicked(this, &SPlutoAssetNamingHelperPanel::HandleScanClicked)
					]
					+ SHorizontalBox::Slot().AutoWidth().Padding(6.0f, 0.0f, 0.0f, 0.0f)
					[
						SNew(SButton).Text(LOCTEXT("ExportReport", "导出报告")).OnClicked(this, &SPlutoAssetNamingHelperPanel::HandleExportClicked)
					]
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(6.0f, 0.0f, 6.0f, 6.0f)
				[
					SNew(SUniformGridPanel).SlotPadding(FMargin(3.0f))
					+ SUniformGridPanel::Slot(0, 0)[BuildSummaryCard(EPlutoAssetNamingStatus::Compliant)]
					+ SUniformGridPanel::Slot(1, 0)[BuildSummaryCard(EPlutoAssetNamingStatus::HistoricalException)]
					+ SUniformGridPanel::Slot(2, 0)[BuildSummaryCard(EPlutoAssetNamingStatus::SuggestedMigration)]
					+ SUniformGridPanel::Slot(3, 0)[BuildSummaryCard(EPlutoAssetNamingStatus::Protected)]
				]
				+ SVerticalBox::Slot().FillHeight(1.0f).Padding(6.0f, 0.0f)
				[
					SAssignNew(ResultListView, SListView<FAuditResultPtr>)
					.ListItemsSource(&VisibleResults)
					.SelectionMode(ESelectionMode::Multi)
					.OnGenerateRow(this, &SPlutoAssetNamingHelperPanel::GenerateResultRow)
					.HeaderRow
					(
						SNew(SHeaderRow)
						+ SHeaderRow::Column(PlutoAssetNamingHelperColumns::Name).DefaultLabel(LOCTEXT("NameColumn", "当前名称")).FillWidth(0.17f)
						+ SHeaderRow::Column(PlutoAssetNamingHelperColumns::TypeOwner).DefaultLabel(LOCTEXT("TypeOwnerColumn", "类型 / 所有权")).FillWidth(0.16f)
						+ SHeaderRow::Column(PlutoAssetNamingHelperColumns::Status).DefaultLabel(LOCTEXT("StatusColumn", "分类")).FillWidth(0.12f)
						+ SHeaderRow::Column(PlutoAssetNamingHelperColumns::Issue).DefaultLabel(LOCTEXT("IssueColumn", "问题")).FillWidth(0.27f)
						+ SHeaderRow::Column(PlutoAssetNamingHelperColumns::Suggestion).DefaultLabel(LOCTEXT("SuggestionColumn", "建议名称")).FillWidth(0.20f)
						+ SHeaderRow::Column(PlutoAssetNamingHelperColumns::Action).DefaultLabel(LOCTEXT("ActionColumn", "操作")).FixedWidth(64.0f)
					)
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(8.0f)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot().FillWidth(1.0f).VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text_Lambda([this]()
						{
							const int32 SelectedCount = ResultListView.IsValid() ? ResultListView->GetNumItemsSelected() : 0;
							return FText::Format(
								LOCTEXT("ScanSummary", "已扫描 {0} 个资产 · 当前显示 {1} 项 · 已选择 {2} 项"),
								FText::AsNumber(AllResults.Num()),
								FText::AsNumber(VisibleResults.Num()),
								FText::AsNumber(SelectedCount));
						})
						.ColorAndOpacity(FSlateColor::UseSubduedForeground())
					]
					+ SHorizontalBox::Slot().AutoWidth().Padding(6.0f, 0.0f)
					[
						SNew(SButton)
						.Text(LOCTEXT("RenamePreview", "重命名预览"))
						.ToolTipText(LOCTEXT("RenamePreviewTooltip", "读取所选资产的引用数量并预览改名计划；第一版不会修改资产。"))
						.OnClicked(this, &SPlutoAssetNamingHelperPanel::HandleRenamePreviewClicked)
					]
				]
			]
		]
	];

}

TSharedRef<ITableRow> SPlutoAssetNamingHelperPanel::GenerateResultRow(FAuditResultPtr Item, const TSharedRef<STableViewBase>& OwnerTable)
{
	return SNew(SPlutoAssetNamingResultRow, OwnerTable)
		.Item(Item)
		.OwnerPanel(SharedThis(this));
}

TSharedRef<SWidget> SPlutoAssetNamingHelperPanel::BuildSummaryCard(EPlutoAssetNamingStatus Status)
{
	const FLinearColor StatusColor = PlutoAssetNamingRules::GetStatusColor(Status);
	return SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
		.Padding(FMargin(10.0f, 7.0f))
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(STextBlock).Text(PlutoAssetNamingRules::GetStatusText(Status))
			]
			+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center).Padding(0.0f, 3.0f, 0.0f, 0.0f)
			[
				SNew(STextBlock)
				.Text_Lambda([this, Status]() { return FText::AsNumber(GetStatusCount(Status)); })
				.Font(FAppStyle::GetFontStyle("HeadingMedium"))
				.ColorAndOpacity(StatusColor)
			]
		];
}

TSharedRef<SWidget> SPlutoAssetNamingHelperPanel::BuildStatusFilter(EPlutoAssetNamingStatus Status)
{
	const FLinearColor StatusColor = PlutoAssetNamingRules::GetStatusColor(Status);
	return SNew(SCheckBox)
		.Padding(FMargin(6.0f, 4.0f))
		.IsChecked_Lambda([this, Status]() { return IsStatusEnabled(Status) ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
		.OnCheckStateChanged_Lambda([this, Status](ECheckBoxState State)
		{
			SetStatusEnabled(Status, State == ECheckBoxState::Checked);
			RefreshVisibleResults();
		})
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(0.0f, 0.0f, 6.0f, 0.0f)
			[
				SNew(SColorBlock).Color(StatusColor).Size(FVector2D(8.0f, 8.0f))
			]
			+ SHorizontalBox::Slot().FillWidth(1.0f).VAlign(VAlign_Center)
			[
				SNew(STextBlock).Text(PlutoAssetNamingRules::GetStatusText(Status))
			]
			+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text_Lambda([this, Status]() { return FText::AsNumber(GetStatusCount(Status)); })
				.ColorAndOpacity(StatusColor)
			]
		];
}

TSharedRef<SWidget> SPlutoAssetNamingHelperPanel::BuildAssetTypeIcon(const FTypeFilterPtr& TypeItem) const
{
	const FSlateBrush* IconBrush = FSlateIconFinder::FindIconBrushForClass(TypeItem->AssetClass.Get(), TEXT("ClassIcon.Object"));
	return SNew(SBox)
		.WidthOverride(24.0f)
		.HeightOverride(24.0f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)
			[
				SNew(SImage)
				.Image(IconBrush)
				.DesiredSizeOverride(FVector2D(18.0f, 18.0f))
				.ColorAndOpacity_Lambda([TypeItem]()
				{
					return TypeItem->bEnabled ? FLinearColor::White : FLinearColor(0.34f, 0.34f, 0.34f, 1.0f);
				})
			]
			+ SOverlay::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Bottom)
			[
				SNew(SColorBlock)
				.Color_Lambda([TypeItem]()
				{
					return TypeItem->bEnabled ? TypeItem->TypeColor : FLinearColor(0.16f, 0.16f, 0.16f, 1.0f);
				})
				.Size(FVector2D(1.0f, 2.0f))
			]
		];
}

void SPlutoAssetNamingHelperPanel::HandlePathSelected(const FString& NewPath)
{
	SelectedRootPath = NewPath;
}

FReply SPlutoAssetNamingHelperPanel::HandleScanClicked()
{
	AllResults.Reset();

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> Assets;
	AssetRegistryModule.Get().GetAssetsByPath(FName(*SelectedRootPath), Assets, true, false);
	Assets.Sort([](const FAssetData& Left, const FAssetData& Right)
	{
		return Left.PackageName.LexicalLess(Right.PackageName);
	});

	for (const FAssetData& Asset : Assets)
	{
		AllResults.Add(MakeShared<FPlutoAssetNamingAuditResult>(PlutoAssetNamingRules::Audit(Asset)));
	}

	RebuildTypeFilters();
	RefreshVisibleResults();
	ShowTransientMessage(
		FText::Format(LOCTEXT("ScanComplete", "扫描完成：找到 {0} 个资产。"), FText::AsNumber(AllResults.Num())),
		true);
	return FReply::Handled();
}

FReply SPlutoAssetNamingHelperPanel::HandleExportClicked()
{
	if (AllResults.IsEmpty())
	{
		ShowTransientMessage(LOCTEXT("NothingToExport", "当前没有可导出的扫描结果。"), false);
		return FReply::Handled();
	}

	FString Csv = TEXT("CurrentName,PackagePath,AssetType,Owner,Classification,Issue,TechnicalDetails,SuggestedName\n");
	for (const FAuditResultPtr& Result : AllResults)
	{
		const TArray<FString> CsvFields =
		{
				EscapeCsv(Result->AssetData.AssetName.ToString()),
				EscapeCsv(Result->AssetData.PackageName.ToString()),
				EscapeCsv(Result->AssetTypeLabel),
				EscapeCsv(Result->OwnerLabel),
				EscapeCsv(PlutoAssetNamingRules::GetStatusText(Result->Status).ToString()),
				EscapeCsv(Result->Issue),
				EscapeCsv(Result->TechnicalDetails),
				EscapeCsv(Result->SuggestedName)
		};
		Csv += FString::Join(CsvFields, TEXT(","));
		Csv += LINE_TERMINATOR;
	}

	const FString ReportDirectory = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("PlutoAssetNamingHelper"));
	IFileManager::Get().MakeDirectory(*ReportDirectory, true);
	const FString ReportPath = FPaths::Combine(
		ReportDirectory,
		FString::Printf(TEXT("AssetNamingReport-%s.csv"), *FDateTime::Now().ToString(TEXT("%Y%m%d-%H%M%S"))));

	const bool bSaved = FFileHelper::SaveStringToFile(Csv, *ReportPath, FFileHelper::EEncodingOptions::ForceUTF8);
	ShowTransientMessage(
		bSaved
			? FText::Format(LOCTEXT("ExportComplete", "报告已导出：{0}"), FText::FromString(ReportPath))
			: LOCTEXT("ExportFailed", "报告导出失败，请检查 Saved 目录写入权限。"),
		bSaved);
	return FReply::Handled();
}

FReply SPlutoAssetNamingHelperPanel::HandleRenamePreviewClicked()
{
	if (!ResultListView.IsValid())
	{
		return FReply::Handled();
	}

	const TArray<FAuditResultPtr> SelectedItems = ResultListView->GetSelectedItems();
	if (SelectedItems.IsEmpty())
	{
		ShowTransientMessage(LOCTEXT("SelectAssetsFirst", "请先在结果表中选择至少一个资产。"), false);
		return FReply::Handled();
	}

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	FString Preview = TEXT("重命名影响预览（当前版本不会修改资产）\n\n");
	for (const FAuditResultPtr& Item : SelectedItems)
	{
		TArray<FName> Referencers;
		TArray<FName> Dependencies;
		AssetRegistryModule.Get().GetReferencers(Item->AssetData.PackageName, Referencers);
		AssetRegistryModule.Get().GetDependencies(Item->AssetData.PackageName, Dependencies);

		Preview += FString::Printf(
			TEXT("%s  →  %s\n引用者：%d　依赖：%d\n%s\n\n"),
			*Item->AssetData.AssetName.ToString(),
			Item->SuggestedName.IsEmpty() ? TEXT("尚无安全建议") : *Item->SuggestedName,
			Referencers.Num(),
			Dependencies.Num(),
			Item->bRenameAllowed ? TEXT("可进入后续受控重命名流程") : TEXT("需要人工确认，不能自动修改"));
	}

	FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(Preview), LOCTEXT("RenamePreviewTitle", "Pluto 重命名预览"));
	return FReply::Handled();
}

FReply SPlutoAssetNamingHelperPanel::HandleDocumentationClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(FPlutoAssetNamingHelperEditorModule::DocumentationTabName);
	return FReply::Handled();
}

void SPlutoAssetNamingHelperPanel::HandleSearchChanged(const FText& NewSearchText)
{
	SearchText = NewSearchText.ToString();
	RefreshVisibleResults();
}

void SPlutoAssetNamingHelperPanel::RebuildTypeFilters()
{
	TMap<FTopLevelAssetPath, FTypeFilterPtr> PreviousFilters;
	for (const FTypeFilterPtr& ExistingFilter : TypeFilters)
	{
		PreviousFilters.Add(ExistingFilter->ClassPath, ExistingFilter);
	}

	TypeFilters.Reset();
	TSet<FTopLevelAssetPath> SeenClasses;
	FAssetToolsModule& AssetToolsModule = FAssetToolsModule::GetModule();

	for (const FAuditResultPtr& Result : AllResults)
	{
		const FTopLevelAssetPath ClassPath = Result->AssetData.AssetClassPath;
		if (SeenClasses.Contains(ClassPath))
		{
			continue;
		}
		SeenClasses.Add(ClassPath);

		FTypeFilterPtr TypeItem = MakeShared<FPlutoAssetTypeFilterItem>();
		TypeItem->ClassPath = ClassPath;
		if (const FTypeFilterPtr* Previous = PreviousFilters.Find(ClassPath))
		{
			TypeItem->bEnabled = (*Previous)->bEnabled;
		}

		UClass* AssetClass = Result->AssetData.GetClass();
		TypeItem->AssetClass = AssetClass;
		TypeItem->DisplayName = AssetClass ? AssetClass->GetDisplayNameText() : FText::FromName(ClassPath.GetAssetName());

		if (AssetClass != nullptr)
		{
			if (const TSharedPtr<IAssetTypeActions> AssetActions = AssetToolsModule.Get().GetAssetTypeActionsForClass(AssetClass).Pin())
			{
				TypeItem->DisplayName = AssetActions->GetName();
				TypeItem->TypeColor = AssetActions->GetTypeColor().ReinterpretAsLinear();
			}
		}
		TypeFilters.Add(TypeItem);
	}

	TypeFilters.Sort([](const FTypeFilterPtr& Left, const FTypeFilterPtr& Right)
	{
		return Left->DisplayName.CompareTo(Right->DisplayName) < 0;
	});

	if (!TypeFilterBox.IsValid())
	{
		return;
	}

	TypeFilterBox->ClearChildren();
	for (const FTypeFilterPtr& TypeItem : TypeFilters)
	{
		TypeFilterBox->AddSlot().AutoHeight().Padding(2.0f)
		[
			SNew(SCheckBox)
			.Style(FAppStyle::Get(), "FilterBar.FilterButton")
			.ToolTipText(LOCTEXT("TypeFilterTooltip", "点亮后仅显示该类型；没有任何类型点亮时显示全部资产。"))
			.IsChecked_Lambda([TypeItem]() { return TypeItem->bEnabled ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
			.OnCheckStateChanged_Lambda([this, TypeItem](ECheckBoxState NewState)
			{
				TypeItem->bEnabled = NewState == ECheckBoxState::Checked;
				RefreshVisibleResults();
			})
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(2.0f, 1.0f, 8.0f, 1.0f)
				[
					BuildAssetTypeIcon(TypeItem)
				]
				+ SHorizontalBox::Slot().FillWidth(1.0f).VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(TypeItem->DisplayName)
					.ColorAndOpacity_Lambda([TypeItem]()
					{
						return TypeItem->bEnabled
							? FSlateColor::UseForeground()
							: FSlateColor(FLinearColor(0.36f, 0.36f, 0.36f, 1.0f));
					})
				]
			]
		];
	}
}

void SPlutoAssetNamingHelperPanel::RefreshVisibleResults()
{
	VisibleResults.Reset();
	const bool bHasActiveTypeFilters = TypeFilters.ContainsByPredicate([](const FTypeFilterPtr& Candidate)
	{
		return Candidate->bEnabled;
	});

	for (const FAuditResultPtr& Result : AllResults)
	{
		if (!IsStatusEnabled(Result->Status))
		{
			continue;
		}

		const FTypeFilterPtr* TypeFilter = TypeFilters.FindByPredicate([&Result](const FTypeFilterPtr& Candidate)
		{
			return Candidate->ClassPath == Result->AssetData.AssetClassPath;
		});
		if (bHasActiveTypeFilters && TypeFilter != nullptr && !(*TypeFilter)->bEnabled)
		{
			continue;
		}

		if (!SearchText.IsEmpty())
		{
			const TArray<FString> SearchFields =
			{
					Result->AssetData.AssetName.ToString(),
					Result->AssetData.PackageName.ToString(),
					Result->AssetTypeLabel,
					Result->Issue,
					Result->TechnicalDetails,
					Result->SuggestedName
			};
			const FString Searchable = FString::Join(SearchFields, TEXT(" "));
			if (!Searchable.Contains(SearchText, ESearchCase::IgnoreCase))
			{
				continue;
			}
		}

		VisibleResults.Add(Result);
	}

	if (ResultListView.IsValid())
	{
		ResultListView->RequestListRefresh();
	}
}

void SPlutoAssetNamingHelperPanel::FocusAsset(const TSharedPtr<FPlutoAssetNamingAuditResult>& Item) const
{
	if (!Item.IsValid())
	{
		return;
	}

	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	ContentBrowserModule.Get().SyncBrowserToAssets({ Item->AssetData });
}

void SPlutoAssetNamingHelperPanel::ShowTransientMessage(const FText& Message, bool bSuccess) const
{
	FNotificationInfo Info(Message);
	Info.ExpireDuration = 4.0f;
	Info.bUseLargeFont = false;
	Info.Image = FAppStyle::GetBrush(bSuccess ? "Icons.SuccessWithColor" : "Icons.WarningWithColor");
	FSlateNotificationManager::Get().AddNotification(Info);
}

int32 SPlutoAssetNamingHelperPanel::GetStatusCount(EPlutoAssetNamingStatus Status) const
{
	int32 Count = 0;
	for (const FAuditResultPtr& Result : AllResults)
	{
		if (Result->Status == Status)
		{
			++Count;
		}
	}
	return Count;
}

bool SPlutoAssetNamingHelperPanel::IsStatusEnabled(EPlutoAssetNamingStatus Status) const
{
	if (const bool* bEnabled = EnabledStatuses.Find(Status))
	{
		return *bEnabled;
	}
	return true;
}

void SPlutoAssetNamingHelperPanel::SetStatusEnabled(EPlutoAssetNamingStatus Status, bool bEnabled)
{
	EnabledStatuses.FindOrAdd(Status) = bEnabled;
}

#undef LOCTEXT_NAMESPACE
