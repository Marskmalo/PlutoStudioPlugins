#include "PlutoCollisionGizmoComponent.h"

#include "Components/BoxComponent.h"
#include "Components/BrushComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/SphereComponent.h"
#include "DynamicMeshBuilder.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "HAL/IConsoleManager.h"
#include "Materials/Material.h"
#include "Materials/MaterialRenderProxy.h"
#include "MeshElementCollector.h"
#include "PlutoGizmoHelperSettings.h"
#include "PhysicsEngine/BodySetup.h"
#include "PhysicsEngine/ConvexElem.h"
#include "PrimitiveDrawingUtils.h"
#include "PrimitiveSceneProxy.h"
#include "PrimitiveViewRelevance.h"
#include "SceneManagement.h"
#include "SceneView.h"

namespace PlutoCollisionGizmo
{
#if !UE_BUILD_SHIPPING
#if WITH_EDITOR
	constexpr int32 DefaultVisibility = 1;
#else
	constexpr int32 DefaultVisibility = 0;
#endif

	static TAutoConsoleVariable<int32> CVarCollisionGizmo(
		TEXT("pluto.Gizmo.Collision"),
		DefaultVisibility,
		TEXT("Controls Pluto collision gizmo rendering. 0: hidden, 1: visible."),
		ECVF_RenderThreadSafe);

	static bool IsGloballyEnabled()
	{
		return CVarCollisionGizmo.GetValueOnAnyThread() != 0;
	}
#endif

	enum class EShapeType : uint8
	{
		None,
		Box,
		Sphere,
		Capsule,
		Brush
	};

	struct FRenderData
	{
		EShapeType ShapeType = EShapeType::None;
		FTransform Transform = FTransform::Identity;
		FVector BoxExtent = FVector::ZeroVector;
		float SphereRadius = 0.0f;
		float CapsuleRadius = 0.0f;
		float CapsuleHalfHeight = 0.0f;
		TArray<FVector> BrushVertices;
		TArray<int32> BrushIndices;
		TArray<FIntPoint> BrushEdges;
		FPlutoCollisionGizmoStyle Style;
		bool bSelectedOnly = false;
		bool bEditorWorld = false;
	};

	static FRenderData MakeRenderData(const UPlutoCollisionGizmoComponent* Component)
	{
		FRenderData Data;
		Data.Style = Component->GetResolvedStyle();
		Data.bSelectedOnly = Component->VisibilityMode == EPlutoCollisionGizmoVisibility::SelectedInEditorOnly;
		Data.bEditorWorld = Component->GetWorld()
			&& (Component->GetWorld()->WorldType == EWorldType::Editor || Component->GetWorld()->WorldType == EWorldType::EditorPreview);

		if (const UBoxComponent* Box = Cast<UBoxComponent>(Component->GetTargetCollision()))
		{
			Data.ShapeType = EShapeType::Box;
			Data.Transform = Box->GetComponentTransform();
			Data.BoxExtent = Box->GetUnscaledBoxExtent();
		}
		else if (const USphereComponent* Sphere = Cast<USphereComponent>(Component->GetTargetCollision()))
		{
			Data.ShapeType = EShapeType::Sphere;
			Data.Transform = Sphere->GetComponentTransform();
			Data.SphereRadius = Sphere->GetScaledSphereRadius();
		}
		else if (const UCapsuleComponent* Capsule = Cast<UCapsuleComponent>(Component->GetTargetCollision()))
		{
			Data.ShapeType = EShapeType::Capsule;
			Data.Transform = Capsule->GetComponentTransform();
			Data.CapsuleRadius = Capsule->GetScaledCapsuleRadius();
			Data.CapsuleHalfHeight = Capsule->GetScaledCapsuleHalfHeight();
		}
		else if (const UBrushComponent* Brush = Cast<UBrushComponent>(Component->GetTargetCollision()))
		{
			const UBodySetup* BodySetup = const_cast<UBrushComponent*>(Brush)->GetBodySetup();
			if (BodySetup)
			{
				Data.ShapeType = EShapeType::Brush;
				Data.Transform = Brush->GetComponentTransform();

				struct FBrushEdgeInfo
				{
					FVector FirstNormal = FVector::ZeroVector;
					int32 AdjacentTriangleCount = 0;
					bool bIsCrease = false;
				};

				TMap<FIntPoint, FBrushEdgeInfo> EdgeInfos;
				for (const FKConvexElem& Convex : BodySetup->AggGeom.ConvexElems)
				{
					const int32 VertexOffset = Data.BrushVertices.Num();
					const FTransform ConvexTransform = Convex.GetTransform();
					for (const FVector& Vertex : Convex.VertexData)
					{
						Data.BrushVertices.Add(ConvexTransform.TransformPosition(Vertex));
					}

					for (int32 TriangleIndex = 0; TriangleIndex + 2 < Convex.IndexData.Num(); TriangleIndex += 3)
					{
						const int32 LocalIndices[3] =
						{
							Convex.IndexData[TriangleIndex],
							Convex.IndexData[TriangleIndex + 1],
							Convex.IndexData[TriangleIndex + 2]
						};

						if (LocalIndices[0] < 0 || LocalIndices[1] < 0 || LocalIndices[2] < 0
							|| !Convex.VertexData.IsValidIndex(LocalIndices[0])
							|| !Convex.VertexData.IsValidIndex(LocalIndices[1])
							|| !Convex.VertexData.IsValidIndex(LocalIndices[2]))
						{
							continue;
						}

						const int32 Indices[3] =
						{
							VertexOffset + LocalIndices[0],
							VertexOffset + LocalIndices[1],
							VertexOffset + LocalIndices[2]
						};
						Data.BrushIndices.Append(Indices, UE_ARRAY_COUNT(Indices));
						const FVector TriangleNormal = FVector::CrossProduct(
							Data.BrushVertices[Indices[1]] - Data.BrushVertices[Indices[0]],
							Data.BrushVertices[Indices[2]] - Data.BrushVertices[Indices[0]]).GetSafeNormal();

						for (int32 EdgeIndex = 0; EdgeIndex < 3; ++EdgeIndex)
						{
							const int32 A = Indices[EdgeIndex];
							const int32 B = Indices[(EdgeIndex + 1) % 3];
							FBrushEdgeInfo& EdgeInfo = EdgeInfos.FindOrAdd(FIntPoint(FMath::Min(A, B), FMath::Max(A, B)));
							if (EdgeInfo.AdjacentTriangleCount == 0)
							{
								EdgeInfo.FirstNormal = TriangleNormal;
							}
							else if (FMath::Abs(FVector::DotProduct(EdgeInfo.FirstNormal, TriangleNormal)) < 0.999f)
							{
								EdgeInfo.bIsCrease = true;
							}
							++EdgeInfo.AdjacentTriangleCount;
						}
					}
				}

				Data.BrushEdges.Reserve(EdgeInfos.Num());
				for (const TPair<FIntPoint, FBrushEdgeInfo>& EdgePair : EdgeInfos)
				{
					if (EdgePair.Value.AdjacentTriangleCount == 1 || EdgePair.Value.bIsCrease)
					{
						Data.BrushEdges.Add(EdgePair.Key);
					}
				}
				if (Data.BrushVertices.IsEmpty() || Data.BrushIndices.IsEmpty())
				{
					Data.ShapeType = EShapeType::None;
				}
			}
		}

		return Data;
	}
}

#if !UE_BUILD_SHIPPING
class FPlutoCollisionGizmoSceneProxy final : public FPrimitiveSceneProxy
{
public:
	explicit FPlutoCollisionGizmoSceneProxy(const UPlutoCollisionGizmoComponent* Component)
		: FPrimitiveSceneProxy(Component)
		, Data(PlutoCollisionGizmo::MakeRenderData(Component))
	{
		bWillEverBeLit = false;
	}

	virtual SIZE_T GetTypeHash() const override
	{
		static size_t UniquePointer;
		return reinterpret_cast<size_t>(&UniquePointer);
	}

	virtual void GetDynamicMeshElements(
		const TArray<const FSceneView*>& Views,
		const FSceneViewFamily& ViewFamily,
		uint32 VisibilityMap,
		FMeshElementCollector& Collector) const override
	{
		if (!PlutoCollisionGizmo::IsGloballyEnabled() || Data.ShapeType == PlutoCollisionGizmo::EShapeType::None)
		{
			return;
		}

		for (int32 ViewIndex = 0; ViewIndex < Views.Num(); ++ViewIndex)
		{
			if ((VisibilityMap & (1u << ViewIndex)) == 0)
			{
				continue;
			}

			FPrimitiveDrawInterface* PDI = Collector.GetPDI(ViewIndex);
			const FLinearColor OutlineColor = Data.Style.OutlineColor;
			const FLinearColor FillColor(
				Data.Style.FillColor.R,
				Data.Style.FillColor.G,
				Data.Style.FillColor.B,
				FMath::Clamp(Data.Style.FillOpacity * Data.Style.FillColor.A, 0.0f, 1.0f));

			const FMaterialRenderProxy* FillMaterial = nullptr;
			if (Data.Style.bDrawFill && FillColor.A > 0.0f && GEngine && GEngine->DebugMeshMaterial)
			{
				FillMaterial = &Collector.AllocateOneFrameResource<FColoredMaterialRenderProxy>(
					GEngine->DebugMeshMaterial->GetRenderProxy(),
					FillColor);
			}

			switch (Data.ShapeType)
			{
			case PlutoCollisionGizmo::EShapeType::Box:
			{
				const FMatrix BoxMatrix = Data.Transform.ToMatrixWithScale();
				if (FillMaterial)
				{
					GetBoxMesh(BoxMatrix, Data.BoxExtent, FillMaterial, SDPG_World, ViewIndex, Collector);
				}
				if (Data.Style.bDrawOutline)
				{
					DrawOrientedWireBox(
						PDI,
						BoxMatrix.GetOrigin(),
						BoxMatrix.GetScaledAxis(EAxis::X),
						BoxMatrix.GetScaledAxis(EAxis::Y),
						BoxMatrix.GetScaledAxis(EAxis::Z),
						Data.BoxExtent,
						OutlineColor,
						SDPG_World,
						Data.Style.LineThickness);
				}
				break;
			}
			case PlutoCollisionGizmo::EShapeType::Sphere:
			{
				const FVector Center = Data.Transform.GetLocation();
				const int32 Sides = FMath::Clamp(FMath::RoundToInt(Data.SphereRadius / 4.0f), 16, 64);
				if (FillMaterial)
				{
					GetSphereMesh(Center, FVector(Data.SphereRadius), Sides, FMath::Max(8, Sides / 2), FillMaterial, SDPG_World, false, ViewIndex, Collector);
				}
				if (Data.Style.bDrawOutline)
				{
					DrawWireSphere(PDI, Center, OutlineColor, Data.SphereRadius, Sides, SDPG_World, Data.Style.LineThickness);
				}
				break;
			}
			case PlutoCollisionGizmo::EShapeType::Capsule:
			{
				const FVector X = Data.Transform.GetUnitAxis(EAxis::X);
				const FVector Y = Data.Transform.GetUnitAxis(EAxis::Y);
				const FVector Z = Data.Transform.GetUnitAxis(EAxis::Z);
				const FVector Center = Data.Transform.GetLocation();
				const FVector BottomOrigin = Center - Z * Data.CapsuleHalfHeight;
				const int32 Sides = FMath::Clamp(FMath::RoundToInt(Data.CapsuleRadius / 4.0f), 16, 64);
				if (FillMaterial)
				{
					GetCapsuleMesh(BottomOrigin, X, Y, Z, FillColor, Data.CapsuleRadius, Data.CapsuleHalfHeight, Sides, FillMaterial, SDPG_World, false, ViewIndex, Collector);
				}
				if (Data.Style.bDrawOutline)
				{
					DrawWireCapsule(PDI, Center, X, Y, Z, OutlineColor, Data.CapsuleRadius, Data.CapsuleHalfHeight, Sides, SDPG_World, Data.Style.LineThickness);
				}
				break;
			}
			case PlutoCollisionGizmo::EShapeType::Brush:
			{
				if (FillMaterial)
				{
					FDynamicMeshBuilder MeshBuilder(Collector.GetFeatureLevel());
					MeshBuilder.ReserveVertices(Data.BrushVertices.Num());
					MeshBuilder.ReserveTriangles(Data.BrushIndices.Num() / 3);
					for (const FVector& Vertex : Data.BrushVertices)
					{
						MeshBuilder.AddVertex(
							FVector3f(Vertex),
							FVector2f::ZeroVector,
							FVector3f(1.0f, 0.0f, 0.0f),
							FVector3f(0.0f, 1.0f, 0.0f),
							FVector3f(0.0f, 0.0f, 1.0f),
							FColor::White);
					}
					for (int32 TriangleIndex = 0; TriangleIndex + 2 < Data.BrushIndices.Num(); TriangleIndex += 3)
					{
						MeshBuilder.AddTriangle(
							Data.BrushIndices[TriangleIndex],
							Data.BrushIndices[TriangleIndex + 1],
							Data.BrushIndices[TriangleIndex + 2]);
					}
					MeshBuilder.GetMesh(Data.Transform.ToMatrixWithScale(), FillMaterial, SDPG_World, true, false, ViewIndex, Collector);
				}

				if (Data.Style.bDrawOutline)
				{
					for (const FIntPoint& Edge : Data.BrushEdges)
					{
						if (Data.BrushVertices.IsValidIndex(Edge.X) && Data.BrushVertices.IsValidIndex(Edge.Y))
						{
							PDI->DrawLine(
								Data.Transform.TransformPosition(Data.BrushVertices[Edge.X]),
								Data.Transform.TransformPosition(Data.BrushVertices[Edge.Y]),
								OutlineColor,
								SDPG_World,
								Data.Style.LineThickness);
						}
					}
				}
				break;
			}
			default:
				break;
			}
		}
	}

	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View) const override
	{
		const bool bSelectionAllowsDrawing = !Data.bSelectedOnly || (Data.bEditorWorld && IsSelected());

		FPrimitiveViewRelevance Result;
		Result.bDrawRelevance = IsShown(View) && bSelectionAllowsDrawing && PlutoCollisionGizmo::IsGloballyEnabled();
		Result.bDynamicRelevance = true;
		Result.bShadowRelevance = false;
		Result.bEditorPrimitiveRelevance = UseEditorCompositing(View);
		Result.bSeparateTranslucency = Data.Style.bDrawFill;
		Result.bNormalTranslucency = Data.Style.bDrawFill;
		Result.bOpaque = Data.Style.bDrawOutline && !Data.Style.bDrawFill;
		return Result;
	}

	virtual uint32 GetMemoryFootprint() const override
	{
		return sizeof(*this) + GetAllocatedSize();
	}

private:
	uint32 GetAllocatedSize() const
	{
		return FPrimitiveSceneProxy::GetAllocatedSize();
	}

	const PlutoCollisionGizmo::FRenderData Data;
};
#endif

UPlutoCollisionGizmoComponent::UPlutoCollisionGizmoComponent()
{
#if UE_BUILD_SHIPPING
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
#else
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	bTickInEditor = true;
#endif
	SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SetGenerateOverlapEvents(false);
	SetCanEverAffectNavigation(false);
	SetIsReplicatedByDefault(false);
	CastShadow = false;
	bHiddenInGame = false;
	bUseAttachParentBound = false;
}

void UPlutoCollisionGizmoComponent::SetTargetCollision(UPrimitiveComponent* InTargetCollision)
{
	SetTargetCollisionReference(InTargetCollision, InTargetCollision ? InTargetCollision->GetFName() : NAME_None);
}

void UPlutoCollisionGizmoComponent::SetTargetCollisionReference(UPrimitiveComponent* InTargetCollision, FName ComponentPropertyName)
{
	TargetCollision.OverrideComponent = InTargetCollision;
	TargetCollision.ComponentProperty = ComponentPropertyName;
	TargetCollision.PathToComponent.Reset();
	TargetCollision.OtherActor.Reset();

	if (InTargetCollision && InTargetCollision->GetOwner() == GetOwner())
	{
		AttachToComponent(InTargetCollision, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}

	RefreshGizmo();
}

UPrimitiveComponent* UPlutoCollisionGizmoComponent::GetTargetCollision() const
{
	const AActor* Owner = GetOwner();
	if (!Owner)
	{
		return nullptr;
	}

	// The attachment is duplicated together with the Actor and is therefore the most
	// reliable way to resolve an instance-created gizmo in PIE. FComponentReference's
	// weak override can still point at the editor-world component after duplication.
	if (UPrimitiveComponent* AttachedTarget = Cast<UPrimitiveComponent>(GetAttachParent()))
	{
		if (AttachedTarget->GetOwner() == Owner && IsSupportedTarget(AttachedTarget))
		{
			return AttachedTarget;
		}
	}

	if (UPrimitiveComponent* ReferencedTarget = Cast<UPrimitiveComponent>(TargetCollision.GetComponent(GetOwner())))
	{
		if (ReferencedTarget->GetOwner() == Owner && IsSupportedTarget(ReferencedTarget))
		{
			return ReferencedTarget;
		}
	}

	if (!TargetCollision.ComponentProperty.IsNone())
	{
		TInlineComponentArray<UPrimitiveComponent*> PrimitiveComponents(GetOwner());
		for (UPrimitiveComponent* Candidate : PrimitiveComponents)
		{
			if (Candidate && Candidate->GetFName() == TargetCollision.ComponentProperty && IsSupportedTarget(Candidate))
			{
				return Candidate;
			}
		}
	}

	return nullptr;
}

bool UPlutoCollisionGizmoComponent::IsSupportedTarget(const UPrimitiveComponent* Component)
{
	return Component
		&& (Component->IsA<UBoxComponent>()
			|| Component->IsA<USphereComponent>()
			|| Component->IsA<UCapsuleComponent>()
			|| Component->IsA<UBrushComponent>());
}

void UPlutoCollisionGizmoComponent::SetGizmoEnabled(bool bEnabled)
{
	if (bGizmoEnabled != bEnabled)
	{
		bGizmoEnabled = bEnabled;
		RefreshGizmo();
	}
}

void UPlutoCollisionGizmoComponent::ApplyStyleMutation(TFunctionRef<void(FPlutoCollisionGizmoStyle&)> Mutation)
{
	if (!bOverrideProjectStyle)
	{
		OverrideStyle = GetResolvedStyle();
		bOverrideProjectStyle = true;
	}

	Mutation(OverrideStyle);
	OverrideStyle.Sanitize();
	RefreshGizmo();
}

void UPlutoCollisionGizmoComponent::SetOutlineColor(FLinearColor Color)
{
	ApplyStyleMutation([Color](FPlutoCollisionGizmoStyle& Style) { Style.OutlineColor = Color; });
}

void UPlutoCollisionGizmoComponent::SetLineThickness(float Thickness)
{
	ApplyStyleMutation([Thickness](FPlutoCollisionGizmoStyle& Style) { Style.LineThickness = Thickness; });
}

void UPlutoCollisionGizmoComponent::SetFillColor(FLinearColor Color)
{
	ApplyStyleMutation([Color](FPlutoCollisionGizmoStyle& Style) { Style.FillColor = Color; });
}

void UPlutoCollisionGizmoComponent::SetFillOpacity(float Opacity)
{
	ApplyStyleMutation([Opacity](FPlutoCollisionGizmoStyle& Style) { Style.FillOpacity = Opacity; });
}

void UPlutoCollisionGizmoComponent::SetDrawOutline(bool bDraw)
{
	ApplyStyleMutation([bDraw](FPlutoCollisionGizmoStyle& Style) { Style.bDrawOutline = bDraw; });
}

void UPlutoCollisionGizmoComponent::SetDrawFill(bool bDraw)
{
	ApplyStyleMutation([bDraw](FPlutoCollisionGizmoStyle& Style) { Style.bDrawFill = bDraw; });
}

void UPlutoCollisionGizmoComponent::SetStyle(const FPlutoCollisionGizmoStyle& Style)
{
	bOverrideProjectStyle = true;
	OverrideStyle = Style;
	OverrideStyle.Sanitize();
	RefreshGizmo();
}

FPlutoCollisionGizmoStyle UPlutoCollisionGizmoComponent::GetResolvedStyle() const
{
	FPlutoCollisionGizmoStyle Style = bOverrideProjectStyle
		? OverrideStyle
		: GetDefault<UPlutoGizmoHelperSettings>()->DefaultCollisionStyle;
	Style.Sanitize();
	return Style;
}

bool UPlutoCollisionGizmoComponent::IsTargetValid() const
{
	return GetTargetCollision() != nullptr;
}

void UPlutoCollisionGizmoComponent::RefreshGizmo()
{
	LastTargetSignature = BuildTargetSignature();
	LastResolvedStyle = GetResolvedStyle();
	UpdateBounds();
	MarkRenderStateDirty();
}

FPrimitiveSceneProxy* UPlutoCollisionGizmoComponent::CreateSceneProxy()
{
#if UE_BUILD_SHIPPING
	return nullptr;
#else
	return bGizmoEnabled && IsTargetValid() ? new FPlutoCollisionGizmoSceneProxy(this) : nullptr;
#endif
}

FBoxSphereBounds UPlutoCollisionGizmoComponent::CalcBounds(const FTransform& LocalToWorld) const
{
	if (const UPrimitiveComponent* Shape = GetTargetCollision())
	{
		return Shape->Bounds;
	}

	return FBoxSphereBounds(LocalToWorld.GetLocation(), FVector::ZeroVector, 0.0f);
}

void UPlutoCollisionGizmoComponent::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

#if !UE_BUILD_SHIPPING
	const uint32 CurrentSignature = BuildTargetSignature();
	const FPlutoCollisionGizmoStyle CurrentStyle = GetResolvedStyle();
	if (CurrentSignature != LastTargetSignature || CurrentStyle != LastResolvedStyle)
	{
		LastTargetSignature = CurrentSignature;
		LastResolvedStyle = CurrentStyle;
		UpdateBounds();
		MarkRenderStateDirty();
	}
#endif
}

void UPlutoCollisionGizmoComponent::OnRegister()
{
	Super::OnRegister();
	RefreshGizmo();
}

uint32 UPlutoCollisionGizmoComponent::BuildTargetSignature() const
{
	const UPrimitiveComponent* Shape = GetTargetCollision();
	if (!Shape)
	{
		return 0;
	}

	uint32 Hash = GetTypeHash(Shape->GetClass());
	Hash = HashCombineFast(Hash, GetTypeHash(Shape->GetComponentTransform()));

	if (const UBoxComponent* Box = Cast<UBoxComponent>(Shape))
	{
		Hash = HashCombineFast(Hash, GetTypeHash(Box->GetUnscaledBoxExtent()));
	}
	else if (const USphereComponent* Sphere = Cast<USphereComponent>(Shape))
	{
		Hash = HashCombineFast(Hash, GetTypeHash(Sphere->GetUnscaledSphereRadius()));
	}
	else if (const UCapsuleComponent* Capsule = Cast<UCapsuleComponent>(Shape))
	{
		Hash = HashCombineFast(Hash, GetTypeHash(Capsule->GetUnscaledCapsuleRadius()));
		Hash = HashCombineFast(Hash, GetTypeHash(Capsule->GetUnscaledCapsuleHalfHeight()));
	}
	else if (const UBrushComponent* Brush = Cast<UBrushComponent>(Shape))
	{
		if (const UBodySetup* BodySetup = const_cast<UBrushComponent*>(Brush)->GetBodySetup())
		{
			Hash = HashCombineFast(Hash, PointerHash(BodySetup));
			Hash = HashCombineFast(Hash, GetTypeHash(BodySetup->AggGeom.ConvexElems.Num()));
			for (const FKConvexElem& Convex : BodySetup->AggGeom.ConvexElems)
			{
				Hash = HashCombineFast(Hash, GetTypeHash(Convex.VertexData.Num()));
				Hash = HashCombineFast(Hash, GetTypeHash(Convex.IndexData.Num()));
				Hash = HashCombineFast(Hash, GetTypeHash(Convex.ElemBox.Min));
				Hash = HashCombineFast(Hash, GetTypeHash(Convex.ElemBox.Max));
				Hash = HashCombineFast(Hash, GetTypeHash(Convex.GetTransform()));
				for (const FVector& Vertex : Convex.VertexData)
				{
					Hash = HashCombineFast(Hash, GetTypeHash(Vertex));
				}
				for (const int32 Index : Convex.IndexData)
				{
					Hash = HashCombineFast(Hash, GetTypeHash(Index));
				}
			}
		}
	}

	Hash = HashCombineFast(Hash, GetTypeHash(bGizmoEnabled));
	Hash = HashCombineFast(Hash, GetTypeHash(static_cast<uint8>(VisibilityMode)));
	return Hash;
}

#if WITH_EDITOR
void UPlutoCollisionGizmoComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	OverrideStyle.Sanitize();
	Super::PostEditChangeProperty(PropertyChangedEvent);
	RefreshGizmo();
}

void UPlutoCollisionGizmoComponent::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	OverrideStyle.Sanitize();
	Super::PostEditChangeChainProperty(PropertyChangedEvent);
	RefreshGizmo();
}
#endif
