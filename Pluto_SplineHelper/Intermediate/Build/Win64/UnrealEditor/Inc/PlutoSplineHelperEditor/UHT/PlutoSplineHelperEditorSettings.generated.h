// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlutoSplineHelperEditorSettings.h"

#ifdef PLUTOSPLINEHELPEREDITOR_PlutoSplineHelperEditorSettings_generated_h
#error "PlutoSplineHelperEditorSettings.generated.h already included, missing '#pragma once' in PlutoSplineHelperEditorSettings.h"
#endif
#define PLUTOSPLINEHELPEREDITOR_PlutoSplineHelperEditorSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPlutoSplineHelperEditorSettings *****************************************
struct Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics;
PLUTOSPLINEHELPEREDITOR_API UClass* Z_Construct_UClass_UPlutoSplineHelperEditorSettings_NoRegister();

#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperEditor_Public_PlutoSplineHelperEditorSettings_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPlutoSplineHelperEditorSettings(); \
	friend struct ::Z_Construct_UClass_UPlutoSplineHelperEditorSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PLUTOSPLINEHELPEREDITOR_API UClass* ::Z_Construct_UClass_UPlutoSplineHelperEditorSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UPlutoSplineHelperEditorSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/PlutoSplineHelperEditor"), Z_Construct_UClass_UPlutoSplineHelperEditorSettings_NoRegister) \
	DECLARE_SERIALIZER(UPlutoSplineHelperEditorSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperEditor_Public_PlutoSplineHelperEditorSettings_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPlutoSplineHelperEditorSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPlutoSplineHelperEditorSettings(UPlutoSplineHelperEditorSettings&&) = delete; \
	UPlutoSplineHelperEditorSettings(const UPlutoSplineHelperEditorSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPlutoSplineHelperEditorSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlutoSplineHelperEditorSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPlutoSplineHelperEditorSettings) \
	NO_API virtual ~UPlutoSplineHelperEditorSettings();


#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperEditor_Public_PlutoSplineHelperEditorSettings_h_14_PROLOG
#define FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperEditor_Public_PlutoSplineHelperEditorSettings_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperEditor_Public_PlutoSplineHelperEditorSettings_h_17_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperEditor_Public_PlutoSplineHelperEditorSettings_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPlutoSplineHelperEditorSettings;

// ********** End Class UPlutoSplineHelperEditorSettings *******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Project_SOD_Plugins_PlutoStudio_Pluto_SplineHelper_Source_PlutoSplineHelperEditor_Public_PlutoSplineHelperEditorSettings_h

// ********** Begin Enum EPlutoSplineHelperLanguage ************************************************
#define FOREACH_ENUM_EPLUTOSPLINEHELPERLANGUAGE(op) \
	op(EPlutoSplineHelperLanguage::Chinese) \
	op(EPlutoSplineHelperLanguage::English) 

enum class EPlutoSplineHelperLanguage : uint8;
template<> struct TIsUEnumClass<EPlutoSplineHelperLanguage> { enum { Value = true }; };
template<> PLUTOSPLINEHELPEREDITOR_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlutoSplineHelperLanguage>();
// ********** End Enum EPlutoSplineHelperLanguage **************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
