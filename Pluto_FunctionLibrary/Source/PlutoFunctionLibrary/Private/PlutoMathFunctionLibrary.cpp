#include "PlutoMathFunctionLibrary.h"

#include <cmath>

namespace
{
	// Scale before normalizing so direction is independent of the vector's magnitude,
	// including very small inputs and inputs whose unscaled squared length would overflow.
	FVector NormalizeFiniteDirection(const FVector& Vector)
	{
		const double LargestComponent = FMath::Max3(FMath::Abs(Vector.X), FMath::Abs(Vector.Y), FMath::Abs(Vector.Z));
		if (LargestComponent == 0.0)
		{
			return FVector::ZeroVector;
		}
		const FVector Scaled(Vector.X / LargestComponent, Vector.Y / LargestComponent, Vector.Z / LargestComponent);
		return Scaled.GetSafeNormal();
	}
}

void UPlutoMathFunctionLibrary::PF_DecomposeVector2DWithDeadZone(
	const FVector2D& InputVector, double DeadZone, FVector2D& Direction, double& Magnitude)
{
	// Cache first so a native caller may reuse InputVector as the Direction output.
	const FVector2D Input = InputVector;
	Direction = FVector2D::ZeroVector;
	Magnitude = 0.0;
	if (!FMath::IsFinite(Input.X) || !FMath::IsFinite(Input.Y) || !FMath::IsFinite(DeadZone))
	{
		return;
	}

	const double Length = std::hypot(Input.X, Input.Y);
	if (!FMath::IsFinite(Length) || Length <= FMath::Max(0.0, DeadZone))
	{
		return;
	}

	Direction = FVector2D(Input.X / Length, Input.Y / Length);
	Magnitude = Length;
}

double UPlutoMathFunctionLibrary::PF_CalculateDirectionalAttenuation(
	const FVector& Direction, const FVector& ReferenceDirection, double AttenuationStrength, double MinimumMultiplier)
{
	if (Direction.ContainsNaN() || ReferenceDirection.ContainsNaN()
		|| !FMath::IsFinite(AttenuationStrength) || !FMath::IsFinite(MinimumMultiplier))
	{
		return 1.0;
	}

	const FVector UnitDirection = NormalizeFiniteDirection(Direction);
	const FVector UnitReference = NormalizeFiniteDirection(ReferenceDirection);
	if (UnitDirection.IsZero() || UnitReference.IsZero())
	{
		return 1.0;
	}

	const double OpposingAmount = FMath::Clamp(-FVector::DotProduct(UnitDirection, UnitReference), 0.0, 1.0);
	const double Strength = FMath::Clamp(AttenuationStrength, 0.0, 1.0);
	const double Minimum = FMath::Clamp(MinimumMultiplier, 0.0, 1.0);
	return FMath::Clamp(1.0 - OpposingAmount * Strength, Minimum, 1.0);
}

double UPlutoMathFunctionLibrary::PF_AdvanceFloatClamped(
	double CurrentValue, double RatePerSecond, double DeltaSeconds, double MinValue, double MaxValue)
{
	return FMath::Clamp(CurrentValue + RatePerSecond * DeltaSeconds, MinValue, MaxValue);
}

void UPlutoMathFunctionLibrary::PF_ScaleFloatByRatios(
	double BaseValue, const TArray<double>& Ratios, TArray<double>& Values)
{
	// A local result also permits native callers to use the same array for input and output.
	TArray<double> Result;
	Result.Reserve(Ratios.Num());
	for (const double Ratio : Ratios)
	{
		Result.Add(BaseValue * Ratio);
	}
	Values = MoveTemp(Result);
}
