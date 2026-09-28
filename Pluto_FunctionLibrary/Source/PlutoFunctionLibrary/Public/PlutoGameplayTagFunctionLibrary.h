#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlutoGameplayTagFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum class EPlutoGameplayTagListeningPolicy : uint8
{
	Added UMETA(DisplayName = "Added / 新增",
		ToolTip = "Fires when the specified Tag is added to the Container.\n仅当指定 Tag 被新增至容器时触发。"),

	Removed UMETA(DisplayName = "Removed / 移除",
		ToolTip = "Fires when the specified Tag is removed from the Container.\n仅当指定 Tag 被从容器移除时触发。"),

	AddedOrRemoved UMETA(DisplayName = "Added or Removed / 新增或移除",
		ToolTip = "Fires when the specified Tag is either added to or removed from the Container.\n仅当指定 Tag 被新增至容器或从容器移除时才会发生事件。"),

	AnyCountChange UMETA(DisplayName = "Any Count Change / 任何计数变更",
		ToolTip = "Fires whenever the Container content changes. The Tag pin is ignored in this mode.\n只要容器内容发生变化就触发，此模式下 Tag 引脚将被忽略。")
};

UCLASS()
class PLUTOFUNCTIONLIBRARY_API UPlutoGameplayTagFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Pluto Function Library|GameplayTag", meta = (DisplayName = "PF_BatchAddGameplayTags", ToolTip = "Add every tag from the source container into the target container.\n把来源容器中的全部 Tag 批量添加到目标容器。"))
	static bool PF_BatchAddGameplayTags(UPARAM(ref) FGameplayTagContainer& TargetContainer, FGameplayTagContainer TagsToAdd);

	UFUNCTION(BlueprintCallable, Category = "Pluto Function Library|GameplayTag", meta = (DisplayName = "PF_BatchRemoveGameplayTags", ToolTip = "Remove every matching tag from the target container.\n从目标容器中批量移除所有匹配的 Tag。"))
	static bool PF_BatchRemoveGameplayTags(UPARAM(ref) FGameplayTagContainer& TargetContainer, FGameplayTagContainer TagsToRemove);

	UFUNCTION(BlueprintCallable, Category = "Pluto Function Library|GameplayTag", meta = (DisplayName = "PF_ClearGameplayTagContainer", ToolTip = "Clear every tag from the target container.\n清空目标容器中的全部 Tag。"))
	static bool PF_ClearGameplayTagContainer(UPARAM(ref) FGameplayTagContainer& TargetContainer);

	UFUNCTION(BlueprintPure, Category = "Pluto Function Library|GameplayTag", meta = (DisplayName = "PF_HasAnyGameplayTags", ToolTip = "Return true when the target container contains any tag from the query container.\n当目标容器包含查询容器中的任意 Tag 时返回真。"))
	static bool PF_HasAnyGameplayTags(const FGameplayTagContainer& TargetContainer, FGameplayTagContainer QueryContainer);

	UFUNCTION(BlueprintPure, Category = "Pluto Function Library|GameplayTag", meta = (DisplayName = "PF_HasAllGameplayTags", ToolTip = "Return true when the target container contains every tag from the query container.\n当目标容器包含查询容器中的全部 Tag 时返回真。"))
	static bool PF_HasAllGameplayTags(const FGameplayTagContainer& TargetContainer, FGameplayTagContainer QueryContainer);

	UFUNCTION(BlueprintCallable, Category = "Pluto Function Library|GameplayTag", meta = (DisplayName = "PF_DetectGameplayTagChanged", ToolTip = "Detect whether a specified Tag change occurred in the Container this frame by comparing it against a snapshot of the previous frame. The caller must store LastContainerSnapshot and bHasInitialized as member variables; the function updates them automatically before returning. When bExactMatch is true, exact tag matching is used. When false, hierarchical matching is used, so querying a parent Tag also matches its child Tags.\n通过与上一帧快照比较，检测本帧 Container 中是否发生了指定类型的 Tag 变化。调用方需将 LastContainerSnapshot 和 bHasInitialized 存为成员变量，函数会在返回前自动更新它们。当 bExactMatch 为 true 时使用精确匹配；为 false 时使用层级匹配，此时父级 Tag 查询也会匹配其子级 Tag。"))
	static bool PF_DetectGameplayTagChanged(
		const FGameplayTagContainer& Container,
		FGameplayTag Tag,
		EPlutoGameplayTagListeningPolicy Policy,
		UPARAM(ref) FGameplayTagContainer& LastContainerSnapshot,
		FGameplayTag& ChangedTag,
		UPARAM(ref) bool& bHasInitialized,
		bool bExactMatch = true,
		bool bIgnoreFirstFrame = false);
};
