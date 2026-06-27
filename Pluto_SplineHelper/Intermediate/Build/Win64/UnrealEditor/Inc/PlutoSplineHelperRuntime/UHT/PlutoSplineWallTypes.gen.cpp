// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlutoSplineWallTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePlutoSplineWallTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
PLUTOSPLINEHELPERRUNTIME_API UEnum* Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallDirection();
PLUTOSPLINEHELPERRUNTIME_API UEnum* Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallEditorPreview();
PLUTOSPLINEHELPERRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle();
UPackage* Z_Construct_UPackage__Script_PlutoSplineHelperRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EPlutoSplineWallDirection *************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPlutoSplineWallDirection;
static UEnum* EPlutoSplineWallDirection_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPlutoSplineWallDirection.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPlutoSplineWallDirection.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallDirection, (UObject*)Z_Construct_UPackage__Script_PlutoSplineHelperRuntime(), TEXT("EPlutoSplineWallDirection"));
	}
	return Z_Registration_Info_UEnum_EPlutoSplineWallDirection.OuterSingleton;
}
template<> PLUTOSPLINEHELPERRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlutoSplineWallDirection>()
{
	return EPlutoSplineWallDirection_StaticEnum();
}
struct Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallDirection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallTypes.h" },
		{ "ProcessExternalObjects.DisplayName", "Process External Objects" },
		{ "ProcessExternalObjects.Name", "EPlutoSplineWallDirection::ProcessExternalObjects" },
		{ "ProcessInternalObjects.DisplayName", "Process Internal Objects" },
		{ "ProcessInternalObjects.Name", "EPlutoSplineWallDirection::ProcessInternalObjects" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPlutoSplineWallDirection::ProcessExternalObjects", (int64)EPlutoSplineWallDirection::ProcessExternalObjects },
		{ "EPlutoSplineWallDirection::ProcessInternalObjects", (int64)EPlutoSplineWallDirection::ProcessInternalObjects },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallDirection_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallDirection_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_PlutoSplineHelperRuntime,
	nullptr,
	"EPlutoSplineWallDirection",
	"EPlutoSplineWallDirection",
	Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallDirection_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallDirection_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallDirection_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallDirection_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallDirection()
{
	if (!Z_Registration_Info_UEnum_EPlutoSplineWallDirection.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPlutoSplineWallDirection.InnerSingleton, Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallDirection_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPlutoSplineWallDirection.InnerSingleton;
}
// ********** End Enum EPlutoSplineWallDirection ***************************************************

// ********** Begin Enum EPlutoSplineWallEditorPreview *********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPlutoSplineWallEditorPreview;
static UEnum* EPlutoSplineWallEditorPreview_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPlutoSplineWallEditorPreview.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPlutoSplineWallEditorPreview.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallEditorPreview, (UObject*)Z_Construct_UPackage__Script_PlutoSplineHelperRuntime(), TEXT("EPlutoSplineWallEditorPreview"));
	}
	return Z_Registration_Info_UEnum_EPlutoSplineWallEditorPreview.OuterSingleton;
}
template<> PLUTOSPLINEHELPERRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlutoSplineWallEditorPreview>()
{
	return EPlutoSplineWallEditorPreview_StaticEnum();
}
struct Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallEditorPreview_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Always.DisplayName", "Always" },
		{ "Always.Name", "EPlutoSplineWallEditorPreview::Always" },
		{ "BlueprintType", "true" },
		{ "Hidden.DisplayName", "Hidden" },
		{ "Hidden.Name", "EPlutoSplineWallEditorPreview::Hidden" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallTypes.h" },
		{ "SelectedOnly.DisplayName", "Selected Only" },
		{ "SelectedOnly.Name", "EPlutoSplineWallEditorPreview::SelectedOnly" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPlutoSplineWallEditorPreview::Always", (int64)EPlutoSplineWallEditorPreview::Always },
		{ "EPlutoSplineWallEditorPreview::SelectedOnly", (int64)EPlutoSplineWallEditorPreview::SelectedOnly },
		{ "EPlutoSplineWallEditorPreview::Hidden", (int64)EPlutoSplineWallEditorPreview::Hidden },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallEditorPreview_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallEditorPreview_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_PlutoSplineHelperRuntime,
	nullptr,
	"EPlutoSplineWallEditorPreview",
	"EPlutoSplineWallEditorPreview",
	Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallEditorPreview_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallEditorPreview_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallEditorPreview_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallEditorPreview_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallEditorPreview()
{
	if (!Z_Registration_Info_UEnum_EPlutoSplineWallEditorPreview.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPlutoSplineWallEditorPreview.InnerSingleton, Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallEditorPreview_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPlutoSplineWallEditorPreview.InnerSingleton;
}
// ********** End Enum EPlutoSplineWallEditorPreview ***********************************************

// ********** Begin ScriptStruct FPlutoSplineWallPreviewStyle **************************************
struct Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPlutoSplineWallPreviewStyle); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPlutoSplineWallPreviewStyle); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FillColor_MetaData[] = {
		{ "Category", "Fill" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FillOpacity_MetaData[] = {
		{ "Category", "Fill" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutlineColor_MetaData[] = {
		{ "Category", "Outline" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineThickness_MetaData[] = {
		{ "Category", "Outline" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallTypes.h" },
		{ "UIMax", "10.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowDirectionArrows_MetaData[] = {
		{ "Category", "Direction" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DirectionArrowColor_MetaData[] = {
		{ "Category", "Direction" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DirectionArrowSpacing_MetaData[] = {
		{ "Category", "Direction" },
		{ "ClampMin", "50.0" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenWallWireColor_MetaData[] = {
		{ "Category", "Open Wall Thickness" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPlutoSplineWallPreviewStyle constinit property declarations ******
	static const UECodeGen_Private::FStructPropertyParams NewProp_FillColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FillOpacity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutlineColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LineThickness;
	static void NewProp_bShowDirectionArrows_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDirectionArrows;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DirectionArrowColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DirectionArrowSpacing;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OpenWallWireColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPlutoSplineWallPreviewStyle constinit property declarations ********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlutoSplineWallPreviewStyle>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPlutoSplineWallPreviewStyle;
class UScriptStruct* FPlutoSplineWallPreviewStyle::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPlutoSplineWallPreviewStyle.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPlutoSplineWallPreviewStyle.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle, (UObject*)Z_Construct_UPackage__Script_PlutoSplineHelperRuntime(), TEXT("PlutoSplineWallPreviewStyle"));
	}
	return Z_Registration_Info_UScriptStruct_FPlutoSplineWallPreviewStyle.OuterSingleton;
	}

// ********** Begin ScriptStruct FPlutoSplineWallPreviewStyle Property Definitions *****************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_FillColor = { "FillColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoSplineWallPreviewStyle, FillColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FillColor_MetaData), NewProp_FillColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_FillOpacity = { "FillOpacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoSplineWallPreviewStyle, FillOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FillOpacity_MetaData), NewProp_FillOpacity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_OutlineColor = { "OutlineColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoSplineWallPreviewStyle, OutlineColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutlineColor_MetaData), NewProp_OutlineColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_LineThickness = { "LineThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoSplineWallPreviewStyle, LineThickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineThickness_MetaData), NewProp_LineThickness_MetaData) };
void Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_bShowDirectionArrows_SetBit(void* Obj)
{
	((FPlutoSplineWallPreviewStyle*)Obj)->bShowDirectionArrows = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_bShowDirectionArrows = { "bShowDirectionArrows", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPlutoSplineWallPreviewStyle), &Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_bShowDirectionArrows_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowDirectionArrows_MetaData), NewProp_bShowDirectionArrows_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_DirectionArrowColor = { "DirectionArrowColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoSplineWallPreviewStyle, DirectionArrowColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DirectionArrowColor_MetaData), NewProp_DirectionArrowColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_DirectionArrowSpacing = { "DirectionArrowSpacing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoSplineWallPreviewStyle, DirectionArrowSpacing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DirectionArrowSpacing_MetaData), NewProp_DirectionArrowSpacing_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_OpenWallWireColor = { "OpenWallWireColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoSplineWallPreviewStyle, OpenWallWireColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenWallWireColor_MetaData), NewProp_OpenWallWireColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_FillColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_FillOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_OutlineColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_LineThickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_bShowDirectionArrows,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_DirectionArrowColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_DirectionArrowSpacing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewProp_OpenWallWireColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPlutoSplineWallPreviewStyle Property Definitions *******************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PlutoSplineHelperRuntime,
	nullptr,
	&NewStructOps,
	"PlutoSplineWallPreviewStyle",
	Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::PropPointers),
	sizeof(FPlutoSplineWallPreviewStyle),
	alignof(FPlutoSplineWallPreviewStyle),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle()
{
	if (!Z_Registration_Info_UScriptStruct_FPlutoSplineWallPreviewStyle.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPlutoSplineWallPreviewStyle.InnerSingleton, Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPlutoSplineWallPreviewStyle.InnerSingleton);
}
// ********** End ScriptStruct FPlutoSplineWallPreviewStyle ****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallTypes_h__Script_PlutoSplineHelperRuntime_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EPlutoSplineWallDirection_StaticEnum, TEXT("EPlutoSplineWallDirection"), &Z_Registration_Info_UEnum_EPlutoSplineWallDirection, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2098914241U) },
		{ EPlutoSplineWallEditorPreview_StaticEnum, TEXT("EPlutoSplineWallEditorPreview"), &Z_Registration_Info_UEnum_EPlutoSplineWallEditorPreview, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3593849892U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPlutoSplineWallPreviewStyle::StaticStruct, Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics::NewStructOps, TEXT("PlutoSplineWallPreviewStyle"),&Z_Registration_Info_UScriptStruct_FPlutoSplineWallPreviewStyle, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPlutoSplineWallPreviewStyle), 3553090776U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallTypes_h__Script_PlutoSplineHelperRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallTypes_h__Script_PlutoSplineHelperRuntime_43781587{
	TEXT("/Script/PlutoSplineHelperRuntime"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallTypes_h__Script_PlutoSplineHelperRuntime_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallTypes_h__Script_PlutoSplineHelperRuntime_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallTypes_h__Script_PlutoSplineHelperRuntime_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallTypes_h__Script_PlutoSplineHelperRuntime_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
