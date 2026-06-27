#pragma once

#include "CoreMinimal.h"
#include "PlutoCollisionGizmoTypes.generated.h"

UENUM(BlueprintType)
enum class EPlutoCollisionGizmoVisibility : uint8
{
	Always UMETA(DisplayName = "Always"),
	SelectedInEditorOnly UMETA(DisplayName = "Selected In Editor Only")
};

USTRUCT(BlueprintType)
struct PLUTOGIZMOHELPERRUNTIME_API FPlutoCollisionGizmoStyle
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Outline")
	bool bDrawOutline = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Outline")
	FLinearColor OutlineColor = FLinearColor(0.85f, 0.05f, 0.16f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Outline", meta = (ClampMin = "0.0", UIMin = "0.0", UIMax = "10.0"))
	float LineThickness = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fill")
	bool bDrawFill = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fill")
	FLinearColor FillColor = FLinearColor(0.85f, 0.05f, 0.16f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fill", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float FillOpacity = 0.15f;

	void Sanitize()
	{
		OutlineColor.R = FMath::Clamp(OutlineColor.R, 0.0f, 1.0f);
		OutlineColor.G = FMath::Clamp(OutlineColor.G, 0.0f, 1.0f);
		OutlineColor.B = FMath::Clamp(OutlineColor.B, 0.0f, 1.0f);
		OutlineColor.A = FMath::Clamp(OutlineColor.A, 0.0f, 1.0f);
		FillColor.R = FMath::Clamp(FillColor.R, 0.0f, 1.0f);
		FillColor.G = FMath::Clamp(FillColor.G, 0.0f, 1.0f);
		FillColor.B = FMath::Clamp(FillColor.B, 0.0f, 1.0f);
		FillColor.A = FMath::Clamp(FillColor.A, 0.0f, 1.0f);
		LineThickness = FMath::Max(0.0f, LineThickness);
		FillOpacity = FMath::Clamp(FillOpacity, 0.0f, 1.0f);
	}

	bool operator==(const FPlutoCollisionGizmoStyle& Other) const
	{
		return bDrawOutline == Other.bDrawOutline
			&& OutlineColor.Equals(Other.OutlineColor)
			&& FMath::IsNearlyEqual(LineThickness, Other.LineThickness)
			&& bDrawFill == Other.bDrawFill
			&& FillColor.Equals(Other.FillColor)
			&& FMath::IsNearlyEqual(FillOpacity, Other.FillOpacity);
	}

	bool operator!=(const FPlutoCollisionGizmoStyle& Other) const
	{
		return !(*this == Other);
	}
};
