// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlutoCollisionGizmoComponent.h"
#include "Engine/EngineTypes.h"
#include "PlutoCollisionGizmoTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePlutoCollisionGizmoComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent();
ENGINE_API UClass* Z_Construct_UClass_UShapeComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FComponentReference();
PLUTOGIZMOHELPERRUNTIME_API UClass* Z_Construct_UClass_UPlutoCollisionGizmoComponent();
PLUTOGIZMOHELPERRUNTIME_API UClass* Z_Construct_UClass_UPlutoCollisionGizmoComponent_NoRegister();
PLUTOGIZMOHELPERRUNTIME_API UEnum* Z_Construct_UEnum_PlutoGizmoHelperRuntime_EPlutoCollisionGizmoVisibility();
PLUTOGIZMOHELPERRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle();
UPackage* Z_Construct_UPackage__Script_PlutoGizmoHelperRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPlutoCollisionGizmoComponent Function GetTargetCollision ****************
struct Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision_Statics
{
	struct PlutoCollisionGizmoComponent_eventGetTargetCollision_Parms
	{
		UShapeComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Gizmo" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTargetCollision constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTargetCollision constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTargetCollision Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoCollisionGizmoComponent_eventGetTargetCollision_Parms, ReturnValue), Z_Construct_UClass_UShapeComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision_Statics::PropPointers) < 2048);
// ********** End Function GetTargetCollision Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoCollisionGizmoComponent, nullptr, "GetTargetCollision", 	Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision_Statics::PlutoCollisionGizmoComponent_eventGetTargetCollision_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision_Statics::PlutoCollisionGizmoComponent_eventGetTargetCollision_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoCollisionGizmoComponent::execGetTargetCollision)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UShapeComponent**)Z_Param__Result=P_THIS->GetTargetCollision();
	P_NATIVE_END;
}
// ********** End Class UPlutoCollisionGizmoComponent Function GetTargetCollision ******************

// ********** Begin Class UPlutoCollisionGizmoComponent Function RefreshGizmo **********************
struct Z_Construct_UFunction_UPlutoCollisionGizmoComponent_RefreshGizmo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Gizmo" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshGizmo constinit property declarations **************************
// ********** End Function RefreshGizmo constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_RefreshGizmo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoCollisionGizmoComponent, nullptr, "RefreshGizmo", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_RefreshGizmo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoCollisionGizmoComponent_RefreshGizmo_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UPlutoCollisionGizmoComponent_RefreshGizmo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoCollisionGizmoComponent_RefreshGizmo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoCollisionGizmoComponent::execRefreshGizmo)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshGizmo();
	P_NATIVE_END;
}
// ********** End Class UPlutoCollisionGizmoComponent Function RefreshGizmo ************************

// ********** Begin Class UPlutoCollisionGizmoComponent Function SetDrawFill ***********************
struct Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics
{
	struct PlutoCollisionGizmoComponent_eventSetDrawFill_Parms
	{
		bool bDraw;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Gizmo|Style" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDrawFill constinit property declarations ***************************
	static void NewProp_bDraw_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDraw;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDrawFill constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDrawFill Property Definitions **************************************
void Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics::NewProp_bDraw_SetBit(void* Obj)
{
	((PlutoCollisionGizmoComponent_eventSetDrawFill_Parms*)Obj)->bDraw = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics::NewProp_bDraw = { "bDraw", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PlutoCollisionGizmoComponent_eventSetDrawFill_Parms), &Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics::NewProp_bDraw_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics::NewProp_bDraw,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics::PropPointers) < 2048);
// ********** End Function SetDrawFill Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoCollisionGizmoComponent, nullptr, "SetDrawFill", 	Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics::PlutoCollisionGizmoComponent_eventSetDrawFill_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics::PlutoCollisionGizmoComponent_eventSetDrawFill_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoCollisionGizmoComponent::execSetDrawFill)
{
	P_GET_UBOOL(Z_Param_bDraw);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDrawFill(Z_Param_bDraw);
	P_NATIVE_END;
}
// ********** End Class UPlutoCollisionGizmoComponent Function SetDrawFill *************************

// ********** Begin Class UPlutoCollisionGizmoComponent Function SetDrawOutline ********************
struct Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics
{
	struct PlutoCollisionGizmoComponent_eventSetDrawOutline_Parms
	{
		bool bDraw;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Gizmo|Style" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDrawOutline constinit property declarations ************************
	static void NewProp_bDraw_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDraw;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDrawOutline constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDrawOutline Property Definitions ***********************************
void Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics::NewProp_bDraw_SetBit(void* Obj)
{
	((PlutoCollisionGizmoComponent_eventSetDrawOutline_Parms*)Obj)->bDraw = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics::NewProp_bDraw = { "bDraw", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PlutoCollisionGizmoComponent_eventSetDrawOutline_Parms), &Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics::NewProp_bDraw_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics::NewProp_bDraw,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics::PropPointers) < 2048);
// ********** End Function SetDrawOutline Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoCollisionGizmoComponent, nullptr, "SetDrawOutline", 	Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics::PlutoCollisionGizmoComponent_eventSetDrawOutline_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics::PlutoCollisionGizmoComponent_eventSetDrawOutline_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoCollisionGizmoComponent::execSetDrawOutline)
{
	P_GET_UBOOL(Z_Param_bDraw);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDrawOutline(Z_Param_bDraw);
	P_NATIVE_END;
}
// ********** End Class UPlutoCollisionGizmoComponent Function SetDrawOutline **********************

// ********** Begin Class UPlutoCollisionGizmoComponent Function SetFillColor **********************
struct Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor_Statics
{
	struct PlutoCollisionGizmoComponent_eventSetFillColor_Parms
	{
		FLinearColor Color;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Gizmo|Style" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetFillColor constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFillColor constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFillColor Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoCollisionGizmoComponent_eventSetFillColor_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor_Statics::NewProp_Color,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor_Statics::PropPointers) < 2048);
// ********** End Function SetFillColor Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoCollisionGizmoComponent, nullptr, "SetFillColor", 	Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor_Statics::PlutoCollisionGizmoComponent_eventSetFillColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor_Statics::PlutoCollisionGizmoComponent_eventSetFillColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoCollisionGizmoComponent::execSetFillColor)
{
	P_GET_STRUCT(FLinearColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFillColor(Z_Param_Color);
	P_NATIVE_END;
}
// ********** End Class UPlutoCollisionGizmoComponent Function SetFillColor ************************

// ********** Begin Class UPlutoCollisionGizmoComponent Function SetFillOpacity ********************
struct Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity_Statics
{
	struct PlutoCollisionGizmoComponent_eventSetFillOpacity_Parms
	{
		float Opacity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Gizmo|Style" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetFillOpacity constinit property declarations ************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Opacity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFillOpacity constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFillOpacity Property Definitions ***********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity_Statics::NewProp_Opacity = { "Opacity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoCollisionGizmoComponent_eventSetFillOpacity_Parms, Opacity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity_Statics::NewProp_Opacity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetFillOpacity Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoCollisionGizmoComponent, nullptr, "SetFillOpacity", 	Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity_Statics::PlutoCollisionGizmoComponent_eventSetFillOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity_Statics::PlutoCollisionGizmoComponent_eventSetFillOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoCollisionGizmoComponent::execSetFillOpacity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Opacity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFillOpacity(Z_Param_Opacity);
	P_NATIVE_END;
}
// ********** End Class UPlutoCollisionGizmoComponent Function SetFillOpacity **********************

// ********** Begin Class UPlutoCollisionGizmoComponent Function SetGizmoEnabled *******************
struct Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics
{
	struct PlutoCollisionGizmoComponent_eventSetGizmoEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Gizmo" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetGizmoEnabled constinit property declarations ***********************
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetGizmoEnabled constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetGizmoEnabled Property Definitions **********************************
void Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((PlutoCollisionGizmoComponent_eventSetGizmoEnabled_Parms*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PlutoCollisionGizmoComponent_eventSetGizmoEnabled_Parms), &Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics::PropPointers) < 2048);
// ********** End Function SetGizmoEnabled Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoCollisionGizmoComponent, nullptr, "SetGizmoEnabled", 	Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics::PlutoCollisionGizmoComponent_eventSetGizmoEnabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics::PlutoCollisionGizmoComponent_eventSetGizmoEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoCollisionGizmoComponent::execSetGizmoEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetGizmoEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UPlutoCollisionGizmoComponent Function SetGizmoEnabled *********************

// ********** Begin Class UPlutoCollisionGizmoComponent Function SetLineThickness ******************
struct Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness_Statics
{
	struct PlutoCollisionGizmoComponent_eventSetLineThickness_Parms
	{
		float Thickness;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Gizmo|Style" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetLineThickness constinit property declarations **********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Thickness;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetLineThickness constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetLineThickness Property Definitions *********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness_Statics::NewProp_Thickness = { "Thickness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoCollisionGizmoComponent_eventSetLineThickness_Parms, Thickness), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness_Statics::NewProp_Thickness,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness_Statics::PropPointers) < 2048);
// ********** End Function SetLineThickness Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoCollisionGizmoComponent, nullptr, "SetLineThickness", 	Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness_Statics::PlutoCollisionGizmoComponent_eventSetLineThickness_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness_Statics::PlutoCollisionGizmoComponent_eventSetLineThickness_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoCollisionGizmoComponent::execSetLineThickness)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Thickness);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLineThickness(Z_Param_Thickness);
	P_NATIVE_END;
}
// ********** End Class UPlutoCollisionGizmoComponent Function SetLineThickness ********************

// ********** Begin Class UPlutoCollisionGizmoComponent Function SetOutlineColor *******************
struct Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor_Statics
{
	struct PlutoCollisionGizmoComponent_eventSetOutlineColor_Parms
	{
		FLinearColor Color;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Gizmo|Style" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetOutlineColor constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetOutlineColor constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetOutlineColor Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoCollisionGizmoComponent_eventSetOutlineColor_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor_Statics::NewProp_Color,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor_Statics::PropPointers) < 2048);
// ********** End Function SetOutlineColor Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoCollisionGizmoComponent, nullptr, "SetOutlineColor", 	Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor_Statics::PlutoCollisionGizmoComponent_eventSetOutlineColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor_Statics::PlutoCollisionGizmoComponent_eventSetOutlineColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoCollisionGizmoComponent::execSetOutlineColor)
{
	P_GET_STRUCT(FLinearColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetOutlineColor(Z_Param_Color);
	P_NATIVE_END;
}
// ********** End Class UPlutoCollisionGizmoComponent Function SetOutlineColor *********************

// ********** Begin Class UPlutoCollisionGizmoComponent Function SetStyle **************************
struct Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle_Statics
{
	struct PlutoCollisionGizmoComponent_eventSetStyle_Parms
	{
		FPlutoCollisionGizmoStyle Style;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Gizmo|Style" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Style_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetStyle constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Style;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetStyle constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetStyle Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle_Statics::NewProp_Style = { "Style", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoCollisionGizmoComponent_eventSetStyle_Parms, Style), Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Style_MetaData), NewProp_Style_MetaData) }; // 4097913088
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle_Statics::NewProp_Style,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle_Statics::PropPointers) < 2048);
// ********** End Function SetStyle Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoCollisionGizmoComponent, nullptr, "SetStyle", 	Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle_Statics::PlutoCollisionGizmoComponent_eventSetStyle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle_Statics::PlutoCollisionGizmoComponent_eventSetStyle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoCollisionGizmoComponent::execSetStyle)
{
	P_GET_STRUCT_REF(FPlutoCollisionGizmoStyle,Z_Param_Out_Style);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetStyle(Z_Param_Out_Style);
	P_NATIVE_END;
}
// ********** End Class UPlutoCollisionGizmoComponent Function SetStyle ****************************

// ********** Begin Class UPlutoCollisionGizmoComponent Function SetTargetCollision ****************
struct Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision_Statics
{
	struct PlutoCollisionGizmoComponent_eventSetTargetCollision_Parms
	{
		UShapeComponent* InTargetCollision;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Gizmo" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InTargetCollision_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetTargetCollision constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InTargetCollision;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTargetCollision constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTargetCollision Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision_Statics::NewProp_InTargetCollision = { "InTargetCollision", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoCollisionGizmoComponent_eventSetTargetCollision_Parms, InTargetCollision), Z_Construct_UClass_UShapeComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InTargetCollision_MetaData), NewProp_InTargetCollision_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision_Statics::NewProp_InTargetCollision,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision_Statics::PropPointers) < 2048);
// ********** End Function SetTargetCollision Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoCollisionGizmoComponent, nullptr, "SetTargetCollision", 	Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision_Statics::PlutoCollisionGizmoComponent_eventSetTargetCollision_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision_Statics::PlutoCollisionGizmoComponent_eventSetTargetCollision_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoCollisionGizmoComponent::execSetTargetCollision)
{
	P_GET_OBJECT(UShapeComponent,Z_Param_InTargetCollision);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTargetCollision(Z_Param_InTargetCollision);
	P_NATIVE_END;
}
// ********** End Class UPlutoCollisionGizmoComponent Function SetTargetCollision ******************

// ********** Begin Class UPlutoCollisionGizmoComponent ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPlutoCollisionGizmoComponent;
UClass* UPlutoCollisionGizmoComponent::GetPrivateStaticClass()
{
	using TClass = UPlutoCollisionGizmoComponent;
	if (!Z_Registration_Info_UClass_UPlutoCollisionGizmoComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PlutoCollisionGizmoComponent"),
			Z_Registration_Info_UClass_UPlutoCollisionGizmoComponent.InnerSingleton,
			StaticRegisterNativesUPlutoCollisionGizmoComponent,
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
	return Z_Registration_Info_UClass_UPlutoCollisionGizmoComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UPlutoCollisionGizmoComponent_NoRegister()
{
	return UPlutoCollisionGizmoComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Pluto" },
		{ "DisplayName", "Pluto Collision Gizmo" },
		{ "HideCategories", "Mobility VirtualTexture Trigger" },
		{ "IncludePath", "PlutoCollisionGizmoComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetCollision_MetaData[] = {
		{ "AllowedClasses", "/Script/Engine.BoxComponent,/Script/Engine.SphereComponent,/Script/Engine.CapsuleComponent" },
		{ "Category", "Pluto Gizmo|Target" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
		{ "UseComponentPicker", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bGizmoEnabled_MetaData[] = {
		{ "Category", "Pluto Gizmo" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisibilityMode_MetaData[] = {
		{ "Category", "Pluto Gizmo" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideProjectStyle_MetaData[] = {
		{ "Category", "Pluto Gizmo|Style" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverrideStyle_MetaData[] = {
		{ "Category", "Pluto Gizmo|Style" },
		{ "EditCondition", "bOverrideProjectStyle" },
		{ "ModuleRelativePath", "Public/PlutoCollisionGizmoComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UPlutoCollisionGizmoComponent constinit property declarations ************
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetCollision;
	static void NewProp_bGizmoEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bGizmoEnabled;
	static const UECodeGen_Private::FBytePropertyParams NewProp_VisibilityMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_VisibilityMode;
	static void NewProp_bOverrideProjectStyle_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideProjectStyle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OverrideStyle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UPlutoCollisionGizmoComponent constinit property declarations **************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetTargetCollision"), .Pointer = &UPlutoCollisionGizmoComponent::execGetTargetCollision },
		{ .NameUTF8 = UTF8TEXT("RefreshGizmo"), .Pointer = &UPlutoCollisionGizmoComponent::execRefreshGizmo },
		{ .NameUTF8 = UTF8TEXT("SetDrawFill"), .Pointer = &UPlutoCollisionGizmoComponent::execSetDrawFill },
		{ .NameUTF8 = UTF8TEXT("SetDrawOutline"), .Pointer = &UPlutoCollisionGizmoComponent::execSetDrawOutline },
		{ .NameUTF8 = UTF8TEXT("SetFillColor"), .Pointer = &UPlutoCollisionGizmoComponent::execSetFillColor },
		{ .NameUTF8 = UTF8TEXT("SetFillOpacity"), .Pointer = &UPlutoCollisionGizmoComponent::execSetFillOpacity },
		{ .NameUTF8 = UTF8TEXT("SetGizmoEnabled"), .Pointer = &UPlutoCollisionGizmoComponent::execSetGizmoEnabled },
		{ .NameUTF8 = UTF8TEXT("SetLineThickness"), .Pointer = &UPlutoCollisionGizmoComponent::execSetLineThickness },
		{ .NameUTF8 = UTF8TEXT("SetOutlineColor"), .Pointer = &UPlutoCollisionGizmoComponent::execSetOutlineColor },
		{ .NameUTF8 = UTF8TEXT("SetStyle"), .Pointer = &UPlutoCollisionGizmoComponent::execSetStyle },
		{ .NameUTF8 = UTF8TEXT("SetTargetCollision"), .Pointer = &UPlutoCollisionGizmoComponent::execSetTargetCollision },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPlutoCollisionGizmoComponent_GetTargetCollision, "GetTargetCollision" }, // 1392422433
		{ &Z_Construct_UFunction_UPlutoCollisionGizmoComponent_RefreshGizmo, "RefreshGizmo" }, // 3324445075
		{ &Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawFill, "SetDrawFill" }, // 4115360363
		{ &Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetDrawOutline, "SetDrawOutline" }, // 1692604562
		{ &Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillColor, "SetFillColor" }, // 523371098
		{ &Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetFillOpacity, "SetFillOpacity" }, // 3235253380
		{ &Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetGizmoEnabled, "SetGizmoEnabled" }, // 241103024
		{ &Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetLineThickness, "SetLineThickness" }, // 2760363588
		{ &Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetOutlineColor, "SetOutlineColor" }, // 2675456883
		{ &Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetStyle, "SetStyle" }, // 3128825839
		{ &Z_Construct_UFunction_UPlutoCollisionGizmoComponent_SetTargetCollision, "SetTargetCollision" }, // 2728351399
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlutoCollisionGizmoComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics

// ********** Begin Class UPlutoCollisionGizmoComponent Property Definitions ***********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_TargetCollision = { "TargetCollision", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlutoCollisionGizmoComponent, TargetCollision), Z_Construct_UScriptStruct_FComponentReference, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetCollision_MetaData), NewProp_TargetCollision_MetaData) }; // 3934819661
void Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_bGizmoEnabled_SetBit(void* Obj)
{
	((UPlutoCollisionGizmoComponent*)Obj)->bGizmoEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_bGizmoEnabled = { "bGizmoEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPlutoCollisionGizmoComponent), &Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_bGizmoEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bGizmoEnabled_MetaData), NewProp_bGizmoEnabled_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_VisibilityMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_VisibilityMode = { "VisibilityMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlutoCollisionGizmoComponent, VisibilityMode), Z_Construct_UEnum_PlutoGizmoHelperRuntime_EPlutoCollisionGizmoVisibility, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisibilityMode_MetaData), NewProp_VisibilityMode_MetaData) }; // 3152319463
void Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_bOverrideProjectStyle_SetBit(void* Obj)
{
	((UPlutoCollisionGizmoComponent*)Obj)->bOverrideProjectStyle = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_bOverrideProjectStyle = { "bOverrideProjectStyle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPlutoCollisionGizmoComponent), &Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_bOverrideProjectStyle_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideProjectStyle_MetaData), NewProp_bOverrideProjectStyle_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_OverrideStyle = { "OverrideStyle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlutoCollisionGizmoComponent, OverrideStyle), Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverrideStyle_MetaData), NewProp_OverrideStyle_MetaData) }; // 4097913088
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_TargetCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_bGizmoEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_VisibilityMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_VisibilityMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_bOverrideProjectStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::NewProp_OverrideStyle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::PropPointers) < 2048);
// ********** End Class UPlutoCollisionGizmoComponent Property Definitions *************************
UObject* (*const Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimitiveComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_PlutoGizmoHelperRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::ClassParams = {
	&UPlutoCollisionGizmoComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::Class_MetaDataParams)
};
void UPlutoCollisionGizmoComponent::StaticRegisterNativesUPlutoCollisionGizmoComponent()
{
	UClass* Class = UPlutoCollisionGizmoComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPlutoCollisionGizmoComponent()
{
	if (!Z_Registration_Info_UClass_UPlutoCollisionGizmoComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlutoCollisionGizmoComponent.OuterSingleton, Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPlutoCollisionGizmoComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPlutoCollisionGizmoComponent);
UPlutoCollisionGizmoComponent::~UPlutoCollisionGizmoComponent() {}
// ********** End Class UPlutoCollisionGizmoComponent **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoComponent_h__Script_PlutoGizmoHelperRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPlutoCollisionGizmoComponent, UPlutoCollisionGizmoComponent::StaticClass, TEXT("UPlutoCollisionGizmoComponent"), &Z_Registration_Info_UClass_UPlutoCollisionGizmoComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlutoCollisionGizmoComponent), 1545123508U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoComponent_h__Script_PlutoGizmoHelperRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoComponent_h__Script_PlutoGizmoHelperRuntime_4119070755{
	TEXT("/Script/PlutoGizmoHelperRuntime"),
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoComponent_h__Script_PlutoGizmoHelperRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoComponent_h__Script_PlutoGizmoHelperRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
