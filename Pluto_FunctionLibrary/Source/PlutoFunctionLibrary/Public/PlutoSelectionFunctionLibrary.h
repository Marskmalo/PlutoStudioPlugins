#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlutoSelectionFunctionLibrary.generated.h"

/** 每组 A/B 判断独立保存的历史快照；保留原生类型名以兼容已保存的蓝图变量。 */
USTRUCT(BlueprintType, meta = (DisplayName = "PF Latest Activated Pair Snapshot",
	ToolTip = "供选择节点自动记住上次 A/B 的有效情况与主导结果。\n创建此类型的蓝图成员变量，保留默认值并连接 Snapshot；不要使用函数局部变量。\n节点自动更新快照，不用填写内部字段或另接 Set；另一组判断另建一份，需要重新开始时才重置。"))
struct PLUTOFUNCTIONLIBRARY_API FPlutoLatestActivatedPairState
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Selection",
		meta = (ToolTip = "上次调用时 A 是否有效，由选择节点自动记录；不是 A 是否主导。"))
	bool bPreviousAActive = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Selection",
		meta = (ToolTip = "上次调用时 B 是否有效，由选择节点自动记录；不是 B 是否主导。"))
	bool bPreviousBActive = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Selection",
		meta = (ToolTip = "上次是否由 A 主导。False 可能表示 B 主导或双方均无效；由节点结合上次有效状态解释。"))
	bool bPreviousADominant = false;
};

UCLASS()
class PLUTOFUNCTIONLIBRARY_API UPlutoSelectionFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Pluto Function Library|Selection",
		meta = (DisplayName = "PF_ResolveLatestActivatedPair",
			Keywords = "最近 激活 主导 优先 条件 选择 latest activated priority bool",
			AdvancedDisplay = "bPreferAOnSimultaneousActivation",
			ToolTip = "选择 A、B 中最近从 False 变为 True 的一方。\n双方持续有效时保持主导；主导方失效时交给仍有效的一方；都无效时均输出 False。\n本节点自动更新传入的历史快照，不修改当前条件，不处理 Tag 或执行玩法。\n@param bAActive A 当前是否有效；True 表示条件成立，不是仅在刚激活时传入 True。\n@param bBActive B 当前是否有效；True 表示条件成立，允许与 A 同时为 True。\n@param Snapshot 在此蓝图中新建这个类型的成员变量，保留默认值并连接到这里；不要使用函数局部变量。\n节点会自动更新历史快照，不用填写内部字段，也不用另接 Set。\n另一组独立判断另建一份；需要清除记忆、重新开始时才重置为默认值。\n@param bADominant True 表示本次由 A 主导；不代表只有 A 有效。与 B 主导互斥，双方无效时为 False。\n@param bBDominant True 表示本次由 B 主导；不代表只有 B 有效。与 A 主导互斥，双方无效时为 False。\n@param bPreferAOnSimultaneousActivation 同一次调用中双方都从 False 变为 True 时，True 优先 A，False 优先 B。默认 True；不改变双方持续有效时的主导。"))
	static void PF_ResolveLatestActivatedPair(
		bool bAActive,
		bool bBActive,
		UPARAM(ref) FPlutoLatestActivatedPairState& Snapshot,
		bool& bADominant,
		bool& bBDominant,
		bool bPreferAOnSimultaneousActivation = true);
};
