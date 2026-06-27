#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "PlutoCollisionGizmoTypes.h"
#include "PlutoGizmoHelperSettings.generated.h"

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Pluto Gizmo Helper"))
class PLUTOGIZMOHELPERRUNTIME_API UPlutoGizmoHelperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, Category = "Collision Gizmo")
	FPlutoCollisionGizmoStyle DefaultCollisionStyle;

	virtual FName GetCategoryName() const override
	{
		return TEXT("Plugins");
	}

#if WITH_EDITOR
	virtual FText GetSectionText() const override;
	virtual FText GetSectionDescription() const override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif
};
