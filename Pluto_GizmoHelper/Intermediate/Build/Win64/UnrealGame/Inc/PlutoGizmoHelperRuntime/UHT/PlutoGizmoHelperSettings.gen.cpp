// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlutoGizmoHelperSettings.h"
#include "PlutoCollisionGizmoTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePlutoGizmoHelperSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
PLUTOGIZMOHELPERRUNTIME_API UClass* Z_Construct_UClass_UPlutoGizmoHelperSettings();
PLUTOGIZMOHELPERRUNTIME_API UClass* Z_Construct_UClass_UPlutoGizmoHelperSettings_NoRegister();
PLUTOGIZMOHELPERRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle();
UPackage* Z_Construct_UPackage__Script_PlutoGizmoHelperRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPlutoGizmoHelperSettings ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPlutoGizmoHelperSettings;
UClass* UPlutoGizmoHelperSettings::GetPrivateStaticClass()
{
	using TClass = UPlutoGizmoHelperSettings;
	if (!Z_Registration_Info_UClass_UPlutoGizmoHelperSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PlutoGizmoHelperSettings"),
			Z_Registration_Info_UClass_UPlutoGizmoHelperSettings.InnerSingleton,
			StaticRegisterNativesUPlutoGizmoHelperSettings,
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
	return Z_Registration_Info_UClass_UPlutoGizmoHelperSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UPlutoGizmoHelperSettings_NoRegister()
{
	return UPlutoGizmoHelperSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Pluto Gizmo Helper" },
		{ "IncludePath", "PlutoGizmoHelperSettings.h" },
		{ "ModuleRelativePath", "Public/PlutoGizmoHelperSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultCollisionStyle_MetaData[] = {
		{ "Category", "Collision Gizmo" },
		{ "ModuleRelativePath", "Public/PlutoGizmoHelperSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UPlutoGizmoHelperSettings constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultCollisionStyle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UPlutoGizmoHelperSettings constinit property declarations ******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlutoGizmoHelperSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics

// ********** Begin Class UPlutoGizmoHelperSettings Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics::NewProp_DefaultCollisionStyle = { "DefaultCollisionStyle", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlutoGizmoHelperSettings, DefaultCollisionStyle), Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultCollisionStyle_MetaData), NewProp_DefaultCollisionStyle_MetaData) }; // 4097913088
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics::NewProp_DefaultCollisionStyle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics::PropPointers) < 2048);
// ********** End Class UPlutoGizmoHelperSettings Property Definitions *****************************
UObject* (*const Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_PlutoGizmoHelperRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics::ClassParams = {
	&UPlutoGizmoHelperSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics::Class_MetaDataParams)
};
void UPlutoGizmoHelperSettings::StaticRegisterNativesUPlutoGizmoHelperSettings()
{
}
UClass* Z_Construct_UClass_UPlutoGizmoHelperSettings()
{
	if (!Z_Registration_Info_UClass_UPlutoGizmoHelperSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlutoGizmoHelperSettings.OuterSingleton, Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPlutoGizmoHelperSettings.OuterSingleton;
}
UPlutoGizmoHelperSettings::UPlutoGizmoHelperSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPlutoGizmoHelperSettings);
UPlutoGizmoHelperSettings::~UPlutoGizmoHelperSettings() {}
// ********** End Class UPlutoGizmoHelperSettings **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoGizmoHelperSettings_h__Script_PlutoGizmoHelperRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPlutoGizmoHelperSettings, UPlutoGizmoHelperSettings::StaticClass, TEXT("UPlutoGizmoHelperSettings"), &Z_Registration_Info_UClass_UPlutoGizmoHelperSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlutoGizmoHelperSettings), 439320548U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoGizmoHelperSettings_h__Script_PlutoGizmoHelperRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoGizmoHelperSettings_h__Script_PlutoGizmoHelperRuntime_2956865526{
	TEXT("/Script/PlutoGizmoHelperRuntime"),
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoGizmoHelperSettings_h__Script_PlutoGizmoHelperRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoGizmoHelperSettings_h__Script_PlutoGizmoHelperRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
