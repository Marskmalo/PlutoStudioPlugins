#pragma once

#include "CoreMinimal.h"
#include "PlutoAssetNamingRules.h"
#include "Widgets/SCompoundWidget.h"

class SSearchBox;
class STableViewBase;
template<typename ItemType> class SListView;

struct FPlutoAssetRenamePreviewItem
{
	TSharedPtr<FPlutoAssetNamingAuditResult> AuditResult;
	TArray<FName> Referencers;
	TArray<FName> Dependencies;
	bool bIncluded = true;

	FText GetRiskText() const;
	FLinearColor GetRiskColor() const;
	bool NeedsAttention() const;
};

class SPlutoAssetRenamePreview : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPlutoAssetRenamePreview) {}
		SLATE_ARGUMENT(TArray<TSharedPtr<FPlutoAssetNamingAuditResult>>, Items)
		SLATE_EVENT(FSimpleDelegate, OnRenameCompleted)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	using FPreviewItemPtr = TSharedPtr<FPlutoAssetRenamePreviewItem>;

	TSharedRef<ITableRow> GenerateRow(FPreviewItemPtr Item, const TSharedRef<STableViewBase>& OwnerTable);
	void HandleSelectionChanged(FPreviewItemPtr Item, ESelectInfo::Type SelectInfo);
	void HandleSearchChanged(const FText& NewText);
	void RefreshVisibleItems();
	FReply HandleLocateClicked();
	FReply HandleRenameClicked();
	ECheckBoxState GetSelectAllState() const;
	void HandleSelectAllChanged(ECheckBoxState NewState);

	FText GetSummaryText() const;
	FText GetRenameButtonText() const;
	FText GetDetailTitle() const;
	FText GetDetailBody() const;
	FText GetSafetyNotice() const;
	int32 GetIncludedCount() const;

private:
	TArray<FPreviewItemPtr> AllItems;
	TArray<FPreviewItemPtr> VisibleItems;
	FPreviewItemPtr SelectedItem;
	FString SearchText;
	bool bAttentionOnly = false;
	TSharedPtr<SListView<FPreviewItemPtr>> ListView;
	FSimpleDelegate OnRenameCompleted;
};
