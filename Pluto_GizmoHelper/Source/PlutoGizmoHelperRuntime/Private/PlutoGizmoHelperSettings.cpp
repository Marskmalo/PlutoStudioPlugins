#include "PlutoGizmoHelperSettings.h"

#if WITH_EDITOR
#include "PlutoCollisionGizmoComponent.h"
#include "UObject/UObjectIterator.h"

namespace
{
	void RefreshAllCollisionGizmos()
	{
		for (TObjectIterator<UPlutoCollisionGizmoComponent> It; It; ++It)
		{
			if (!It->IsTemplate() && IsValid(*It))
			{
				It->RefreshGizmo();
			}
		}
	}
}

FText UPlutoGizmoHelperSettings::GetSectionText() const
{
	return NSLOCTEXT("PlutoGizmoHelper", "SettingsSection", "Pluto Gizmo Helper");
}

FText UPlutoGizmoHelperSettings::GetSectionDescription() const
{
	return NSLOCTEXT("PlutoGizmoHelper", "SettingsDescription", "Default styles used by Pluto collision gizmos.");
}

void UPlutoGizmoHelperSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	DefaultCollisionStyle.Sanitize();
	Super::PostEditChangeProperty(PropertyChangedEvent);
	RefreshAllCollisionGizmos();
}

void UPlutoGizmoHelperSettings::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	DefaultCollisionStyle.Sanitize();
	Super::PostEditChangeChainProperty(PropertyChangedEvent);
	RefreshAllCollisionGizmos();
}
#endif
