// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlutoCollisionGizmoTypes.h"

#ifdef PLUTOGIZMOHELPERRUNTIME_PlutoCollisionGizmoTypes_generated_h
#error "PlutoCollisionGizmoTypes.generated.h already included, missing '#pragma once' in PlutoCollisionGizmoTypes.h"
#endif
#define PLUTOGIZMOHELPERRUNTIME_PlutoCollisionGizmoTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FPlutoCollisionGizmoStyle *****************************************
struct Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics;
#define FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoTypes_h_16_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FPlutoCollisionGizmoStyle_Statics; \
	static class UScriptStruct* StaticStruct();


struct FPlutoCollisionGizmoStyle;
// ********** End ScriptStruct FPlutoCollisionGizmoStyle *******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoTypes_h

// ********** Begin Enum EPlutoCollisionGizmoVisibility ********************************************
#define FOREACH_ENUM_EPLUTOCOLLISIONGIZMOVISIBILITY(op) \
	op(EPlutoCollisionGizmoVisibility::Always) \
	op(EPlutoCollisionGizmoVisibility::SelectedInEditorOnly) 

enum class EPlutoCollisionGizmoVisibility : uint8;
template<> struct TIsUEnumClass<EPlutoCollisionGizmoVisibility> { enum { Value = true }; };
template<> PLUTOGIZMOHELPERRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EPlutoCollisionGizmoVisibility>();
// ********** End Enum EPlutoCollisionGizmoVisibility **********************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
