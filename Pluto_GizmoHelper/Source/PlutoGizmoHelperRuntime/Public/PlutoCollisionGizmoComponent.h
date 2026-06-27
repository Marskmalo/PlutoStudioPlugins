#pragma once

#include "Components/PrimitiveComponent.h"
#include "Engine/EngineTypes.h"
#include "PlutoCollisionGizmoTypes.h"
#include "PlutoCollisionGizmoComponent.generated.h"

class UShapeComponent;

UCLASS(ClassGroup = (Pluto), BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent, DisplayName = "Pluto Collision Gizmo"))
class PLUTOGIZMOHELPERRUNTIME_API UPlutoCollisionGizmoComponent : public UPrimitiveComponent
{
	GENERATED_BODY()

public:
	UPlutoCollisionGizmoComponent();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pluto Gizmo|Target", meta = (UseComponentPicker, AllowedClasses = "/Script/Engine.BoxComponent,/Script/Engine.SphereComponent,/Script/Engine.CapsuleComponent"))
	FComponentReference TargetCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Gizmo")
	bool bGizmoEnabled = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Gizmo")
	EPlutoCollisionGizmoVisibility VisibilityMode = EPlutoCollisionGizmoVisibility::Always;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Gizmo|Style")
	bool bOverrideProjectStyle = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto Gizmo|Style", meta = (EditCondition = "bOverrideProjectStyle"))
	FPlutoCollisionGizmoStyle OverrideStyle;

	UFUNCTION(BlueprintCallable, Category = "Pluto Gizmo")
	void SetTargetCollision(UShapeComponent* InTargetCollision);

	UFUNCTION(BlueprintPure, Category = "Pluto Gizmo")
	UShapeComponent* GetTargetCollision() const;

	UFUNCTION(BlueprintCallable, Category = "Pluto Gizmo")
	void SetGizmoEnabled(bool bEnabled);

	UFUNCTION(BlueprintCallable, Category = "Pluto Gizmo|Style")
	void SetOutlineColor(FLinearColor Color);

	UFUNCTION(BlueprintCallable, Category = "Pluto Gizmo|Style")
	void SetLineThickness(float Thickness);

	UFUNCTION(BlueprintCallable, Category = "Pluto Gizmo|Style")
	void SetFillColor(FLinearColor Color);

	UFUNCTION(BlueprintCallable, Category = "Pluto Gizmo|Style")
	void SetFillOpacity(float Opacity);

	UFUNCTION(BlueprintCallable, Category = "Pluto Gizmo|Style")
	void SetDrawOutline(bool bDraw);

	UFUNCTION(BlueprintCallable, Category = "Pluto Gizmo|Style")
	void SetDrawFill(bool bDraw);

	UFUNCTION(BlueprintCallable, Category = "Pluto Gizmo|Style")
	void SetStyle(const FPlutoCollisionGizmoStyle& Style);

	UFUNCTION(BlueprintCallable, Category = "Pluto Gizmo")
	void RefreshGizmo();

	FPlutoCollisionGizmoStyle GetResolvedStyle() const;
	bool IsTargetValid() const;
	FName GetTargetComponentName() const { return TargetCollision.ComponentProperty; }
	void SetTargetCollisionReference(UShapeComponent* InTargetCollision, FName ComponentPropertyName);

	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
	virtual FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void OnRegister() override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif

private:
	uint32 BuildTargetSignature() const;
	void ApplyStyleMutation(TFunctionRef<void(FPlutoCollisionGizmoStyle&)> Mutation);

	uint32 LastTargetSignature = 0;
	FPlutoCollisionGizmoStyle LastResolvedStyle;
};
