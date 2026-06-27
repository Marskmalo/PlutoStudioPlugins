#pragma once

#include "CoreMinimal.h"
#include "Containers/Ticker.h"
#include "GameplayTagContainer.h"
#include "Input/Reply.h"
#include "PlutoGameplayTagContainerProvider.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Input/SCheckBox.h"

class AActor;
struct FAssetData;
class ITableRow;
class SHeaderRow;
class SSearchBox;
class STableViewBase;
class STreeViewBase;
class USelection;
class SPlutoGameplayTagInspectorTableRow;

enum class EPlutoGameplayTagInspectorNodeType : uint8
{
	Container,
	Tag
};

enum class EPlutoGameplayTagInspectorStatusSeverity : uint8
{
	Success,
	Warning,
	Error
};

struct FPlutoGameplayTagInspectorTreeNode
{
	EPlutoGameplayTagInspectorNodeType NodeType = EPlutoGameplayTagInspectorNodeType::Container;
	FText Label;
	FText DimmedPrefixLabel;
	FText FocusLabel;
	FText SecondaryLabel;
	FText Tooltip;
	FSlateColor Color = FSlateColor::UseForeground();
	FSlateColor DimmedColor = FSlateColor::UseSubduedForeground();
	FSlateColor SecondaryColor = FSlateColor::UseSubduedForeground();
	TArray<TSharedPtr<FPlutoGameplayTagInspectorTreeNode>> Children;
};

class SPlutoGameplayTagInspectorPanel : public SCompoundWidget
{
	friend class SPlutoGameplayTagInspectorTableRow;

public:
	SLATE_BEGIN_ARGS(SPlutoGameplayTagInspectorPanel)
	{
	}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	virtual ~SPlutoGameplayTagInspectorPanel() override;

private:
	using FTreeNodePtr = TSharedPtr<FPlutoGameplayTagInspectorTreeNode>;

	bool HandleProjectTick(float InDeltaTime);
	void HandleEditorSelectionChanged(UObject* NewSelection);
	void RefreshObservedData(bool bForceStatusText);
	uint32 BuildObservedDataRevision(const AActor* TargetActor) const;
	void RebuildTreeNodes();
	void SetLockedTarget(AActor* InActor);
	void ClearObservedData();
	TWeakObjectPtr<AActor> ResolveObservedActor() const;
	TWeakObjectPtr<AActor> GetFirstSelectedActor() const;
	FText MakeContainerTooltip(const FPlutoGameplayTagContainerDescriptor& Container) const;
	FText MakeIsolatedTagTooltip(const FPlutoGameplayTagDescriptor& IsolatedTag) const;
	FText BuildStatusText() const;
	FText BuildStatusPrefixText() const;
	FText BuildSummaryText() const;
	FText BuildObservedActorText() const;
	FText BuildObservedClassText() const;
	FText BuildTreeHeaderText() const;
	FText BuildSourceHeaderText() const;
	FText BuildLockButtonText() const;
	FText BuildLanguageButtonText() const;
	FText BuildAutoRefreshText() const;
	FText BuildSearchHintText() const;
	FText BuildColorDepthLabelText() const;
	FText BuildColorDepthValueText() const;
	FText BuildColorDepthTooltipText() const;
	FSlateColor GetObservedActorTextColor() const;
	FSlateColor GetObservedClassTextColor() const;
	FSlateColor GetStatusTextColor() const;
	ECheckBoxState GetAutoRefreshCheckState() const;
	float GetColorDepthSliderValue() const;
	void HandleSearchTextChanged(const FText& NewText);
	void HandleAutoRefreshChanged(ECheckBoxState NewState);
	void HandleColorDepthChanged(float NewValue);
	FReply HandleRefreshClicked();
	FReply HandleLockClicked();
	FReply HandleLanguageClicked();
	FReply HandleDocumentationClicked();
	TSharedRef<SWidget> BuildTreeColumnWidget(FTreeNodePtr Item) const;
	TSharedRef<SWidget> BuildSourceColumnWidget(FTreeNodePtr Item) const;
	FString GetObservedActorObjectPath() const;
	void HandleObservedActorChanged(const FAssetData& AssetData);
	bool IsObservedActorAllowed(const AActor* Actor) const;
	bool CanLockTarget() const;
	bool HasObservedActor() const;
	TSharedRef<ITableRow> HandleGenerateRow(FTreeNodePtr Item, const TSharedRef<STableViewBase>& OwnerTable) const;
	void HandleGetChildren(FTreeNodePtr Item, TArray<FTreeNodePtr>& OutChildren) const;
	FSlateColor GetTagColor(const FGameplayTag& GameplayTag) const;
	FSlateColor GetDimmedTagPrefixColor() const;
	FSlateColor GetObservationHighlightColor() const;
	FString GetContainerDisplayName(const FPlutoGameplayTagContainerDescriptor& Container) const;
	FString GetContainerSourceName(const FPlutoGameplayTagContainerDescriptor& Container) const;
	FString GetObservedSourceName() const;
	FString GetTagColorKey(const FGameplayTag& GameplayTag) const;
	void BuildTagLayerLabels(const FString& TagName, FText& OutDimmedPrefixLabel, FText& OutFocusLabel) const;
	int32 CountVisibleTags() const;

private:
	TSharedPtr<SSearchBox> SearchBoxWidget;
	TSharedPtr<SHeaderRow> TreeHeaderRowWidget;
	TSharedPtr<class STreeView<FTreeNodePtr>> TreeViewWidget;
	TArray<FTreeNodePtr> RootNodes;
	TArray<FPlutoGameplayTagContainerDescriptor> ObservedContainers;
	TArray<FPlutoGameplayTagDescriptor> ObservedIsolatedTags;
	FGameplayTagContainer ObservedOwnedTags;
	FText StatusText;
	FText SummaryText;
	EPlutoGameplayTagInspectorStatusSeverity StatusSeverity = EPlutoGameplayTagInspectorStatusSeverity::Warning;
	FDelegateHandle SelectionChangedHandle;
	FTSTicker::FDelegateHandle ProjectTickHandle;
	TWeakObjectPtr<AActor> LockedActor;
	bool bLockObservedActor = false;
	bool bAutoRefresh = true;
	int32 ColorDepthLevel = 1;
	FString SearchText;
	TWeakObjectPtr<AActor> LastObservedActor;
	uint32 LastObservedDataRevision = 0;
	bool bHasObservedDataRevision = false;
};
