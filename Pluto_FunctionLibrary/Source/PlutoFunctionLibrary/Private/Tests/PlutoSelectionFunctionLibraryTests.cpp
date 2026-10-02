#include "PlutoSelectionFunctionLibrary.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"
#include "UObject/CoreRedirects.h"
#include "UObject/UnrealType.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoLatestActivatedPairSequencesTest,
	"Pluto.FunctionLibrary.Selection.LatestActivatedPair.Sequences",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPlutoLatestActivatedPairSequencesTest::RunTest(const FString& Parameters)
{
	// Run the user-facing sequence and its mirror, including sustained sampling.
	for (const bool bFirstIsA : {true, false})
	{
		FPlutoLatestActivatedPairState Snapshot;
		auto Step = [&](const TCHAR* Label, bool A, bool B, bool ExpectedA, bool ExpectedB)
		{
			bool OutA = true;
			bool OutB = true;
			UPlutoSelectionFunctionLibrary::PF_ResolveLatestActivatedPair(A, B, Snapshot, OutA, OutB);
			TestEqual(FString(Label) + TEXT(" A"), OutA, ExpectedA);
			TestEqual(FString(Label) + TEXT(" B"), OutB, ExpectedB);
			TestEqual(TEXT("History tracks actual A, not selection"), Snapshot.bPreviousAActive, A);
			TestEqual(TEXT("History tracks actual B, not selection"), Snapshot.bPreviousBActive, B);
		};
		Step(TEXT("Initially inactive"), false, false, false, false);
		Step(TEXT("First activated"), bFirstIsA, !bFirstIsA, bFirstIsA, !bFirstIsA);
		Step(TEXT("Second takes over"), true, true, !bFirstIsA, bFirstIsA);
		for (int32 Index = 0; Index < 120; ++Index)
		{
			Step(TEXT("Both held: no oscillation"), true, true, !bFirstIsA, bFirstIsA);
		}
		Step(TEXT("Release non-dominant"), !bFirstIsA, bFirstIsA, !bFirstIsA, bFirstIsA);
		Step(TEXT("Reactivate first: takes over"), true, true, bFirstIsA, !bFirstIsA);
		Step(TEXT("Keep reactivated winner"), true, true, bFirstIsA, !bFirstIsA);
		Step(TEXT("Release dominant: fallback"), !bFirstIsA, bFirstIsA, !bFirstIsA, bFirstIsA);
		Step(TEXT("Release all"), false, false, false, false);
		Step(TEXT("Re-enter"), bFirstIsA, !bFirstIsA, bFirstIsA, !bFirstIsA);
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoLatestActivatedPairBoundariesTest,
	"Pluto.FunctionLibrary.Selection.LatestActivatedPair.Boundaries",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPlutoLatestActivatedPairBoundariesTest::RunTest(const FString& Parameters)
{
	for (const bool bPreferA : {true, false})
	{
		FPlutoLatestActivatedPairState Snapshot;
		bool A = false, B = false;
		UPlutoSelectionFunctionLibrary::PF_ResolveLatestActivatedPair(true, true, Snapshot, A, B, bPreferA);
		TestEqual(TEXT("Simultaneous A"), A, bPreferA);
		TestEqual(TEXT("Simultaneous B"), B, !bPreferA);
		UPlutoSelectionFunctionLibrary::PF_ResolveLatestActivatedPair(true, true, Snapshot, A, B, !bPreferA);
		TestEqual(TEXT("Changing tie preference does not steal existing dominance"), A, bPreferA);
		Snapshot = {};
		UPlutoSelectionFunctionLibrary::PF_ResolveLatestActivatedPair(true, true, Snapshot, A, B, !bPreferA);
		TestEqual(TEXT("Reset clears history"), A, !bPreferA);
	}

	FPlutoLatestActivatedPairState First, Second;
	bool A = false, B = false;
	UPlutoSelectionFunctionLibrary::PF_ResolveLatestActivatedPair(true, true, First, A, B, true);
	UPlutoSelectionFunctionLibrary::PF_ResolveLatestActivatedPair(true, true, Second, A, B, false);
	UPlutoSelectionFunctionLibrary::PF_ResolveLatestActivatedPair(true, true, First, A, B, false);
	TestTrue(TEXT("Independent state does not leak across callers"), A && !B);

	// All combinations of the three stored bits, two current inputs, and tie policy.
	for (int32 Bits = 0; Bits < 64; ++Bits)
	{
		FPlutoLatestActivatedPairState Snapshot;
		Snapshot.bPreviousAActive = (Bits & 1) != 0;
		Snapshot.bPreviousBActive = (Bits & 2) != 0;
		Snapshot.bPreviousADominant = (Bits & 4) != 0;
		const bool ActiveA = (Bits & 8) != 0;
		const bool ActiveB = (Bits & 16) != 0;
		UPlutoSelectionFunctionLibrary::PF_ResolveLatestActivatedPair(ActiveA, ActiveB, Snapshot, A, B, (Bits & 32) != 0);
		TestFalse(TEXT("Never select both"), A && B);
		TestEqual(TEXT("Select exactly one iff any condition is active"), A || B, ActiveA || ActiveB);
		TestFalse(TEXT("Never select inactive A"), A && !ActiveA);
		TestFalse(TEXT("Never select inactive B"), B && !ActiveB);
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoLatestActivatedPairMetadataTest,
	"Pluto.FunctionLibrary.Selection.LatestActivatedPair.Metadata",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPlutoLatestActivatedPairMetadataTest::RunTest(const FString& Parameters)
{
#if WITH_METADATA
	const UFunction* Function = UPlutoSelectionFunctionLibrary::StaticClass()->FindFunctionByName(
		GET_FUNCTION_NAME_CHECKED(UPlutoSelectionFunctionLibrary, PF_ResolveLatestActivatedPair));
	if (!TestNotNull(TEXT("Blueprint function registered"), Function)) return false;
	TestFalse(TEXT("Stateful node must not be pure"), Function->HasAnyFunctionFlags(FUNC_BlueprintPure));
	const FString Tooltip = Function->GetMetaData(TEXT("ToolTip"));
	TestTrue(TEXT("Chinese node explanation"), Tooltip.Contains(TEXT("最近从 False 变为 True")));
	TestTrue(TEXT("Multiline node explanation"), Tooltip.Contains(TEXT("\n")));
	for (const TCHAR* Pin : {TEXT("bAActive"), TEXT("bBActive"), TEXT("Snapshot"),
		TEXT("bADominant"), TEXT("bBDominant"), TEXT("bPreferAOnSimultaneousActivation")})
	{
		// K2Node_CallFunction extracts each pin's help from these @param entries.
		TestTrue(FString(TEXT("Pin documentation: ")) + Pin,
			Tooltip.Contains(FString(TEXT("@param ")) + Pin + TEXT(" ")));
	}
	const FProperty* SnapshotProperty = Function->FindPropertyByName(TEXT("Snapshot"));
	if (TestNotNull(TEXT("Snapshot parameter is reflected"), SnapshotProperty))
	{
		TestTrue(TEXT("Snapshot remains an updated reference"), SnapshotProperty->HasAllPropertyFlags(CPF_ReferenceParm | CPF_OutParm));
	}
	TestNull(TEXT("Old State parameter no longer exposed"), Function->FindPropertyByName(TEXT("State")));
	TestEqual(TEXT("Snapshot type display name"), FPlutoLatestActivatedPairState::StaticStruct()->GetMetaData(TEXT("DisplayName")),
		FString(TEXT("PF Latest Activated Pair Snapshot")));
	const FCoreRedirectObjectName Redirected = FCoreRedirects::GetRedirectedName(ECoreRedirectFlags::Type_Property,
		FCoreRedirectObjectName(TEXT("PlutoSelectionFunctionLibrary.PF_ResolveLatestActivatedPair.State")));
	TestEqual(TEXT("Legacy Blueprint pin redirects to Snapshot"), Redirected.ObjectName, FName(TEXT("Snapshot")));
#endif
	return true;
}

#endif
