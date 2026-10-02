#include "PlutoMathFunctionLibrary.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"
#include "UObject/UnrealType.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoAdvanceFloatClampedValuesTest,
	"Pluto.FunctionLibrary.Math.AdvanceFloatClamped.Values",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPlutoAdvanceFloatClampedValuesTest::RunTest(const FString& Parameters)
{
	const auto Advance = &UPlutoMathFunctionLibrary::PF_AdvanceFloatClamped;
	TestEqual(TEXT("Positive rate increases per second"), Advance(40, 20, 0.5, 0, 100), 50.0);
	TestEqual(TEXT("Negative rate decreases per second"), Advance(40, -20, 0.5, 0, 100), 30.0);
	TestEqual(TEXT("Clamp upper overshoot"), Advance(90, 20, 1, 0, 100), 100.0);
	TestEqual(TEXT("Clamp lower overshoot"), Advance(10, -20, 1, 0, 100), 0.0);
	TestEqual(TEXT("Reach exact upper bound"), Advance(80, 20, 1, 0, 100), 100.0);
	TestEqual(TEXT("Reach exact lower bound"), Advance(20, -20, 1, 0, 100), 0.0);
	TestEqual(TEXT("Reverse away from upper bound"), Advance(100, -20, 1, 0, 100), 80.0);
	TestEqual(TEXT("Reverse away from lower bound"), Advance(0, 20, 1, 0, 100), 20.0);
	TestEqual(TEXT("Zero time preserves in-range value"), Advance(40, 20, 0, 0, 100), 40.0);
	TestEqual(TEXT("Zero rate preserves in-range value"), Advance(40, 0, 1, 0, 100), 40.0);
	TestEqual(TEXT("Zero time still clamps"), Advance(120, -20, 0, 0, 100), 100.0);
	TestEqual(TEXT("Zero rate still clamps"), Advance(-20, 0, 1, 0, 100), 0.0);
	TestEqual(TEXT("Advance before clamp, not pre-clamp"), Advance(120, -30, 1, 0, 100), 90.0);
	TestEqual(TEXT("Below range advances before clamp"), Advance(-20, 30, 1, 0, 100), 10.0);
	TestEqual(TEXT("Equal bounds fix result"), Advance(40, -20, 10, 7, 7), 7.0);
	TestEqual(TEXT("Negative interval supported"), Advance(-50, -10, 1, -100, -20), -60.0);
	TestEqual(TEXT("Large time saturates"), Advance(40, 20, 10000, 0, 100), 100.0);
	double Value = 0;
	for (int32 Step = 0; Step < 4; ++Step) Value = Advance(Value, 0.5, 0.5, 0, 1);
	TestEqual(TEXT("Caller writeback accumulates over calls"), Value, 1.0);
	TestEqual(TEXT("Partitioned constant-rate time agrees"), Value, Advance(0, 0.5, 2, 0, 1));
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoAdvanceFloatClampedMetadataTest,
	"Pluto.FunctionLibrary.Math.AdvanceFloatClamped.Metadata",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPlutoAdvanceFloatClampedMetadataTest::RunTest(const FString& Parameters)
{
	const UFunction* Function = UPlutoMathFunctionLibrary::StaticClass()->FindFunctionByName(
		GET_FUNCTION_NAME_CHECKED(UPlutoMathFunctionLibrary, PF_AdvanceFloatClamped));
	if (!TestNotNull(TEXT("Blueprint function registered"), Function)) return false;
	TestTrue(TEXT("Calculation is pure"), Function->HasAnyFunctionFlags(FUNC_BlueprintPure));
	TestEqual(TEXT("Five inputs and one return, no hidden snapshot"), int32(Function->NumParms), 6);
	for (const TCHAR* Pin : {TEXT("CurrentValue"), TEXT("RatePerSecond"), TEXT("DeltaSeconds"), TEXT("MinValue"), TEXT("MaxValue")})
	{
		const FDoubleProperty* Property = FindFProperty<FDoubleProperty>(Function, Pin);
		if (TestNotNull(FString(TEXT("Double input: ")) + Pin, Property))
			TestFalse(TEXT("Inputs are not modified by reference"), Property->HasAnyPropertyFlags(CPF_OutParm | CPF_ReferenceParm));
#if WITH_METADATA
		TestTrue(FString(TEXT("Chinese pin documentation: ")) + Pin,
			Function->GetMetaData(TEXT("ToolTip")).Contains(FString(TEXT("@param ")) + Pin + TEXT(" ")));
#endif
	}
	const FDoubleProperty* Result = FindFProperty<FDoubleProperty>(Function, TEXT("ReturnValue"));
	if (TestNotNull(TEXT("Double return"), Result))
		TestTrue(TEXT("Return flag"), Result->HasAnyPropertyFlags(CPF_ReturnParm));
#if WITH_METADATA
	TestEqual(TEXT("Existing math category"), Function->GetMetaData(TEXT("Category")), FString(TEXT("Pluto Function Library|Math")));
	TestTrue(TEXT("Chinese result documentation"), Function->GetMetaData(TEXT("ToolTip")).Contains(TEXT("@return 本次计算后的新数值")));
#endif
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoScaleFloatByRatiosValuesTest,
	"Pluto.FunctionLibrary.Math.ScaleFloatByRatios.Values",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPlutoScaleFloatByRatiosValuesTest::RunTest(const FString& Parameters)
{
	const TArray<double> Ratios = {0.25, 0.75, 0.9};
	TArray<double> Values;
	UPlutoMathFunctionLibrary::PF_ScaleFloatByRatios(1000.0, Ratios, Values);
	TestTrue(TEXT("Example returns ratio positions, not normalized portions"),
		Values == TArray<double>({250.0, 750.0, 900.0}));
	TestTrue(TEXT("Input remains unchanged"), Ratios == TArray<double>({0.25, 0.75, 0.9}));

	UPlutoMathFunctionLibrary::PF_ScaleFloatByRatios(8.0, {1.5, -0.5, 0.0, 1.0, 0.25, 0.25}, Values);
	TestTrue(TEXT("Preserve count, order, duplicates and unrestricted ratios"),
		Values == TArray<double>({12.0, -4.0, 0.0, 8.0, 2.0, 2.0}));
	UPlutoMathFunctionLibrary::PF_ScaleFloatByRatios(-8.0, {0.25}, Values);
	TestTrue(TEXT("One ratio and a negative base"), Values == TArray<double>({-2.0}));
	UPlutoMathFunctionLibrary::PF_ScaleFloatByRatios(0.0, Ratios, Values);
	TestTrue(TEXT("Zero base preserves result count"), Values == TArray<double>({0.0, 0.0, 0.0}));
	UPlutoMathFunctionLibrary::PF_ScaleFloatByRatios(1000.0, {}, Values);
	TestTrue(TEXT("Empty input clears previous results"), Values.IsEmpty());

	Values = {0.25, 0.75};
	UPlutoMathFunctionLibrary::PF_ScaleFloatByRatios(1000.0, Values, Values);
	TestTrue(TEXT("Native input/output alias is safe"), Values == TArray<double>({250.0, 750.0}));
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoScaleFloatByRatiosMetadataTest,
	"Pluto.FunctionLibrary.Math.ScaleFloatByRatios.Metadata",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPlutoScaleFloatByRatiosMetadataTest::RunTest(const FString& Parameters)
{
	const UFunction* Function = UPlutoMathFunctionLibrary::StaticClass()->FindFunctionByName(
		GET_FUNCTION_NAME_CHECKED(UPlutoMathFunctionLibrary, PF_ScaleFloatByRatios));
	if (!TestNotNull(TEXT("Blueprint function registered"), Function)) return false;
	TestTrue(TEXT("Stateless calculation is pure"), Function->HasAnyFunctionFlags(FUNC_BlueprintPure));
	const FArrayProperty* Ratios = FindFProperty<FArrayProperty>(Function, TEXT("Ratios"));
	const FArrayProperty* Values = FindFProperty<FArrayProperty>(Function, TEXT("Values"));
	if (TestNotNull(TEXT("Ratios array pin"), Ratios))
	{
		TestTrue(TEXT("Input is const"), Ratios->HasAnyPropertyFlags(CPF_ConstParm));
		TestNotNull(TEXT("Double precision ratios"), CastField<FDoubleProperty>(Ratios->Inner));
	}
	if (TestNotNull(TEXT("Values array pin"), Values))
	{
		TestTrue(TEXT("Values output"), Values->HasAnyPropertyFlags(CPF_OutParm));
	}
#if WITH_METADATA
	TestEqual(TEXT("Existing library root"), Function->GetMetaData(TEXT("Category")),
		FString(TEXT("Pluto Function Library|Math")));
	TestEqual(TEXT("Unconnected ratios may be empty"), Function->GetMetaData(TEXT("AutoCreateRefTerm")),
		FString(TEXT("Ratios")));
	const FString Tooltip = Function->GetMetaData(TEXT("ToolTip"));
	TestTrue(TEXT("Chinese multiline usage"), Tooltip.Contains(TEXT("得到同样数量的结果。\n")));
	for (const TCHAR* Pin : {TEXT("BaseValue"), TEXT("Ratios"), TEXT("Values")})
	{
		TestTrue(FString(TEXT("Pin documentation: ")) + Pin,
			Tooltip.Contains(FString(TEXT("@param ")) + Pin + TEXT(" ")));
	}
#endif
	return true;
}

#endif
