#include "PlutoGameplayTagInspectorBlueprintLibrary.h"

#include "PlutoGameplayTagInspectorRuntimeUtils.h"

bool UPlutoGameplayTagInspectorBlueprintLibrary::PF_FindGameplayTagContainerName(
	const UObject* TargetObject,
	const FGameplayTagContainer& TargetContainer,
	FString& OutContainerName)
{
	return FPlutoGameplayTagInspectorRuntimeUtils::FindInspectableGameplayTagContainerName(
		TargetObject,
		TargetContainer,
		OutContainerName);
}

void UPlutoGameplayTagInspectorBlueprintLibrary::PF_GetInspectableGameplayTagContainers(
	const UObject* TargetObject,
	TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers)
{
	FPlutoGameplayTagInspectorRuntimeUtils::CollectInspectableGameplayTagContainers(TargetObject, OutContainers);
}
