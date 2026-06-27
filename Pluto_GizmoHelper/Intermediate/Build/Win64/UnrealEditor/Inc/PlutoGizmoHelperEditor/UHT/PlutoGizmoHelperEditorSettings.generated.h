// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlutoGizmoHelperEditorSettings.h"

#ifdef PLUTOGIZMOHELPEREDITOR_PlutoGizmoHelperEditorSettings_generated_h
#error "PlutoGizmoHelperEditorSettings.generated.h already included, missing '#pragma once' in PlutoGizmoHelperEditorSettings.h"
#endif
#define PLUTOGIZMOHELPEREDITOR_PlutoGizmoHelperEditorSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPlutoGizmoHelperEditorSettings ******************************************
struct Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics;
PLUTOGIZMOHELPEREDITOR_API UClass* Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_NoRegister();

#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperEditor_Public_PlutoGizmoHelperEditorSettings_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPlutoGizmoHelperEditorSettings(); \
	friend struct ::Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PLUTOGIZMOHELPEREDITOR_API UClass* ::Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UPlutoGizmoHelperEditorSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/PlutoGizmoHelperEditor"), Z_Construct_UClass_UPlutoGizmoHelperEditorSettings_NoRegister) \
	DECLARE_SERIALIZER(UPlutoGizmoHelperEditorSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperEditor_Public_PlutoGizmoHelperEditorSettings_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPlutoGizmoHelperEditorSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPlutoGizmoHelperEditorSettings(UPlutoGizmoHelperEditorSettings&&) = delete; \
	UPlutoGizmoHelperEditorSettings(const UPlutoGizmoHelperEditorSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPlutoGizmoHelperEditorSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlutoGizmoHelperEditorSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPlutoGizmoHelperEditorSettings) \
	NO_API virtual ~UPlutoGizmoHelperEditorSettings();


#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperEditor_Public_PlutoGizmoHelperEditorSettings_h_14_PROLOG
#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperEditor_Public_PlutoGizmoHelperEditorSettings_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperEditor_Public_PlutoGizmoHelperEditorSettings_h_17_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperEditor_Public_PlutoGizmoHelperEditorSettings_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPlutoGizmoHelperEditorSettings;

// ********** End Class UPlutoGizmoHelperEditorSettings ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GizmoHelper_Source_PlutoGizmoHelperEditor_Public_PlutoGizmoHelperEditorSettings_h

// ********** Begin Enum EPlutoGizmoHelperLanguage *************************************************
#define FOREACH_ENUM_EPLUTOGIZMOHELPERLANGUAGE(op) \
	op(EPlutoGizmoHelperLanguage::Chinese) \
	op(EPlutoGizmoHelperLanguage::English) 

enum class EPlutoGizmoHelperLanguage : uint8;
template<> struct TIsUEnumClass<EPlutoGizmoHelperLanguage> { enum { Value = true }; };
template<> PLUTOGIZMOHELPEREDITOR_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlutoGizmoHelperLanguage>();
// ********** End Enum EPlutoGizmoHelperLanguage ***************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
