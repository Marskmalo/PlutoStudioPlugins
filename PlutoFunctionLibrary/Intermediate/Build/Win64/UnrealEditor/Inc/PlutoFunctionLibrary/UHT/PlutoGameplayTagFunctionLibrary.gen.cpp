// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlutoGameplayTagFunctionLibrary.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePlutoGameplayTagFunctionLibrary() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
PLUTOFUNCTIONLIBRARY_API UClass* Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary();
PLUTOFUNCTIONLIBRARY_API UClass* Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_NoRegister();
PLUTOFUNCTIONLIBRARY_API UEnum* Z_Construct_UEnum_PlutoFunctionLibrary_EPlutoGameplayTagListeningPolicy();
UPackage* Z_Construct_UPackage__Script_PlutoFunctionLibrary();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EPlutoGameplayTagListeningPolicy ******************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPlutoGameplayTagListeningPolicy;
static UEnum* EPlutoGameplayTagListeningPolicy_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPlutoGameplayTagListeningPolicy.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPlutoGameplayTagListeningPolicy.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PlutoFunctionLibrary_EPlutoGameplayTagListeningPolicy, (UObject*)Z_Construct_UPackage__Script_PlutoFunctionLibrary(), TEXT("EPlutoGameplayTagListeningPolicy"));
	}
	return Z_Registration_Info_UEnum_EPlutoGameplayTagListeningPolicy.OuterSingleton;
}
template<> PLUTOFUNCTIONLIBRARY_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlutoGameplayTagListeningPolicy>()
{
	return EPlutoGameplayTagListeningPolicy_StaticEnum();
}
struct Z_Construct_UEnum_PlutoFunctionLibrary_EPlutoGameplayTagListeningPolicy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Added.DisplayName", "Added / \xe6\x96\xb0\xe5\xa2\x9e" },
		{ "Added.Name", "EPlutoGameplayTagListeningPolicy::Added" },
		{ "Added.ToolTip", "Fires when the specified Tag is added to the Container.\n\xe4\xbb\x85\xe5\xbd\x93\xe6\x8c\x87\xe5\xae\x9a Tag \xe8\xa2\xab\xe6\x96\xb0\xe5\xa2\x9e\xe8\x87\xb3\xe5\xae\xb9\xe5\x99\xa8\xe6\x97\xb6\xe8\xa7\xa6\xe5\x8f\x91\xe3\x80\x82" },
		{ "AddedOrRemoved.DisplayName", "Added or Removed / \xe6\x96\xb0\xe5\xa2\x9e\xe6\x88\x96\xe7\xa7\xbb\xe9\x99\xa4" },
		{ "AddedOrRemoved.Name", "EPlutoGameplayTagListeningPolicy::AddedOrRemoved" },
		{ "AddedOrRemoved.ToolTip", "Fires when the specified Tag is either added to or removed from the Container.\n\xe4\xbb\x85\xe5\xbd\x93\xe6\x8c\x87\xe5\xae\x9a Tag \xe8\xa2\xab\xe6\x96\xb0\xe5\xa2\x9e\xe8\x87\xb3\xe5\xae\xb9\xe5\x99\xa8\xe6\x88\x96\xe4\xbb\x8e\xe5\xae\xb9\xe5\x99\xa8\xe7\xa7\xbb\xe9\x99\xa4\xe6\x97\xb6\xe6\x89\x8d\xe4\xbc\x9a\xe5\x8f\x91\xe7\x94\x9f\xe4\xba\x8b\xe4\xbb\xb6\xe3\x80\x82" },
		{ "AnyCountChange.DisplayName", "Any Count Change / \xe4\xbb\xbb\xe4\xbd\x95\xe8\xae\xa1\xe6\x95\xb0\xe5\x8f\x98\xe6\x9b\xb4" },
		{ "AnyCountChange.Name", "EPlutoGameplayTagListeningPolicy::AnyCountChange" },
		{ "AnyCountChange.ToolTip", "Fires whenever the Container content changes. The Tag pin is ignored in this mode.\n\xe5\x8f\xaa\xe8\xa6\x81\xe5\xae\xb9\xe5\x99\xa8\xe5\x86\x85\xe5\xae\xb9\xe5\x8f\x91\xe7\x94\x9f\xe5\x8f\x98\xe5\x8c\x96\xe5\xb0\xb1\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe6\xad\xa4\xe6\xa8\xa1\xe5\xbc\x8f\xe4\xb8\x8b Tag \xe5\xbc\x95\xe8\x84\x9a\xe5\xb0\x86\xe8\xa2\xab\xe5\xbf\xbd\xe7\x95\xa5\xe3\x80\x82" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagFunctionLibrary.h" },
		{ "Removed.DisplayName", "Removed / \xe7\xa7\xbb\xe9\x99\xa4" },
		{ "Removed.Name", "EPlutoGameplayTagListeningPolicy::Removed" },
		{ "Removed.ToolTip", "Fires when the specified Tag is removed from the Container.\n\xe4\xbb\x85\xe5\xbd\x93\xe6\x8c\x87\xe5\xae\x9a Tag \xe8\xa2\xab\xe4\xbb\x8e\xe5\xae\xb9\xe5\x99\xa8\xe7\xa7\xbb\xe9\x99\xa4\xe6\x97\xb6\xe8\xa7\xa6\xe5\x8f\x91\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPlutoGameplayTagListeningPolicy::Added", (int64)EPlutoGameplayTagListeningPolicy::Added },
		{ "EPlutoGameplayTagListeningPolicy::Removed", (int64)EPlutoGameplayTagListeningPolicy::Removed },
		{ "EPlutoGameplayTagListeningPolicy::AddedOrRemoved", (int64)EPlutoGameplayTagListeningPolicy::AddedOrRemoved },
		{ "EPlutoGameplayTagListeningPolicy::AnyCountChange", (int64)EPlutoGameplayTagListeningPolicy::AnyCountChange },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_PlutoFunctionLibrary_EPlutoGameplayTagListeningPolicy_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PlutoFunctionLibrary_EPlutoGameplayTagListeningPolicy_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_PlutoFunctionLibrary,
	nullptr,
	"EPlutoGameplayTagListeningPolicy",
	"EPlutoGameplayTagListeningPolicy",
	Z_Construct_UEnum_PlutoFunctionLibrary_EPlutoGameplayTagListeningPolicy_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_PlutoFunctionLibrary_EPlutoGameplayTagListeningPolicy_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PlutoFunctionLibrary_EPlutoGameplayTagListeningPolicy_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PlutoFunctionLibrary_EPlutoGameplayTagListeningPolicy_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_PlutoFunctionLibrary_EPlutoGameplayTagListeningPolicy()
{
	if (!Z_Registration_Info_UEnum_EPlutoGameplayTagListeningPolicy.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPlutoGameplayTagListeningPolicy.InnerSingleton, Z_Construct_UEnum_PlutoFunctionLibrary_EPlutoGameplayTagListeningPolicy_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPlutoGameplayTagListeningPolicy.InnerSingleton;
}
// ********** End Enum EPlutoGameplayTagListeningPolicy ********************************************

// ********** Begin Class UPlutoGameplayTagFunctionLibrary Function PF_BatchAddGameplayTags ********
struct Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics
{
	struct PlutoGameplayTagFunctionLibrary_eventPF_BatchAddGameplayTags_Parms
	{
		FGameplayTagContainer TargetContainer;
		FGameplayTagContainer TagsToAdd;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Function Library|GameplayTag" },
		{ "DisplayName", "PF_BatchAddGameplayTags" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Add every tag from the source container into the target container.\n\xe6\x8a\x8a\xe6\x9d\xa5\xe6\xba\x90\xe5\xae\xb9\xe5\x99\xa8\xe4\xb8\xad\xe7\x9a\x84\xe5\x85\xa8\xe9\x83\xa8 Tag \xe6\x89\xb9\xe9\x87\x8f\xe6\xb7\xbb\xe5\x8a\xa0\xe5\x88\xb0\xe7\x9b\xae\xe6\xa0\x87\xe5\xae\xb9\xe5\x99\xa8\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function PF_BatchAddGameplayTags constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetContainer;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TagsToAdd;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PF_BatchAddGameplayTags constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PF_BatchAddGameplayTags Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::NewProp_TargetContainer = { "TargetContainer", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagFunctionLibrary_eventPF_BatchAddGameplayTags_Parms, TargetContainer), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 3438578166
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::NewProp_TagsToAdd = { "TagsToAdd", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagFunctionLibrary_eventPF_BatchAddGameplayTags_Parms, TagsToAdd), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 3438578166
void Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PlutoGameplayTagFunctionLibrary_eventPF_BatchAddGameplayTags_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PlutoGameplayTagFunctionLibrary_eventPF_BatchAddGameplayTags_Parms), &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::NewProp_TargetContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::NewProp_TagsToAdd,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::PropPointers) < 2048);
// ********** End Function PF_BatchAddGameplayTags Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary, nullptr, "PF_BatchAddGameplayTags", 	Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::PlutoGameplayTagFunctionLibrary_eventPF_BatchAddGameplayTags_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::PlutoGameplayTagFunctionLibrary_eventPF_BatchAddGameplayTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoGameplayTagFunctionLibrary::execPF_BatchAddGameplayTags)
{
	P_GET_STRUCT_REF(FGameplayTagContainer,Z_Param_Out_TargetContainer);
	P_GET_STRUCT(FGameplayTagContainer,Z_Param_TagsToAdd);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPlutoGameplayTagFunctionLibrary::PF_BatchAddGameplayTags(Z_Param_Out_TargetContainer,Z_Param_TagsToAdd);
	P_NATIVE_END;
}
// ********** End Class UPlutoGameplayTagFunctionLibrary Function PF_BatchAddGameplayTags **********

// ********** Begin Class UPlutoGameplayTagFunctionLibrary Function PF_BatchRemoveGameplayTags *****
struct Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics
{
	struct PlutoGameplayTagFunctionLibrary_eventPF_BatchRemoveGameplayTags_Parms
	{
		FGameplayTagContainer TargetContainer;
		FGameplayTagContainer TagsToRemove;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Function Library|GameplayTag" },
		{ "DisplayName", "PF_BatchRemoveGameplayTags" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Remove every matching tag from the target container.\n\xe4\xbb\x8e\xe7\x9b\xae\xe6\xa0\x87\xe5\xae\xb9\xe5\x99\xa8\xe4\xb8\xad\xe6\x89\xb9\xe9\x87\x8f\xe7\xa7\xbb\xe9\x99\xa4\xe6\x89\x80\xe6\x9c\x89\xe5\x8c\xb9\xe9\x85\x8d\xe7\x9a\x84 Tag\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function PF_BatchRemoveGameplayTags constinit property declarations ************
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetContainer;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TagsToRemove;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PF_BatchRemoveGameplayTags constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PF_BatchRemoveGameplayTags Property Definitions ***********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::NewProp_TargetContainer = { "TargetContainer", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagFunctionLibrary_eventPF_BatchRemoveGameplayTags_Parms, TargetContainer), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 3438578166
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::NewProp_TagsToRemove = { "TagsToRemove", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagFunctionLibrary_eventPF_BatchRemoveGameplayTags_Parms, TagsToRemove), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 3438578166
void Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PlutoGameplayTagFunctionLibrary_eventPF_BatchRemoveGameplayTags_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PlutoGameplayTagFunctionLibrary_eventPF_BatchRemoveGameplayTags_Parms), &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::NewProp_TargetContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::NewProp_TagsToRemove,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::PropPointers) < 2048);
// ********** End Function PF_BatchRemoveGameplayTags Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary, nullptr, "PF_BatchRemoveGameplayTags", 	Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::PlutoGameplayTagFunctionLibrary_eventPF_BatchRemoveGameplayTags_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::PlutoGameplayTagFunctionLibrary_eventPF_BatchRemoveGameplayTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoGameplayTagFunctionLibrary::execPF_BatchRemoveGameplayTags)
{
	P_GET_STRUCT_REF(FGameplayTagContainer,Z_Param_Out_TargetContainer);
	P_GET_STRUCT(FGameplayTagContainer,Z_Param_TagsToRemove);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPlutoGameplayTagFunctionLibrary::PF_BatchRemoveGameplayTags(Z_Param_Out_TargetContainer,Z_Param_TagsToRemove);
	P_NATIVE_END;
}
// ********** End Class UPlutoGameplayTagFunctionLibrary Function PF_BatchRemoveGameplayTags *******

// ********** Begin Class UPlutoGameplayTagFunctionLibrary Function PF_ClearGameplayTagContainer ***
struct Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics
{
	struct PlutoGameplayTagFunctionLibrary_eventPF_ClearGameplayTagContainer_Parms
	{
		FGameplayTagContainer TargetContainer;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Function Library|GameplayTag" },
		{ "DisplayName", "PF_ClearGameplayTagContainer" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear every tag from the target container.\n\xe6\xb8\x85\xe7\xa9\xba\xe7\x9b\xae\xe6\xa0\x87\xe5\xae\xb9\xe5\x99\xa8\xe4\xb8\xad\xe7\x9a\x84\xe5\x85\xa8\xe9\x83\xa8 Tag\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function PF_ClearGameplayTagContainer constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetContainer;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PF_ClearGameplayTagContainer constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PF_ClearGameplayTagContainer Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::NewProp_TargetContainer = { "TargetContainer", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagFunctionLibrary_eventPF_ClearGameplayTagContainer_Parms, TargetContainer), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 3438578166
void Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PlutoGameplayTagFunctionLibrary_eventPF_ClearGameplayTagContainer_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PlutoGameplayTagFunctionLibrary_eventPF_ClearGameplayTagContainer_Parms), &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::NewProp_TargetContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::PropPointers) < 2048);
// ********** End Function PF_ClearGameplayTagContainer Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary, nullptr, "PF_ClearGameplayTagContainer", 	Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::PlutoGameplayTagFunctionLibrary_eventPF_ClearGameplayTagContainer_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::PlutoGameplayTagFunctionLibrary_eventPF_ClearGameplayTagContainer_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoGameplayTagFunctionLibrary::execPF_ClearGameplayTagContainer)
{
	P_GET_STRUCT_REF(FGameplayTagContainer,Z_Param_Out_TargetContainer);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPlutoGameplayTagFunctionLibrary::PF_ClearGameplayTagContainer(Z_Param_Out_TargetContainer);
	P_NATIVE_END;
}
// ********** End Class UPlutoGameplayTagFunctionLibrary Function PF_ClearGameplayTagContainer *****

// ********** Begin Class UPlutoGameplayTagFunctionLibrary Function PF_DetectGameplayTagChanged ****
struct Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics
{
	struct PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms
	{
		FGameplayTagContainer Container;
		FGameplayTag Tag;
		EPlutoGameplayTagListeningPolicy Policy;
		FGameplayTagContainer LastContainerSnapshot;
		FGameplayTag ChangedTag;
		bool bHasInitialized;
		bool bExactMatch;
		bool bIgnoreFirstFrame;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Function Library|GameplayTag" },
		{ "CPP_Default_bExactMatch", "true" },
		{ "CPP_Default_bIgnoreFirstFrame", "false" },
		{ "DisplayName", "PF_DetectGameplayTagChanged" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Detect whether a specified Tag change occurred in the Container this frame by comparing it against a snapshot of the previous frame. The caller must store LastContainerSnapshot and bHasInitialized as member variables; the function updates them automatically before returning. When bExactMatch is true, exact tag matching is used. When false, hierarchical matching is used, so querying a parent Tag also matches its child Tags.\n\xe9\x80\x9a\xe8\xbf\x87\xe4\xb8\x8e\xe4\xb8\x8a\xe4\xb8\x80\xe5\xb8\xa7\xe5\xbf\xab\xe7\x85\xa7\xe6\xaf\x94\xe8\xbe\x83\xef\xbc\x8c\xe6\xa3\x80\xe6\xb5\x8b\xe6\x9c\xac\xe5\xb8\xa7 Container \xe4\xb8\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8f\x91\xe7\x94\x9f\xe4\xba\x86\xe6\x8c\x87\xe5\xae\x9a\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84 Tag \xe5\x8f\x98\xe5\x8c\x96\xe3\x80\x82\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe9\x9c\x80\xe5\xb0\x86 LastContainerSnapshot \xe5\x92\x8c bHasInitialized \xe5\xad\x98\xe4\xb8\xba\xe6\x88\x90\xe5\x91\x98\xe5\x8f\x98\xe9\x87\x8f\xef\xbc\x8c\xe5\x87\xbd\xe6\x95\xb0\xe4\xbc\x9a\xe5\x9c\xa8\xe8\xbf\x94\xe5\x9b\x9e\xe5\x89\x8d\xe8\x87\xaa\xe5\x8a\xa8\xe6\x9b\xb4\xe6\x96\xb0\xe5\xae\x83\xe4\xbb\xac\xe3\x80\x82\xe5\xbd\x93 bExactMatch \xe4\xb8\xba true \xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe7\xb2\xbe\xe7\xa1\xae\xe5\x8c\xb9\xe9\x85\x8d\xef\xbc\x9b\xe4\xb8\xba false \xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe5\xb1\x82\xe7\xba\xa7\xe5\x8c\xb9\xe9\x85\x8d\xef\xbc\x8c\xe6\xad\xa4\xe6\x97\xb6\xe7\x88\xb6\xe7\xba\xa7 Tag \xe6\x9f\xa5\xe8\xaf\xa2\xe4\xb9\x9f\xe4\xbc\x9a\xe5\x8c\xb9\xe9\x85\x8d\xe5\x85\xb6\xe5\xad\x90\xe7\xba\xa7 Tag\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Container_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function PF_DetectGameplayTagChanged constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_Container;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tag;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Policy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Policy;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastContainerSnapshot;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ChangedTag;
	static void NewProp_bHasInitialized_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasInitialized;
	static void NewProp_bExactMatch_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bExactMatch;
	static void NewProp_bIgnoreFirstFrame_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIgnoreFirstFrame;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PF_DetectGameplayTagChanged constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PF_DetectGameplayTagChanged Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_Container = { "Container", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms, Container), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Container_MetaData), NewProp_Container_MetaData) }; // 3438578166
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms, Tag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_Policy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_Policy = { "Policy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms, Policy), Z_Construct_UEnum_PlutoFunctionLibrary_EPlutoGameplayTagListeningPolicy, METADATA_PARAMS(0, nullptr) }; // 2903679809
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_LastContainerSnapshot = { "LastContainerSnapshot", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms, LastContainerSnapshot), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 3438578166
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_ChangedTag = { "ChangedTag", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms, ChangedTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_bHasInitialized_SetBit(void* Obj)
{
	((PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms*)Obj)->bHasInitialized = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_bHasInitialized = { "bHasInitialized", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms), &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_bHasInitialized_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_bExactMatch_SetBit(void* Obj)
{
	((PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms*)Obj)->bExactMatch = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_bExactMatch = { "bExactMatch", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms), &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_bExactMatch_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_bIgnoreFirstFrame_SetBit(void* Obj)
{
	((PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms*)Obj)->bIgnoreFirstFrame = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_bIgnoreFirstFrame = { "bIgnoreFirstFrame", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms), &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_bIgnoreFirstFrame_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms), &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_Container,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_Tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_Policy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_Policy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_LastContainerSnapshot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_ChangedTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_bHasInitialized,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_bExactMatch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_bIgnoreFirstFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::PropPointers) < 2048);
// ********** End Function PF_DetectGameplayTagChanged Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary, nullptr, "PF_DetectGameplayTagChanged", 	Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::PlutoGameplayTagFunctionLibrary_eventPF_DetectGameplayTagChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoGameplayTagFunctionLibrary::execPF_DetectGameplayTagChanged)
{
	P_GET_STRUCT_REF(FGameplayTagContainer,Z_Param_Out_Container);
	P_GET_STRUCT(FGameplayTag,Z_Param_Tag);
	P_GET_ENUM(EPlutoGameplayTagListeningPolicy,Z_Param_Policy);
	P_GET_STRUCT_REF(FGameplayTagContainer,Z_Param_Out_LastContainerSnapshot);
	P_GET_STRUCT_REF(FGameplayTag,Z_Param_Out_ChangedTag);
	P_GET_UBOOL_REF(Z_Param_Out_bHasInitialized);
	P_GET_UBOOL(Z_Param_bExactMatch);
	P_GET_UBOOL(Z_Param_bIgnoreFirstFrame);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPlutoGameplayTagFunctionLibrary::PF_DetectGameplayTagChanged(Z_Param_Out_Container,Z_Param_Tag,EPlutoGameplayTagListeningPolicy(Z_Param_Policy),Z_Param_Out_LastContainerSnapshot,Z_Param_Out_ChangedTag,Z_Param_Out_bHasInitialized,Z_Param_bExactMatch,Z_Param_bIgnoreFirstFrame);
	P_NATIVE_END;
}
// ********** End Class UPlutoGameplayTagFunctionLibrary Function PF_DetectGameplayTagChanged ******

// ********** Begin Class UPlutoGameplayTagFunctionLibrary Function PF_HasAllGameplayTags **********
struct Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics
{
	struct PlutoGameplayTagFunctionLibrary_eventPF_HasAllGameplayTags_Parms
	{
		FGameplayTagContainer TargetContainer;
		FGameplayTagContainer QueryContainer;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Function Library|GameplayTag" },
		{ "DisplayName", "PF_HasAllGameplayTags" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Return true when the target container contains every tag from the query container.\n\xe5\xbd\x93\xe7\x9b\xae\xe6\xa0\x87\xe5\xae\xb9\xe5\x99\xa8\xe5\x8c\x85\xe5\x90\xab\xe6\x9f\xa5\xe8\xaf\xa2\xe5\xae\xb9\xe5\x99\xa8\xe4\xb8\xad\xe7\x9a\x84\xe5\x85\xa8\xe9\x83\xa8 Tag \xe6\x97\xb6\xe8\xbf\x94\xe5\x9b\x9e\xe7\x9c\x9f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetContainer_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function PF_HasAllGameplayTags constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetContainer;
	static const UECodeGen_Private::FStructPropertyParams NewProp_QueryContainer;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PF_HasAllGameplayTags constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PF_HasAllGameplayTags Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::NewProp_TargetContainer = { "TargetContainer", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagFunctionLibrary_eventPF_HasAllGameplayTags_Parms, TargetContainer), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetContainer_MetaData), NewProp_TargetContainer_MetaData) }; // 3438578166
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::NewProp_QueryContainer = { "QueryContainer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagFunctionLibrary_eventPF_HasAllGameplayTags_Parms, QueryContainer), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 3438578166
void Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PlutoGameplayTagFunctionLibrary_eventPF_HasAllGameplayTags_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PlutoGameplayTagFunctionLibrary_eventPF_HasAllGameplayTags_Parms), &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::NewProp_TargetContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::NewProp_QueryContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::PropPointers) < 2048);
// ********** End Function PF_HasAllGameplayTags Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary, nullptr, "PF_HasAllGameplayTags", 	Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::PlutoGameplayTagFunctionLibrary_eventPF_HasAllGameplayTags_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::PlutoGameplayTagFunctionLibrary_eventPF_HasAllGameplayTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoGameplayTagFunctionLibrary::execPF_HasAllGameplayTags)
{
	P_GET_STRUCT_REF(FGameplayTagContainer,Z_Param_Out_TargetContainer);
	P_GET_STRUCT(FGameplayTagContainer,Z_Param_QueryContainer);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPlutoGameplayTagFunctionLibrary::PF_HasAllGameplayTags(Z_Param_Out_TargetContainer,Z_Param_QueryContainer);
	P_NATIVE_END;
}
// ********** End Class UPlutoGameplayTagFunctionLibrary Function PF_HasAllGameplayTags ************

// ********** Begin Class UPlutoGameplayTagFunctionLibrary Function PF_HasAnyGameplayTags **********
struct Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics
{
	struct PlutoGameplayTagFunctionLibrary_eventPF_HasAnyGameplayTags_Parms
	{
		FGameplayTagContainer TargetContainer;
		FGameplayTagContainer QueryContainer;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto Function Library|GameplayTag" },
		{ "DisplayName", "PF_HasAnyGameplayTags" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Return true when the target container contains any tag from the query container.\n\xe5\xbd\x93\xe7\x9b\xae\xe6\xa0\x87\xe5\xae\xb9\xe5\x99\xa8\xe5\x8c\x85\xe5\x90\xab\xe6\x9f\xa5\xe8\xaf\xa2\xe5\xae\xb9\xe5\x99\xa8\xe4\xb8\xad\xe7\x9a\x84\xe4\xbb\xbb\xe6\x84\x8f Tag \xe6\x97\xb6\xe8\xbf\x94\xe5\x9b\x9e\xe7\x9c\x9f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetContainer_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function PF_HasAnyGameplayTags constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetContainer;
	static const UECodeGen_Private::FStructPropertyParams NewProp_QueryContainer;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PF_HasAnyGameplayTags constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PF_HasAnyGameplayTags Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::NewProp_TargetContainer = { "TargetContainer", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagFunctionLibrary_eventPF_HasAnyGameplayTags_Parms, TargetContainer), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetContainer_MetaData), NewProp_TargetContainer_MetaData) }; // 3438578166
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::NewProp_QueryContainer = { "QueryContainer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagFunctionLibrary_eventPF_HasAnyGameplayTags_Parms, QueryContainer), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 3438578166
void Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PlutoGameplayTagFunctionLibrary_eventPF_HasAnyGameplayTags_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PlutoGameplayTagFunctionLibrary_eventPF_HasAnyGameplayTags_Parms), &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::NewProp_TargetContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::NewProp_QueryContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::PropPointers) < 2048);
// ********** End Function PF_HasAnyGameplayTags Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary, nullptr, "PF_HasAnyGameplayTags", 	Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::PlutoGameplayTagFunctionLibrary_eventPF_HasAnyGameplayTags_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::PlutoGameplayTagFunctionLibrary_eventPF_HasAnyGameplayTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlutoGameplayTagFunctionLibrary::execPF_HasAnyGameplayTags)
{
	P_GET_STRUCT_REF(FGameplayTagContainer,Z_Param_Out_TargetContainer);
	P_GET_STRUCT(FGameplayTagContainer,Z_Param_QueryContainer);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UPlutoGameplayTagFunctionLibrary::PF_HasAnyGameplayTags(Z_Param_Out_TargetContainer,Z_Param_QueryContainer);
	P_NATIVE_END;
}
// ********** End Class UPlutoGameplayTagFunctionLibrary Function PF_HasAnyGameplayTags ************

// ********** Begin Class UPlutoGameplayTagFunctionLibrary *****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPlutoGameplayTagFunctionLibrary;
UClass* UPlutoGameplayTagFunctionLibrary::GetPrivateStaticClass()
{
	using TClass = UPlutoGameplayTagFunctionLibrary;
	if (!Z_Registration_Info_UClass_UPlutoGameplayTagFunctionLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PlutoGameplayTagFunctionLibrary"),
			Z_Registration_Info_UClass_UPlutoGameplayTagFunctionLibrary.InnerSingleton,
			StaticRegisterNativesUPlutoGameplayTagFunctionLibrary,
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
	return Z_Registration_Info_UClass_UPlutoGameplayTagFunctionLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_NoRegister()
{
	return UPlutoGameplayTagFunctionLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "PlutoGameplayTagFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagFunctionLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UPlutoGameplayTagFunctionLibrary constinit property declarations *********
// ********** End Class UPlutoGameplayTagFunctionLibrary constinit property declarations ***********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("PF_BatchAddGameplayTags"), .Pointer = &UPlutoGameplayTagFunctionLibrary::execPF_BatchAddGameplayTags },
		{ .NameUTF8 = UTF8TEXT("PF_BatchRemoveGameplayTags"), .Pointer = &UPlutoGameplayTagFunctionLibrary::execPF_BatchRemoveGameplayTags },
		{ .NameUTF8 = UTF8TEXT("PF_ClearGameplayTagContainer"), .Pointer = &UPlutoGameplayTagFunctionLibrary::execPF_ClearGameplayTagContainer },
		{ .NameUTF8 = UTF8TEXT("PF_DetectGameplayTagChanged"), .Pointer = &UPlutoGameplayTagFunctionLibrary::execPF_DetectGameplayTagChanged },
		{ .NameUTF8 = UTF8TEXT("PF_HasAllGameplayTags"), .Pointer = &UPlutoGameplayTagFunctionLibrary::execPF_HasAllGameplayTags },
		{ .NameUTF8 = UTF8TEXT("PF_HasAnyGameplayTags"), .Pointer = &UPlutoGameplayTagFunctionLibrary::execPF_HasAnyGameplayTags },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchAddGameplayTags, "PF_BatchAddGameplayTags" }, // 1038187327
		{ &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_BatchRemoveGameplayTags, "PF_BatchRemoveGameplayTags" }, // 2116240340
		{ &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_ClearGameplayTagContainer, "PF_ClearGameplayTagContainer" }, // 3351491953
		{ &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_DetectGameplayTagChanged, "PF_DetectGameplayTagChanged" }, // 3927028728
		{ &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAllGameplayTags, "PF_HasAllGameplayTags" }, // 2374861175
		{ &Z_Construct_UFunction_UPlutoGameplayTagFunctionLibrary_PF_HasAnyGameplayTags, "PF_HasAnyGameplayTags" }, // 550132667
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlutoGameplayTagFunctionLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_Statics
UObject* (*const Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_PlutoFunctionLibrary,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_Statics::ClassParams = {
	&UPlutoGameplayTagFunctionLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_Statics::Class_MetaDataParams)
};
void UPlutoGameplayTagFunctionLibrary::StaticRegisterNativesUPlutoGameplayTagFunctionLibrary()
{
	UClass* Class = UPlutoGameplayTagFunctionLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary()
{
	if (!Z_Registration_Info_UClass_UPlutoGameplayTagFunctionLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlutoGameplayTagFunctionLibrary.OuterSingleton, Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPlutoGameplayTagFunctionLibrary.OuterSingleton;
}
UPlutoGameplayTagFunctionLibrary::UPlutoGameplayTagFunctionLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPlutoGameplayTagFunctionLibrary);
UPlutoGameplayTagFunctionLibrary::~UPlutoGameplayTagFunctionLibrary() {}
// ********** End Class UPlutoGameplayTagFunctionLibrary *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h__Script_PlutoFunctionLibrary_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EPlutoGameplayTagListeningPolicy_StaticEnum, TEXT("EPlutoGameplayTagListeningPolicy"), &Z_Registration_Info_UEnum_EPlutoGameplayTagListeningPolicy, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2903679809U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary, UPlutoGameplayTagFunctionLibrary::StaticClass, TEXT("UPlutoGameplayTagFunctionLibrary"), &Z_Registration_Info_UClass_UPlutoGameplayTagFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlutoGameplayTagFunctionLibrary), 4228793409U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h__Script_PlutoFunctionLibrary_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h__Script_PlutoFunctionLibrary_304218333{
	TEXT("/Script/PlutoFunctionLibrary"),
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h__Script_PlutoFunctionLibrary_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h__Script_PlutoFunctionLibrary_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h__Script_PlutoFunctionLibrary_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h__Script_PlutoFunctionLibrary_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
