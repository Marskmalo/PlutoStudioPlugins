// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlutoGameplayTagContainerProvider.h"

#ifdef PLUTOGAMEPLAYTAGINSPECTORRUNTIME_PlutoGameplayTagContainerProvider_generated_h
#error "PlutoGameplayTagContainerProvider.generated.h already included, missing '#pragma once' in PlutoGameplayTagContainerProvider.h"
#endif
#define PLUTOGAMEPLAYTAGINSPECTORRUNTIME_PlutoGameplayTagContainerProvider_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FPlutoGameplayTagContainerDescriptor;

// ********** Begin ScriptStruct FPlutoGameplayTagContainerDescriptor ******************************
struct Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics;
#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_11_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FPlutoGameplayTagContainerDescriptor_Statics; \
	static class UScriptStruct* StaticStruct();


struct FPlutoGameplayTagContainerDescriptor;
// ********** End ScriptStruct FPlutoGameplayTagContainerDescriptor ********************************

// ********** Begin ScriptStruct FPlutoGameplayTagDescriptor ***************************************
struct Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics;
#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_26_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FPlutoGameplayTagDescriptor_Statics; \
	static class UScriptStruct* StaticStruct();


struct FPlutoGameplayTagDescriptor;
// ********** End ScriptStruct FPlutoGameplayTagDescriptor *****************************************

// ********** Begin Interface UPlutoGameplayTagContainerProvider ***********************************
#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void PF_GetInspectableGameplayTagContainers_Implementation(TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers) const {}; \
	DECLARE_FUNCTION(execPF_GetInspectableGameplayTagContainers);


#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_38_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UPlutoGameplayTagContainerProvider_Statics;
PLUTOGAMEPLAYTAGINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UPlutoGameplayTagContainerProvider_NoRegister();

#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_38_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPlutoGameplayTagContainerProvider(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPlutoGameplayTagContainerProvider(UPlutoGameplayTagContainerProvider&&) = delete; \
	UPlutoGameplayTagContainerProvider(const UPlutoGameplayTagContainerProvider&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPlutoGameplayTagContainerProvider); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlutoGameplayTagContainerProvider); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPlutoGameplayTagContainerProvider) \
	virtual ~UPlutoGameplayTagContainerProvider() = default;


#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_38_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUPlutoGameplayTagContainerProvider(); \
	friend struct ::Z_Construct_UClass_UPlutoGameplayTagContainerProvider_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PLUTOGAMEPLAYTAGINSPECTORRUNTIME_API UClass* ::Z_Construct_UClass_UPlutoGameplayTagContainerProvider_NoRegister(); \
public: \
	DECLARE_CLASS2(UPlutoGameplayTagContainerProvider, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/PlutoGameplayTagInspectorRuntime"), Z_Construct_UClass_UPlutoGameplayTagContainerProvider_NoRegister) \
	DECLARE_SERIALIZER(UPlutoGameplayTagContainerProvider)


#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_38_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_38_GENERATED_UINTERFACE_BODY() \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_38_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_38_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IPlutoGameplayTagContainerProvider() {} \
public: \
	typedef UPlutoGameplayTagContainerProvider UClassType; \
	typedef IPlutoGameplayTagContainerProvider ThisClass; \
	static void Execute_PF_GetInspectableGameplayTagContainers(const UObject* O, TArray<FPlutoGameplayTagContainerDescriptor>& OutContainers); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_35_PROLOG
#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_43_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_38_CALLBACK_WRAPPERS \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h_38_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPlutoGameplayTagContainerProvider;

// ********** End Interface UPlutoGameplayTagContainerProvider *************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorRuntime_Public_PlutoGameplayTagContainerProvider_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
