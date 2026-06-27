#pragma once

#include "Components/SplineComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlutoSplineWallTypes.h"
#include "PlutoSplineWallActor.generated.h"

class UDynamicMeshComponent;
class ULineBatchComponent;
class UPlutoSplineWallSplineComponent;

DECLARE_MULTICAST_DELEGATE_OneParam(FPlutoSplineWallValidationFailed, class APlutoSplineWall*);

UCLASS(BlueprintType, Blueprintable, meta = (DisplayName = "Pluto Spline Wall"))
class PLUTOSPLINEHELPERRUNTIME_API APlutoSplineWall : public AActor
{
	GENERATED_BODY()

public:
	APlutoSplineWall();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pluto Spline Wall")
	TObjectPtr<UPlutoSplineWallSplineComponent> Spline;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pluto Spline Wall")
	TObjectPtr<UDynamicMeshComponent> CollisionMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category = "Pluto Spline Wall")
	TObjectPtr<ULineBatchComponent> Preview;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Spline Wall|Geometry")
	bool bClosedLoop = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Spline Wall|Geometry", meta = (ClampMin = "1.0"))
	float Height = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Spline Wall|Geometry")
	float BottomOffset = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Spline Wall|Geometry", meta = (ClampMin = "5.0"))
	float SampleSpacing = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Spline Wall|Geometry", meta = (ClampMin = "1.0", EditCondition = "!bClosedLoop"))
	float OpenWallThickness = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Spline Wall|Geometry")
	TEnumAsByte<ESplinePointType::Type> AllSplinePointType = ESplinePointType::Curve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Spline Wall|Geometry", meta = (EditCondition = "bClosedLoop"))
	EPlutoSplineWallDirection Direction = EPlutoSplineWallDirection::ProcessExternalObjects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Spline Wall|Caps", meta = (EditCondition = "bClosedLoop"))
	bool bCollisionTopCap = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Spline Wall|Caps", meta = (EditCondition = "bClosedLoop"))
	bool bCollisionBottomCap = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Spline Wall|Caps", meta = (EditCondition = "bClosedLoop"))
	bool bPreviewTopCap = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Spline Wall|Caps", meta = (EditCondition = "bClosedLoop"))
	bool bPreviewBottomCap = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Spline Wall|Preview")
	EPlutoSplineWallEditorPreview EditorPreview = EPlutoSplineWallEditorPreview::Always;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Spline Wall|Preview")
	bool bShowPreviewInPIE = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Spline Wall|Preview")
	FPlutoSplineWallPreviewStyle PreviewStyle;

	UFUNCTION(BlueprintCallable, Category = "Pluto Spline Wall")
	bool RebuildWall();

	UFUNCTION(BlueprintCallable, Category = "Pluto Spline Wall")
	void ApplySplinePointTypeToAll();

	UFUNCTION(BlueprintPure, Category = "Pluto Spline Wall")
	bool IsCurrentShapeValid() const { return bCurrentShapeValid; }

	UFUNCTION(BlueprintPure, Category = "Pluto Spline Wall")
	FText GetValidationMessage() const { return ValidationMessage; }

	void HandleSplineEdited();
	static FPlutoSplineWallValidationFailed& OnValidationFailed();

	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual bool ShouldTickIfViewportsOnly() const override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostEditMove(bool bFinished) override;
	virtual void PostEditUndo() override;
#endif

private:
	struct FGeneratedGeometry
	{
		TArray<FVector> CollisionVertices;
		TArray<int32> CollisionIndices;
		TArray<FVector> PreviewVertices;
		TArray<int32> PreviewIndices;
		TArray<FVector2D> SampledPoints;
	};

	bool GenerateGeometry(FGeneratedGeometry& OutGeometry, FText& OutError) const;
	bool BuildSampledPolygon(TArray<FVector2D>& OutPoints) const;
	bool ValidateClosedPolygon(const TArray<FVector2D>& Points, FText& OutError) const;
	void ApplyCollisionGeometry(const FGeneratedGeometry& Geometry);
	void RefreshPreview(bool bForce = false);
	void DrawValidPreview();
	void DrawInvalidPreview();
	bool ShouldShowPreview() const;
	uint32 BuildConfigurationSignature() const;

	FGeneratedGeometry LastValidGeometry;
	bool bCurrentShapeValid = false;
	bool bValidationNotificationSent = false;
	bool bIsRebuilding = false;
	bool bLastPreviewVisible = false;
	uint32 LastConfigurationSignature = 0;
	FText ValidationMessage;
};
