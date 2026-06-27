// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlutoGameplayTagInspectorEditorSettings.h"

#ifdef PLUTOGAMEPLAYTAGINSPECTOREDITOR_PlutoGameplayTagInspectorEditorSettings_generated_h
#error "PlutoGameplayTagInspectorEditorSettings.generated.h already included, missing '#pragma once' in PlutoGameplayTagInspectorEditorSettings.h"
#endif
#define PLUTOGAMEPLAYTAGINSPECTOREDITOR_PlutoGameplayTagInspectorEditorSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPlutoGameplayTagInspectorEditorSettings *********************************
struct Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics;
PLUTOGAMEPLAYTAGINSPECTOREDITOR_API UClass* Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_NoRegister();

#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorEditor_Public_PlutoGameplayTagInspectorEditorSettings_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPlutoGameplayTagInspectorEditorSettings(); \
	friend struct ::Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PLUTOGAMEPLAYTAGINSPECTOREDITOR_API UClass* ::Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UPlutoGameplayTagInspectorEditorSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PlutoGameplayTagInspectorEditor"), Z_Construct_UClass_UPlutoGameplayTagInspectorEditorSettings_NoRegister) \
	DECLARE_SERIALIZER(UPlutoGameplayTagInspectorEditorSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorEditor_Public_PlutoGameplayTagInspectorEditorSettings_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPlutoGameplayTagInspectorEditorSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPlutoGameplayTagInspectorEditorSettings(UPlutoGameplayTagInspectorEditorSettings&&) = delete; \
	UPlutoGameplayTagInspectorEditorSettings(const UPlutoGameplayTagInspectorEditorSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPlutoGameplayTagInspectorEditorSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlutoGameplayTagInspectorEditorSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPlutoGameplayTagInspectorEditorSettings) \
	NO_API virtual ~UPlutoGameplayTagInspectorEditorSettings();


#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorEditor_Public_PlutoGameplayTagInspectorEditorSettings_h_14_PROLOG
#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorEditor_Public_PlutoGameplayTagInspectorEditorSettings_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorEditor_Public_PlutoGameplayTagInspectorEditorSettings_h_17_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorEditor_Public_PlutoGameplayTagInspectorEditorSettings_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPlutoGameplayTagInspectorEditorSettings;

// ********** End Class UPlutoGameplayTagInspectorEditorSettings ***********************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_GameplayTagInspector_Source_PlutoGameplayTagInspectorEditor_Public_PlutoGameplayTagInspectorEditorSettings_h

// ********** Begin Enum EPlutoGameplayTagInspectorLanguage ****************************************
#define FOREACH_ENUM_EPLUTOGAMEPLAYTAGINSPECTORLANGUAGE(op) \
	op(EPlutoGameplayTagInspectorLanguage::Chinese) \
	op(EPlutoGameplayTagInspectorLanguage::English) 

enum class EPlutoGameplayTagInspectorLanguage : uint8;
template<> struct TIsUEnumClass<EPlutoGameplayTagInspectorLanguage> { enum { Value = true }; };
template<> PLUTOGAMEPLAYTAGINSPECTOREDITOR_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlutoGameplayTagInspectorLanguage>();
// ********** End Enum EPlutoGameplayTagInspectorLanguage ******************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
