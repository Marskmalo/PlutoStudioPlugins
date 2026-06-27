// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlutoSplineWallSplineComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePlutoSplineWallSplineComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_USplineComponent();
PLUTOSPLINEHELPERRUNTIME_API UClass* Z_Construct_UClass_UPlutoSplineWallSplineComponent();
PLUTOSPLINEHELPERRUNTIME_API UClass* Z_Construct_UClass_UPlutoSplineWallSplineComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_PlutoSplineHelperRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPlutoSplineWallSplineComponent ******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPlutoSplineWallSplineComponent;
UClass* UPlutoSplineWallSplineComponent::GetPrivateStaticClass()
{
	using TClass = UPlutoSplineWallSplineComponent;
	if (!Z_Registration_Info_UClass_UPlutoSplineWallSplineComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PlutoSplineWallSplineComponent"),
			Z_Registration_Info_UClass_UPlutoSplineWallSplineComponent.InnerSingleton,
			StaticRegisterNativesUPlutoSplineWallSplineComponent,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UPlutoSplineWallSplineComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UPlutoSplineWallSplineComponent_NoRegister()
{
	return UPlutoSplineWallSplineComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPlutoSplineWallSplineComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Pluto" },
		{ "DisplayName", "Pluto Spline Wall Path" },
		{ "HideCategories", "Physics Collision Lighting Rendering Mobile Trigger VirtualTexture" },
		{ "IncludePath", "PlutoSplineWallSplineComponent.h" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallSplineComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UPlutoSplineWallSplineComponent constinit property declarations **********
// ********** End Class UPlutoSplineWallSplineComponent constinit property declarations ************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlutoSplineWallSplineComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPlutoSplineWallSplineComponent_Statics
UObject* (*const Z_Construct_UClass_UPlutoSplineWallSplineComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USplineComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_PlutoSplineHelperRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoSplineWallSplineComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlutoSplineWallSplineComponent_Statics::ClassParams = {
	&UPlutoSplineWallSplineComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoSplineWallSplineComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlutoSplineWallSplineComponent_Statics::Class_MetaDataParams)
};
void UPlutoSplineWallSplineComponent::StaticRegisterNativesUPlutoSplineWallSplineComponent()
{
}
UClass* Z_Construct_UClass_UPlutoSplineWallSplineComponent()
{
	if (!Z_Registration_Info_UClass_UPlutoSplineWallSplineComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlutoSplineWallSplineComponent.OuterSingleton, Z_Construct_UClass_UPlutoSplineWallSplineComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPlutoSplineWallSplineComponent.OuterSingleton;
}
UPlutoSplineWallSplineComponent::UPlutoSplineWallSplineComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPlutoSplineWallSplineComponent);
UPlutoSplineWallSplineComponent::~UPlutoSplineWallSplineComponent() {}
// ********** End Class UPlutoSplineWallSplineComponent ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallSplineComponent_h__Script_PlutoSplineHelperRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPlutoSplineWallSplineComponent, UPlutoSplineWallSplineComponent::StaticClass, TEXT("UPlutoSplineWallSplineComponent"), &Z_Registration_Info_UClass_UPlutoSplineWallSplineComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlutoSplineWallSplineComponent), 4198691418U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallSplineComponent_h__Script_PlutoSplineHelperRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallSplineComponent_h__Script_PlutoSplineHelperRuntime_1890496433{
	TEXT("/Script/PlutoSplineHelperRuntime"),
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallSplineComponent_h__Script_PlutoSplineHelperRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallSplineComponent_h__Script_PlutoSplineHelperRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
