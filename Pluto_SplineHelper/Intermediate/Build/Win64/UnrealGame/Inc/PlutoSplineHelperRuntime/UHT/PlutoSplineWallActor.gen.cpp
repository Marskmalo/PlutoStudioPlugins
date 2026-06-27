// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlutoSplineWallActor.h"
#include "PlutoSplineWallTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePlutoSplineWallActor() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_ULineBatchComponent_NoRegister();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ESplinePointType();
GEOMETRYFRAMEWORK_API UClass* Z_Construct_UClass_UDynamicMeshComponent_NoRegister();
PLUTOSPLINEHELPERRUNTIME_API UClass* Z_Construct_UClass_APlutoSplineWall();
PLUTOSPLINEHELPERRUNTIME_API UClass* Z_Construct_UClass_APlutoSplineWall_NoRegister();
PLUTOSPLINEHELPERRUNTIME_API UClass* Z_Construct_UClass_UPlutoSplineWallSplineComponent_NoRegister();
PLUTOSPLINEHELPERRUNTIME_API UEnum* Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallDirection();
PLUTOSPLINEHELPERRUNTIME_API UEnum* Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallEditorPreview();
PLUTOSPLINEHELPERRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle();
UPackage* Z_Construct_UPackage__Script_PlutoSplineHelperRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class APlutoSplineWall Function ApplySplinePointTypeToAll **********************
struct Z_Construct_UFunction_APlutoSplineWall_ApplySplinePointTypeToAll_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Spline Wall" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplySplinePointTypeToAll constinit property declarations *************
// ********** End Function ApplySplinePointTypeToAll constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlutoSplineWall_ApplySplinePointTypeToAll_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APlutoSplineWall, nullptr, "ApplySplinePointTypeToAll", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlutoSplineWall_ApplySplinePointTypeToAll_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlutoSplineWall_ApplySplinePointTypeToAll_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_APlutoSplineWall_ApplySplinePointTypeToAll()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlutoSplineWall_ApplySplinePointTypeToAll_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlutoSplineWall::execApplySplinePointTypeToAll)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplySplinePointTypeToAll();
	P_NATIVE_END;
}
// ********** End Class APlutoSplineWall Function ApplySplinePointTypeToAll ************************

// ********** Begin Class APlutoSplineWall Function GetValidationMessage ***************************
struct Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage_Statics
{
	struct PlutoSplineWall_eventGetValidationMessage_Parms
	{
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Spline Wall" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetValidationMessage constinit property declarations ******************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetValidationMessage constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetValidationMessage Property Definitions *****************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoSplineWall_eventGetValidationMessage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage_Statics::PropPointers) < 2048);
// ********** End Function GetValidationMessage Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APlutoSplineWall, nullptr, "GetValidationMessage", 	Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage_Statics::PlutoSplineWall_eventGetValidationMessage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage_Statics::PlutoSplineWall_eventGetValidationMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlutoSplineWall::execGetValidationMessage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetValidationMessage();
	P_NATIVE_END;
}
// ********** End Class APlutoSplineWall Function GetValidationMessage *****************************

// ********** Begin Class APlutoSplineWall Function IsCurrentShapeValid ****************************
struct Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics
{
	struct PlutoSplineWall_eventIsCurrentShapeValid_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Spline Wall" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsCurrentShapeValid constinit property declarations *******************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsCurrentShapeValid constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsCurrentShapeValid Property Definitions ******************************
void Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PlutoSplineWall_eventIsCurrentShapeValid_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PlutoSplineWall_eventIsCurrentShapeValid_Parms), &Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics::PropPointers) < 2048);
// ********** End Function IsCurrentShapeValid Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APlutoSplineWall, nullptr, "IsCurrentShapeValid", 	Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics::PlutoSplineWall_eventIsCurrentShapeValid_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics::PlutoSplineWall_eventIsCurrentShapeValid_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlutoSplineWall::execIsCurrentShapeValid)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsCurrentShapeValid();
	P_NATIVE_END;
}
// ********** End Class APlutoSplineWall Function IsCurrentShapeValid ******************************

// ********** Begin Class APlutoSplineWall Function RebuildWall ************************************
struct Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics
{
	struct PlutoSplineWall_eventRebuildWall_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Spline Wall" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RebuildWall constinit property declarations ***************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RebuildWall constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RebuildWall Property Definitions **************************************
void Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PlutoSplineWall_eventRebuildWall_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PlutoSplineWall_eventRebuildWall_Parms), &Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics::PropPointers) < 2048);
// ********** End Function RebuildWall Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APlutoSplineWall, nullptr, "RebuildWall", 	Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics::PlutoSplineWall_eventRebuildWall_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics::PlutoSplineWall_eventRebuildWall_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlutoSplineWall_RebuildWall()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlutoSplineWall_RebuildWall_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlutoSplineWall::execRebuildWall)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RebuildWall();
	P_NATIVE_END;
}
// ********** End Class APlutoSplineWall Function RebuildWall **************************************

// ********** Begin Class APlutoSplineWall *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_APlutoSplineWall;
UClass* APlutoSplineWall::GetPrivateStaticClass()
{
	using TClass = APlutoSplineWall;
	if (!Z_Registration_Info_UClass_APlutoSplineWall.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PlutoSplineWall"),
			Z_Registration_Info_UClass_APlutoSplineWall.InnerSingleton,
			StaticRegisterNativesAPlutoSplineWall,
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
	return Z_Registration_Info_UClass_APlutoSplineWall.InnerSingleton;
}
UClass* Z_Construct_UClass_APlutoSplineWall_NoRegister()
{
	return APlutoSplineWall::GetPrivateStaticClass();
}
struct Z_Construct_UClass_APlutoSplineWall_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "Pluto Spline Wall" },
		{ "IncludePath", "PlutoSplineWallActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Spline_MetaData[] = {
		{ "Category", "Pluto Spline Wall" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionMesh_MetaData[] = {
		{ "Category", "Pluto Spline Wall" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Preview_MetaData[] = {
		{ "Category", "Pluto Spline Wall" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bClosedLoop_MetaData[] = {
		{ "Category", "Pluto Spline Wall|Geometry" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[] = {
		{ "Category", "Pluto Spline Wall|Geometry" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BottomOffset_MetaData[] = {
		{ "Category", "Pluto Spline Wall|Geometry" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SampleSpacing_MetaData[] = {
		{ "Category", "Pluto Spline Wall|Geometry" },
		{ "ClampMin", "5.0" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenWallThickness_MetaData[] = {
		{ "Category", "Pluto Spline Wall|Geometry" },
		{ "ClampMin", "1.0" },
		{ "EditCondition", "!bClosedLoop" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AllSplinePointType_MetaData[] = {
		{ "Category", "Pluto Spline Wall|Geometry" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[] = {
		{ "Category", "Pluto Spline Wall|Geometry" },
		{ "EditCondition", "bClosedLoop" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCollisionTopCap_MetaData[] = {
		{ "Category", "Pluto Spline Wall|Caps" },
		{ "EditCondition", "bClosedLoop" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCollisionBottomCap_MetaData[] = {
		{ "Category", "Pluto Spline Wall|Caps" },
		{ "EditCondition", "bClosedLoop" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPreviewTopCap_MetaData[] = {
		{ "Category", "Pluto Spline Wall|Caps" },
		{ "EditCondition", "bClosedLoop" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPreviewBottomCap_MetaData[] = {
		{ "Category", "Pluto Spline Wall|Caps" },
		{ "EditCondition", "bClosedLoop" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EditorPreview_MetaData[] = {
		{ "Category", "Pluto Spline Wall|Preview" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowPreviewInPIE_MetaData[] = {
		{ "Category", "Pluto Spline Wall|Preview" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewStyle_MetaData[] = {
		{ "Category", "Pluto Spline Wall|Preview" },
		{ "ModuleRelativePath", "Public/PlutoSplineWallActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class APlutoSplineWall constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Spline;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CollisionMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Preview;
	static void NewProp_bClosedLoop_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bClosedLoop;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Height;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BottomOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SampleSpacing;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenWallThickness;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AllSplinePointType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Direction_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Direction;
	static void NewProp_bCollisionTopCap_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCollisionTopCap;
	static void NewProp_bCollisionBottomCap_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCollisionBottomCap;
	static void NewProp_bPreviewTopCap_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreviewTopCap;
	static void NewProp_bPreviewBottomCap_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreviewBottomCap;
	static const UECodeGen_Private::FBytePropertyParams NewProp_EditorPreview_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EditorPreview;
	static void NewProp_bShowPreviewInPIE_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowPreviewInPIE;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviewStyle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class APlutoSplineWall constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplySplinePointTypeToAll"), .Pointer = &APlutoSplineWall::execApplySplinePointTypeToAll },
		{ .NameUTF8 = UTF8TEXT("GetValidationMessage"), .Pointer = &APlutoSplineWall::execGetValidationMessage },
		{ .NameUTF8 = UTF8TEXT("IsCurrentShapeValid"), .Pointer = &APlutoSplineWall::execIsCurrentShapeValid },
		{ .NameUTF8 = UTF8TEXT("RebuildWall"), .Pointer = &APlutoSplineWall::execRebuildWall },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_APlutoSplineWall_ApplySplinePointTypeToAll, "ApplySplinePointTypeToAll" }, // 2154375170
		{ &Z_Construct_UFunction_APlutoSplineWall_GetValidationMessage, "GetValidationMessage" }, // 1834173611
		{ &Z_Construct_UFunction_APlutoSplineWall_IsCurrentShapeValid, "IsCurrentShapeValid" }, // 91682366
		{ &Z_Construct_UFunction_APlutoSplineWall_RebuildWall, "RebuildWall" }, // 1402268001
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlutoSplineWall>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_APlutoSplineWall_Statics

// ********** Begin Class APlutoSplineWall Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_Spline = { "Spline", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlutoSplineWall, Spline), Z_Construct_UClass_UPlutoSplineWallSplineComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Spline_MetaData), NewProp_Spline_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_CollisionMesh = { "CollisionMesh", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlutoSplineWall, CollisionMesh), Z_Construct_UClass_UDynamicMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionMesh_MetaData), NewProp_CollisionMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_Preview = { "Preview", nullptr, (EPropertyFlags)0x01140000000a201d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlutoSplineWall, Preview), Z_Construct_UClass_ULineBatchComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Preview_MetaData), NewProp_Preview_MetaData) };
void Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bClosedLoop_SetBit(void* Obj)
{
	((APlutoSplineWall*)Obj)->bClosedLoop = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bClosedLoop = { "bClosedLoop", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APlutoSplineWall), &Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bClosedLoop_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bClosedLoop_MetaData), NewProp_bClosedLoop_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlutoSplineWall, Height), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Height_MetaData), NewProp_Height_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_BottomOffset = { "BottomOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlutoSplineWall, BottomOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BottomOffset_MetaData), NewProp_BottomOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_SampleSpacing = { "SampleSpacing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlutoSplineWall, SampleSpacing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SampleSpacing_MetaData), NewProp_SampleSpacing_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_OpenWallThickness = { "OpenWallThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlutoSplineWall, OpenWallThickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenWallThickness_MetaData), NewProp_OpenWallThickness_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_AllSplinePointType = { "AllSplinePointType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlutoSplineWall, AllSplinePointType), Z_Construct_UEnum_Engine_ESplinePointType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AllSplinePointType_MetaData), NewProp_AllSplinePointType_MetaData) }; // 1424505408
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_Direction_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlutoSplineWall, Direction), Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallDirection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Direction_MetaData), NewProp_Direction_MetaData) }; // 2098914241
void Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bCollisionTopCap_SetBit(void* Obj)
{
	((APlutoSplineWall*)Obj)->bCollisionTopCap = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bCollisionTopCap = { "bCollisionTopCap", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APlutoSplineWall), &Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bCollisionTopCap_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCollisionTopCap_MetaData), NewProp_bCollisionTopCap_MetaData) };
void Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bCollisionBottomCap_SetBit(void* Obj)
{
	((APlutoSplineWall*)Obj)->bCollisionBottomCap = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bCollisionBottomCap = { "bCollisionBottomCap", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APlutoSplineWall), &Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bCollisionBottomCap_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCollisionBottomCap_MetaData), NewProp_bCollisionBottomCap_MetaData) };
void Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bPreviewTopCap_SetBit(void* Obj)
{
	((APlutoSplineWall*)Obj)->bPreviewTopCap = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bPreviewTopCap = { "bPreviewTopCap", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APlutoSplineWall), &Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bPreviewTopCap_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPreviewTopCap_MetaData), NewProp_bPreviewTopCap_MetaData) };
void Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bPreviewBottomCap_SetBit(void* Obj)
{
	((APlutoSplineWall*)Obj)->bPreviewBottomCap = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bPreviewBottomCap = { "bPreviewBottomCap", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APlutoSplineWall), &Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bPreviewBottomCap_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPreviewBottomCap_MetaData), NewProp_bPreviewBottomCap_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_EditorPreview_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_EditorPreview = { "EditorPreview", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlutoSplineWall, EditorPreview), Z_Construct_UEnum_PlutoSplineHelperRuntime_EPlutoSplineWallEditorPreview, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EditorPreview_MetaData), NewProp_EditorPreview_MetaData) }; // 3593849892
void Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bShowPreviewInPIE_SetBit(void* Obj)
{
	((APlutoSplineWall*)Obj)->bShowPreviewInPIE = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bShowPreviewInPIE = { "bShowPreviewInPIE", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APlutoSplineWall), &Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bShowPreviewInPIE_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowPreviewInPIE_MetaData), NewProp_bShowPreviewInPIE_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_PreviewStyle = { "PreviewStyle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlutoSplineWall, PreviewStyle), Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewStyle_MetaData), NewProp_PreviewStyle_MetaData) }; // 3553090776
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APlutoSplineWall_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_Spline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_CollisionMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_Preview,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bClosedLoop,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_Height,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_BottomOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_SampleSpacing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_OpenWallThickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_AllSplinePointType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_Direction_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_Direction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bCollisionTopCap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bCollisionBottomCap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bPreviewTopCap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bPreviewBottomCap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_EditorPreview_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_EditorPreview,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_bShowPreviewInPIE,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlutoSplineWall_Statics::NewProp_PreviewStyle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlutoSplineWall_Statics::PropPointers) < 2048);
// ********** End Class APlutoSplineWall Property Definitions **************************************
UObject* (*const Z_Construct_UClass_APlutoSplineWall_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_PlutoSplineHelperRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlutoSplineWall_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APlutoSplineWall_Statics::ClassParams = {
	&APlutoSplineWall::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_APlutoSplineWall_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_APlutoSplineWall_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlutoSplineWall_Statics::Class_MetaDataParams), Z_Construct_UClass_APlutoSplineWall_Statics::Class_MetaDataParams)
};
void APlutoSplineWall::StaticRegisterNativesAPlutoSplineWall()
{
	UClass* Class = APlutoSplineWall::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_APlutoSplineWall_Statics::Funcs));
}
UClass* Z_Construct_UClass_APlutoSplineWall()
{
	if (!Z_Registration_Info_UClass_APlutoSplineWall.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APlutoSplineWall.OuterSingleton, Z_Construct_UClass_APlutoSplineWall_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APlutoSplineWall.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, APlutoSplineWall);
APlutoSplineWall::~APlutoSplineWall() {}
// ********** End Class APlutoSplineWall ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallActor_h__Script_PlutoSplineHelperRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APlutoSplineWall, APlutoSplineWall::StaticClass, TEXT("APlutoSplineWall"), &Z_Registration_Info_UClass_APlutoSplineWall, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlutoSplineWall), 3045336591U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallActor_h__Script_PlutoSplineHelperRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallActor_h__Script_PlutoSplineHelperRuntime_770296773{
	TEXT("/Script/PlutoSplineHelperRuntime"),
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallActor_h__Script_PlutoSplineHelperRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallActor_h__Script_PlutoSplineHelperRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
