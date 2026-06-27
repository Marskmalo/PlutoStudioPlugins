#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PlutoGameplayTagContainerProvider.h"

class UObject;

class PLUTOGAMEPLAYTAGINSPECTORRUNTIME_API FPlutoGameplayTagInspectorRuntimeUtils
{
public:
	static void CollectInspectableGameplayTagContainers(const UObject* TargetObject, TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers);
	static void CollectInspectableIsolatedGameplayTags(const UObject* TargetObject, TArray<FPlutoGameplayTagDescriptor>& OutTags);
	static bool FindInspectableGameplayTagContainerName(const UObject* TargetObject, const FGameplayTagContainer& TargetContainer, FString& OutContainerName);

private:
	static void CollectContainersFromObject(const UObject* TargetObject, const FString& RootPath, TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers);
	static void CollectIsolatedTagsFromObject(const UObject* TargetObject, const FString& RootPath, TArray<FPlutoGameplayTagDescriptor>& OutTags);
	static void CollectContainersFromProvider(const UObject* TargetObject, TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers);
	static void CollectContainersFromReflection(const UObject* TargetObject, TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers);
	static void CollectTagsFromReflection(const UObject* TargetObject, TArray<FPlutoGameplayTagDescriptor>& OutTags);
	static void AppendContainersWithRootPath(
		const TArray<FPlutoGameplayTagContainerDescriptor>& SourceContainers,
		const FString& RootPath,
		TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers);
	static void AppendTagsWithRootPath(
		const TArray<FPlutoGameplayTagDescriptor>& SourceTags,
		const FString& RootPath,
		TArray<FPlutoGameplayTagDescriptor>& OutTags);
	static void CollectTagsFromStruct(
		const UStruct* StructType,
		const void* StructData,
		const FString& ParentPath,
		int32 Depth,
		TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers,
		TArray<FPlutoGameplayTagDescriptor>& OutTags);
	static void CollectTagsFromProperty(
		const FProperty* Property,
		const void* PropertyOwnerData,
		const FString& ParentPath,
		int32 Depth,
		TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers,
		TArray<FPlutoGameplayTagDescriptor>& OutTags);
	static void AddContainerIfUnique(
		TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers,
		FName ContainerName,
		const FString& ContainerPath,
		const FGameplayTagContainer& GameplayTags);
	static void AddIsolatedTagIfUnique(
		TArray<FPlutoGameplayTagDescriptor>& OutTags,
		const FString& TagPath,
		const FGameplayTag& GameplayTag);
};
