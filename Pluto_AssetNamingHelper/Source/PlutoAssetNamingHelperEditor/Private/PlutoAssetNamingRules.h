#pragma once

#include "AssetRegistry/AssetData.h"
#include "CoreMinimal.h"

enum class EPlutoAssetNamingStatus : uint8
{
	Compliant,
	HistoricalException,
	SuggestedMigration,
	Protected
};

struct FPlutoAssetNamingAuditResult
{
	FAssetData AssetData;
	EPlutoAssetNamingStatus Status = EPlutoAssetNamingStatus::HistoricalException;
	FString AssetTypeLabel;
	FString OwnerLabel;
	FString Issue;
	FString TechnicalDetails;
	FString SuggestedName;
	FString ExpectedPrefix;
	bool bRenameAllowed = false;
};

namespace PlutoAssetNamingRules
{
	FPlutoAssetNamingAuditResult Audit(const FAssetData& AssetData);
	FText GetStatusText(EPlutoAssetNamingStatus Status);
	FLinearColor GetStatusColor(EPlutoAssetNamingStatus Status);
}
