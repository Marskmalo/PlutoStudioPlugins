// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlutoGameplayTagContainerProvider.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePlutoGameplayTagContainerProvider() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
PLUTOGAMEPLAYTAGINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UPlutoGameplayTagContainerProvider();
PLUTOGAMEPLAYTAGINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UPlutoGameplayTagContainerProvider_NoRegister();
PLUTOGAMEPLAYTAGINSPECTORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor();
PLUTOGAMEPLAYTAGINSPECTORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor();
UPackage* Z_Construct_UPackage__Script_PlutoGameplayTagInspectorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FPlutoGameplayTagContainerDescriptor ******************************
struct Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPlutoGameplayTagContainerDescriptor); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPlutoGameplayTagContainerDescriptor); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagContainerProvider.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContainerName_MetaData[] = {
		{ "Category", "Pluto GameplayTag Inspector" },
		{ "DisplayName", "Container Name" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagContainerProvider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Inspector-facing container name.\n\xe4\xbe\x9b\xe6\xa3\x80\xe6\x9f\xa5\xe5\x99\xa8\xe6\x98\xbe\xe7\xa4\xba\xe7\x9a\x84\xe5\xae\xb9\xe5\x99\xa8\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContainerPath_MetaData[] = {
		{ "Category", "Pluto GameplayTag Inspector" },
		{ "DisplayName", "Container Path" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagContainerProvider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Property path or custom path for this container.\n\xe8\xaf\xa5\xe5\xae\xb9\xe5\x99\xa8\xe7\x9a\x84\xe5\xb1\x9e\xe6\x80\xa7\xe8\xb7\xaf\xe5\xbe\x84\xe6\x88\x96\xe8\x87\xaa\xe5\xae\x9a\xe4\xb9\x89\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameplayTags_MetaData[] = {
		{ "Category", "Pluto GameplayTag Inspector" },
		{ "DisplayName", "Gameplay Tags" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagContainerProvider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gameplay tags stored in this container.\n\xe8\xbf\x99\xe4\xb8\xaa\xe5\xae\xb9\xe5\x99\xa8\xe9\x87\x8c\xe5\xad\x98\xe6\x94\xbe\xe7\x9a\x84 GameplayTag\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPlutoGameplayTagContainerDescriptor constinit property declarations 
	static const UECodeGen_Private::FNamePropertyParams NewProp_ContainerName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ContainerPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GameplayTags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPlutoGameplayTagContainerDescriptor constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlutoGameplayTagContainerDescriptor>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPlutoGameplayTagContainerDescriptor;
class UScriptStruct* FPlutoGameplayTagContainerDescriptor::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPlutoGameplayTagContainerDescriptor.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPlutoGameplayTagContainerDescriptor.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor, (UObject*)Z_Construct_UPackage__Script_PlutoGameplayTagInspectorRuntime(), TEXT("PlutoGameplayTagContainerDescriptor"));
	}
	return Z_Registration_Info_UScriptStruct_FPlutoGameplayTagContainerDescriptor.OuterSingleton;
	}

// ********** Begin ScriptStruct FPlutoGameplayTagContainerDescriptor Property Definitions *********
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::NewProp_ContainerName = { "ContainerName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoGameplayTagContainerDescriptor, ContainerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContainerName_MetaData), NewProp_ContainerName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::NewProp_ContainerPath = { "ContainerPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoGameplayTagContainerDescriptor, ContainerPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContainerPath_MetaData), NewProp_ContainerPath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::NewProp_GameplayTags = { "GameplayTags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoGameplayTagContainerDescriptor, GameplayTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameplayTags_MetaData), NewProp_GameplayTags_MetaData) }; // 3438578166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::NewProp_ContainerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::NewProp_ContainerPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::NewProp_GameplayTags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPlutoGameplayTagContainerDescriptor Property Definitions ***********
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PlutoGameplayTagInspectorRuntime,
	nullptr,
	&NewStructOps,
	"PlutoGameplayTagContainerDescriptor",
	Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::PropPointers),
	sizeof(FPlutoGameplayTagContainerDescriptor),
	alignof(FPlutoGameplayTagContainerDescriptor),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor()
{
	if (!Z_Registration_Info_UScriptStruct_FPlutoGameplayTagContainerDescriptor.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPlutoGameplayTagContainerDescriptor.InnerSingleton, Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPlutoGameplayTagContainerDescriptor.InnerSingleton);
}
// ********** End ScriptStruct FPlutoGameplayTagContainerDescriptor ********************************

// ********** Begin ScriptStruct FPlutoGameplayTagDescriptor ***************************************
struct Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FPlutoGameplayTagDescriptor); }
	static inline consteval int16 GetStructAlignment() { return alignof(FPlutoGameplayTagDescriptor); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagContainerProvider.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TagPath_MetaData[] = {
		{ "Category", "Pluto GameplayTag Inspector" },
		{ "DisplayName", "Tag Path" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagContainerProvider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Property path for this isolated gameplay tag." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameplayTag_MetaData[] = {
		{ "Category", "Pluto GameplayTag Inspector" },
		{ "DisplayName", "Gameplay Tag" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagContainerProvider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A standalone gameplay tag that is not stored in a gameplay tag container." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FPlutoGameplayTagDescriptor constinit property declarations *******
	static const UECodeGen_Private::FStrPropertyParams NewProp_TagPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GameplayTag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FPlutoGameplayTagDescriptor constinit property declarations *********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlutoGameplayTagDescriptor>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPlutoGameplayTagDescriptor;
class UScriptStruct* FPlutoGameplayTagDescriptor::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPlutoGameplayTagDescriptor.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPlutoGameplayTagDescriptor.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor, (UObject*)Z_Construct_UPackage__Script_PlutoGameplayTagInspectorRuntime(), TEXT("PlutoGameplayTagDescriptor"));
	}
	return Z_Registration_Info_UScriptStruct_FPlutoGameplayTagDescriptor.OuterSingleton;
	}

// ********** Begin ScriptStruct FPlutoGameplayTagDescriptor Property Definitions ******************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics::NewProp_TagPath = { "TagPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoGameplayTagDescriptor, TagPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TagPath_MetaData), NewProp_TagPath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics::NewProp_GameplayTag = { "GameplayTag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlutoGameplayTagDescriptor, GameplayTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameplayTag_MetaData), NewProp_GameplayTag_MetaData) }; // 517357616
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics::NewProp_TagPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics::NewProp_GameplayTag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FPlutoGameplayTagDescriptor Property Definitions ********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PlutoGameplayTagInspectorRuntime,
	nullptr,
	&NewStructOps,
	"PlutoGameplayTagDescriptor",
	Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics::PropPointers),
	sizeof(FPlutoGameplayTagDescriptor),
	alignof(FPlutoGameplayTagDescriptor),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor()
{
	if (!Z_Registration_Info_UScriptStruct_FPlutoGameplayTagDescriptor.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPlutoGameplayTagDescriptor.InnerSingleton, Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FPlutoGameplayTagDescriptor.InnerSingleton);
}
// ********** End ScriptStruct FPlutoGameplayTagDescriptor *****************************************

// ********** Begin Interface UPlutoGameplayTagContainerProvider Function PF_GetInspectableGameplayTagContainers 
struct PlutoGameplayTagContainerProvider_eventPF_GetInspectableGameplayTagContainers_Parms
{
	TArray<FPlutoGameplayTagContainerDescriptor> OutContainers;
};
void IPlutoGameplayTagContainerProvider::PF_GetInspectableGameplayTagContainers(TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_PF_GetInspectableGameplayTagContainers instead.");
}
static FName NAME_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers = FName(TEXT("PF_GetInspectableGameplayTagContainers"));
void IPlutoGameplayTagContainerProvider::Execute_PF_GetInspectableGameplayTagContainers(const UObject* O, TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UPlutoGameplayTagContainerProvider::StaticClass()));
	PlutoGameplayTagContainerProvider_eventPF_GetInspectableGameplayTagContainers_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers);
	if (Func)
	{
		Parms.OutContainers=std::move(OutContainers);
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
		OutContainers=std::move(Parms.OutContainers);
	}
	else if (auto I = (const IPlutoGameplayTagContainerProvider*)(O->GetNativeInterfaceAddress(UPlutoGameplayTagContainerProvider::StaticClass())))
	{
		I->PF_GetInspectableGameplayTagContainers_Implementation(OutContainers);
	}
}
struct Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pluto GameplayTag Inspector" },
		{ "DisplayName", "PF_GetInspectableGameplayTagContainers" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagContainerProvider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Return named gameplay tag containers for the Pluto inspector.\n\xe8\xbf\x94\xe5\x9b\x9e\xe4\xbe\x9b Pluto \xe6\xa3\x80\xe6\x9f\xa5\xe5\x99\xa8\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe5\x85\xb7\xe5\x90\x8d GameplayTag \xe5\xae\xb9\xe5\x99\xa8\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function PF_GetInspectableGameplayTagContainers constinit property declarations 
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutContainers_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutContainers;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PF_GetInspectableGameplayTagContainers constinit property declarations **
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PF_GetInspectableGameplayTagContainers Property Definitions ***********
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers_Statics::NewProp_OutContainers_Inner = { "OutContainers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor, METADATA_PARAMS(0, nullptr) }; // 3026502342
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers_Statics::NewProp_OutContainers = { "OutContainers", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlutoGameplayTagContainerProvider_eventPF_GetInspectableGameplayTagContainers_Parms, OutContainers), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3026502342
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers_Statics::NewProp_OutContainers_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers_Statics::NewProp_OutContainers,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers_Statics::PropPointers) < 2048);
// ********** End Function PF_GetInspectableGameplayTagContainers Property Definitions *************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPlutoGameplayTagContainerProvider, nullptr, "PF_GetInspectableGameplayTagContainers", 	Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers_Statics::PropPointers), 
sizeof(PlutoGameplayTagContainerProvider_eventPF_GetInspectableGameplayTagContainers_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(PlutoGameplayTagContainerProvider_eventPF_GetInspectableGameplayTagContainers_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IPlutoGameplayTagContainerProvider::execPF_GetInspectableGameplayTagContainers)
{
	P_GET_TARRAY_REF(FPlutoGameplayTagContainerDescriptor,Z_Param_Out_OutContainers);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PF_GetInspectableGameplayTagContainers_Implementation(Z_Param_Out_OutContainers);
	P_NATIVE_END;
}
// ********** End Interface UPlutoGameplayTagContainerProvider Function PF_GetInspectableGameplayTagContainers 

// ********** Begin Interface UPlutoGameplayTagContainerProvider ***********************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPlutoGameplayTagContainerProvider;
UClass* UPlutoGameplayTagContainerProvider::GetPrivateStaticClass()
{
	using TClass = UPlutoGameplayTagContainerProvider;
	if (!Z_Registration_Info_UClass_UPlutoGameplayTagContainerProvider.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PlutoGameplayTagContainerProvider"),
			Z_Registration_Info_UClass_UPlutoGameplayTagContainerProvider.InnerSingleton,
			StaticRegisterNativesUPlutoGameplayTagContainerProvider,
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
	return Z_Registration_Info_UClass_UPlutoGameplayTagContainerProvider.InnerSingleton;
}
UClass* Z_Construct_UClass_UPlutoGameplayTagContainerProvider_NoRegister()
{
	return UPlutoGameplayTagContainerProvider::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPlutoGameplayTagContainerProvider_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PlutoGameplayTagContainerProvider.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UPlutoGameplayTagContainerProvider constinit property declarations ***
// ********** End Interface UPlutoGameplayTagContainerProvider constinit property declarations *****
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("PF_GetInspectableGameplayTagContainers"), .Pointer = &IPlutoGameplayTagContainerProvider::execPF_GetInspectableGameplayTagContainers },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPlutoGameplayTagContainerProvider_PF_GetInspectableGameplayTagContainers, "PF_GetInspectableGameplayTagContainers" }, // 230977855
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IPlutoGameplayTagContainerProvider>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPlutoGameplayTagContainerProvider_Statics
UObject* (*const Z_Construct_UClass_UPlutoGameplayTagContainerProvider_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_PlutoGameplayTagInspectorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGameplayTagContainerProvider_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlutoGameplayTagContainerProvider_Statics::ClassParams = {
	&UPlutoGameplayTagContainerProvider::StaticClass,
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
	0x001040A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlutoGameplayTagContainerProvider_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlutoGameplayTagContainerProvider_Statics::Class_MetaDataParams)
};
void UPlutoGameplayTagContainerProvider::StaticRegisterNativesUPlutoGameplayTagContainerProvider()
{
	UClass* Class = UPlutoGameplayTagContainerProvider::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPlutoGameplayTagContainerProvider_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPlutoGameplayTagContainerProvider()
{
	if (!Z_Registration_Info_UClass_UPlutoGameplayTagContainerProvider.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlutoGameplayTagContainerProvider.OuterSingleton, Z_Construct_UClass_UPlutoGameplayTagContainerProvider_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPlutoGameplayTagContainerProvider.OuterSingleton;
}
UPlutoGameplayTagContainerProvider::UPlutoGameplayTagContainerProvider(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPlutoGameplayTagContainerProvider);
// ********** End Interface UPlutoGameplayTagContainerProvider *************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h__Script_PlutoGameplayTagInspectorRuntime_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPlutoGameplayTagContainerDescriptor::StaticStruct, Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics::NewStructOps, TEXT("PlutoGameplayTagContainerDescriptor"),&Z_Registration_Info_UScriptStruct_FPlutoGameplayTagContainerDescriptor, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPlutoGameplayTagContainerDescriptor), 3026502342U) },
		{ FPlutoGameplayTagDescriptor::StaticStruct, Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics::NewStructOps, TEXT("PlutoGameplayTagDescriptor"),&Z_Registration_Info_UScriptStruct_FPlutoGameplayTagDescriptor, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPlutoGameplayTagDescriptor), 962980005U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPlutoGameplayTagContainerProvider, UPlutoGameplayTagContainerProvider::StaticClass, TEXT("UPlutoGameplayTagContainerProvider"), &Z_Registration_Info_UClass_UPlutoGameplayTagContainerProvider, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlutoGameplayTagContainerProvider), 1673362072U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h__Script_PlutoGameplayTagInspectorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h__Script_PlutoGameplayTagInspectorRuntime_3081556481{
	TEXT("/Script/PlutoGameplayTagInspectorRuntime"),
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h__Script_PlutoGameplayTagInspectorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h__Script_PlutoGameplayTagInspectorRuntime_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h__Script_PlutoGameplayTagInspectorRuntime_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h__Script_PlutoGameplayTagInspectorRuntime_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
