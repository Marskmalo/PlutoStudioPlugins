// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlutoSplineHelperEditorSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePlutoSplineHelperEditorSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
PLUTOSPLINEHELPEREDITOR_API UClass* Z_Construct_UClass_UPlutoSplineHelperEditorSettings();
PLUTOSPLINEHELPEREDITOR_API UClass* Z_Construct_UClass_UPlutoSplineHelperEditorSettings_NoRegister();
PLUTOSPLINEHELPEREDITOR_API UEnum* Z_Construct_UEnum_PlutoSplineHelperEditor_EPlutoSplineHelperLanguage();
UPackage* Z_Construct_UPackage__Script_PlutoSplineHelperEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EPlutoSplineHelperLanguage ************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPlutoSplineHelperLanguage;
static UEnum* EPlutoSplineHelperLanguage_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPlutoSplineHelperLanguage.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPlutoSplineHelperLanguage.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PlutoSplineHelperEditor_EPlutoSplineHelperLanguage, (UObject*)Z_Construct_UPackage__Script_PlutoSplineHelperEditor(), TEXT("EPlutoSplineHelperLanguage"));
	}
	return Z_Registration_Info_UEnum_EPlutoSplineHelperLanguage.OuterSingleton;
}
template<> PLUTOSPLINEHELPEREDITOR_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlutoSplineHelperLanguage>()
{
	return EPlutoSplineHelperLanguage_StaticEnum();
}
struct Z_Construct_UEnum_PlutoSplineHelperEditor_EPlutoSplineHelperLanguage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Chinese.DisplayName", "\xe4\xb8\xad\xe6\x96\x87" },
		{ "Chinese.Name", "EPlutoSplineHelperLanguage::Chinese" },
		{ "English.DisplayName", "English" },
		{ "English.Name", "EPlutoSplineHelperLanguage::English" },
		{ "ModuleRelativePath", "Public/PlutoSplineHelperEditorSettings.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPlutoSplineHelperLanguage::Chinese", (int64)EPlutoSplineHelperLanguage::Chinese },
		{ "EPlutoSplineHelperLanguage::English", (int64)EPlutoSplineHelperLanguage::English },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_PlutoSplineHelperEditor_EPlutoSplineHelperLanguage_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PlutoSplineHelperEditor_EPlutoSplineHelperLanguage_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_PlutoSplineHelperEditor,
	nullptr,
	"EPlutoSplineHelperLanguage",
	"EPlutoSplineHelperLanguage",
	Z_Construct_UEnum_PlutoSplineHelperEditor_EPlutoSplineHelperLanguage_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_PlutoSplineHelperEditor_EPlutoSplineHelperLanguage_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PlutoSplineHelperEditor_EPlutoSplineHelperLanguage_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PlutoSplineHelperEditor_EPlutoSplineHelperLanguage_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_PlutoSplineHelperEditor_EPlutoSplineHelperLanguage()
{
	if (!Z_Registration_Info_UEnum_EPlutoSplineHelperLanguage.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPlutoSplineHelperLanguage.InnerSingleton, Z_Construct_UEnum_PlutoSplineHelperEditor_EPlutoSplineHelperLanguage_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPlutoSplineHelperLanguage.InnerSingleton;
}
// ********** End Enum EPlutoSplineHelperLanguage **************************************************

// ********** Begin Class UPlutoSplineHelperEditorSettings *****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPlutoSplineHelperEditorSettings;
UClass* UPlutoSplineHelperEditorSettings::GetPrivateStaticClass()
{
	using TClass = UPlutoSplineHelperEditorSettings;
	if (!Z_Registration_Info_UClass_UPlutoSplineHelperEditorSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PlutoSplineHelperEditorSettings"),
			Z_Registration_Info_UClass_UPlutoSplineHelperEditorSettings.InnerSingleton,
			StaticRegisterNativesUPlutoSplineHelperEditorSettings,
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
	return Z_Registration_Info_UClass_UPlutoSplineHelperEditorSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UPlutoSplineHelperEditorSettings_NoRegister()
{
	return UPlutoSplineHelperEditorSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Pluto Spline Helper Editor" },
		{ "IncludePath", "PlutoSplineHelperEditorSettings.h" },
		{ "ModuleRelativePath", "Public/PlutoSplineHelperEditorSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Language_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/PlutoSplineHelperEditorSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UPlutoSplineHelperEditorSettings constinit property declarations *********
	static const UECodeGen_Private::FBytePropertyParams NewProp_Language_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Language;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UPlutoSplineHelperEditorSettings constinit property declarations ***********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlutoSplineHelperEditorSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics

// ********** Begin Class UPlutoSplineHelperEditorSettings Property Definitions ********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics::NewProp_Language_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics::NewProp_Language = { "Language", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlutoSplineHelperEditorSettings, Language), Z_Construct_UEnum_PlutoSplineHelperEditor_EPlutoSplineHelperLanguage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Language_MetaData), NewProp_Language_MetaData) }; // 2321741515
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics::NewProp_Language_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics::NewProp_Language,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics::PropPointers) < 2048);
// ********** End Class UPlutoSplineHelperEditorSettings Property Definitions **********************
UObject* (*const Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_PlutoSplineHelperEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics::ClassParams = {
	&UPlutoSplineHelperEditorSettings::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics::Class_MetaDataParams)
};
void UPlutoSplineHelperEditorSettings::StaticRegisterNativesUPlutoSplineHelperEditorSettings()
{
}
UClass* Z_Construct_UClass_UPlutoSplineHelperEditorSettings()
{
	if (!Z_Registration_Info_UClass_UPlutoSplineHelperEditorSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlutoSplineHelperEditorSettings.OuterSingleton, Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPlutoSplineHelperEditorSettings.OuterSingleton;
}
UPlutoSplineHelperEditorSettings::UPlutoSplineHelperEditorSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPlutoSplineHelperEditorSettings);
UPlutoSplineHelperEditorSettings::~UPlutoSplineHelperEditorSettings() {}
// ********** End Class UPlutoSplineHelperEditorSettings *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperEditor_Public_PlutoSplineHelperEditorSettings_h__Script_PlutoSplineHelperEditor_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EPlutoSplineHelperLanguage_StaticEnum, TEXT("EPlutoSplineHelperLanguage"), &Z_Registration_Info_UEnum_EPlutoSplineHelperLanguage, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2321741515U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPlutoSplineHelperEditorSettings, UPlutoSplineHelperEditorSettings::StaticClass, TEXT("UPlutoSplineHelperEditorSettings"), &Z_Registration_Info_UClass_UPlutoSplineHelperEditorSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlutoSplineHelperEditorSettings), 3604971304U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperEditor_Public_PlutoSplineHelperEditorSettings_h__Script_PlutoSplineHelperEditor_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperEditor_Public_PlutoSplineHelperEditorSettings_h__Script_PlutoSplineHelperEditor_67836060{
	TEXT("/Script/PlutoSplineHelperEditor"),
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperEditor_Public_PlutoSplineHelperEditorSettings_h__Script_PlutoSplineHelperEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperEditor_Public_PlutoSplineHelperEditorSettings_h__Script_PlutoSplineHelperEditor_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperEditor_Public_PlutoSplineHelperEditorSettings_h__Script_PlutoSplineHelperEditor_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperEditor_Public_PlutoSplineHelperEditorSettings_h__Script_PlutoSplineHelperEditor_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
