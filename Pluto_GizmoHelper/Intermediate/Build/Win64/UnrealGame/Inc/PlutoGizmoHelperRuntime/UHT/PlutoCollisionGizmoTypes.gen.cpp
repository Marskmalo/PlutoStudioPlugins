// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlutoCollisionGizmoTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePlutoCollisionGizmoTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
PLUTOGIZMOHELPERRUNTIME_API UEnum* Z_Construct_UEnum_PlutoGizmoHelperRuntime_EPlutoCollisionGizmoVisibility();
PLUTOGIZMOHELPERRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle();
UPackage* Z_Construct_UPackage__Script_PlutoGizmoHelperRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EPlutoCollisionGizmoVisibility ********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPlutoCollisionGizmoVisibility;
static UEnum* EPlutoCollisionGizmoVisibility_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPlutoCollisionGizmoVisibility.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPlutoCollisionGizmoVisibility.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PlutoGizmoHelperRuntime_EPlutoCollisionGizmoVisibility, (UObject*)Z_Construct_UPackage__Script_PlutoGizmoHelperRuntime(), TEXT("EPlutoCollisionGizmoVisibility"));
	}
	return Z_Registration_Info_UEnum_EPlutoCollisionGizmoVisibility.OuterSingleton;
}
template<> PLUTOGIZMOHELPERRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlutoCollisionGizmoVisibility>()
{
	return EPlutoCollisionGizmoVisibility_StaticEnum();
}
struct Z_Construct_UEnum_PlutoGizmoHelperRuntime_EPlutoCollisionGizmoVisibility_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Always.DisplayName", "Always" },
		{ "Always.Name", "EPlutoCollisionGizmoVisibility::Always" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoTypes.h" },
		{ "SelectedInEditorOnly.DisplayName", "Selected In Editor Only" },
		{ "SelectedInEditorOnly.Name", "EPlutoCollisionGizmoVisibility::SelectedInEditorOnly" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPlutoCollisionGizmoVisibility::Always", (int64)EPlutoCollisionGizmoVisibility::Always },
		{ "EPlutoCollisionGizmoVisibility::SelectedInEditorOnly", (int64)EPlutoCollisionGizmoVisibility::SelectedInEditorOnly },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_PlutoGizmoHelperRuntime_EPlutoCollisionGizmoVisibility_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PlutoGizmoHelperRuntime_EPlutoCollisionGizmoVisibility_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_PlutoGizmoHelperRuntime,
	nullptr,
	"EPlutoCollisionGizmoVisibility",
	"EPlutoCollisionGizmoVisibility",
	Z_Construct_UEnum_PlutoGizmoHelperRuntime_EPlutoCollisionGizmoVisibility_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_PlutoGizmoHelperRuntime_EPlutoCollisionGizmoVisibility_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PlutoGizmoHelperRuntime_EPlutoCollisionGizmoVisibility_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PlutoGizmoHelperRuntime_EPlutoCollisionGizmoVisibility_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_PlutoGizmoHelperRuntime_EPlutoCollisionGizmoVisibility()
{
	if (!Z_Registration_Info_UEnum_EPlutoCollisionGizmoVisibility.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPlutoCollisionGizmoVisibility.InnerSingleton, Z_Construct_UEnum_PlutoGizmoHelperRuntime_EPlutoCollisionGizmoVisibility_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPlutoCollisionGizmoVisibility.InnerSingleton;
}
// ********** End Enum EPlutoCollisionGizmoVisibility **********************************************

// ********** Begin ScriptStruct FPlutoCollisionGizmoStyle *****************************************
struct Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPlutoCollisionGizmoStyle); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPlutoCollisionGizmoStyle); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawOutline_MetaData[] = {
		{ "Category", "Outline" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutlineColor_MetaData[] = {
		{ "Category", "Outline" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineThickness_MetaData[] = {
		{ "Category", "Outline" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoTypes.h" },
		{ "UIMax", "10.0" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawFill_MetaData[] = {
		{ "Category", "Fill" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FillColor_MetaData[] = {
		{ "Category", "Fill" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FillOpacity_MetaData[] = {
		{ "Category", "Fill" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoTypes.h" },
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPlutoCollisionGizmoStyle constinit property declarations *********
	static void NewProp_bDrawOutline_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawOutline;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutlineColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LineThickness;
	static void NewProp_bDrawFill_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawFill;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FillColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FillOpacity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPlutoCollisionGizmoStyle constinit property declarations ***********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlutoCollisionGizmoStyle>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPlutoCollisionGizmoStyle;
class UScriptStruct* FPlutoCollisionGizmoStyle::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPlutoCollisionGizmoStyle.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPlutoCollisionGizmoStyle.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle, (UObject*)Z_Construct_UPackage__Script_PlutoGizmoHelperRuntime(), TEXT("PlutoCollisionGizmoStyle"));
	}
	return Z_Registration_Info_UScriptStruct_FPlutoCollisionGizmoStyle.OuterSingleton;
	}

// ********** Begin ScriptStruct FPlutoCollisionGizmoStyle Property Definitions ********************
void Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_bDrawOutline_SetBit(void* Obj)
{
	((FPlutoCollisionGizmoStyle*)Obj)->bDrawOutline = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_bDrawOutline = { "bDrawOutline", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPlutoCollisionGizmoStyle), &Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_bDrawOutline_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawOutline_MetaData), NewProp_bDrawOutline_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_OutlineColor = { "OutlineColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoCollisionGizmoStyle, OutlineColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutlineColor_MetaData), NewProp_OutlineColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_LineThickness = { "LineThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoCollisionGizmoStyle, LineThickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineThickness_MetaData), NewProp_LineThickness_MetaData) };
void Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_bDrawFill_SetBit(void* Obj)
{
	((FPlutoCollisionGizmoStyle*)Obj)->bDrawFill = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_bDrawFill = { "bDrawFill", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPlutoCollisionGizmoStyle), &Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_bDrawFill_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawFill_MetaData), NewProp_bDrawFill_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_FillColor = { "FillColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoCollisionGizmoStyle, FillColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FillColor_MetaData), NewProp_FillColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_FillOpacity = { "FillOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoCollisionGizmoStyle, FillOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FillOpacity_MetaData), NewProp_FillOpacity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_bDrawOutline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_OutlineColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_LineThickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_bDrawFill,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_FillColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewProp_FillOpacity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPlutoCollisionGizmoStyle Property Definitions **********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PlutoGizmoHelperRuntime,
	nullptr,
	&NewStructOps,
	"PlutoCollisionGizmoStyle",
	Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::PropPointers),
	sizeof(FPlutoCollisionGizmoStyle),
	alignof(FPlutoCollisionGizmoStyle),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle()
{
	if (!Z_Registration_Info_UScriptStruct_FPlutoCollisionGizmoStyle.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPlutoCollisionGizmoStyle.InnerSingleton, Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPlutoCollisionGizmoStyle.InnerSingleton);
}
// ********** End ScriptStruct FPlutoCollisionGizmoStyle *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoTypes_h__Script_PlutoGizmoHelperRuntime_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EPlutoCollisionGizmoVisibility_StaticEnum, TEXT("EPlutoCollisionGizmoVisibility"), &Z_Registration_Info_UEnum_EPlutoCollisionGizmoVisibility, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3152319463U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPlutoCollisionGizmoStyle::StaticStruct, Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics::NewStructOps, TEXT("PlutoCollisionGizmoStyle"),&Z_Registration_Info_UScriptStruct_FPlutoCollisionGizmoStyle, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPlutoCollisionGizmoStyle), 4097913088U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoTypes_h__Script_PlutoGizmoHelperRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoTypes_h__Script_PlutoGizmoHelperRuntime_2546300081{
	TEXT("/Script/PlutoGizmoHelperRuntime"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoTypes_h__Script_PlutoGizmoHelperRuntime_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoTypes_h__Script_PlutoGizmoHelperRuntime_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoTypes_h__Script_PlutoGizmoHelperRuntime_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoTypes_h__Script_PlutoGizmoHelperRuntime_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
