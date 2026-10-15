#include "PlutoMathFunctionLibrary.h"

#if WITH_DEV_AUTOMATION_TESTS
#include "Misc/AutomationTest.h"
#include "UObject/UnrealType.h"
#include <limits>

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoPlanarPolarValuesTest,
	"Pluto.FunctionLibrary.Math.PlanarPolar.Coordinates",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FPlutoPlanarPolarValuesTest::RunTest(const FString& Parameters)
{
	const auto Check = [&](const FVector& Offset, const FVector& Reference, double ExpectedRadius, double ExpectedAngle, float Tolerance = .0001f)
	{
		double Radius = -1; float Angle = -1;
		UPlutoMathFunctionLibrary::PF_ComputePlanarPolarCoordinates(Offset, Reference, Radius, Angle, Tolerance);
		TestTrue(TEXT("Radius"), FMath::IsNearlyEqual(Radius, ExpectedRadius, 1e-9));
		TestTrue(TEXT("Float angle modulo one turn"), FMath::Abs(FMath::FindDeltaAngleDegrees(Angle, static_cast<float>(ExpectedAngle))) < 1e-6f);
	};
	Check(FVector(100,0,40), FVector(3,0,-10), 100, 0);
	Check(FVector(0,100,40), FVector(3,0,-10), 100, 90);
	Check(FVector(0,-100,40), FVector(3,0,-10), 100, -90);
	Check(FVector(-100,0,40), FVector(3,0,-10), 100, 180);
	Check(FVector(3,4,1000), FVector(0,7,0), 5, -36.86989764584402);
	Check(FVector::ZeroVector, FVector(0,1,0), 0, -90);
	Check(FVector(0,10,0), FVector::ZeroVector, 10, 90);
	Check(FVector(0,.001,0), FVector(0,1,0), .001, -90);
	Check(FVector(0,1,0), FVector(0,1,0), 1, 0, 1.f);
	Check(FVector(0,.999,0), FVector(0,1,0), .999, -90, 1.f);
	Check(FVector(0,1.001,0), FVector(0,1,0), 1.001, 0, 1.f);
	Check(FVector(0,1,0), FVector(3,0,0), 1, 0, 4.f);
	Check(FVector(1,2,0), FVector(0,1,0), 0, 0, 0.f);
	Check(FVector(1,2,0), FVector(0,1,0), 0, 0, -1.f);
	Check(FVector(std::numeric_limits<double>::infinity(),0,0), FVector(1,0,0), 0, 0);
	Check(FVector(0,2,std::numeric_limits<double>::quiet_NaN()), FVector(1,0,0), 2, 90);
	Check(FVector(1,2,0), FVector(std::numeric_limits<double>::max(),0,0), 0, 0);
	FVector Aliased(3,4,0); float Angle;
	UPlutoMathFunctionLibrary::PF_ComputePlanarPolarCoordinates(Aliased, FVector::ForwardVector, Aliased.X, Angle);
	TestEqual(TEXT("Native output alias preserves original radius"), Aliased.X, 5.0);
	TestEqual(TEXT("Native output alias preserves original float angle"), Angle,53.13010235415598f);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoPlanarOffsetValuesTest,
	"Pluto.FunctionLibrary.Math.PlanarPolar.Offset",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FPlutoPlanarOffsetValuesTest::RunTest(const FString& Parameters)
{
	const auto Check = [&](FVector Reference, float Angle, double Radius, FVector Expected, float Tolerance = .0001f)
	{
		const FVector Result=UPlutoMathFunctionLibrary::PF_ComputePlanarOffset(Reference,Angle,Radius,Tolerance);
		TestTrue(TEXT("Planar offset"), Result.Equals(Expected,1e-8));
		TestEqual(TEXT("Always planar"), Result.Z, 0.0);
	};
	Check(FVector(5,0,30),0,100,FVector(100,0,0));
	Check(FVector(5,0,30),90,100,FVector(0,100,0));
	Check(FVector(5,0,30),-90,100,FVector(0,-100,0));
	Check(FVector(0,5,30),90,100,FVector(-100,0,0));
	Check(FVector(1,0,0),450,100,FVector(0,100,0));
	Check(FVector(1,0,0),0,-100,FVector(-100,0,0));
	Check(FVector(1,0,0),15,0,FVector::ZeroVector);
	Check(FVector::ZeroVector,30,100,FVector::ZeroVector);
	Check(FVector(.001,0,100),30,100,FVector::ZeroVector);
	Check(FVector(.999,0,0),0,100,FVector::ZeroVector,1.f);
	Check(FVector(1,0,0),0,100,FVector(100,0,0),1.f);
	Check(FVector(1.001,0,0),0,100,FVector(100,0,0),1.f);
	Check(FVector(1,0,0),0,100,FVector::ZeroVector,4.f);
	Check(FVector(1,0,0),0,100,FVector::ZeroVector,0.f);
	Check(FVector(1,0,0),std::numeric_limits<float>::infinity(),100,FVector::ZeroVector);
	Check(FVector(1,0,0),0,std::numeric_limits<double>::quiet_NaN(),FVector::ZeroVector);
	Check(FVector(1,0,std::numeric_limits<double>::quiet_NaN()),0,100,FVector(100,0,0));
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoPlanarPolarRoundTripTest,
	"Pluto.FunctionLibrary.Math.PlanarPolar.RoundTrip",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FPlutoPlanarPolarRoundTripTest::RunTest(const FString& Parameters)
{
	for (int32 Yaw=-180;Yaw<=180;Yaw+=30)
	for (float Angle : {-180.f,-135.25f,-90.f,-.01f,0.f,.01f,45.75f,90.f,179.99f,180.f})
	for (double Radius : {1.,75.,300.,1000.})
	{
		const FVector Reference=FRotator(0,Yaw,0).Vector()*3.;
		const FVector Offset=UPlutoMathFunctionLibrary::PF_ComputePlanarOffset(Reference,Angle,Radius);
		double ReadRadius; float ReadAngle;
		UPlutoMathFunctionLibrary::PF_ComputePlanarPolarCoordinates(Offset,Reference,ReadRadius,ReadAngle);
		TestTrue(TEXT("Round trip radius"), FMath::IsNearlyEqual(ReadRadius,Radius,1e-8));
		TestTrue(TEXT("Round trip signed angle"), FMath::Abs(FMath::FindDeltaAngleDegrees(ReadAngle,double(Angle)))<1e-5);
		const FVector Rebuilt=UPlutoMathFunctionLibrary::PF_ComputePlanarOffset(Reference,float(ReadAngle),ReadRadius);
		TestTrue(TEXT("Round trip offset"), Rebuilt.Equals(Offset,1e-4));
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlutoPlanarPolarMetadataTest,
	"Pluto.FunctionLibrary.Math.PlanarPolar.Metadata",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FPlutoPlanarPolarMetadataTest::RunTest(const FString& Parameters)
{
	for (FName Name : {GET_FUNCTION_NAME_CHECKED(UPlutoMathFunctionLibrary,PF_ComputePlanarPolarCoordinates),GET_FUNCTION_NAME_CHECKED(UPlutoMathFunctionLibrary,PF_ComputePlanarOffset)})
	{
		const UFunction* Function=UPlutoMathFunctionLibrary::StaticClass()->FindFunctionByName(Name);
		if (!TestNotNull(TEXT("Function registered"),Function))return false;
		TestTrue(TEXT("Stateless Blueprint pure"),Function->HasAnyFunctionFlags(FUNC_BlueprintPure));
#if WITH_METADATA
		TestEqual(TEXT("Math category"),Function->GetMetaData(TEXT("Category")),FString(TEXT("Pluto Function Library|Math")));
		const FString Tooltip=Function->GetMetaData(TEXT("ToolTip"));
		TestTrue(TEXT("Chinese multiline tooltip"),Tooltip.Contains(TEXT("平面"))&&Tooltip.Contains(TEXT("\n")));
		for(TFieldIterator<FProperty> It(Function);It;++It)
		{
			if(!It->HasAnyPropertyFlags(CPF_Parm))continue;
			const FString Marker=It->HasAnyPropertyFlags(CPF_ReturnParm)?TEXT("@return "):FString(TEXT("@param "))+It->GetName()+TEXT(" ");
			TestTrue(FString(TEXT("Individual pin tooltip: "))+It->GetName(),Tooltip.Contains(Marker));
		}
#endif
	}
	return true;
}
#endif
