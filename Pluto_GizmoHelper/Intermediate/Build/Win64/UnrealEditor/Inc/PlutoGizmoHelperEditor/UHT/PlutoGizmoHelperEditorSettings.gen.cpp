// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlutoGizmoHelperEditorSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePlutoGizmoHelperEditorSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
PLUTOGIZMOHELPEREDITOR_API UClass* Z_Construct_UClass_UPlutoGizmoHelperEditorSettings();
PLUTOGIZMOHELPEREDITOR_API UClass* Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_NoRegister();
PLUTOGIZMOHELPEREDITOR_API UEnum* Z_Construct_UEnum_PlutoGizmoHelperEditor_EPlutoGizmoHelperLanguage();
UPackage* Z_Construct_UPackage__Script_PlutoGizmoHelperEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EPlutoGizmoHelperLanguage *************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPlutoGizmoHelperLanguage;
static UEnum* EPlutoGizmoHelperLanguage_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPlutoGizmoHelperLanguage.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPlutoGizmoHelperLanguage.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PlutoGizmoHelperEditor_EPlutoGizmoHelperLanguage, (UObject*)Z_Construct_UPackage__Script_PlutoGizmoHelperEditor(), TEXT("EPlutoGizmoHelperLanguage"));
	}
	return Z_Registration_Info_UEnum_EPlutoGizmoHelperLanguage.OuterSingleton;
}
template<> PLUTOGIZMOHELPEREDITOR_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlutoGizmoHelperLanguage>()
{
	return EPlutoGizmoHelperLanguage_StaticEnum();
}
struct Z_Construct_UEnum_PlutoGizmoHelperEditor_EPlutoGizmoHelperLanguage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Chinese.DisplayName", "\xe4\xb8\xad\xe6\x96\x87" },
		{ "Chinese.Name", "EPlutoGizmoHelperLanguage::Chinese" },
		{ "English.DisplayName", "English" },
		{ "English.Name", "EPlutoGizmoHelperLanguage::English" },
		{ "ModuleRelativePath", "Public/PlutoGizmoHelperEditorSettings.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPlutoGizmoHelperLanguage::Chinese", (int64)EPlutoGizmoHelperLanguage::Chinese },
		{ "EPlutoGizmoHelperLanguage::English", (int64)EPlutoGizmoHelperLanguage::English },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_PlutoGizmoHelperEditor_EPlutoGizmoHelperLanguage_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PlutoGizmoHelperEditor_EPlutoGizmoHelperLanguage_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_PlutoGizmoHelperEditor,
	nullptr,
	"EPlutoGizmoHelperLanguage",
	"EPlutoGizmoHelperLanguage",
	Z_Construct_UEnum_PlutoGizmoHelperEditor_EPlutoGizmoHelperLanguage_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_PlutoGizmoHelperEditor_EPlutoGizmoHelperLanguage_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PlutoGizmoHelperEditor_EPlutoGizmoHelperLanguage_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PlutoGizmoHelperEditor_EPlutoGizmoHelperLanguage_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_PlutoGizmoHelperEditor_EPlutoGizmoHelperLanguage()
{
	if (!Z_Registration_Info_UEnum_EPlutoGizmoHelperLanguage.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPlutoGizmoHelperLanguage.InnerSingleton, Z_Construct_UEnum_PlutoGizmoHelperEditor_EPlutoGizmoHelperLanguage_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPlutoGizmoHelperLanguage.InnerSingleton;
}
// ********** End Enum EPlutoGizmoHelperLanguage ***************************************************

// ********** Begin Class UPlutoGizmoHelperEditorSettings ******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPlutoGizmoHelperEditorSettings;
UClass* UPlutoGizmoHelperEditorSettings::GetPrivateStaticClass()
{
	using TClass = UPlutoGizmoHelperEditorSettings;
	if (!Z_Registration_Info_UClass_UPlutoGizmoHelperEditorSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PlutoGizmoHelperEditorSettings"),
			Z_Registration_Info_UClass_UPlutoGizmoHelperEditorSettings.InnerSingleton,
			StaticRegisterNativesUPlutoGizmoHelperEditorSettings,
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
	return Z_Registration_Info_UClass_UPlutoGizmoHelperEditorSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_NoRegister()
{
	return UPlutoGizmoHelperEditorSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Pluto Gizmo Helper Editor" },
		{ "IncludePath", "PlutoGizmoHelperEditorSettings.h" },
		{ "ModuleRelativePath", "Public/PlutoGizmoHelperEditorSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Language_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/PlutoGizmoHelperEditorSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UPlutoGizmoHelperEditorSettings constinit property declarations **********
	static const UECodeGen_Private::FBytePropertyParams NewProp_Language_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Language;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UPlutoGizmoHelperEditorSettings constinit property declarations ************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlutoGizmoHelperEditorSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics

// ********** Begin Class UPlutoGizmoHelperEditorSettings Property Definitions *********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics::NewProp_Language_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics::NewProp_Language = { "Language", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlutoGizmoHelperEditorSettings, Language), Z_Construct_UEnum_PlutoGizmoHelperEditor_EPlutoGizmoHelperLanguage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Language_MetaData), NewProp_Language_MetaData) }; // 1630371987
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics::NewProp_Language_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics::NewProp_Language,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics::PropPointers) < 2048);
// ********** End Class UPlutoGizmoHelperEditorSettings Property Definitions ***********************
UObject* (*const Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_PlutoGizmoHelperEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics::ClassParams = {
	&UPlutoGizmoHelperEditorSettings::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics::Class_MetaDataParams)
};
void UPlutoGizmoHelperEditorSettings::StaticRegisterNativesUPlutoGizmoHelperEditorSettings()
{
}
UClass* Z_Construct_UClass_UPlutoGizmoHelperEditorSettings()
{
	if (!Z_Registration_Info_UClass_UPlutoGizmoHelperEditorSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlutoGizmoHelperEditorSettings.OuterSingleton, Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPlutoGizmoHelperEditorSettings.OuterSingleton;
}
UPlutoGizmoHelperEditorSettings::UPlutoGizmoHelperEditorSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPlutoGizmoHelperEditorSettings);
UPlutoGizmoHelperEditorSettings::~UPlutoGizmoHelperEditorSettings() {}
// ********** End Class UPlutoGizmoHelperEditorSettings ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperEditor_Public_PlutoGizmoHelperEditorSettings_h__Script_PlutoGizmoHelperEditor_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EPlutoGizmoHelperLanguage_StaticEnum, TEXT("EPlutoGizmoHelperLanguage"), &Z_Registration_Info_UEnum_EPlutoGizmoHelperLanguage, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1630371987U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPlutoGizmoHelperEditorSettings, UPlutoGizmoHelperEditorSettings::StaticClass, TEXT("UPlutoGizmoHelperEditorSettings"), &Z_Registration_Info_UClass_UPlutoGizmoHelperEditorSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlutoGizmoHelperEditorSettings), 3120894989U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperEditor_Public_PlutoGizmoHelperEditorSettings_h__Script_PlutoGizmoHelperEditor_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperEditor_Public_PlutoGizmoHelperEditorSettings_h__Script_PlutoGizmoHelperEditor_3306503454{
	TEXT("/Script/PlutoGizmoHelperEditor"),
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperEditor_Public_PlutoGizmoHelperEditorSettings_h__Script_PlutoGizmoHelperEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperEditor_Public_PlutoGizmoHelperEditorSettings_h__Script_PlutoGizmoHelperEditor_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperEditor_Public_PlutoGizmoHelperEditorSettings_h__Script_PlutoGizmoHelperEditor_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperEditor_Public_PlutoGizmoHelperEditorSettings_h__Script_PlutoGizmoHelperEditor_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
