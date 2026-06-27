// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlutoSplineWallActor.h"

#ifdef PLUTOSPLINEHELPERRUNTIME_PlutoSplineWallActor_generated_h
#error "PlutoSplineWallActor.generated.h already included, missing '#pragma once' in PlutoSplineWallActor.h"
#endif
#define PLUTOSPLINEHELPERRUNTIME_PlutoSplineWallActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APlutoSplineWall *********************************************************
#define FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallActor_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetValidationMessage); \
	DECLARE_FUNCTION(execIsCurrentShapeValid); \
	DECLARE_FUNCTION(execApplySplinePointTypeToAll); \
	DECLARE_FUNCTION(execRebuildWall);


struct Z_Construct_UClass_APlutoSplineWall_Statics;
PLUTOSPLINEHELPERRUNTIME_API UClass* Z_Construct_UClass_APlutoSplineWall_NoRegister();

#define FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallActor_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlutoSplineWall(); \
	friend struct ::Z_Construct_UClass_APlutoSplineWall_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PLUTOSPLINEHELPERRUNTIME_API UClass* ::Z_Construct_UClass_APlutoSplineWall_NoRegister(); \
public: \
	DECLARE_CLASS2(APlutoSplineWall, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PlutoSplineHelperRuntime"), Z_Construct_UClass_APlutoSplineWall_NoRegister) \
	DECLARE_SERIALIZER(APlutoSplineWall)


#define FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallActor_h_18_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	APlutoSplineWall(APlutoSplineWall&&) = delete; \
	APlutoSplineWall(const APlutoSplineWall&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlutoSplineWall); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlutoSplineWall); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlutoSplineWall) \
	NO_API virtual ~APlutoSplineWall();


#define FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallActor_h_15_PROLOG
#define FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallActor_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallActor_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallActor_h_18_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallActor_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APlutoSplineWall;

// ********** End Class APlutoSplineWall ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Project_SOD_Plugins_Pluto_SplineHelper_Source_PlutoSplineHelperRuntime_Public_PlutoSplineWallActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
