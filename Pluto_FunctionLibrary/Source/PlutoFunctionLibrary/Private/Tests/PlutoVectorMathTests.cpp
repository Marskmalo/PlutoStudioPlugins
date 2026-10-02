#include "PlutoMathFunctionLibrary.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"
#include "UObject/UnrealType.h"
#include <limits>

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoDecomposeVector2DValuesTest,
	"Pluto.FunctionLibrary.Math.DecomposeVector2DWithDeadZone.Values",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPlutoDecomposeVector2DValuesTest::RunTest(const FString& Parameters)
{
	FVector2D Direction;
	double Magnitude = -1.0;
	const auto Check = [&](const TCHAR* Label, FVector2D Input, double DeadZone, FVector2D ExpectedDirection, double ExpectedMagnitude)
	{
		Direction = FVector2D(99.0, 99.0);
		Magnitude = 99.0;
		UPlutoMathFunctionLibrary::PF_DecomposeVector2DWithDeadZone(Input, DeadZone, Direction, Magnitude);
		TestTrue(FString(Label) + TEXT(" direction"), Direction.Equals(ExpectedDirection, 1e-12));
		TestTrue(FString(Label) + TEXT(" magnitude"), FMath::IsNearlyEqual(Magnitude, ExpectedMagnitude, 1e-12));
	};
	Check(TEXT("Preview example"), FVector2D(0.3, 0.4), 0.1, FVector2D(0.6, 0.8), 0.5);
	Check(TEXT("Inside radial dead zone"), FVector2D(0.03, 0.04), 0.1, FVector2D::ZeroVector, 0.0);
	Check(TEXT("Boundary is zero"), FVector2D(3, 4), 5, FVector2D::ZeroVector, 0.0);
	Check(TEXT("Outside preserves length, no remap"), FVector2D(3, 4), 4.99, FVector2D(0.6, 0.8), 5.0);
	Check(TEXT("Both axes below threshold but radial length above"), FVector2D(0.3, 0.4), 0.45, FVector2D(0.6, 0.8), 0.5);
	Check(TEXT("Zero input and zero dead zone"), FVector2D::ZeroVector, 0, FVector2D::ZeroVector, 0.0);
	Check(TEXT("Negative dead zone is zero"), FVector2D(-3, 4), -2, FVector2D(-0.6, 0.8), 5.0);
	Check(TEXT("Negative axes"), FVector2D(-3, -4), 0, FVector2D(-0.6, -0.8), 5.0);
	Check(TEXT("No hidden small-value dead zone"), FVector2D(1e-100, 0), 0, FVector2D(1, 0), 1e-100);
	Check(TEXT("Non-finite component"), FVector2D(std::numeric_limits<double>::infinity(), 0), 0, FVector2D::ZeroVector, 0);
	Check(TEXT("NaN component"), FVector2D(0, std::numeric_limits<double>::quiet_NaN()), 0, FVector2D::ZeroVector, 0);
	Check(TEXT("Non-finite dead zone"), FVector2D(3, 4), std::numeric_limits<double>::quiet_NaN(), FVector2D::ZeroVector, 0);
	Check(TEXT("Unrepresentable length"), FVector2D(std::numeric_limits<double>::max(), std::numeric_limits<double>::max()), 0, FVector2D::ZeroVector, 0);
	FVector2D Aliased(3, 4);
	UPlutoMathFunctionLibrary::PF_DecomposeVector2DWithDeadZone(Aliased, 0, Aliased, Magnitude);
	TestTrue(TEXT("Native input/output alias"), Aliased.Equals(FVector2D(0.6, 0.8), 1e-12));
	TestEqual(TEXT("Native alias preserves length"), Magnitude, 5.0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoDirectionalAttenuationValuesTest,
	"Pluto.FunctionLibrary.Math.CalculateDirectionalAttenuation.Values",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPlutoDirectionalAttenuationValuesTest::RunTest(const FString& Parameters)
{
	const auto Attenuate = &UPlutoMathFunctionLibrary::PF_CalculateDirectionalAttenuation;
	const FVector Reference(1, 0, 0);
	TestEqual(TEXT("Same direction"), Attenuate(Reference, Reference, 0.6, 0.3), 1.0);
	TestEqual(TEXT("Perpendicular"), Attenuate(FVector(0, 1, 0), Reference, 0.6, 0.3), 1.0);
	TestEqual(TEXT("Toward half-plane"), Attenuate(FVector(1, 1, 0), Reference, 0.6, 0.3), 1.0);
	TestTrue(TEXT("Opposite preview example"), FMath::IsNearlyEqual(Attenuate(-Reference, Reference, 0.6, 0.3), 0.4, 1e-12));
	TestTrue(TEXT("Diagonal opposition"), FMath::IsNearlyEqual(Attenuate(FVector(-1, 1, 0), Reference, 0.6, 0.3), 1.0 - 0.6 / FMath::Sqrt(2.0), 1e-12));
	TestEqual(TEXT("Minimum multiplier"), Attenuate(-Reference, Reference, 1, 0.3), 0.3);
	TestEqual(TEXT("Full suppression allowed"), Attenuate(-Reference, Reference, 1, 0), 0.0);
	TestEqual(TEXT("Zero strength"), Attenuate(-Reference, Reference, 0, 0), 1.0);
	TestEqual(TEXT("Zero direction"), Attenuate(FVector::ZeroVector, Reference, 1, 0), 1.0);
	TestEqual(TEXT("Zero reference"), Attenuate(Reference, FVector::ZeroVector, 1, 0), 1.0);
	TestEqual(TEXT("Strength above range clamped"), Attenuate(-Reference, Reference, 2, 0), 0.0);
	TestEqual(TEXT("Negative strength clamped"), Attenuate(-Reference, Reference, -1, 0), 1.0);
	TestEqual(TEXT("Minimum above range clamped"), Attenuate(-Reference, Reference, 1, 2), 1.0);
	TestEqual(TEXT("Negative minimum clamped"), Attenuate(-Reference, Reference, 1, -1), 0.0);
	TestEqual(TEXT("Not implicitly flattened"), Attenuate(FVector(0, 0, -10), FVector(0, 0, 20), 1, 0), 0.0);
	TestEqual(TEXT("Invalid vector returns neutral"), Attenuate(FVector(std::numeric_limits<double>::infinity(), 0, 0), Reference, 1, 0), 1.0);
	TestEqual(TEXT("Invalid strength returns neutral"), Attenuate(-Reference, Reference, std::numeric_limits<double>::quiet_NaN(), 0), 1.0);
	TestEqual(TEXT("Invalid minimum returns neutral"), Attenuate(-Reference, Reference, 1, std::numeric_limits<double>::infinity()), 1.0);
	for (double Scale : {1e-100, 1.0, 1e100})
	{
		TestTrue(TEXT("Magnitude independent"), FMath::IsNearlyEqual(Attenuate(FVector(-Scale, 0, 0), FVector(2 * Scale, 0, 0), 0.6, 0.3), 0.4, 1e-12));
	}
	for (int32 Angle = -180; Angle <= 180; Angle += 5)
	{
		const double Radians = FMath::DegreesToRadians(double(Angle));
		const FVector Direction(FMath::Cos(Radians), FMath::Sin(Radians), 0);
		const double Multiplier = Attenuate(Direction, Reference, 0.8, 0.25);
		TestTrue(TEXT("Output bounded"), Multiplier >= 0.25 && Multiplier <= 1.0);
		TestTrue(TEXT("Rotation invariant"), FMath::IsNearlyEqual(Multiplier,
			Attenuate(FVector(-Direction.Y, Direction.X, 0), FVector(0, 1, 0), 0.8, 0.25), 1e-12));
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoVectorMathMetadataTest,
	"Pluto.FunctionLibrary.Math.VectorBricks.Metadata",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPlutoVectorMathMetadataTest::RunTest(const FString& Parameters)
{
	const UFunction* Decompose = UPlutoMathFunctionLibrary::StaticClass()->FindFunctionByName(
		GET_FUNCTION_NAME_CHECKED(UPlutoMathFunctionLibrary, PF_DecomposeVector2DWithDeadZone));
	const UFunction* Attenuate = UPlutoMathFunctionLibrary::StaticClass()->FindFunctionByName(
		GET_FUNCTION_NAME_CHECKED(UPlutoMathFunctionLibrary, PF_CalculateDirectionalAttenuation));
	if (!TestNotNull(TEXT("Decompose registered"), Decompose) || !TestNotNull(TEXT("Attenuate registered"), Attenuate)) return false;
	TestEqual(TEXT("Decompose: two inputs, two outputs"), int32(Decompose->NumParms), 4);
	TestEqual(TEXT("Attenuate: four inputs, one return"), int32(Attenuate->NumParms), 5);
	for (const UFunction* Function : {Decompose, Attenuate})
	{
		TestTrue(TEXT("Stateless pure calculation"), Function->HasAnyFunctionFlags(FUNC_BlueprintPure));
#if WITH_METADATA
		TestEqual(TEXT("Existing math category"), Function->GetMetaData(TEXT("Category")), FString(TEXT("Pluto Function Library|Math")));
		const FString Tooltip = Function->GetMetaData(TEXT("ToolTip"));
		TestTrue(TEXT("Chinese node tooltip"), Tooltip.Contains(TEXT("方向")) && Tooltip.Contains(TEXT("\n")));
#endif
		for (TFieldIterator<FProperty> It(Function); It; ++It)
		{
			if (!It->HasAnyPropertyFlags(CPF_Parm)) continue;
#if WITH_METADATA
			const FString Marker = It->HasAnyPropertyFlags(CPF_ReturnParm) ? TEXT("@return ") : FString(TEXT("@param ")) + It->GetName() + TEXT(" ");
			TestTrue(FString(TEXT("Pin tooltip: ")) + It->GetName(), Tooltip.Contains(Marker));
#endif
			TestFalse(TEXT("No mutable reference input"), It->HasAnyPropertyFlags(CPF_ReferenceParm) && !It->HasAnyPropertyFlags(CPF_ConstParm));
		}
	}
	const FStructProperty* Input = FindFProperty<FStructProperty>(Decompose, TEXT("InputVector"));
	const FStructProperty* Direction = FindFProperty<FStructProperty>(Decompose, TEXT("Direction"));
	const FDoubleProperty* Magnitude = FindFProperty<FDoubleProperty>(Decompose, TEXT("Magnitude"));
	if (TestNotNull(TEXT("Input vector pin"), Input)) TestTrue(TEXT("Explicit Vector2D input"), Input->Struct == TBaseStructure<FVector2D>::Get());
	if (TestNotNull(TEXT("Direction pin"), Direction))
	{
		TestTrue(TEXT("Explicit Vector2D output"), Direction->Struct == TBaseStructure<FVector2D>::Get());
		TestTrue(TEXT("Direction is output"), Direction->HasAnyPropertyFlags(CPF_OutParm));
	}
	if (TestNotNull(TEXT("Magnitude pin"), Magnitude)) TestTrue(TEXT("Magnitude is output"), Magnitude->HasAnyPropertyFlags(CPF_OutParm));
	return true;
}

#endif
