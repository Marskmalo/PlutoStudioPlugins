#include "PlutoGameplayTagInspectorRuntimeUtils.h"

#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "GameplayTagAssetInterface.h"
#include "UObject/Field.h"
#include "UObject/UnrealType.h"

namespace PlutoGameplayTagInspectorRuntimeUtils
{
	constexpr int32 MaxRecursiveDepth = 6;

	bool ShouldInspectProperty(const FProperty* Property)
	{
		if (Property == nullptr)
		{
			return false;
		}

		if (Property->HasAnyPropertyFlags(CPF_Transient | CPF_Deprecated))
		{
			return false;
		}

		return Property->HasAnyPropertyFlags(CPF_Edit | CPF_BlueprintVisible);
	}

	FName MakeContainerName(const FString& ContainerPath, const FProperty* Property)
	{
		if (!ContainerPath.IsEmpty())
		{
			return FName(*ContainerPath);
		}

		return Property != nullptr ? Property->GetFName() : NAME_None;
	}

	bool ContainersMatchExactly(const FGameplayTagContainer& A, const FGameplayTagContainer& B)
	{
		return A == B;
	}

	bool IsGameplayTagContainerStruct(const UScriptStruct* StructType)
	{
		return StructType == TBaseStructure<FGameplayTagContainer>::Get();
	}

	bool IsGameplayTagStruct(const UScriptStruct* StructType)
	{
		return StructType == TBaseStructure<FGameplayTag>::Get();
	}

	FString FormatCompactNumber(double Value)
	{
		if (FMath::IsNearlyZero(Value))
		{
			Value = 0.0;
		}

		FString NumberString = FString::Printf(TEXT("%.3f"), Value);
		while (NumberString.Contains(TEXT(".")) && NumberString.EndsWith(TEXT("0")))
		{
			NumberString.LeftChopInline(1);
		}
		if (NumberString.EndsWith(TEXT(".")))
		{
			NumberString.LeftChopInline(1);
		}

		return NumberString;
	}

	FString ExportPropertyValueToString(const FProperty* Property, const void* ValuePtr)
	{
		if (const FFloatProperty* FloatProperty = CastField<FFloatProperty>(Property))
		{
			return ValuePtr != nullptr
				? FormatCompactNumber(FloatProperty->GetPropertyValue(ValuePtr))
				: TEXT("<None>");
		}

		if (const FDoubleProperty* DoubleProperty = CastField<FDoubleProperty>(Property))
		{
			return ValuePtr != nullptr
				? FormatCompactNumber(DoubleProperty->GetPropertyValue(ValuePtr))
				: TEXT("<None>");
		}

		if (const FStructProperty* StructProperty = CastField<FStructProperty>(Property))
		{
			if (StructProperty->Struct == TBaseStructure<FVector>::Get())
			{
				const FVector* VectorValue = static_cast<const FVector*>(ValuePtr);
				if (VectorValue != nullptr)
				{
					return FString::Printf(
						TEXT("X=%s,Y=%s,Z=%s"),
						*FormatCompactNumber(VectorValue->X),
						*FormatCompactNumber(VectorValue->Y),
						*FormatCompactNumber(VectorValue->Z));
				}
			}

			if (StructProperty->Struct == TBaseStructure<FVector2D>::Get())
			{
				const FVector2D* VectorValue = static_cast<const FVector2D*>(ValuePtr);
				if (VectorValue != nullptr)
				{
					return FString::Printf(
						TEXT("X=%s,Y=%s"),
						*FormatCompactNumber(VectorValue->X),
						*FormatCompactNumber(VectorValue->Y));
				}
			}
		}

		FString ValueString;
		if (Property != nullptr && ValuePtr != nullptr)
		{
			Property->ExportTextItem_Direct(ValueString, ValuePtr, nullptr, nullptr, PPF_None);
		}

		return ValueString.IsEmpty() ? TEXT("<None>") : ValueString;
	}
}

void FPlutoGameplayTagInspectorRuntimeUtils::CollectInspectableGameplayTagContainers(
	const UObject* TargetObject,
	TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers)
{
	OutContainers.Reset();

	if (TargetObject == nullptr)
	{
		return;
	}

	CollectContainersFromObject(TargetObject, FString(), OutContainers);

	if (const AActor* Actor = Cast<AActor>(TargetObject))
	{
		TInlineComponentArray<UActorComponent*> Components(const_cast<AActor*>(Actor));
		for (const UActorComponent* Component : Components)
		{
			if (Component == nullptr)
			{
				continue;
			}

			const FString ComponentRootPath = FString::Printf(TEXT("Components.%s"), *Component->GetName());
			CollectContainersFromObject(Component, ComponentRootPath, OutContainers);
		}
	}
}

void FPlutoGameplayTagInspectorRuntimeUtils::CollectInspectableIsolatedGameplayTags(
	const UObject* TargetObject,
	TArray<FPlutoGameplayTagDescriptor>& OutTags)
{
	OutTags.Reset();

	if (TargetObject == nullptr)
	{
		return;
	}

	CollectIsolatedTagsFromObject(TargetObject, FString(), OutTags);

	if (const AActor* Actor = Cast<AActor>(TargetObject))
	{
		TInlineComponentArray<UActorComponent*> Components(const_cast<AActor*>(Actor));
		for (const UActorComponent* Component : Components)
		{
			if (Component == nullptr)
			{
				continue;
			}

			const FString ComponentRootPath = FString::Printf(TEXT("Components.%s"), *Component->GetName());
			CollectIsolatedTagsFromObject(Component, ComponentRootPath, OutTags);
		}
	}
}

bool FPlutoGameplayTagInspectorRuntimeUtils::FindInspectableGameplayTagContainerName(
	const UObject* TargetObject,
	const FGameplayTagContainer& TargetContainer,
	FString& OutContainerName)
{
	OutContainerName.Reset();

	TArray<FPlutoGameplayTagContainerDescriptor> Containers;
	CollectInspectableGameplayTagContainers(TargetObject, Containers);

	FString MatchedName;
	int32 MatchCount = 0;

	for (const FPlutoGameplayTagContainerDescriptor& Container : Containers)
	{
		if (PlutoGameplayTagInspectorRuntimeUtils::ContainersMatchExactly(Container.GameplayTags, TargetContainer))
		{
			MatchedName = !Container.ContainerPath.IsEmpty()
				? Container.ContainerPath
				: Container.ContainerName.ToString();
			++MatchCount;
		}
	}

	if (MatchCount == 1)
	{
		OutContainerName = MatchedName;
		return true;
	}

	return false;
}

void FPlutoGameplayTagInspectorRuntimeUtils::CollectContainersFromObject(
	const UObject* TargetObject,
	const FString& RootPath,
	TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers)
{
	if (TargetObject == nullptr)
	{
		return;
	}

	TArray<FPlutoGameplayTagContainerDescriptor> LocalContainers;
	CollectContainersFromProvider(TargetObject, LocalContainers);
	CollectContainersFromReflection(TargetObject, LocalContainers);

	if (LocalContainers.Num() == 0)
	{
		if (const IGameplayTagAssetInterface* GameplayTagAsset = Cast<IGameplayTagAssetInterface>(TargetObject))
		{
			FGameplayTagContainer OwnedGameplayTags;
			GameplayTagAsset->GetOwnedGameplayTags(OwnedGameplayTags);

			if (!OwnedGameplayTags.IsEmpty())
			{
				AddContainerIfUnique(
					LocalContainers,
					TEXT("OwnedGameplayTags_View"),
					TEXT("OwnedGameplayTags_View"),
					OwnedGameplayTags);
			}
		}
	}

	AppendContainersWithRootPath(LocalContainers, RootPath, OutContainers);
}

void FPlutoGameplayTagInspectorRuntimeUtils::CollectIsolatedTagsFromObject(
	const UObject* TargetObject,
	const FString& RootPath,
	TArray<FPlutoGameplayTagDescriptor>& OutTags)
{
	if (TargetObject == nullptr)
	{
		return;
	}

	TArray<FPlutoGameplayTagDescriptor> LocalTags;
	CollectTagsFromReflection(TargetObject, LocalTags);
	AppendTagsWithRootPath(LocalTags, RootPath, OutTags);
}

void FPlutoGameplayTagInspectorRuntimeUtils::CollectContainersFromProvider(
	const UObject* TargetObject,
	TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers)
{
	if (TargetObject == nullptr || !TargetObject->GetClass()->ImplementsInterface(UPlutoGameplayTagContainerProvider::StaticClass()))
	{
		return;
	}

	TArray<FPlutoGameplayTagContainerDescriptor> ProvidedContainers;
	IPlutoGameplayTagContainerProvider::Execute_PF_GetInspectableGameplayTagContainers(TargetObject, ProvidedContainers);

	for (const FPlutoGameplayTagContainerDescriptor& Container : ProvidedContainers)
	{
		AddContainerIfUnique(
			OutContainers,
			Container.ContainerName,
			Container.ContainerPath,
			Container.GameplayTags);
	}
}

void FPlutoGameplayTagInspectorRuntimeUtils::CollectContainersFromReflection(
	const UObject* TargetObject,
	TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers)
{
	if (TargetObject == nullptr)
	{
		return;
	}

	TArray<FPlutoGameplayTagDescriptor> IgnoredIsolatedTags;
	CollectTagsFromStruct(TargetObject->GetClass(), TargetObject, FString(), 0, OutContainers, IgnoredIsolatedTags);
}

void FPlutoGameplayTagInspectorRuntimeUtils::CollectTagsFromReflection(
	const UObject* TargetObject,
	TArray<FPlutoGameplayTagDescriptor>& OutTags)
{
	if (TargetObject == nullptr)
	{
		return;
	}

	TArray<FPlutoGameplayTagContainerDescriptor> IgnoredContainers;
	CollectTagsFromStruct(TargetObject->GetClass(), TargetObject, FString(), 0, IgnoredContainers, OutTags);
}

void FPlutoGameplayTagInspectorRuntimeUtils::AppendContainersWithRootPath(
	const TArray<FPlutoGameplayTagContainerDescriptor>& SourceContainers,
	const FString& RootPath,
	TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers)
{
	for (const FPlutoGameplayTagContainerDescriptor& SourceContainer : SourceContainers)
	{
		const FString LocalPath = !SourceContainer.ContainerPath.IsEmpty()
			? SourceContainer.ContainerPath
			: SourceContainer.ContainerName.ToString();
		const FString FullPath = RootPath.IsEmpty()
			? LocalPath
			: FString::Printf(TEXT("%s.%s"), *RootPath, *LocalPath);

		AddContainerIfUnique(
			OutContainers,
			FName(*FullPath),
			FullPath,
			SourceContainer.GameplayTags);
	}
}

void FPlutoGameplayTagInspectorRuntimeUtils::AppendTagsWithRootPath(
	const TArray<FPlutoGameplayTagDescriptor>& SourceTags,
	const FString& RootPath,
	TArray<FPlutoGameplayTagDescriptor>& OutTags)
{
	for (const FPlutoGameplayTagDescriptor& SourceTag : SourceTags)
	{
		const FString FullPath = RootPath.IsEmpty()
			? SourceTag.TagPath
			: FString::Printf(TEXT("%s.%s"), *RootPath, *SourceTag.TagPath);

		AddIsolatedTagIfUnique(OutTags, FullPath, SourceTag.GameplayTag);
	}
}

void FPlutoGameplayTagInspectorRuntimeUtils::CollectTagsFromStruct(
	const UStruct* StructType,
	const void* StructData,
	const FString& ParentPath,
	int32 Depth,
	TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers,
	TArray<FPlutoGameplayTagDescriptor>& OutTags)
{
	if (StructType == nullptr || StructData == nullptr || Depth > PlutoGameplayTagInspectorRuntimeUtils::MaxRecursiveDepth)
	{
		return;
	}

	for (TFieldIterator<FProperty> PropertyIt(StructType, EFieldIteratorFlags::IncludeSuper); PropertyIt; ++PropertyIt)
	{
		CollectTagsFromProperty(*PropertyIt, StructData, ParentPath, Depth, OutContainers, OutTags);
	}
}

void FPlutoGameplayTagInspectorRuntimeUtils::CollectTagsFromProperty(
	const FProperty* Property,
	const void* PropertyOwnerData,
	const FString& ParentPath,
	int32 Depth,
	TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers,
	TArray<FPlutoGameplayTagDescriptor>& OutTags)
{
	using namespace PlutoGameplayTagInspectorRuntimeUtils;

	if (!ShouldInspectProperty(Property) || PropertyOwnerData == nullptr)
	{
		return;
	}

	const FString PropertyPath = ParentPath.IsEmpty()
		? Property->GetName()
		: FString::Printf(TEXT("%s.%s"), *ParentPath, *Property->GetName());

	if (const FStructProperty* StructProperty = CastField<FStructProperty>(Property))
	{
		const void* ValuePtr = StructProperty->ContainerPtrToValuePtr<void>(PropertyOwnerData);

		if (IsGameplayTagContainerStruct(StructProperty->Struct))
		{
			const FGameplayTagContainer* GameplayTagContainer = static_cast<const FGameplayTagContainer*>(ValuePtr);
			AddContainerIfUnique(
				OutContainers,
				MakeContainerName(PropertyPath, Property),
				PropertyPath,
				*GameplayTagContainer);
			return;
		}

		if (IsGameplayTagStruct(StructProperty->Struct))
		{
			const FGameplayTag* GameplayTag = static_cast<const FGameplayTag*>(ValuePtr);
			AddIsolatedTagIfUnique(OutTags, PropertyPath, *GameplayTag);
			return;
		}

		if (!StructProperty->Struct->IsChildOf(TBaseStructure<FGameplayTagContainer>::Get()) &&
			!IsGameplayTagContainerStruct(StructProperty->Struct))
		{
			CollectTagsFromStruct(StructProperty->Struct, ValuePtr, PropertyPath, Depth + 1, OutContainers, OutTags);
		}

		return;
	}

	if (const FArrayProperty* ArrayProperty = CastField<FArrayProperty>(Property))
	{
		const void* ArrayPtr = ArrayProperty->ContainerPtrToValuePtr<void>(PropertyOwnerData);
		FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayPtr);

		for (int32 ArrayIndex = 0; ArrayIndex < ArrayHelper.Num(); ++ArrayIndex)
		{
			const FString ElementPath = FString::Printf(TEXT("%s[Index %d]"), *PropertyPath, ArrayIndex);
			const void* ElementPtr = ArrayHelper.GetRawPtr(ArrayIndex);

			if (const FStructProperty* InnerStructProperty = CastField<FStructProperty>(ArrayProperty->Inner))
			{
				if (IsGameplayTagContainerStruct(InnerStructProperty->Struct))
				{
					const FGameplayTagContainer* GameplayTagContainer = static_cast<const FGameplayTagContainer*>(ElementPtr);
					AddContainerIfUnique(
						OutContainers,
						FName(*ElementPath),
						ElementPath,
						*GameplayTagContainer);
				}
				else if (IsGameplayTagStruct(InnerStructProperty->Struct))
				{
					const FGameplayTag* GameplayTag = static_cast<const FGameplayTag*>(ElementPtr);
					AddIsolatedTagIfUnique(OutTags, ElementPath, *GameplayTag);
				}
				else
				{
					CollectTagsFromStruct(InnerStructProperty->Struct, ElementPtr, ElementPath, Depth + 1, OutContainers, OutTags);
				}
			}
		}

		return;
	}

	if (const FMapProperty* MapProperty = CastField<FMapProperty>(Property))
	{
		const void* MapPtr = MapProperty->ContainerPtrToValuePtr<void>(PropertyOwnerData);
		FScriptMapHelper MapHelper(MapProperty, MapPtr);

		for (int32 MapIndex = 0; MapIndex < MapHelper.GetMaxIndex(); ++MapIndex)
		{
			if (!MapHelper.IsValidIndex(MapIndex))
			{
				continue;
			}

			const FString KeyString = ExportPropertyValueToString(MapProperty->KeyProp, MapHelper.GetKeyPtr(MapIndex));
			const FString ValuePath = FString::Printf(TEXT("%s[Key %s]"), *PropertyPath, *KeyString);
			const void* ValuePtr = MapHelper.GetValuePtr(MapIndex);

			if (const FStructProperty* ValueStructProperty = CastField<FStructProperty>(MapProperty->ValueProp))
			{
				if (IsGameplayTagContainerStruct(ValueStructProperty->Struct))
				{
					const FGameplayTagContainer* GameplayTagContainer = static_cast<const FGameplayTagContainer*>(ValuePtr);
					AddContainerIfUnique(
						OutContainers,
						FName(*ValuePath),
						ValuePath,
						*GameplayTagContainer);
				}
				else if (IsGameplayTagStruct(ValueStructProperty->Struct))
				{
					const FGameplayTag* GameplayTag = static_cast<const FGameplayTag*>(ValuePtr);
					AddIsolatedTagIfUnique(OutTags, ValuePath, *GameplayTag);
				}
				else
				{
					CollectTagsFromStruct(ValueStructProperty->Struct, ValuePtr, ValuePath, Depth + 1, OutContainers, OutTags);
				}
			}
		}
	}
}

void FPlutoGameplayTagInspectorRuntimeUtils::AddContainerIfUnique(
	TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers,
	FName ContainerName,
	const FString& ContainerPath,
	const FGameplayTagContainer& GameplayTags)
{
	const FString EffectivePath = !ContainerPath.IsEmpty() ? ContainerPath : ContainerName.ToString();

	for (const FPlutoGameplayTagContainerDescriptor& ExistingContainer : OutContainers)
	{
		const FString ExistingPath = !ExistingContainer.ContainerPath.IsEmpty()
			? ExistingContainer.ContainerPath
			: ExistingContainer.ContainerName.ToString();

		if (ExistingPath == EffectivePath)
		{
			return;
		}
	}

	FPlutoGameplayTagContainerDescriptor NewContainer;
	NewContainer.ContainerName = ContainerName.IsNone() ? FName(*EffectivePath) : ContainerName;
	NewContainer.ContainerPath = EffectivePath;
	NewContainer.GameplayTags = GameplayTags;
	OutContainers.Add(MoveTemp(NewContainer));
}

void FPlutoGameplayTagInspectorRuntimeUtils::AddIsolatedTagIfUnique(
	TArray<FPlutoGameplayTagDescriptor>& OutTags,
	const FString& TagPath,
	const FGameplayTag& GameplayTag)
{
	if (!GameplayTag.IsValid())
	{
		return;
	}

	for (const FPlutoGameplayTagDescriptor& ExistingTag : OutTags)
	{
		if (ExistingTag.TagPath == TagPath && ExistingTag.GameplayTag == GameplayTag)
		{
			return;
		}
	}

	FPlutoGameplayTagDescriptor NewTag;
	NewTag.TagPath = TagPath;
	NewTag.GameplayTag = GameplayTag;
	OutTags.Add(MoveTemp(NewTag));
}
