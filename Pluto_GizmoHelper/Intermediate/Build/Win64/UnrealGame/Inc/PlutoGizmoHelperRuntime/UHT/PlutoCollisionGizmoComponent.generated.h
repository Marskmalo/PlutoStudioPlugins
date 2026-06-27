// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlutoCollisionGizmoComponent.h"

#ifdef PLUTOGIZMOHELPERRUNTIME_PlutoCollisionGizmoComponent_generated_h
#error "PlutoCollisionGizmoComponent.generated.h already included, missing '#pragma once' in PlutoCollisionGizmoComponent.h"
#endif
#define PLUTOGIZMOHELPERRUNTIME_PlutoCollisionGizmoComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UShapeComponent;
struct FLinearColor;
struct FPlutoCollisionGizmoStyle;

// ********** Begin Class UPlutoCollisionGizmoComponent ********************************************
#define FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRefreshGizmo); \
	DECLARE_FUNCTION(execSetStyle); \
	DECLARE_FUNCTION(execSetDrawFill); \
	DECLARE_FUNCTION(execSetDrawOutline); \
	DECLARE_FUNCTION(execSetFillOpacity); \
	DECLARE_FUNCTION(execSetFillColor); \
	DECLARE_FUNCTION(execSetLineThickness); \
	DECLARE_FUNCTION(execSetOutlineColor); \
	DECLARE_FUNCTION(execSetGizmoEnabled); \
	DECLARE_FUNCTION(execGetTargetCollision); \
	DECLARE_FUNCTION(execSetTargetCollision);


struct Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics;
PLUTOGIZMOHELPERRUNTIME_API UClass* Z_Construct_UClass_UPlutoCollisionGizmoComponent_NoRegister();

#define FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoComponent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPlutoCollisionGizmoComponent(); \
	friend struct ::Z_Construct_UClass_UPlutoCollisionGizmoComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PLUTOGIZMOHELPERRUNTIME_API UClass* ::Z_Construct_UClass_UPlutoCollisionGizmoComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UPlutoCollisionGizmoComponent, UPrimitiveComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PlutoGizmoHelperRuntime"), Z_Construct_UClass_UPlutoCollisionGizmoComponent_NoRegister) \
	DECLARE_SERIALIZER(UPlutoCollisionGizmoComponent)


#define FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoComponent_h_13_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPlutoCollisionGizmoComponent(UPlutoCollisionGizmoComponent&&) = delete; \
	UPlutoCollisionGizmoComponent(const UPlutoCollisionGizmoComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPlutoCollisionGizmoComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlutoCollisionGizmoComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPlutoCollisionGizmoComponent) \
	NO_API virtual ~UPlutoCollisionGizmoComponent();


#define FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoComponent_h_10_PROLOG
#define FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoComponent_h_13_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPlutoCollisionGizmoComponent;

// ********** End Class UPlutoCollisionGizmoComponent **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Project_SOD_Plugins_Pluto_GizmoHelper_Source_PlutoGizmoHelperRuntime_Public_PlutoCollisionGizmoComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
