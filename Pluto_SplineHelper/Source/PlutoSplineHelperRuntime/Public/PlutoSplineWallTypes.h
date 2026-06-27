#pragma once

#include "CoreMinimal.h"
#include "PlutoSplineWallTypes.generated.h"

UENUM(BlueprintType)
enum class EPlutoSplineWallDirection : uint8
{
	ProcessExternalObjects UMETA(DisplayName = "Process External Objects"),
	ProcessInternalObjects UMETA(DisplayName = "Process Internal Objects")
};

UENUM(BlueprintType)
enum class EPlutoSplineWallEditorPreview : uint8
{
	Always UMETA(DisplayName = "Always"),
	SelectedOnly UMETA(DisplayName = "Selected Only"),
	Hidden UMETA(DisplayName = "Hidden")
};

USTRUCT(BlueprintType)
struct PLUTOSPLINEHELPERRUNTIME_API FPlutoSplineWallPreviewStyle
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fill")
	FLinearColor FillColor = FLinearColor(0.05f, 0.8f, 0.65f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fill", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float FillOpacity = 0.18f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Outline")
	FLinearColor OutlineColor = FLinearColor(1.0f, 0.65f, 0.0f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Outline", meta = (ClampMin = "0.0", UIMax = "10.0"))
	float LineThickness = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Direction")
	bool bShowDirectionArrows = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Direction")
	FLinearColor DirectionArrowColor = FLinearColor(1.0f, 0.15f, 0.05f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Direction", meta = (ClampMin = "50.0"))
	float DirectionArrowSpacing = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Open Wall Thickness")
	FLinearColor OpenWallWireColor = FLinearColor(0.78f, 0.25f, 0.9f, 1.0f);

	void Sanitize()
	{
		FillOpacity = FMath::Clamp(FillOpacity, 0.0f, 1.0f);
		LineThickness = FMath::Max(0.0f, LineThickness);
		DirectionArrowSpacing = FMath::Max(50.0f, DirectionArrowSpacing);
	}
};
