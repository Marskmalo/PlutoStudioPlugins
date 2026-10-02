#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlutoMathFunctionLibrary.generated.h"

/** 不依赖项目玩法的数值计算。 */
UCLASS()
class PLUTOFUNCTIONLIBRARY_API UPlutoMathFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Pluto Function Library|Math",
		meta = (DisplayName = "PF_DecomposeVector2DWithDeadZone",
			Keywords = "二维 向量 分解 方向 长度 强度 径向 死区 手柄 vector direction magnitude radial deadzone",
			ToolTip = "将二维向量拆成单位方向与强度，并过滤径向死区。\n长度小于或等于死区时，方向和强度都为 0；超过死区时保留原长度，不重映射、不限制到 1。\n适合整理摇杆或合成后的二维意图；只计算，不读取设备、不修改变量，也不需要快照。\n@param InputVector 要分解的二维向量，X/Y 分量须使用同一单位。\n若来自三维向量，请由调用方明确选择平面；本节点不处理 Z。\n@param DeadZone 死区半径，与输入向量长度使用同一单位；边界也归零。\n0 只过滤零向量，负值按 0 处理；这不是分别过滤 X/Y 的轴向死区。\n@param Direction 通过死区时返回长度为 1 的二维方向；否则为零向量。\n方向不包含原强度，需要完整结果时与 Magnitude 相乘。\n@param Magnitude 通过死区时返回输入原长度；否则为 0。\n不会把死区外的强度重映射到 0～1，也不会截断大于 1 的长度。\n输入含 NaN/无穷大、死区非有限，或长度超出双精度可表示范围时，两项输出均为 0。"))
	static void PF_DecomposeVector2DWithDeadZone(const FVector2D& InputVector, double DeadZone,
		FVector2D& Direction, double& Magnitude);

	UFUNCTION(BlueprintPure, Category = "Pluto Function Library|Math",
		meta = (DisplayName = "PF_CalculateDirectionalAttenuation",
			Keywords = "方向 相对 背离 反向 衰减 倍率 阻力 directional attenuation opposite backward",
			ToolTip = "根据两个方向的背离程度计算衰减倍率：同向或垂直不衰减，越反向衰减越强。\n只输出倍率，不修改方向、不移动对象；调用方决定将倍率乘到哪个数值上。\n参考方向由你提供，不默认代表角色朝向；不读取角色、Tag 或其他项目状态，也不需要快照。\n@param Direction 要判断的方向向量，不需要预先归一化；长度不影响结果。\n与 Reference Direction 使用同一坐标空间；需要水平判断时，由调用方先将两个向量的 Z 设为 0。\n@param ReferenceDirection 作为正向基准的方向，不需要预先归一化。\n例如角色前方、水流方向或朝向目标的方向；背离它时才产生衰减。\n@param AttenuationStrength 衰减强度，限制在 0～1：0 不影响，1 可完全抑制正反向情况。\n完全背离时未限幅倍率为 1 减此值；斜向背离按反向点积的大小线性减弱。\n@param MinimumMultiplier 最低允许倍率，限制在 0～1；例如 0.3 表示至少保留 30%。\n它限制返回倍率，不是方向夹角阈值，也不决定何时启用此能力。\n@return 衰减倍率，位于 Minimum Multiplier（限制到 0～1 后）与 1 之间。\n同向或垂直返回 1；任一方向为零、任一输入非有限时也返回 1（不衰减）。\n这是整体强度倍率，不是只削弱向量中的反向分量。"))
	static double PF_CalculateDirectionalAttenuation(const FVector& Direction, const FVector& ReferenceDirection,
		double AttenuationStrength = 1.0, double MinimumMultiplier = 0.0);

	UFUNCTION(BlueprintPure, Category = "Pluto Function Library|Math",
		meta = (DisplayName = "PF_AdvanceFloatClamped",
			Keywords = "数值 匀速 增加 减少 限制 范围 rate advance float clamp",
			ToolTip = "让数值按每秒速率增加或减少，并把结果限制在指定范围内。\n计算：Clamp(Current Value + Rate Per Second × Delta Seconds, Min Value, Max Value)。\n适合体力增减、蓄力、冷却或长度收放；只计算，不自动计时或修改变量，也不需要快照。\n需要持续变化时，每次调用后把返回值 Set 回当前值变量，下次再传入更新后的值。\n所有输入须为有限数值，时间须非负，下限须不大于上限；不修复无效输入或计算溢出。\n@param CurrentValue 本次变化前的数值，例如当前体力、蓄力值或长度。\n节点不会修改它；需要累计变化时，请自行将返回值写回对应变量。\n@param RatePerSecond 每秒变化多少：正数增加，负数减少，0 不推进。\n例如 -20 表示每秒减少 20；单位与 Current Value 一致。\n@param DeltaSeconds 本次要推进的时间，单位为秒，须大于或等于 0。\n每帧使用时接 Tick 的 Delta Seconds；定时调用时传本次实际经过的时间。\n@param MinValue 允许的最小结果，须小于或等于 Max Value。\n计算结果低于此值时返回此值；上下限相等时结果固定为该值。\n@param MaxValue 允许的最大结果，须大于或等于 Min Value。\n计算结果高于此值时返回此值；即使速率或时间为 0，结果仍会限制在范围内。\n@return 本次计算后的新数值，位于 Min Value 到 Max Value 之间（包含边界）。\n先增加 Rate Per Second × Delta Seconds，再限制范围；不会先把 Current Value 截断，也不会自动写回。"))
	static double PF_AdvanceFloatClamped(double CurrentValue, double RatePerSecond, double DeltaSeconds,
		double MinValue = 0.0, double MaxValue = 1.0);

	UFUNCTION(BlueprintPure, Category = "Pluto Function Library|Math",
		meta = (DisplayName = "PF_ScaleFloatByRatios",
			Keywords = "比例 批量 数值 阈值 分段 scale float ratios thresholds",
			AutoCreateRefTerm = "Ratios",
			ToolTip = "把一个数值分别乘以一组比例，得到同样数量的结果。\n例如：1000 配合 [0.25, 0.75, 0.9]，得到 [250, 750, 900]。\n用 Make Array 填比例，添加元素就增加一个结果；不需要创建快照变量。\n不排序、不限制比例、不按总和归一化；只计算数值，不判断阶段或修改状态。\n@param BaseValue 用来乘比例的基准数值，例如总长度、时长或容量。\n传 1000 并配合 0.25，即得到 250；允许零和负数。\n@param Ratios 从这里拉线创建 Make Array，逐项填写比例；0.25 表示 25%，1 表示 100%。\n填几项就输出几项；允许重复、负数和大于 1 的比例，不要求总和等于 1。\n留空返回空数组。请使用有限数值，节点不修复 NaN、无穷大或计算溢出。\n@param Values 每项等于 Base Value 乘以同位置的比例，数量和顺序与 Ratios 一致。\n使用 Get（索引从 0 开始）取某一项，或 For Each Loop 逐项使用；比例为空时结果也为空。\n这些是独立乘法结果，不是自动分配后加起来等于总量的每段长度。"))
	static void PF_ScaleFloatByRatios(double BaseValue, const TArray<double>& Ratios, TArray<double>& Values);
};
