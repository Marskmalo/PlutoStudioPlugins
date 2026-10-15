#include "PlutoAssetNamingRules.h"

#if WITH_DEV_AUTOMATION_TESTS
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoChooserNamingTest, "Pluto.AssetNaming.Chooser",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPlutoChooserNamingTest::RunTest(const FString& Parameters)
{
	const FTopLevelAssetPath ChooserClass(TEXT("/Script/Chooser"), TEXT("ChooserTable"));
	const auto Audit = [](const TCHAR* Name, const FTopLevelAssetPath& Class)
	{
		return PlutoAssetNamingRules::Audit(FAssetData(
			FName(*(FString(TEXT("/Game/WorkSpace/ChooserDemo/")) + Name)),
			FName(TEXT("/Game/WorkSpace/ChooserDemo")), FName(Name), Class));
	};

	const auto Correct = Audit(TEXT("CT_SOD_ChooserTest"), ChooserClass);
	TestTrue(TEXT("Existing teaching name is compliant"), Correct.Status == EPlutoAssetNamingStatus::Compliant);
	TestEqual(TEXT("Chooser prefix"), Correct.ExpectedPrefix, FString(TEXT("CT")));
	TestTrue(TEXT("Compliant asset has no rename suggestion"), Correct.SuggestedName.IsEmpty());

	for (const TCHAR* Name : { TEXT("DT_SOD_GirlReaction"), TEXT("DA_SOD_GirlReaction"),
		TEXT("SOD_CT_GirlReaction"), TEXT("DT_SOD_CT_SOD_GirlReaction") })
	{
		const auto Wrong = Audit(Name, ChooserClass);
		TestTrue(Name, Wrong.Status == EPlutoAssetNamingStatus::SuggestedMigration);
		TestEqual(Name, Wrong.SuggestedName, FString(TEXT("CT_SOD_GirlReaction")));
	}

	const auto Unowned = Audit(TEXT("CT_GirlReaction"), ChooserClass);
	TestTrue(TEXT("Missing owner still requires provenance review"), Unowned.Status == EPlutoAssetNamingStatus::HistoricalException);
	TestFalse(TEXT("Missing owner cannot be automatically renamed"), Unowned.bRenameAllowed);
	TestEqual(TEXT("Prefix is not duplicated in suggestion"), Unowned.SuggestedName, FString(TEXT("CT_SOD_GirlReaction")));

	const auto DataTable = Audit(TEXT("CT_SOD_GirlReaction"), FTopLevelAssetPath(TEXT("/Script/Engine"), TEXT("DataTable")));
	TestEqual(TEXT("Actual DataTable type wins over CT name"), DataTable.SuggestedName, FString(TEXT("DT_SOD_GirlReaction")));
	for (const FTopLevelAssetPath& Class : {
		FTopLevelAssetPath(TEXT("/Script/Engine"), TEXT("CurveTable")),
		FTopLevelAssetPath(TEXT("/Script/Chooser"), TEXT("ChooserSignature")),
		FTopLevelAssetPath(TEXT("/Script/OtherPlugin"), TEXT("ChooserTable")) })
	{
		const auto Other = Audit(TEXT("CT_SOD_GirlReaction"), Class);
		TestTrue(TEXT("CT name alone does not register another asset class"), Other.ExpectedPrefix.IsEmpty());
	}
	return true;
}
#endif
