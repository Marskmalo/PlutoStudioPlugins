#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "PlutoGameplayTagContainerProvider.generated.h"

USTRUCT(BlueprintType)
struct PLUTOGAMEPLAYTAGINSPECTORRUNTIME_API FPlutoGameplayTagContainerDescriptor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto GameplayTag Inspector", meta = (DisplayName = "Container Name", ToolTip = "Inspector-facing container name.\n供检查器显示的容器名称。"))
	FName ContainerName = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto GameplayTag Inspector", meta = (DisplayName = "Container Path", ToolTip = "Property path or custom path for this container.\n该容器的属性路径或自定义路径。"))
	FString ContainerPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto GameplayTag Inspector", meta = (DisplayName = "Gameplay Tags", ToolTip = "Gameplay tags stored in this container.\n这个容器里存放的 GameplayTag。"))
	FGameplayTagContainer GameplayTags;
};

USTRUCT(BlueprintType)
struct PLUTOGAMEPLAYTAGINSPECTORRUNTIME_API FPlutoGameplayTagDescriptor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto GameplayTag Inspector", meta = (DisplayName = "Tag Path", ToolTip = "Property path for this isolated gameplay tag."))
	FString TagPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pluto GameplayTag Inspector", meta = (DisplayName = "Gameplay Tag", ToolTip = "A standalone gameplay tag that is not stored in a gameplay tag container."))
	FGameplayTag GameplayTag;
};

UINTERFACE(BlueprintType)
class PLUTOGAMEPLAYTAGINSPECTORRUNTIME_API UPlutoGameplayTagContainerProvider : public UInterface
{
	GENERATED_BODY()
};

class PLUTOGAMEPLAYTAGINSPECTORRUNTIME_API IPlutoGameplayTagContainerProvider
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Pluto GameplayTag Inspector", meta = (DisplayName = "PF_GetInspectableGameplayTagContainers", ToolTip = "Return named gameplay tag containers for the Pluto inspector.\n返回供 Pluto 检查器使用的具名 GameplayTag 容器。"))
	void PF_GetInspectableGameplayTagContainers(TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers) const;
};
