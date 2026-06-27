// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlutoSplineWallTypes.h"

#ifdef PLUTOSPLINEHELPERRUNTIME_PlutoSplineWallTypes_generated_h
#error "PlutoSplineWallTypes.generated.h already included, missing '#pragma once' in PlutoSplineWallTypes.h"
#endif
#define PLUTOSPLINEHELPERRUNTIME_PlutoSplineWallTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FPlutoSplineWallPreviewStyle **************************************
struct Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics;
#define FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallTypes_h_24_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FPlutoSplineWallPreviewStyle_Statics; \
	static class UScriptStruct* StaticStruct();


struct FPlutoSplineWallPreviewStyle;
// ********** End ScriptStruct FPlutoSplineWallPreviewStyle ****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallTypes_h

// ********** Begin Enum EPlutoSplineWallDirection *************************************************
#define FOREACH_ENUM_EPLUTOSPLINEWALLDIRECTION(op) \
	op(EPlutoSplineWallDirection::ProcessExternalObjects) \
	op(EPlutoSplineWallDirection::ProcessInternalObjects) 

enum class EPlutoSplineWallDirection : uint8;
template<> struct TIsUEnumClass<EPlutoSplineWallDirection> { enum { Value = true }; };
template<> PLUTOSPLINEHELPERRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlutoSplineWallDirection>();
// ********** End Enum EPlutoSplineWallDirection ***************************************************

// ********** Begin Enum EPlutoSplineWallEditorPreview *********************************************
#define FOREACH_ENUM_EPLUTOSPLINEWALLEDITORPREVIEW(op) \
	op(EPlutoSplineWallEditorPreview::Always) \
	op(EPlutoSplineWallEditorPreview::SelectedOnly) \
	op(EPlutoSplineWallEditorPreview::Hidden) 

enum class EPlutoSplineWallEditorPreview : uint8;
template<> struct TIsUEnumClass<EPlutoSplineWallEditorPreview> { enum { Value = true }; };
template<> PLUTOSPLINEHELPERRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlutoSplineWallEditorPreview>();
// ********** End Enum EPlutoSplineWallEditorPreview ***********************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
