#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlutoGameplayTagContainerProvider.h"
#include "PlutoGameplayTagInspectorBlueprintLibrary.generated.h"

UCLASS()
class PLUTOGAMEPLAYTAGINSPECTORRUNTIME_API UPlutoGameplayTagInspectorBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Pluto GameplayTag Inspector", meta = (DisplayName = "PF_FindGameplayTagContainerName", DefaultToSelf = "TargetObject", ToolTip = "Try to resolve the reflected or provided name of a gameplay tag container on the target object. The returned value is a property path string when available.\n尝试解析目标对象上 GameplayTag 容器的反射名称或提供接口名称。若可用，返回值会优先使用属性路径字符串。"))
	static bool PF_FindGameplayTagContainerName(const UObject* TargetObject, const FGameplayTagContainer& TargetContainer, FString& OutContainerName);

	UFUNCTION(BlueprintPure, Category = "Pluto GameplayTag Inspector", meta = (DisplayName = "PF_GetInspectableGameplayTagContainers", DefaultToSelf = "TargetObject", ToolTip = "Collect named gameplay tag containers from the target object using the Pluto provider interface, reflection, and owned-tag fallback.\n通过 Pluto 提供接口、反射扫描和 OwnedTag 回退，从目标对象收集具名 GameplayTag 容器。"))
	static void PF_GetInspectableGameplayTagContainers(const UObject* TargetObject, TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers);
};
