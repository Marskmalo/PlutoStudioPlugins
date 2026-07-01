#include "SPlutoGameplayTagInspectorPanel.h"

#include "AssetRegistry/AssetData.h"
#include "Containers/Ticker.h"
#include "Editor.h"
#include "Engine/Selection.h"
#include "GameFramework/Actor.h"
#include "GameplayTagAssetInterface.h"
#include "PlutoGameplayTagInspectorEditorModule.h"
#include "PlutoGameplayTagInspectorEditorSettings.h"
#include "PlutoGameplayTagInspectorRuntimeUtils.h"
#include "PropertyCustomizationHelpers.h"
#include "Styling/AppStyle.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SSearchBox.h"
#include "Widgets/Input/SSlider.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SSeparator.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Views/SExpanderArrow.h"
#include "Widgets/Views/SHeaderRow.h"
#include "Widgets/Views/STableRow.h"
#include "Widgets/Views/STreeView.h"

namespace PlutoGameplayTagInspectorPanelText
{
	const FName TreeColumnId(TEXT("Tree"));
	const FName SourceColumnId(TEXT("Source"));

	FText Localized(const TCHAR* ChineseText, const TCHAR* EnglishText)
	{
		return PlutoGameplayTagInspectorEditor::MakeLocalizedText(ChineseText, EnglishText);
	}
}

class SPlutoGameplayTagInspectorTableRow : public SMultiColumnTableRow<TSharedPtr<FPlutoGameplayTagInspectorTreeNode>>
{
public:
	SLATE_BEGIN_ARGS(SPlutoGameplayTagInspectorTableRow)
	{
	}
		SLATE_ARGUMENT(TSharedPtr<FPlutoGameplayTagInspectorTreeNode>, Item)
		SLATE_ARGUMENT(const SPlutoGameplayTagInspectorPanel*, OwnerPanel)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& OwnerTableView)
	{
		Item = InArgs._Item;
		OwnerPanel = InArgs._OwnerPanel;

		SMultiColumnTableRow<TSharedPtr<FPlutoGameplayTagInspectorTreeNode>>::Construct(
			FSuperRowType::FArguments().Padding(FMargin(2.0f, 1.0f)),
			OwnerTableView);
	}

	virtual TSharedRef<SWidget> GenerateWidgetForColumn(const FName& ColumnName) override
	{
		if (OwnerPanel == nullptr || !Item.IsValid())
		{
			return SNew(STextBlock).Text(FText::GetEmpty());
		}

		if (ColumnName == PlutoGameplayTagInspectorPanelText::TreeColumnId)
		{
			return SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				[
					SNew(SExpanderArrow, SharedThis(this))
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				[
					OwnerPanel->BuildTreeColumnWidget(Item)
				];
		}

		if (ColumnName == PlutoGameplayTagInspectorPanelText::SourceColumnId)
		{
			return OwnerPanel->BuildSourceColumnWidget(Item);
		}

		return SNew(STextBlock).Text(FText::GetEmpty());
	}

private:
	const SPlutoGameplayTagInspectorPanel* OwnerPanel = nullptr;
	TSharedPtr<FPlutoGameplayTagInspectorTreeNode> Item;
};

namespace
{
	constexpr int32 MinColorDepthLevel = 1;
	constexpr int32 MaxColorDepthLevel = 8;

	constexpr int32 ComplementaryHueOffsets[] =
	{
		0,
		180,
		60,
		240,
		120,
		300,
		30,
		210,
		90,
		270,
		150,
		330
	};

	FText MakePanelText(const TCHAR* ChineseText, const TCHAR* EnglishText)
	{
		return PlutoGameplayTagInspectorPanelText::Localized(ChineseText, EnglishText);
	}
}

void SPlutoGameplayTagInspectorPanel::Construct(const FArguments& InArgs)
{
	SelectionChangedHandle = USelection::SelectionChangedEvent.AddSP(this, &SPlutoGameplayTagInspectorPanel::HandleEditorSelectionChanged);
	ProjectTickHandle = FTSTicker::GetCoreTicker().AddTicker(
		FTickerDelegate::CreateSP(this, &SPlutoGameplayTagInspectorPanel::HandleProjectTick),
		0.0f);

	ChildSlot
	[
		SNew(SBorder)
		.Padding(10.0f)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 0.0f, 0.0f, 8.0f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text_Lambda([]()
					{
						return MakePanelText(TEXT("Pluto GameplayTag 检查器"), TEXT("Pluto GameplayTag Inspector"));
					})
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.Padding(0.0f, 0.0f, 8.0f, 0.0f)
				[
					SNew(SButton)
					.Text(this, &SPlutoGameplayTagInspectorPanel::BuildLanguageButtonText)
					.ToolTipText_Lambda([]()
					{
						return MakePanelText(TEXT("切换中英文界面。"), TEXT("Toggle the UI language between Chinese and English."));
					})
					.OnClicked(this, &SPlutoGameplayTagInspectorPanel::HandleLanguageClicked)
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				[
					SNew(SButton)
					.ButtonStyle(FAppStyle::Get(), "SimpleButton")
					.ContentPadding(FMargin(4.0f, 2.0f))
					.ToolTipText_Lambda([]()
					{
						return MakePanelText(
							TEXT("打开插件使用文档窗口。文档内容来自插件目录下的 Markdown 文件。"),
							TEXT("Open the plugin documentation window. The content is loaded from Markdown files in the plugin folder."));
					})
					.OnClicked(this, &SPlutoGameplayTagInspectorPanel::HandleDocumentationClicked)
					[
						SNew(SImage)
						.Image(FAppStyle::GetBrush("Icons.Documentation"))
					]
				]
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 0.0f, 0.0f, 6.0f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.Padding(0.0f, 0.0f, 8.0f, 0.0f)
				[
					SNew(SObjectPropertyEntryBox)
					.AllowedClass(AActor::StaticClass())
					.ObjectPath(this, &SPlutoGameplayTagInspectorPanel::GetObservedActorObjectPath)
					.OnObjectChanged(this, &SPlutoGameplayTagInspectorPanel::HandleObservedActorChanged)
					.OnShouldFilterActor(this, &SPlutoGameplayTagInspectorPanel::IsObservedActorAllowed)
					.DisplayBrowse(true)
					.OnBrowseOverride(FSimpleDelegate::CreateSP(this, &SPlutoGameplayTagInspectorPanel::HandleFocusClicked))
					.AllowClear(true)
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(0.0f, 0.0f, 8.0f, 0.0f)
				[
					SNew(SButton)
					.Text(this, &SPlutoGameplayTagInspectorPanel::BuildLockButtonText)
					.ToolTipText_Lambda([]()
					{
						return MakePanelText(
							TEXT("锁定或解锁当前观察目标。解锁后会跟随编辑器选中对象变化。"),
							TEXT("Lock or unlock the current observed target. When unlocked, the panel follows editor selection."));
					})
					.IsEnabled(this, &SPlutoGameplayTagInspectorPanel::CanLockTarget)
					.OnClicked(this, &SPlutoGameplayTagInspectorPanel::HandleLockClicked)
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(0.0f, 0.0f, 8.0f, 0.0f)
				[
					SNew(SButton)
					.Text_Lambda([]()
					{
						return MakePanelText(TEXT("刷新"), TEXT("Refresh"));
					})
					.ToolTipText_Lambda([]()
					{
						return MakePanelText(
							TEXT("立即重新读取观察目标上的 GameplayTag 数据。"),
							TEXT("Immediately refresh gameplay tag data from the observed target."));
					})
					.OnClicked(this, &SPlutoGameplayTagInspectorPanel::HandleRefreshClicked)
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				[
					SNew(SCheckBox)
					.IsChecked(this, &SPlutoGameplayTagInspectorPanel::GetAutoRefreshCheckState)
					.OnCheckStateChanged(this, &SPlutoGameplayTagInspectorPanel::HandleAutoRefreshChanged)
					.ToolTipText_Lambda([]()
					{
						return MakePanelText(
							TEXT("在编辑器主 Tick 中自动刷新当前观察对象。"),
							TEXT("Refresh the current observed object on the editor main tick."));
					})
					[
						SNew(STextBlock)
						.Text(this, &SPlutoGameplayTagInspectorPanel::BuildAutoRefreshText)
					]
				]
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 0.0f, 0.0f, 6.0f)
			[
				SAssignNew(SearchBoxWidget, SSearchBox)
				.HintText(this, &SPlutoGameplayTagInspectorPanel::BuildSearchHintText)
				.OnTextChanged(this, &SPlutoGameplayTagInspectorPanel::HandleSearchTextChanged)
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 0.0f, 0.0f, 6.0f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SNullWidget::NullWidget
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				[
					SNew(SHorizontalBox)
					.ToolTipText(this, &SPlutoGameplayTagInspectorPanel::BuildColorDepthTooltipText)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					.Padding(0.0f, 0.0f, 8.0f, 0.0f)
					[
						SNew(STextBlock)
						.Text(this, &SPlutoGameplayTagInspectorPanel::BuildColorDepthLabelText)
					]
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					.Padding(0.0f, 0.0f, 8.0f, 0.0f)
					[
						SNew(SBox)
						.WidthOverride(150.0f)
						[
							SNew(SSlider)
							.Value(this, &SPlutoGameplayTagInspectorPanel::GetColorDepthSliderValue)
							.StepSize(1.0f / static_cast<float>(MaxColorDepthLevel - MinColorDepthLevel))
							.OnValueChanged(this, &SPlutoGameplayTagInspectorPanel::HandleColorDepthChanged)
						]
					]
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text(this, &SPlutoGameplayTagInspectorPanel::BuildColorDepthValueText)
						.ColorAndOpacity(this, &SPlutoGameplayTagInspectorPanel::GetObservationHighlightColor)
					]
				]
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 0.0f, 0.0f, 6.0f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(0.0f, 0.0f, 6.0f, 0.0f)
				[
					SNew(STextBlock)
					.Text_Lambda([]()
					{
						return MakePanelText(TEXT("观察目标："), TEXT("Observed Actor:"));
					})
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SNew(STextBlock)
					.Text(this, &SPlutoGameplayTagInspectorPanel::BuildObservedActorText)
					.ColorAndOpacity(this, &SPlutoGameplayTagInspectorPanel::GetObservedActorTextColor)
				]
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 0.0f, 0.0f, 6.0f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(0.0f, 0.0f, 6.0f, 0.0f)
				[
					SNew(STextBlock)
					.Text_Lambda([]()
					{
						return MakePanelText(TEXT("目标类型："), TEXT("Observed Class:"));
					})
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SNew(STextBlock)
					.Text(this, &SPlutoGameplayTagInspectorPanel::BuildObservedClassText)
					.ColorAndOpacity(this, &SPlutoGameplayTagInspectorPanel::GetObservedClassTextColor)
				]
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 0.0f, 0.0f, 4.0f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(0.0f, 0.0f, 6.0f, 0.0f)
				[
					SNew(STextBlock)
					.Text(this, &SPlutoGameplayTagInspectorPanel::BuildStatusPrefixText)
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SNew(STextBlock)
					.Text(this, &SPlutoGameplayTagInspectorPanel::BuildStatusText)
					.ColorAndOpacity(this, &SPlutoGameplayTagInspectorPanel::GetStatusTextColor)
					.AutoWrapText(true)
				]
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 0.0f, 0.0f, 8.0f)
			[
				SNew(STextBlock)
				.Text(this, &SPlutoGameplayTagInspectorPanel::BuildSummaryText)
			]
			+ SVerticalBox::Slot()
			.FillHeight(1.0f)
			[
				SAssignNew(TreeViewWidget, STreeView<FTreeNodePtr>)
				.TreeItemsSource(&RootNodes)
				.HeaderRow(
					SAssignNew(TreeHeaderRowWidget, SHeaderRow)
					+ SHeaderRow::Column(PlutoGameplayTagInspectorPanelText::TreeColumnId)
					.FillWidth(0.58f)
					[
						SNew(STextBlock)
						.Text(this, &SPlutoGameplayTagInspectorPanel::BuildTreeHeaderText)
					]
					+ SHeaderRow::Column(PlutoGameplayTagInspectorPanelText::SourceColumnId)
					.FillWidth(0.42f)
					[
						SNew(STextBlock)
						.Text(this, &SPlutoGameplayTagInspectorPanel::BuildSourceHeaderText)
					])
				.OnGenerateRow(this, &SPlutoGameplayTagInspectorPanel::HandleGenerateRow)
				.OnGetChildren(this, &SPlutoGameplayTagInspectorPanel::HandleGetChildren)
				.SelectionMode(ESelectionMode::Single)
			]
		]
	];

	RefreshObservedData(true);
}

SPlutoGameplayTagInspectorPanel::~SPlutoGameplayTagInspectorPanel()
{
	if (SelectionChangedHandle.IsValid())
	{
		USelection::SelectionChangedEvent.Remove(SelectionChangedHandle);
	}

	if (ProjectTickHandle.IsValid())
	{
		FTSTicker::GetCoreTicker().RemoveTicker(ProjectTickHandle);
		ProjectTickHandle.Reset();
	}
}

bool SPlutoGameplayTagInspectorPanel::HandleProjectTick(float InDeltaTime)
{
	if (bAutoRefresh)
	{
		RefreshObservedData(false);
	}

	return true;
}

void SPlutoGameplayTagInspectorPanel::HandleEditorSelectionChanged(UObject* NewSelection)
{
	if (!bLockObservedActor)
	{
		RefreshObservedData(true);
	}
}

void SPlutoGameplayTagInspectorPanel::RefreshObservedData(bool bForceStatusText)
{
	AActor* TargetActor = ResolveObservedActor().Get();
	if (TargetActor == nullptr)
	{
		const bool bObservedActorChanged = LastObservedActor.IsValid();
		const bool bObservedDataChanged = bHasObservedDataRevision;
		ClearObservedData();
		LastObservedActor.Reset();
		LastObservedDataRevision = 0;
		bHasObservedDataRevision = false;
		StatusText = MakePanelText(
			TEXT("当前没有可观察的 Actor。请选择一个 Actor，或在上方 Actor 选择框中使用小吸管选择目标。"),
			TEXT("No valid actor is being observed. Select an actor, or use the actor picker above to choose one."));
		StatusSeverity = bLockObservedActor ? EPlutoGameplayTagInspectorStatusSeverity::Error : EPlutoGameplayTagInspectorStatusSeverity::Warning;
		SummaryText = MakePanelText(TEXT("没有可显示的数据。"), TEXT("No data to display."));

		if (bForceStatusText || bObservedActorChanged || bObservedDataChanged)
		{
			RebuildTreeNodes();
		}

		return;
	}

	FPlutoGameplayTagInspectorRuntimeUtils::CollectInspectableGameplayTagContainers(TargetActor, ObservedContainers);
	FPlutoGameplayTagInspectorRuntimeUtils::CollectInspectableIsolatedGameplayTags(TargetActor, ObservedIsolatedTags);
	ObservedOwnedTags.Reset();

	if (const IGameplayTagAssetInterface* GameplayTagAsset = Cast<IGameplayTagAssetInterface>(TargetActor))
	{
		GameplayTagAsset->GetOwnedGameplayTags(ObservedOwnedTags);
	}

	const uint32 NewObservedDataRevision = BuildObservedDataRevision(TargetActor);
	const bool bObservedActorChanged = LastObservedActor.Get() != TargetActor;
	const bool bObservedDataChanged = !bHasObservedDataRevision || LastObservedDataRevision != NewObservedDataRevision;
	LastObservedActor = TargetActor;
	LastObservedDataRevision = NewObservedDataRevision;
	bHasObservedDataRevision = true;

	if (ObservedContainers.Num() == 0 && ObservedIsolatedTags.Num() == 0 && ObservedOwnedTags.IsEmpty())
	{
		StatusText = MakePanelText(
			TEXT("目标对象存在，但没有可读的 GameplayTag 数据。"),
			TEXT("The target actor is valid, but no readable gameplay tag data was found."));
		StatusSeverity = EPlutoGameplayTagInspectorStatusSeverity::Warning;
	}
	else
	{
		StatusText = FText::FromString(TargetActor->GetName());
		StatusSeverity = EPlutoGameplayTagInspectorStatusSeverity::Success;
	}

	SummaryText = MakePanelText(
		*FString::Printf(TEXT("容器 %d 个，可见 Tag %d 个。"), ObservedContainers.Num(), CountVisibleTags()),
		*FString::Printf(TEXT("%d containers, %d isolated tags, %d visible tags."), ObservedContainers.Num(), ObservedIsolatedTags.Num(), CountVisibleTags()));

	if (bForceStatusText || bObservedActorChanged || bObservedDataChanged)
	{
		RebuildTreeNodes();
	}
}

uint32 SPlutoGameplayTagInspectorPanel::BuildObservedDataRevision(const AActor* TargetActor) const
{
	uint32 Revision = TargetActor != nullptr ? GetTypeHash(TargetActor->GetPathName()) : 0u;

	for (const FPlutoGameplayTagContainerDescriptor& Container : ObservedContainers)
	{
		Revision = HashCombineFast(Revision, GetTypeHash(Container.ContainerName));
		Revision = HashCombineFast(Revision, GetTypeHash(Container.ContainerPath));

		for (const FGameplayTag& GameplayTag : Container.GameplayTags)
		{
			Revision = HashCombineFast(Revision, GetTypeHash(GameplayTag.GetTagName()));
		}
	}

	for (const FPlutoGameplayTagDescriptor& IsolatedTag : ObservedIsolatedTags)
	{
		Revision = HashCombineFast(Revision, GetTypeHash(IsolatedTag.TagPath));
		Revision = HashCombineFast(Revision, GetTypeHash(IsolatedTag.GameplayTag.GetTagName()));
	}

	for (const FGameplayTag& GameplayTag : ObservedOwnedTags)
	{
		Revision = HashCombineFast(Revision, GetTypeHash(GameplayTag.GetTagName()));
	}

	return Revision;
}

void SPlutoGameplayTagInspectorPanel::RebuildTreeNodes()
{
	RootNodes.Reset();

	const FString SearchLower = SearchText.ToLower();

	for (const FPlutoGameplayTagContainerDescriptor& Container : ObservedContainers)
	{
		const FString ContainerPath = !Container.ContainerPath.IsEmpty()
			? Container.ContainerPath
			: Container.ContainerName.ToString();
		const bool bContainerMatches = SearchLower.IsEmpty() || ContainerPath.ToLower().Contains(SearchLower);

		FTreeNodePtr ContainerNode = MakeShared<FPlutoGameplayTagInspectorTreeNode>();
		ContainerNode->NodeType = EPlutoGameplayTagInspectorNodeType::Container;
		ContainerNode->Label = FText::FromString(GetContainerDisplayName(Container));
		ContainerNode->SecondaryLabel = FText::FromString(GetContainerSourceName(Container));
		ContainerNode->Tooltip = MakeContainerTooltip(Container);
		ContainerNode->Color = FLinearColor(0.90f, 0.92f, 0.98f);
		ContainerNode->SecondaryColor = FLinearColor(0.52f, 0.58f, 0.66f);

		for (const FGameplayTag& GameplayTag : Container.GameplayTags)
		{
			const FString TagName = GameplayTag.ToString();
			if (!SearchLower.IsEmpty() && !bContainerMatches && !TagName.ToLower().Contains(SearchLower))
			{
				continue;
			}

			FTreeNodePtr TagNode = MakeShared<FPlutoGameplayTagInspectorTreeNode>();
			TagNode->NodeType = EPlutoGameplayTagInspectorNodeType::Tag;
			TagNode->Label = FText::FromString(TagName);
			BuildTagLayerLabels(TagName, TagNode->DimmedPrefixLabel, TagNode->FocusLabel);
			TagNode->SecondaryLabel = FText::GetEmpty();
			TagNode->Tooltip = FText::FromString(TagName);
			TagNode->Color = GetTagColor(GameplayTag);
			TagNode->DimmedColor = GetDimmedTagPrefixColor();
			ContainerNode->Children.Add(TagNode);
		}

		if (bContainerMatches || ContainerNode->Children.Num() > 0)
		{
			RootNodes.Add(ContainerNode);
		}
	}

	RootNodes.Sort([](const FTreeNodePtr& A, const FTreeNodePtr& B)
	{
		return A->Label.ToString() < B->Label.ToString();
	});

	if (ObservedIsolatedTags.Num() > 0)
	{
		const FString IsolatedRootName = TEXT("孤立Tag");
		const bool bRootMatches = SearchLower.IsEmpty() || IsolatedRootName.ToLower().Contains(SearchLower) || FString(TEXT("Isolated Tags")).ToLower().Contains(SearchLower);

		FTreeNodePtr IsolatedRootNode = MakeShared<FPlutoGameplayTagInspectorTreeNode>();
		IsolatedRootNode->NodeType = EPlutoGameplayTagInspectorNodeType::Container;
		IsolatedRootNode->Label = MakePanelText(TEXT("孤立Tag"), TEXT("Isolated Tags"));
		IsolatedRootNode->SecondaryLabel = FText::FromString(GetObservedSourceName());
		IsolatedRootNode->Tooltip = MakePanelText(
			TEXT("未由 GameplayTagContainer 承载的真实 GameplayTag。"),
			TEXT("Real gameplay tags that are not stored in a GameplayTagContainer."));
		IsolatedRootNode->Color = FLinearColor(0.86f, 0.78f, 0.45f);
		IsolatedRootNode->SecondaryColor = FLinearColor(0.52f, 0.58f, 0.66f);

		for (const FPlutoGameplayTagDescriptor& IsolatedTag : ObservedIsolatedTags)
		{
			const FString TagName = IsolatedTag.GameplayTag.ToString();
			const bool bTagMatches = SearchLower.IsEmpty()
				|| bRootMatches
				|| TagName.ToLower().Contains(SearchLower)
				|| IsolatedTag.TagPath.ToLower().Contains(SearchLower);
			if (!bTagMatches)
			{
				continue;
			}

			FTreeNodePtr TagNode = MakeShared<FPlutoGameplayTagInspectorTreeNode>();
			TagNode->NodeType = EPlutoGameplayTagInspectorNodeType::Tag;
			TagNode->Label = FText::FromString(TagName);
			BuildTagLayerLabels(TagName, TagNode->DimmedPrefixLabel, TagNode->FocusLabel);
			TagNode->SecondaryLabel = FText::FromString(IsolatedTag.TagPath);
			TagNode->Tooltip = MakeIsolatedTagTooltip(IsolatedTag);
			TagNode->Color = GetTagColor(IsolatedTag.GameplayTag);
			TagNode->DimmedColor = GetDimmedTagPrefixColor();
			TagNode->SecondaryColor = FLinearColor(0.52f, 0.58f, 0.66f);
			IsolatedRootNode->Children.Add(TagNode);
		}

		IsolatedRootNode->Children.Sort([](const FTreeNodePtr& A, const FTreeNodePtr& B)
		{
			return A->Label.ToString() < B->Label.ToString();
		});

		if (bRootMatches || IsolatedRootNode->Children.Num() > 0)
		{
			RootNodes.Add(IsolatedRootNode);
		}
	}

	if (TreeViewWidget.IsValid())
	{
		TreeViewWidget->RequestTreeRefresh();
		for (const FTreeNodePtr& RootNode : RootNodes)
		{
			TreeViewWidget->SetItemExpansion(RootNode, true);
		}
	}
}

void SPlutoGameplayTagInspectorPanel::SetLockedTarget(AActor* InActor)
{
	LockedActor = InActor;
	bLockObservedActor = InActor != nullptr;
	RefreshObservedData(true);
}

void SPlutoGameplayTagInspectorPanel::ClearObservedData()
{
	ObservedContainers.Reset();
	ObservedIsolatedTags.Reset();
	ObservedOwnedTags.Reset();
}

TWeakObjectPtr<AActor> SPlutoGameplayTagInspectorPanel::ResolveObservedActor() const
{
	if (bLockObservedActor && LockedActor.IsValid())
	{
		return LockedActor;
	}

	return GetFirstSelectedActor();
}

TWeakObjectPtr<AActor> SPlutoGameplayTagInspectorPanel::GetFirstSelectedActor() const
{
	if (GEditor == nullptr)
	{
		return nullptr;
	}

	USelection* SelectedActors = GEditor->GetSelectedActors();
	if (SelectedActors == nullptr)
	{
		return nullptr;
	}

	return Cast<AActor>(SelectedActors->GetTop(AActor::StaticClass()));
}

FText SPlutoGameplayTagInspectorPanel::MakeContainerTooltip(const FPlutoGameplayTagContainerDescriptor& Container) const
{
	const FString ContainerPath = !Container.ContainerPath.IsEmpty()
		? Container.ContainerPath
		: Container.ContainerName.ToString();

	return MakePanelText(
		*FString::Printf(TEXT("容器路径：%s"), *ContainerPath),
		*FString::Printf(TEXT("Container path: %s"), *ContainerPath));
}

FText SPlutoGameplayTagInspectorPanel::MakeIsolatedTagTooltip(const FPlutoGameplayTagDescriptor& IsolatedTag) const
{
	return MakePanelText(
		*FString::Printf(TEXT("孤立 Tag：%s\n来源：%s"), *IsolatedTag.GameplayTag.ToString(), *IsolatedTag.TagPath),
		*FString::Printf(TEXT("Isolated tag: %s\nSource: %s"), *IsolatedTag.GameplayTag.ToString(), *IsolatedTag.TagPath));
}

FText SPlutoGameplayTagInspectorPanel::BuildStatusText() const
{
	return StatusText;
}

FText SPlutoGameplayTagInspectorPanel::BuildStatusPrefixText() const
{
	if (StatusSeverity == EPlutoGameplayTagInspectorStatusSeverity::Success)
	{
		return MakePanelText(TEXT("正在观察："), TEXT("Observing:"));
	}

	return FText::GetEmpty();
}

FText SPlutoGameplayTagInspectorPanel::BuildSummaryText() const
{
	return SummaryText;
}

FText SPlutoGameplayTagInspectorPanel::BuildObservedActorText() const
{
	const AActor* TargetActor = ResolveObservedActor().Get();
	return FText::FromString(TargetActor != nullptr ? TargetActor->GetName() : TEXT("None"));
}

FText SPlutoGameplayTagInspectorPanel::BuildObservedClassText() const
{
	const AActor* TargetActor = ResolveObservedActor().Get();
	return FText::FromString(TargetActor != nullptr ? TargetActor->GetClass()->GetName() : TEXT("None"));
}

FText SPlutoGameplayTagInspectorPanel::BuildTreeHeaderText() const
{
	return MakePanelText(TEXT("树状图"), TEXT("Tree"));
}

FText SPlutoGameplayTagInspectorPanel::BuildSourceHeaderText() const
{
	return MakePanelText(TEXT("来源"), TEXT("Source"));
}

FSlateColor SPlutoGameplayTagInspectorPanel::GetObservedActorTextColor() const
{
	return GetObservationHighlightColor();
}

FSlateColor SPlutoGameplayTagInspectorPanel::GetObservedClassTextColor() const
{
	return GetObservationHighlightColor();
}

FText SPlutoGameplayTagInspectorPanel::BuildLockButtonText() const
{
	return MakePanelText(
		bLockObservedActor ? TEXT("解锁") : TEXT("锁定"),
		bLockObservedActor ? TEXT("Unlock") : TEXT("Lock"));
}

FText SPlutoGameplayTagInspectorPanel::BuildLanguageButtonText() const
{
	return MakePanelText(TEXT("切换到 English"), TEXT("Switch to 中文"));
}

FText SPlutoGameplayTagInspectorPanel::BuildAutoRefreshText() const
{
	return MakePanelText(TEXT("自动刷新"), TEXT("Auto Refresh"));
}

FText SPlutoGameplayTagInspectorPanel::BuildSearchHintText() const
{
	return MakePanelText(TEXT("搜索容器名或 Tag"), TEXT("Search container names or tags"));
}

FText SPlutoGameplayTagInspectorPanel::BuildColorDepthLabelText() const
{
	return MakePanelText(TEXT("\u5206\u8272\u5c42\u7ea7"), TEXT("Color Level"));
}

FText SPlutoGameplayTagInspectorPanel::BuildColorDepthValueText() const
{
	return FText::AsNumber(ColorDepthLevel);
}

FText SPlutoGameplayTagInspectorPanel::BuildColorDepthTooltipText() const
{
	return MakePanelText(
		TEXT("\u6309 Tag \u524d N \u6bb5\u8ba1\u7b97\u989c\u8272\uff0c\u5e76\u5c06\u5f53\u524d\u5206\u8272\u5c42\u7ea7\u4e4b\u524d\u7684\u524d\u7f00\u53d8\u6697\u3002"),
		TEXT("Calculate tag colors from the first N tag segments and dim the prefix before the active color level."));
}

FSlateColor SPlutoGameplayTagInspectorPanel::GetStatusTextColor() const
{
	switch (StatusSeverity)
	{
	case EPlutoGameplayTagInspectorStatusSeverity::Success:
		return FLinearColor(0.32f, 0.88f, 0.48f);

	case EPlutoGameplayTagInspectorStatusSeverity::Error:
		return FLinearColor(0.96f, 0.34f, 0.34f);

	case EPlutoGameplayTagInspectorStatusSeverity::Warning:
	default:
		return FLinearColor(0.96f, 0.78f, 0.25f);
	}
}

ECheckBoxState SPlutoGameplayTagInspectorPanel::GetAutoRefreshCheckState() const
{
	return bAutoRefresh ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

float SPlutoGameplayTagInspectorPanel::GetColorDepthSliderValue() const
{
	return static_cast<float>(ColorDepthLevel - MinColorDepthLevel) /
		static_cast<float>(MaxColorDepthLevel - MinColorDepthLevel);
}

void SPlutoGameplayTagInspectorPanel::HandleSearchTextChanged(const FText& NewText)
{
	SearchText = NewText.ToString();
	RebuildTreeNodes();
}

void SPlutoGameplayTagInspectorPanel::HandleAutoRefreshChanged(ECheckBoxState NewState)
{
	bAutoRefresh = (NewState == ECheckBoxState::Checked);
}

void SPlutoGameplayTagInspectorPanel::HandleColorDepthChanged(float NewValue)
{
	const int32 NewColorDepthLevel = FMath::Clamp(
		FMath::RoundToInt(NewValue * static_cast<float>(MaxColorDepthLevel - MinColorDepthLevel)) + MinColorDepthLevel,
		MinColorDepthLevel,
		MaxColorDepthLevel);

	if (ColorDepthLevel != NewColorDepthLevel)
	{
		ColorDepthLevel = NewColorDepthLevel;
		RebuildTreeNodes();
	}
}

FReply SPlutoGameplayTagInspectorPanel::HandleRefreshClicked()
{
	RefreshObservedData(true);
	return FReply::Handled();
}

FReply SPlutoGameplayTagInspectorPanel::HandleLockClicked()
{
	if (bLockObservedActor)
	{
		bLockObservedActor = false;
		LockedActor.Reset();
	}
	else if (AActor* TargetActor = ResolveObservedActor().Get())
	{
		SetLockedTarget(TargetActor);
	}

	RefreshObservedData(true);
	return FReply::Handled();
}

void SPlutoGameplayTagInspectorPanel::HandleFocusClicked()
{
	if (GEditor == nullptr)
	{
		return;
	}

	if (AActor* TargetActor = ResolveObservedActor().Get())
	{
		GEditor->SelectNone(false, true);
		GEditor->SelectActor(TargetActor, true, true, true);
		GEditor->MoveViewportCamerasToActor(*TargetActor, false);
	}
}

FString SPlutoGameplayTagInspectorPanel::GetObservedActorObjectPath() const
{
	if (const AActor* TargetActor = ResolveObservedActor().Get())
	{
		return TargetActor->GetPathName();
	}

	return FString();
}

void SPlutoGameplayTagInspectorPanel::HandleObservedActorChanged(const FAssetData& AssetData)
{
	if (AActor* PickedActor = Cast<AActor>(AssetData.GetAsset()))
	{
		SetLockedTarget(PickedActor);
	}
	else
	{
		bLockObservedActor = false;
		LockedActor.Reset();
		RefreshObservedData(true);
	}
}

bool SPlutoGameplayTagInspectorPanel::IsObservedActorAllowed(const AActor* Actor) const
{
	return Actor != nullptr;
}

FReply SPlutoGameplayTagInspectorPanel::HandleLanguageClicked()
{
	const EPlutoGameplayTagInspectorLanguage NextLanguage =
		PlutoGameplayTagInspectorEditor::GetCurrentLanguage() == EPlutoGameplayTagInspectorLanguage::Chinese
			? EPlutoGameplayTagInspectorLanguage::English
			: EPlutoGameplayTagInspectorLanguage::Chinese;

	PlutoGameplayTagInspectorEditor::SetCurrentLanguage(NextLanguage);
	RefreshObservedData(true);

	if (TreeHeaderRowWidget.IsValid())
	{
		TreeHeaderRowWidget->Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
	}

	if (TreeViewWidget.IsValid())
	{
		TreeViewWidget->RequestTreeRefresh();
	}

	Invalidate(EInvalidateWidgetReason::LayoutAndVolatility);
	return FReply::Handled();
}

FReply SPlutoGameplayTagInspectorPanel::HandleDocumentationClicked()
{
	FModuleManager::LoadModuleChecked<FPlutoGameplayTagInspectorEditorModule>("PlutoGameplayTagInspectorEditor").OpenDocumentationTab();
	return FReply::Handled();
}

bool SPlutoGameplayTagInspectorPanel::CanLockTarget() const
{
	return HasObservedActor();
}

bool SPlutoGameplayTagInspectorPanel::HasObservedActor() const
{
	return ResolveObservedActor().IsValid();
}

TSharedRef<ITableRow> SPlutoGameplayTagInspectorPanel::HandleGenerateRow(
	FTreeNodePtr Item,
	const TSharedRef<STableViewBase>& OwnerTable) const
{
	return SNew(SPlutoGameplayTagInspectorTableRow, OwnerTable)
		.Item(Item)
		.OwnerPanel(this)
		.ToolTipText(Item->Tooltip);
}

TSharedRef<SWidget> SPlutoGameplayTagInspectorPanel::BuildTreeColumnWidget(FTreeNodePtr Item) const
{
	if (Item->NodeType == EPlutoGameplayTagInspectorNodeType::Tag)
	{
		return SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(Item->DimmedPrefixLabel)
				.ColorAndOpacity(Item->DimmedColor)
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(Item->FocusLabel)
				.ColorAndOpacity(Item->Color)
			];
	}

	return SNew(STextBlock)
		.Text(Item->Label)
		.ColorAndOpacity(Item->Color);
}

TSharedRef<SWidget> SPlutoGameplayTagInspectorPanel::BuildSourceColumnWidget(FTreeNodePtr Item) const
{
	return SNew(STextBlock)
		.Text(Item->SecondaryLabel)
		.ColorAndOpacity(Item->SecondaryColor)
		.ToolTipText(Item->Tooltip)
		.OverflowPolicy(ETextOverflowPolicy::Ellipsis);
}

void SPlutoGameplayTagInspectorPanel::HandleGetChildren(FTreeNodePtr Item, TArray<FTreeNodePtr>& OutChildren) const
{
	OutChildren.Append(Item->Children);
}

FSlateColor SPlutoGameplayTagInspectorPanel::GetTagColor(const FGameplayTag& GameplayTag) const
{
	const FString ColorKey = GetTagColorKey(GameplayTag);

	if (ColorKey.Equals(TEXT("State"), ESearchCase::IgnoreCase))
	{
		return FLinearColor(0.95f, 0.58f, 0.16f);
	}

	if (ColorKey.Equals(TEXT("Debug"), ESearchCase::IgnoreCase))
	{
		return FLinearColor(0.27f, 0.78f, 0.42f);
	}

	if (ColorKey.Equals(TEXT("Ability"), ESearchCase::IgnoreCase))
	{
		return FLinearColor(0.20f, 0.58f, 0.95f);
	}

	if (ColorKey.Equals(TEXT("Input"), ESearchCase::IgnoreCase))
	{
		return FLinearColor(0.92f, 0.34f, 0.38f);
	}

	if (ColorKey.Equals(TEXT("UI"), ESearchCase::IgnoreCase))
	{
		return FLinearColor(0.69f, 0.36f, 0.93f);
	}

	TArray<FString> ColorKeyParts;
	ColorKey.ParseIntoArray(ColorKeyParts, TEXT("."), true);

	FString ParentKey = ColorKey;
	FString LocalKey = ColorKey;
	if (ColorKeyParts.Num() > 1)
	{
		ParentKey = ColorKeyParts[0];
		for (int32 Index = 1; Index < ColorKeyParts.Num() - 1; ++Index)
		{
			ParentKey += TEXT(".");
			ParentKey += ColorKeyParts[Index];
		}

		LocalKey = ColorKeyParts.Last();
	}

	const uint32 ParentHash = GetTypeHash(ParentKey);
	const uint32 LocalHash = GetTypeHash(LocalKey);
	const int32 OffsetCount = UE_ARRAY_COUNT(ComplementaryHueOffsets);
	const int32 ComplementaryOffset = ComplementaryHueOffsets[LocalHash % OffsetCount];
	const int32 FineOffset = static_cast<int32>((LocalHash / OffsetCount) % 25u) - 12;
	const int32 HueDegrees = (static_cast<int32>(ParentHash % 360u) + ComplementaryOffset + FineOffset + 360) % 360;

	return FLinearColor::MakeFromHSV8(
		static_cast<uint8>(static_cast<float>(HueDegrees) / 360.0f * 255.0f),
		165,
		230);
}

FSlateColor SPlutoGameplayTagInspectorPanel::GetDimmedTagPrefixColor() const
{
	const float DimValue = FMath::Clamp(0.62f - (static_cast<float>(ColorDepthLevel - MinColorDepthLevel) * 0.055f), 0.30f, 0.62f);
	return FLinearColor(DimValue, DimValue, DimValue, 0.95f);
}

FSlateColor SPlutoGameplayTagInspectorPanel::GetObservationHighlightColor() const
{
	return FLinearColor(0.36f, 0.82f, 0.95f);
}

FString SPlutoGameplayTagInspectorPanel::GetContainerDisplayName(const FPlutoGameplayTagContainerDescriptor& Container) const
{
	const FString ContainerPath = !Container.ContainerPath.IsEmpty()
		? Container.ContainerPath
		: Container.ContainerName.ToString();

	if (ContainerPath.Equals(TEXT("OwnedGameplayTags_View"), ESearchCase::IgnoreCase))
	{
		return TEXT("OwnedGameplayTags");
	}

	FString LeftPart;
	FString RightPart;
	FString KeySuffix;
	FString PathBeforeKey = ContainerPath;
	const int32 KeyStartIndex = ContainerPath.Find(TEXT("[Key "), ESearchCase::IgnoreCase, ESearchDir::FromStart);
	if (KeyStartIndex != INDEX_NONE)
	{
		PathBeforeKey = ContainerPath.Left(KeyStartIndex);
		KeySuffix = ContainerPath.Mid(KeyStartIndex);
	}

	if (PathBeforeKey.Split(TEXT("."), &LeftPart, &RightPart, ESearchCase::IgnoreCase, ESearchDir::FromEnd))
	{
		return RightPart + KeySuffix;
	}

	return ContainerPath;
}

FString SPlutoGameplayTagInspectorPanel::GetContainerSourceName(const FPlutoGameplayTagContainerDescriptor& Container) const
{
	const FString ContainerPath = !Container.ContainerPath.IsEmpty()
		? Container.ContainerPath
		: Container.ContainerName.ToString();

	if (ContainerPath.StartsWith(TEXT("Components."), ESearchCase::IgnoreCase))
	{
		TArray<FString> Parts;
		ContainerPath.ParseIntoArray(Parts, TEXT("."));
		if (Parts.Num() >= 2)
		{
			return Parts[1];
		}
	}

	return GetObservedSourceName();
}

FString SPlutoGameplayTagInspectorPanel::GetObservedSourceName() const
{
	const AActor* TargetActor = ResolveObservedActor().Get();
	if (TargetActor == nullptr)
	{
		return TEXT("None");
	}

#if WITH_EDITOR
	return TargetActor->GetActorLabel();
#else
	return TargetActor->GetName();
#endif
}

FString SPlutoGameplayTagInspectorPanel::GetTagColorKey(const FGameplayTag& GameplayTag) const
{
	const FString TagName = GameplayTag.ToString();
	TArray<FString> TagParts;
	TagName.ParseIntoArray(TagParts, TEXT("."), true);

	if (TagParts.Num() == 0)
	{
		return TagName;
	}

	const int32 ClampedDepthLevel = FMath::Clamp(ColorDepthLevel, MinColorDepthLevel, MaxColorDepthLevel);
	const int32 SegmentCount = FMath::Min(ClampedDepthLevel, TagParts.Num());
	FString ColorKey = TagParts[0];

	for (int32 Index = 1; Index < SegmentCount; ++Index)
	{
		ColorKey += TEXT(".");
		ColorKey += TagParts[Index];
	}

	return ColorKey;
}

void SPlutoGameplayTagInspectorPanel::BuildTagLayerLabels(
	const FString& TagName,
	FText& OutDimmedPrefixLabel,
	FText& OutFocusLabel) const
{
	const int32 ClampedDepthLevel = FMath::Clamp(ColorDepthLevel, MinColorDepthLevel, MaxColorDepthLevel);
	if (ClampedDepthLevel <= MinColorDepthLevel)
	{
		OutDimmedPrefixLabel = FText::GetEmpty();
		OutFocusLabel = FText::FromString(TagName);
		return;
	}

	TArray<FString> TagParts;
	TagName.ParseIntoArray(TagParts, TEXT("."), true);

	if (TagParts.Num() == 0)
	{
		OutDimmedPrefixLabel = FText::GetEmpty();
		OutFocusLabel = FText::FromString(TagName);
		return;
	}

	if (TagParts.Num() < ClampedDepthLevel)
	{
		OutDimmedPrefixLabel = FText::FromString(TagName);
		OutFocusLabel = FText::GetEmpty();
		return;
	}

	FString DimmedPrefix = TagParts[0];
	for (int32 Index = 1; Index < ClampedDepthLevel - 1; ++Index)
	{
		DimmedPrefix += TEXT(".");
		DimmedPrefix += TagParts[Index];
	}
	DimmedPrefix += TEXT(".");

	FString FocusText = TagParts[ClampedDepthLevel - 1];
	for (int32 Index = ClampedDepthLevel; Index < TagParts.Num(); ++Index)
	{
		FocusText += TEXT(".");
		FocusText += TagParts[Index];
	}

	OutDimmedPrefixLabel = FText::FromString(DimmedPrefix);
	OutFocusLabel = FText::FromString(FocusText);
}

int32 SPlutoGameplayTagInspectorPanel::CountVisibleTags() const
{
	int32 TagCount = 0;
	for (const FPlutoGameplayTagContainerDescriptor& Container : ObservedContainers)
	{
		TagCount += Container.GameplayTags.Num();
	}

	TagCount += ObservedIsolatedTags.Num();

	return TagCount;
}
