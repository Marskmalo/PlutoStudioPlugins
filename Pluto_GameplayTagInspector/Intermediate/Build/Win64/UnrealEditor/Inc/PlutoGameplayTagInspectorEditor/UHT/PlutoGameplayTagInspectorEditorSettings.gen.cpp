// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlutoGameplayTagInspectorEditorSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePlutoGameplayTagInspectorEditorSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
PLUTOGAMEPLAYTAGINSPECTOREDITOR_API UClass* Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings();
PLUTOGAMEPLAYTAGINSPECTOREDITOR_API UClass* Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_NoRegister();
PLUTOGAMEPLAYTAGINSPECTOREDITOR_API UEnum* Z_Construct_UEnum_PlutoGameplayTagInspectorEditor_EPlutoGameplayTagInspectorLanguage();
UPackage* Z_Construct_UPackage__Script_PlutoGameplayTagInspectorEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EPlutoGameplayTagInspectorLanguage ****************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPlutoGameplayTagInspectorLanguage;
static UEnum* EPlutoGameplayTagInspectorLanguage_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPlutoGameplayTagInspectorLanguage.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPlutoGameplayTagInspectorLanguage.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PlutoGameplayTagInspectorEditor_EPlutoGameplayTagInspectorLanguage, (UObject*)Z_Construct_UPackage__Script_PlutoGameplayTagInspectorEditor(), TEXT("EPlutoGameplayTagInspectorLanguage"));
	}
	return Z_Registration_Info_UEnum_EPlutoGameplayTagInspectorLanguage.OuterSingleton;
}
template<> PLUTOGAMEPLAYTAGINSPECTOREDITOR_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlutoGameplayTagInspectorLanguage>()
{
	return EPlutoGameplayTagInspectorLanguage_StaticEnum();
}
struct Z_Construct_UEnum_PlutoGameplayTagInspectorEditor_EPlutoGameplayTagInspectorLanguage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Chinese.Name", "EPlutoGameplayTagInspectorLanguage::Chinese" },
		{ "English.Name", "EPlutoGameplayTagInspectorLanguage::English" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagInspectorEditorSettings.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPlutoGameplayTagInspectorLanguage::Chinese", (int64)EPlutoGameplayTagInspectorLanguage::Chinese },
		{ "EPlutoGameplayTagInspectorLanguage::English", (int64)EPlutoGameplayTagInspectorLanguage::English },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_PlutoGameplayTagInspectorEditor_EPlutoGameplayTagInspectorLanguage_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PlutoGameplayTagInspectorEditor_EPlutoGameplayTagInspectorLanguage_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_PlutoGameplayTagInspectorEditor,
	nullptr,
	"EPlutoGameplayTagInspectorLanguage",
	"EPlutoGameplayTagInspectorLanguage",
	Z_Construct_UEnum_PlutoGameplayTagInspectorEditor_EPlutoGameplayTagInspectorLanguage_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_PlutoGameplayTagInspectorEditor_EPlutoGameplayTagInspectorLanguage_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PlutoGameplayTagInspectorEditor_EPlutoGameplayTagInspectorLanguage_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PlutoGameplayTagInspectorEditor_EPlutoGameplayTagInspectorLanguage_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_PlutoGameplayTagInspectorEditor_EPlutoGameplayTagInspectorLanguage()
{
	if (!Z_Registration_Info_UEnum_EPlutoGameplayTagInspectorLanguage.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPlutoGameplayTagInspectorLanguage.InnerSingleton, Z_Construct_UEnum_PlutoGameplayTagInspectorEditor_EPlutoGameplayTagInspectorLanguage_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPlutoGameplayTagInspectorLanguage.InnerSingleton;
}
// ********** End Enum EPlutoGameplayTagInspectorLanguage ******************************************

// ********** Begin Class UPlutoGameplayTagInspectorEditorSettings *********************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPlutoGameplayTagInspectorEditorSettings;
UClass* UPlutoGameplayTagInspectorEditorSettings::GetPrivateStaticClass()
{
	using TClass = UPlutoGameplayTagInspectorEditorSettings;
	if (!Z_Registration_Info_UClass_UPlutoGameplayTagInspectorEditorSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PlutoGameplayTagInspectorEditorSettings"),
			Z_Registration_Info_UClass_UPlutoGameplayTagInspectorEditorSettings.InnerSingleton,
			StaticRegisterNativesUPlutoGameplayTagInspectorEditorSettings,
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
	return Z_Registration_Info_UClass_UPlutoGameplayTagInspectorEditorSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_NoRegister()
{
	return UPlutoGameplayTagInspectorEditorSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "PlutoGameplayTagInspectorEditorSettings.h" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagInspectorEditorSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Language_MetaData[] = {
		{ "Category", "General" },
		{ "DisplayName", "Language" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagInspectorEditorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Inspector UI language.\n\xe6\xa3\x80\xe6\x9f\xa5\xe5\x99\xa8\xe7\x95\x8c\xe9\x9d\xa2\xe8\xaf\xad\xe8\xa8\x80\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UPlutoGameplayTagInspectorEditorSettings constinit property declarations *
	static const UECodeGen_Private::FBytePropertyParams NewProp_Language_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Language;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UPlutoGameplayTagInspectorEditorSettings constinit property declarations ***
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlutoGameplayTagInspectorEditorSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics

// ********** Begin Class UPlutoGameplayTagInspectorEditorSettings Property Definitions ************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics::NewProp_Language_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics::NewProp_Language = { "Language", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlutoGameplayTagInspectorEditorSettings, Language), Z_Construct_UEnum_PlutoGameplayTagInspectorEditor_EPlutoGameplayTagInspectorLanguage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Language_MetaData), NewProp_Language_MetaData) }; // 4089258884
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics::NewProp_Language_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics::NewProp_Language,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics::PropPointers) < 2048);
// ********** End Class UPlutoGameplayTagInspectorEditorSettings Property Definitions **************
UObject* (*const Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_PlutoGameplayTagInspectorEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics::ClassParams = {
	&UPlutoGameplayTagInspectorEditorSettings::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics::PropPointers),
	0,
	0x001000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics::Class_MetaDataParams)
};
void UPlutoGameplayTagInspectorEditorSettings::StaticRegisterNativesUPlutoGameplayTagInspectorEditorSettings()
{
}
UClass* Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings()
{
	if (!Z_Registration_Info_UClass_UPlutoGameplayTagInspectorEditorSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlutoGameplayTagInspectorEditorSettings.OuterSingleton, Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPlutoGameplayTagInspectorEditorSettings.OuterSingleton;
}
UPlutoGameplayTagInspectorEditorSettings::UPlutoGameplayTagInspectorEditorSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPlutoGameplayTagInspectorEditorSettings);
UPlutoGameplayTagInspectorEditorSettings::~UPlutoGameplayTagInspectorEditorSettings() {}
// ********** End Class UPlutoGameplayTagInspectorEditorSettings ***********************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorEditor_Public_PlutoGameplayTagInspectorEditorSettings_h__Script_PlutoGameplayTagInspectorEditor_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EPlutoGameplayTagInspectorLanguage_StaticEnum, TEXT("EPlutoGameplayTagInspectorLanguage"), &Z_Registration_Info_UEnum_EPlutoGameplayTagInspectorLanguage, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4089258884U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings, UPlutoGameplayTagInspectorEditorSettings::StaticClass, TEXT("UPlutoGameplayTagInspectorEditorSettings"), &Z_Registration_Info_UClass_UPlutoGameplayTagInspectorEditorSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlutoGameplayTagInspectorEditorSettings), 3954822469U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorEditor_Public_PlutoGameplayTagInspectorEditorSettings_h__Script_PlutoGameplayTagInspectorEditor_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorEditor_Public_PlutoGameplayTagInspectorEditorSettings_h__Script_PlutoGameplayTagInspectorEditor_1522967095{
	TEXT("/Script/PlutoGameplayTagInspectorEditor"),
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorEditor_Public_PlutoGameplayTagInspectorEditorSettings_h__Script_PlutoGameplayTagInspectorEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorEditor_Public_PlutoGameplayTagInspectorEditorSettings_h__Script_PlutoGameplayTagInspectorEditor_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorEditor_Public_PlutoGameplayTagInspectorEditorSettings_h__Script_PlutoGameplayTagInspectorEditor_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorEditor_Public_PlutoGameplayTagInspectorEditorSettings_h__Script_PlutoGameplayTagInspectorEditor_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
