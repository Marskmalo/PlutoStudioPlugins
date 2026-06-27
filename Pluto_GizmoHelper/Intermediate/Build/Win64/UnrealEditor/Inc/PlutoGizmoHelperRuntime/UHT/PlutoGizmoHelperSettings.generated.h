// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlutoGizmoHelperSettings.h"

#ifdef PLUTOGIZMOHELPERRUNTIME_PlutoGizmoHelperSettings_generated_h
#error "PlutoGizmoHelperSettings.generated.h already included, missing '#pragma once' in PlutoGizmoHelperSettings.h"
#endif
#define PLUTOGIZMOHELPERRUNTIME_PlutoGizmoHelperSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPlutoGizmoHelperSettings ************************************************
struct Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics;
PLUTOGIZMOHELPERRUNTIME_API UClass* Z_Construct_UClass_UPlutoGizmoHelperSettings_NoRegister();

#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoGizmoHelperSettings_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPlutoGizmoHelperSettings(); \
	friend struct ::Z_Construct_UClass_UPlutoGizmoHelperSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PLUTOGIZMOHELPERRUNTIME_API UClass* ::Z_Construct_UClass_UPlutoGizmoHelperSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UPlutoGizmoHelperSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/PlutoGizmoHelperRuntime"), Z_Construct_UClass_UPlutoGizmoHelperSettings_NoRegister) \
	DECLARE_SERIALIZER(UPlutoGizmoHelperSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoGizmoHelperSettings_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPlutoGizmoHelperSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPlutoGizmoHelperSettings(UPlutoGizmoHelperSettings&&) = delete; \
	UPlutoGizmoHelperSettings(const UPlutoGizmoHelperSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPlutoGizmoHelperSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlutoGizmoHelperSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPlutoGizmoHelperSettings) \
	NO_API virtual ~UPlutoGizmoHelperSettings();


#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoGizmoHelperSettings_h_8_PROLOG
#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoGizmoHelperSettings_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoGizmoHelperSettings_h_11_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoGizmoHelperSettings_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPlutoGizmoHelperSettings;

// ********** End Class UPlutoGizmoHelperSettings **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoGizmoHelperSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
