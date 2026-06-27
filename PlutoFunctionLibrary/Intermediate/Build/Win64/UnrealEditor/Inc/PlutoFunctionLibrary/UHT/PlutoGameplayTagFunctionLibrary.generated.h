// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlutoGameplayTagFunctionLibrary.h"

#ifdef PLUTOFUNCTIONLIBRARY_PlutoGameplayTagFunctionLibrary_generated_h
#error "PlutoGameplayTagFunctionLibrary.generated.h already included, missing '#pragma once' in PlutoGameplayTagFunctionLibrary.h"
#endif
#define PLUTOFUNCTIONLIBRARY_PlutoGameplayTagFunctionLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EPlutoGameplayTagListeningPolicy : uint8;
struct FGameplayTag;
struct FGameplayTagContainer;

// ********** Begin Class UPlutoGameplayTagFunctionLibrary *****************************************
#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execPF_DetectGameplayTagChanged); \
	DECLARE_FUNCTION(execPF_HasAllGameplayTags); \
	DECLARE_FUNCTION(execPF_HasAnyGameplayTags); \
	DECLARE_FUNCTION(execPF_ClearGameplayTagContainer); \
	DECLARE_FUNCTION(execPF_BatchRemoveGameplayTags); \
	DECLARE_FUNCTION(execPF_BatchAddGameplayTags);


struct Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_Statics;
PLUTOFUNCTIONLIBRARY_API UClass* Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_NoRegister();

#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPlutoGameplayTagFunctionLibrary(); \
	friend struct ::Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PLUTOFUNCTIONLIBRARY_API UClass* ::Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UPlutoGameplayTagFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PlutoFunctionLibrary"), Z_Construct_UClass_UPlutoGameplayTagFunctionLibrary_NoRegister) \
	DECLARE_SERIALIZER(UPlutoGameplayTagFunctionLibrary)


#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h_27_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPlutoGameplayTagFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPlutoGameplayTagFunctionLibrary(UPlutoGameplayTagFunctionLibrary&&) = delete; \
	UPlutoGameplayTagFunctionLibrary(const UPlutoGameplayTagFunctionLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPlutoGameplayTagFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlutoGameplayTagFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPlutoGameplayTagFunctionLibrary) \
	NO_API virtual ~UPlutoGameplayTagFunctionLibrary();


#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h_24_PROLOG
#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h_27_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPlutoGameplayTagFunctionLibrary;

// ********** End Class UPlutoGameplayTagFunctionLibrary *******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Project_SOD_Plugins_PlutoStudio_PlutoFunctionLibrary_Source_PlutoFunctionLibrary_Public_PlutoGameplayTagFunctionLibrary_h

// ********** Begin Enum EPlutoGameplayTagListeningPolicy ******************************************
#define FOREACH_ENUM_EPLUTOGAMEPLAYTAGLISTENINGPOLICY(op) \
	op(EPlutoGameplayTagListeningPolicy::Added) \
	op(EPlutoGameplayTagListeningPolicy::Removed) \
	op(EPlutoGameplayTagListeningPolicy::AddedOrRemoved) \
	op(EPlutoGameplayTagListeningPolicy::AnyCountChange) 

enum class EPlutoGameplayTagListeningPolicy : uint8;
template<> struct TIsUEnumClass<EPlutoGameplayTagListeningPolicy> { enum { Value = true }; };
template<> PLUTOFUNCTIONLIBRARY_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlutoGameplayTagListeningPolicy>();
// ********** End Enum EPlutoGameplayTagListeningPolicy ********************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
