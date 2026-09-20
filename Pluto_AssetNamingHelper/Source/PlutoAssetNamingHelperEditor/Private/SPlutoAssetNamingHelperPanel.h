#pragma once

#include "CoreMinimal.h"
#include "PlutoAssetNamingRules.h"
#include "Widgets/SCompoundWidget.h"

class SHeaderRow;
class SSearchBox;
class STableViewBase;
class SVerticalBox;
template<typename ItemType> class SListView;

struct FPlutoAssetTypeFilterItem
{
	FTopLevelAssetPath ClassPath;
	FText DisplayName;
	TWeakObjectPtr<UClass> AssetClass;
	FLinearColor TypeColor = FLinearColor::White;
	bool bEnabled = false;
};

class SPlutoAssetNamingHelperPanel : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPlutoAssetNamingHelperPanel) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	void FocusAsset(const TSharedPtr<FPlutoAssetNamingAuditResult>& Item) const;

private:
	using FAuditResultPtr = TSharedPtr<FPlutoAssetNamingAuditResult>;
	using FTypeFilterPtr = TSharedPtr<FPlutoAssetTypeFilterItem>;

	TSharedRef<ITableRow> GenerateResultRow(FAuditResultPtr Item, const TSharedRef<STableViewBase>& OwnerTable);
	TSharedRef<SWidget> BuildSummaryCard(EPlutoAssetNamingStatus Status);
	TSharedRef<SWidget> BuildStatusFilter(EPlutoAssetNamingStatus Status);
	TSharedRef<SWidget> BuildAssetTypeIcon(const FTypeFilterPtr& TypeItem) const;

	void HandlePathSelected(const FString& NewPath);
	FReply HandleScanClicked();
	FReply HandleExportClicked();
	FReply HandleRenamePreviewClicked();
	FReply HandleDocumentationClicked();
	void HandleSearchChanged(const FText& NewSearchText);
	void RebuildTypeFilters();
	void RefreshVisibleResults();
	void ShowTransientMessage(const FText& Message, bool bSuccess) const;

	int32 GetStatusCount(EPlutoAssetNamingStatus Status) const;
	bool IsStatusEnabled(EPlutoAssetNamingStatus Status) const;
	void SetStatusEnabled(EPlutoAssetNamingStatus Status, bool bEnabled);

private:
	FString SelectedRootPath = TEXT("/Game/SOD");
	FString SearchText;
	TArray<FAuditResultPtr> AllResults;
	TArray<FAuditResultPtr> VisibleResults;
	TArray<FTypeFilterPtr> TypeFilters;
	TMap<EPlutoAssetNamingStatus, bool> EnabledStatuses;

	TSharedPtr<SVerticalBox> TypeFilterBox;
	TSharedPtr<SListView<FAuditResultPtr>> ResultListView;
};
