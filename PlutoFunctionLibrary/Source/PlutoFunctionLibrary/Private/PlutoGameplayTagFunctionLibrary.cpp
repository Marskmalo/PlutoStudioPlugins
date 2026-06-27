#include "PlutoGameplayTagFunctionLibrary.h"

namespace
{
	bool PlutoContainerHasTag(
		const FGameplayTagContainer& Container,
		const FGameplayTag& Tag,
		const bool bExactMatch)
	{
		return bExactMatch ? Container.HasTagExact(Tag) : Container.HasTag(Tag);
	}
}

bool UPlutoGameplayTagFunctionLibrary::PF_BatchAddGameplayTags(
	FGameplayTagContainer& TargetContainer,
	FGameplayTagContainer TagsToAdd)
{
	const int32 InitialCount = TargetContainer.Num();
	TargetContainer.AppendTags(TagsToAdd);
	return TargetContainer.Num() != InitialCount;
}

bool UPlutoGameplayTagFunctionLibrary::PF_BatchRemoveGameplayTags(
	FGameplayTagContainer& TargetContainer,
	FGameplayTagContainer TagsToRemove)
{
	bool bChanged = false;

	for (const FGameplayTag& GameplayTag : TagsToRemove)
	{
		bChanged |= TargetContainer.RemoveTag(GameplayTag);
	}

	return bChanged;
}

bool UPlutoGameplayTagFunctionLibrary::PF_ClearGameplayTagContainer(FGameplayTagContainer& TargetContainer)
{
	const bool bHadTags = !TargetContainer.IsEmpty();
	TargetContainer.Reset();
	return bHadTags;
}

bool UPlutoGameplayTagFunctionLibrary::PF_HasAnyGameplayTags(
	const FGameplayTagContainer& TargetContainer,
	FGameplayTagContainer QueryContainer)
{
	return TargetContainer.HasAny(QueryContainer);
}

bool UPlutoGameplayTagFunctionLibrary::PF_HasAllGameplayTags(
	const FGameplayTagContainer& TargetContainer,
	FGameplayTagContainer QueryContainer)
{
	return TargetContainer.HasAll(QueryContainer);
}

bool UPlutoGameplayTagFunctionLibrary::PF_DetectGameplayTagChanged(
	const FGameplayTagContainer& Container,
	FGameplayTag Tag,
	EPlutoGameplayTagListeningPolicy Policy,
	FGameplayTagContainer& LastContainerSnapshot,
	FGameplayTag& ChangedTag,
	bool& bHasInitialized,
	bool bExactMatch,
	bool bIgnoreFirstFrame)
{
	ChangedTag = FGameplayTag();

	const bool bIsFirstFrame = !bHasInitialized;
	const bool bShouldSkipComparison = bIsFirstFrame && bIgnoreFirstFrame;

	bool bDetected = false;

	if (!bShouldSkipComparison)
	{
		switch (Policy)
		{
		case EPlutoGameplayTagListeningPolicy::Added:
		{
			const bool bHasCurrentTag = PlutoContainerHasTag(Container, Tag, bExactMatch);
			const bool bHadPreviousTag = PlutoContainerHasTag(LastContainerSnapshot, Tag, bExactMatch);

			if (bHasCurrentTag && !bHadPreviousTag)
			{
				ChangedTag = Tag;
				bDetected = true;
			}
			break;
		}

		case EPlutoGameplayTagListeningPolicy::Removed:
		{
			const bool bHasCurrentTag = PlutoContainerHasTag(Container, Tag, bExactMatch);
			const bool bHadPreviousTag = PlutoContainerHasTag(LastContainerSnapshot, Tag, bExactMatch);

			if (!bHasCurrentTag && bHadPreviousTag)
			{
				ChangedTag = Tag;
				bDetected = true;
			}
			break;
		}

		case EPlutoGameplayTagListeningPolicy::AddedOrRemoved:
		{
			const bool bHasCurrentTag = PlutoContainerHasTag(Container, Tag, bExactMatch);
			const bool bHadPreviousTag = PlutoContainerHasTag(LastContainerSnapshot, Tag, bExactMatch);

			if (bHasCurrentTag != bHadPreviousTag)
			{
				ChangedTag = Tag;
				bDetected = true;
			}
			break;
		}

		case EPlutoGameplayTagListeningPolicy::AnyCountChange:
			bDetected = Container != LastContainerSnapshot;
			break;

		default:
			break;
		}
	}

	LastContainerSnapshot = Container;
	bHasInitialized = true;
	return bDetected;
}
