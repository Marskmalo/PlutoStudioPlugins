#include "PlutoSplineWallSplineComponent.h"

#include "PlutoSplineWallActor.h"

void UPlutoSplineWallSplineComponent::UpdateSpline()
{
	Super::UpdateSpline();

#if WITH_EDITOR
	if (APlutoSplineWall* Wall = Cast<APlutoSplineWall>(GetOwner()))
	{
		Wall->HandleSplineEdited();
	}
#endif
}
