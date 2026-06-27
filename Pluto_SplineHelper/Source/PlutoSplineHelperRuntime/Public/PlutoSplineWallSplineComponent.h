#pragma once

#include "Components/SplineComponent.h"
#include "PlutoSplineWallSplineComponent.generated.h"

UCLASS(ClassGroup = (Pluto), meta = (BlueprintSpawnableComponent, DisplayName = "Pluto Spline Wall Path"))
class PLUTOSPLINEHELPERRUNTIME_API UPlutoSplineWallSplineComponent : public USplineComponent
{
	GENERATED_BODY()

public:
	virtual void UpdateSpline() override;
};
