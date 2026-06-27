#include "PlutoSplineWallActor.h"

#include "CompGeom/PolygonTriangulation.h"
#include "Components/DynamicMeshComponent.h"
#include "Components/LineBatchComponent.h"
#include "DynamicMesh/DynamicMesh3.h"
#include "Engine/CollisionProfile.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "HAL/IConsoleManager.h"
#include "PhysicsEngine/BodySetup.h"
#include "PlutoSplineWallSplineComponent.h"

using namespace UE::Geometry;

namespace PlutoSplineWall
{
#if !UE_BUILD_SHIPPING
#if WITH_EDITOR
	constexpr int32 DefaultPreviewVisibility = 1;
#else
	constexpr int32 DefaultPreviewVisibility = 0;
#endif

	static TAutoConsoleVariable<int32> CVarPreview(
		TEXT("pluto.Spline.Preview"),
		DefaultPreviewVisibility,
		TEXT("Controls Pluto Spline Helper previews. 0: hidden, 1: visible."),
		ECVF_RenderThreadSafe);
#endif

	static constexpr float PointTolerance = 0.1f;

	static double Cross2D(const FVector2D& A, const FVector2D& B, const FVector2D& C)
	{
		return static_cast<double>(B.X - A.X) * static_cast<double>(C.Y - A.Y)
			- static_cast<double>(B.Y - A.Y) * static_cast<double>(C.X - A.X);
	}

	static bool PointOnSegment(const FVector2D& A, const FVector2D& B, const FVector2D& P)
	{
		if (FMath::Abs(Cross2D(A, B, P)) > PointTolerance)
		{
			return false;
		}

		return P.X >= FMath::Min(A.X, B.X) - PointTolerance
			&& P.X <= FMath::Max(A.X, B.X) + PointTolerance
			&& P.Y >= FMath::Min(A.Y, B.Y) - PointTolerance
			&& P.Y <= FMath::Max(A.Y, B.Y) + PointTolerance;
	}

	static bool SegmentsIntersect(
		const FVector2D& A0,
		const FVector2D& A1,
		const FVector2D& B0,
		const FVector2D& B1)
	{
		const double C1 = Cross2D(A0, A1, B0);
		const double C2 = Cross2D(A0, A1, B1);
		const double C3 = Cross2D(B0, B1, A0);
		const double C4 = Cross2D(B0, B1, A1);

		const bool bProperIntersection =
			((C1 > PointTolerance && C2 < -PointTolerance) || (C1 < -PointTolerance && C2 > PointTolerance))
			&& ((C3 > PointTolerance && C4 < -PointTolerance) || (C3 < -PointTolerance && C4 > PointTolerance));
		if (bProperIntersection)
		{
			return true;
		}

		return (FMath::Abs(C1) <= PointTolerance && PointOnSegment(A0, A1, B0))
			|| (FMath::Abs(C2) <= PointTolerance && PointOnSegment(A0, A1, B1))
			|| (FMath::Abs(C3) <= PointTolerance && PointOnSegment(B0, B1, A0))
			|| (FMath::Abs(C4) <= PointTolerance && PointOnSegment(B0, B1, A1));
	}

	static double SignedArea(const TArray<FVector2D>& Points)
	{
		double Area = 0.0;
		for (int32 Index = 0; Index < Points.Num(); ++Index)
		{
			const FVector2D& A = Points[Index];
			const FVector2D& B = Points[(Index + 1) % Points.Num()];
			Area += static_cast<double>(A.X) * static_cast<double>(B.Y)
				- static_cast<double>(B.X) * static_cast<double>(A.Y);
		}
		return Area * 0.5;
	}

	static void AddTriangle(TArray<int32>& Indices, int32 A, int32 B, int32 C, bool bReverse)
	{
		if (bReverse)
		{
			Indices.Append({A, C, B});
		}
		else
		{
			Indices.Append({A, B, C});
		}
	}

	static void AddQuad(TArray<int32>& Indices, int32 A, int32 B, int32 C, int32 D, bool bReverse)
	{
		AddTriangle(Indices, A, B, C, bReverse);
		AddTriangle(Indices, A, C, D, bReverse);
	}

	static FVector2D SegmentRightNormal(const FVector2D& A, const FVector2D& B)
	{
		const FVector2D Direction = (B - A).GetSafeNormal();
		return FVector2D(Direction.Y, -Direction.X);
	}

	static bool IntersectOffsetLines(
		const FVector2D& A0,
		const FVector2D& A1,
		const FVector2D& B0,
		const FVector2D& B1,
		FVector2D& OutIntersection)
	{
		const FVector2D R = A1 - A0;
		const FVector2D S = B1 - B0;
		const double Denominator = static_cast<double>(R.X) * static_cast<double>(S.Y)
			- static_cast<double>(R.Y) * static_cast<double>(S.X);
		if (FMath::Abs(Denominator) <= UE_SMALL_NUMBER)
		{
			return false;
		}

		const FVector2D Delta = B0 - A0;
		const double T = (static_cast<double>(Delta.X) * static_cast<double>(S.Y)
			- static_cast<double>(Delta.Y) * static_cast<double>(S.X)) / Denominator;
		OutIntersection = A0 + R * static_cast<float>(T);
		return true;
	}

	static FVector2D ComputeOpenWallOffsetPoint(
		const TArray<FVector2D>& Points,
		int32 PointIndex,
		float HalfThickness,
		float SideSign)
	{
		const int32 LastIndex = Points.Num() - 1;
		const FVector2D& Point = Points[PointIndex];
		if (PointIndex == 0)
		{
			return Point + SegmentRightNormal(Points[0], Points[1]) * HalfThickness * SideSign;
		}
		if (PointIndex == LastIndex)
		{
			return Point + SegmentRightNormal(Points[LastIndex - 1], Points[LastIndex]) * HalfThickness * SideSign;
		}

		const FVector2D PrevNormal = SegmentRightNormal(Points[PointIndex - 1], Point) * SideSign;
		const FVector2D NextNormal = SegmentRightNormal(Point, Points[PointIndex + 1]) * SideSign;
		const FVector2D PrevOffsetA = Points[PointIndex - 1] + PrevNormal * HalfThickness;
		const FVector2D PrevOffsetB = Point + PrevNormal * HalfThickness;
		const FVector2D NextOffsetA = Point + NextNormal * HalfThickness;
		const FVector2D NextOffsetB = Points[PointIndex + 1] + NextNormal * HalfThickness;

		FVector2D Intersection;
		const float MaxMiterLength = FMath::Max(HalfThickness * 4.0f, HalfThickness + 1.0f);
		if (IntersectOffsetLines(PrevOffsetA, PrevOffsetB, NextOffsetA, NextOffsetB, Intersection)
			&& FVector2D::Distance(Point, Intersection) <= MaxMiterLength)
		{
			return Intersection;
		}

		FVector2D AverageNormal = PrevNormal + NextNormal;
		if (!AverageNormal.Normalize())
		{
			AverageNormal = NextNormal;
		}
		return Point + AverageNormal * HalfThickness;
	}

	static void AppendOpenWallPrism(
		TArray<FVector>& Vertices,
		TArray<int32>& Indices,
		const TArray<FVector2D>& Points,
		float Bottom,
		float Top,
		float Thickness)
	{
		if (Points.Num() < 2)
		{
			return;
		}

		const float HalfThickness = FMath::Max(1.0f, Thickness) * 0.5f;
		TArray<FVector2D> RightPoints;
		TArray<FVector2D> LeftPoints;
		RightPoints.Reserve(Points.Num());
		LeftPoints.Reserve(Points.Num());
		for (int32 PointIndex = 0; PointIndex < Points.Num(); ++PointIndex)
		{
			RightPoints.Add(ComputeOpenWallOffsetPoint(Points, PointIndex, HalfThickness, 1.0f));
			LeftPoints.Add(ComputeOpenWallOffsetPoint(Points, PointIndex, HalfThickness, -1.0f));
		}

		const int32 BaseIndex = Vertices.Num();
		for (int32 PointIndex = 0; PointIndex < Points.Num(); ++PointIndex)
		{
			const FVector2D& Right = RightPoints[PointIndex];
			const FVector2D& Left = LeftPoints[PointIndex];
			Vertices.Add(FVector(Right.X, Right.Y, Bottom));
			Vertices.Add(FVector(Right.X, Right.Y, Top));
			Vertices.Add(FVector(Left.X, Left.Y, Bottom));
			Vertices.Add(FVector(Left.X, Left.Y, Top));
		}

		for (int32 PointIndex = 0; PointIndex < Points.Num() - 1; ++PointIndex)
		{
			const int32 A = BaseIndex + PointIndex * 4;
			const int32 B = BaseIndex + (PointIndex + 1) * 4;

			AddQuad(Indices, A, B, B + 1, A + 1, false);
			AddQuad(Indices, A + 2, A + 3, B + 3, B + 2, false);
			AddQuad(Indices, A + 1, B + 1, B + 3, A + 3, false);
			AddQuad(Indices, A, A + 2, B + 2, B, false);
		}

		AddQuad(Indices, BaseIndex, BaseIndex + 1, BaseIndex + 3, BaseIndex + 2, false);

		const int32 EndIndex = BaseIndex + (Points.Num() - 1) * 4;
		AddQuad(Indices, EndIndex, EndIndex + 2, EndIndex + 3, EndIndex + 1, false);
	}

	static void AppendSideWall(
		TArray<FVector>& Vertices,
		TArray<int32>& Indices,
		const FVector2D& P0,
		const FVector2D& P1,
		float Bottom,
		float Top,
		bool bRightFacing,
		bool bDoubleSided)
	{
		const int32 BaseIndex = Vertices.Num();
		Vertices.Add(FVector(P0.X, P0.Y, Bottom));
		Vertices.Add(FVector(P1.X, P1.Y, Bottom));
		Vertices.Add(FVector(P1.X, P1.Y, Top));
		Vertices.Add(FVector(P0.X, P0.Y, Top));

		AddTriangle(Indices, BaseIndex, BaseIndex + 1, BaseIndex + 2, !bRightFacing);
		AddTriangle(Indices, BaseIndex, BaseIndex + 2, BaseIndex + 3, !bRightFacing);
		if (bDoubleSided)
		{
			AddTriangle(Indices, BaseIndex, BaseIndex + 1, BaseIndex + 2, bRightFacing);
			AddTriangle(Indices, BaseIndex, BaseIndex + 2, BaseIndex + 3, bRightFacing);
		}
	}

	static void AppendCap(
		TArray<FVector>& Vertices,
		TArray<int32>& Indices,
		const TArray<FVector2D>& Points,
		const TArray<FIndex3i>& Triangles,
		float Z,
		bool bFacePositiveZ)
	{
		const int32 BaseIndex = Vertices.Num();
		for (const FVector2D& Point : Points)
		{
			Vertices.Add(FVector(Point.X, Point.Y, Z));
		}

		for (const FIndex3i& Triangle : Triangles)
		{
			const double Cross = Cross2D(Points[Triangle.A], Points[Triangle.B], Points[Triangle.C]);
			const bool bCurrentPositive = Cross > 0.0;
			AddTriangle(
				Indices,
				BaseIndex + Triangle.A,
				BaseIndex + Triangle.B,
				BaseIndex + Triangle.C,
				bCurrentPositive != bFacePositiveZ);
		}
	}

	static uint32 HashLinearColor(const FLinearColor& Color)
	{
		uint32 Hash = GetTypeHash(Color.R);
		Hash = HashCombineFast(Hash, GetTypeHash(Color.G));
		Hash = HashCombineFast(Hash, GetTypeHash(Color.B));
		Hash = HashCombineFast(Hash, GetTypeHash(Color.A));
		return Hash;
	}

	static FPlutoSplineWallValidationFailed ValidationFailedDelegate;
}

APlutoSplineWall::APlutoSplineWall()
{
#if UE_BUILD_SHIPPING
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
#else
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
#endif

	Spline = CreateDefaultSubobject<UPlutoSplineWallSplineComponent>(TEXT("Spline"));
	SetRootComponent(Spline);
	Spline->SetClosedLoop(true, false);
	Spline->ClearSplinePoints(false);
	Spline->AddSplinePoint(FVector(-250.0f, -250.0f, 0.0f), ESplineCoordinateSpace::Local, false);
	Spline->AddSplinePoint(FVector(250.0f, -250.0f, 0.0f), ESplineCoordinateSpace::Local, false);
	Spline->AddSplinePoint(FVector(250.0f, 250.0f, 0.0f), ESplineCoordinateSpace::Local, false);
	Spline->AddSplinePoint(FVector(-250.0f, 250.0f, 0.0f), ESplineCoordinateSpace::Local, true);

	CollisionMesh = CreateDefaultSubobject<UDynamicMeshComponent>(TEXT("CollisionMesh"));
	CollisionMesh->SetupAttachment(Spline);
	CollisionMesh->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	CollisionMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionMesh->SetGenerateOverlapEvents(false);
	CollisionMesh->SetCanEverAffectNavigation(false);
	CollisionMesh->SetVisibility(false, true);
	CollisionMesh->SetHiddenInGame(true);
	CollisionMesh->CastShadow = false;
	CollisionMesh->bUseAsyncCooking = false;
	CollisionMesh->SetComplexAsSimpleCollisionEnabled(true, false);

	Preview = CreateDefaultSubobject<ULineBatchComponent>(TEXT("Preview"));
	Preview->SetupAttachment(Spline);
	Preview->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Preview->SetGenerateOverlapEvents(false);
	Preview->SetCanEverAffectNavigation(false);
	Preview->bCalculateAccurateBounds = true;
	Preview->CastShadow = false;
}

FPlutoSplineWallValidationFailed& APlutoSplineWall::OnValidationFailed()
{
	return PlutoSplineWall::ValidationFailedDelegate;
}

void APlutoSplineWall::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	RebuildWall();
}

void APlutoSplineWall::BeginPlay()
{
	Super::BeginPlay();
	RebuildWall();
}

void APlutoSplineWall::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

#if !UE_BUILD_SHIPPING
	const uint32 CurrentSignature = BuildConfigurationSignature();
	if (CurrentSignature != LastConfigurationSignature)
	{
		RebuildWall();
	}
	else
	{
		RefreshPreview();
	}
#endif
}

bool APlutoSplineWall::ShouldTickIfViewportsOnly() const
{
	return true;
}

void APlutoSplineWall::HandleSplineEdited()
{
#if WITH_EDITOR
	if (!bIsRebuilding && HasAnyFlags(RF_ClassDefaultObject) == false)
	{
		RebuildWall();
	}
#endif
}

void APlutoSplineWall::ApplySplinePointTypeToAll()
{
	if (!Spline)
	{
		return;
	}

#if WITH_EDITOR
	Spline->Modify();
#endif

	const int32 PointCount = Spline->GetNumberOfSplinePoints();
	for (int32 PointIndex = 0; PointIndex < PointCount; ++PointIndex)
	{
		Spline->SetSplinePointType(PointIndex, AllSplinePointType.GetValue(), false);
	}

	Spline->UpdateSpline();

#if !WITH_EDITOR
	RebuildWall();
#endif
}

bool APlutoSplineWall::BuildSampledPolygon(TArray<FVector2D>& OutPoints) const
{
	OutPoints.Reset();
	if (!Spline)
	{
		return false;
	}

	const int32 SegmentCount = Spline->GetNumberOfSplineSegments();
	if (SegmentCount <= 0)
	{
		return false;
	}

	const float SafeSpacing = FMath::Max(5.0f, SampleSpacing);
	for (int32 SegmentIndex = 0; SegmentIndex < SegmentCount; ++SegmentIndex)
	{
		float EstimatedLength = 0.0f;
		FVector Previous = Spline->GetLocationAtSplineInputKey(
			static_cast<float>(SegmentIndex),
			ESplineCoordinateSpace::Local);
		Previous.Z = 0.0f;

		constexpr int32 EstimateSteps = 8;
		for (int32 Step = 1; Step <= EstimateSteps; ++Step)
		{
			const float Key = static_cast<float>(SegmentIndex) + static_cast<float>(Step) / EstimateSteps;
			FVector Current = Spline->GetLocationAtSplineInputKey(Key, ESplineCoordinateSpace::Local);
			Current.Z = 0.0f;
			EstimatedLength += FVector::Distance(Previous, Current);
			Previous = Current;
		}

		const int32 Divisions = FMath::Clamp(FMath::CeilToInt(EstimatedLength / SafeSpacing), 1, 256);
		for (int32 Division = 0; Division < Divisions; ++Division)
		{
			const float Key = static_cast<float>(SegmentIndex) + static_cast<float>(Division) / Divisions;
			const FVector Location = Spline->GetLocationAtSplineInputKey(Key, ESplineCoordinateSpace::Local);
			const FVector2D Point(Location.X, Location.Y);
			if (OutPoints.IsEmpty() || !OutPoints.Last().Equals(Point, PlutoSplineWall::PointTolerance))
			{
				OutPoints.Add(Point);
			}
		}
	}

	if (!bClosedLoop)
	{
		const FVector EndLocation = Spline->GetLocationAtSplineInputKey(
			static_cast<float>(SegmentCount),
			ESplineCoordinateSpace::Local);
		const FVector2D EndPoint(EndLocation.X, EndLocation.Y);
		if (OutPoints.IsEmpty() || !OutPoints.Last().Equals(EndPoint, PlutoSplineWall::PointTolerance))
		{
			OutPoints.Add(EndPoint);
		}
	}
	else if (OutPoints.Num() > 1 && OutPoints[0].Equals(OutPoints.Last(), PlutoSplineWall::PointTolerance))
	{
		OutPoints.Pop();
	}

	return bClosedLoop ? OutPoints.Num() >= 3 : OutPoints.Num() >= 2;
}

bool APlutoSplineWall::ValidateClosedPolygon(const TArray<FVector2D>& Points, FText& OutError) const
{
	if (Points.Num() < 3)
	{
		OutError = NSLOCTEXT("PlutoSplineHelper", "NotEnoughPoints", "A closed wall requires at least three distinct points.");
		return false;
	}

	if (FMath::Abs(PlutoSplineWall::SignedArea(Points)) < 1.0)
	{
		OutError = NSLOCTEXT("PlutoSplineHelper", "DegeneratePolygon", "The closed spline has no usable area.");
		return false;
	}

	const int32 SegmentCount = Points.Num();
	for (int32 A = 0; A < SegmentCount; ++A)
	{
		const int32 ANext = (A + 1) % SegmentCount;
		for (int32 B = A + 1; B < SegmentCount; ++B)
		{
			const int32 BNext = (B + 1) % SegmentCount;
			const bool bAdjacent = A == B || ANext == B || BNext == A;
			if (bAdjacent)
			{
				continue;
			}

			if (PlutoSplineWall::SegmentsIntersect(Points[A], Points[ANext], Points[B], Points[BNext]))
			{
				OutError = NSLOCTEXT("PlutoSplineHelper", "SelfIntersection", "Spline self-intersection detected. The last valid shape is still active.");
				return false;
			}
		}
	}

	return true;
}

bool APlutoSplineWall::GenerateGeometry(FGeneratedGeometry& OutGeometry, FText& OutError) const
{
	OutGeometry = FGeneratedGeometry();
	if (!BuildSampledPolygon(OutGeometry.SampledPoints))
	{
		OutError = NSLOCTEXT("PlutoSplineHelper", "InvalidSpline", "The spline does not contain enough usable points.");
		return false;
	}

	if (bClosedLoop && !ValidateClosedPolygon(OutGeometry.SampledPoints, OutError))
	{
		return false;
	}

	const float Bottom = BottomOffset;
	const float Top = BottomOffset + FMath::Max(1.0f, Height);
	const bool bPolygonCounterClockwise = bClosedLoop
		&& PlutoSplineWall::SignedArea(OutGeometry.SampledPoints) > 0.0;
	const bool bFaceOutward = Direction == EPlutoSplineWallDirection::ProcessExternalObjects;
	const bool bRightFacing = bClosedLoop
		? (bPolygonCounterClockwise == bFaceOutward)
		: true;

	if (bClosedLoop)
	{
		const int32 SegmentCount = OutGeometry.SampledPoints.Num();
		for (int32 SegmentIndex = 0; SegmentIndex < SegmentCount; ++SegmentIndex)
		{
			const FVector2D& P0 = OutGeometry.SampledPoints[SegmentIndex];
			const FVector2D& P1 = OutGeometry.SampledPoints[(SegmentIndex + 1) % OutGeometry.SampledPoints.Num()];
			PlutoSplineWall::AppendSideWall(
				OutGeometry.CollisionVertices,
				OutGeometry.CollisionIndices,
				P0,
				P1,
				Bottom,
				Top,
				bRightFacing,
				false);
			PlutoSplineWall::AppendSideWall(
				OutGeometry.PreviewVertices,
				OutGeometry.PreviewIndices,
				P0,
				P1,
				Bottom,
				Top,
				bRightFacing,
				false);
		}
	}
	else
	{
		PlutoSplineWall::AppendOpenWallPrism(
			OutGeometry.CollisionVertices,
			OutGeometry.CollisionIndices,
			OutGeometry.SampledPoints,
			Bottom,
			Top,
			OpenWallThickness);
		PlutoSplineWall::AppendOpenWallPrism(
			OutGeometry.PreviewVertices,
			OutGeometry.PreviewIndices,
			OutGeometry.SampledPoints,
			Bottom,
			Top,
			OpenWallThickness);
	}

	if (bClosedLoop)
	{
		TArray<FIndex3i> Triangles;
		PolygonTriangulation::TriangulateSimplePolygon(OutGeometry.SampledPoints, Triangles, false);
		if (Triangles.IsEmpty())
		{
			OutError = NSLOCTEXT("PlutoSplineHelper", "TriangulationFailed", "Failed to triangulate the closed spline.");
			return false;
		}

		const bool bTopFacesPositive = Direction == EPlutoSplineWallDirection::ProcessExternalObjects;
		const bool bBottomFacesPositive = !bTopFacesPositive;
		if (bCollisionTopCap)
		{
			PlutoSplineWall::AppendCap(
				OutGeometry.CollisionVertices,
				OutGeometry.CollisionIndices,
				OutGeometry.SampledPoints,
				Triangles,
				Top,
				bTopFacesPositive);
		}
		if (bCollisionBottomCap)
		{
			PlutoSplineWall::AppendCap(
				OutGeometry.CollisionVertices,
				OutGeometry.CollisionIndices,
				OutGeometry.SampledPoints,
				Triangles,
				Bottom,
				bBottomFacesPositive);
		}
		if (bPreviewTopCap)
		{
			PlutoSplineWall::AppendCap(
				OutGeometry.PreviewVertices,
				OutGeometry.PreviewIndices,
				OutGeometry.SampledPoints,
				Triangles,
				Top,
				bTopFacesPositive);
		}
		if (bPreviewBottomCap)
		{
			PlutoSplineWall::AppendCap(
				OutGeometry.PreviewVertices,
				OutGeometry.PreviewIndices,
				OutGeometry.SampledPoints,
				Triangles,
				Bottom,
				bBottomFacesPositive);
		}
	}

	return !OutGeometry.CollisionIndices.IsEmpty();
}

void APlutoSplineWall::ApplyCollisionGeometry(const FGeneratedGeometry& Geometry)
{
	if (!CollisionMesh)
	{
		return;
	}

	FDynamicMesh3 Mesh;
	for (const FVector& Vertex : Geometry.CollisionVertices)
	{
		Mesh.AppendVertex(FVector3d(Vertex));
	}
	for (int32 Index = 0; Index + 2 < Geometry.CollisionIndices.Num(); Index += 3)
	{
		Mesh.AppendTriangle(
			Geometry.CollisionIndices[Index],
			Geometry.CollisionIndices[Index + 1],
			Geometry.CollisionIndices[Index + 2]);
	}

	CollisionMesh->SetDeferredCollisionUpdatesEnabled(true, false);
	CollisionMesh->SetMesh(MoveTemp(Mesh));
	CollisionMesh->SetComplexAsSimpleCollisionEnabled(true, false);
	if (UBodySetup* BodySetup = CollisionMesh->GetBodySetup())
	{
		BodySetup->bDoubleSidedGeometry = !bClosedLoop;
	}
	CollisionMesh->SetDeferredCollisionUpdatesEnabled(false, true);
}

bool APlutoSplineWall::RebuildWall()
{
	if (bIsRebuilding || !Spline)
	{
		return false;
	}

	TGuardValue<bool> RebuildGuard(bIsRebuilding, true);
	PreviewStyle.Sanitize();
	Height = FMath::Max(1.0f, Height);
	SampleSpacing = FMath::Max(5.0f, SampleSpacing);
	OpenWallThickness = FMath::Max(1.0f, OpenWallThickness);

	if (Spline->IsClosedLoop() != bClosedLoop)
	{
		Spline->SetClosedLoop(bClosedLoop, true);
	}

	FGeneratedGeometry NewGeometry;
	FText Error;
	const bool bWasValid = bCurrentShapeValid;
	bCurrentShapeValid = GenerateGeometry(NewGeometry, Error);
	ValidationMessage = Error;

	if (bCurrentShapeValid)
	{
		LastValidGeometry = MoveTemp(NewGeometry);
		ApplyCollisionGeometry(LastValidGeometry);
		bValidationNotificationSent = false;
	}
	else if (!bValidationNotificationSent)
	{
		bValidationNotificationSent = true;
		PlutoSplineWall::ValidationFailedDelegate.Broadcast(this);
	}

	LastConfigurationSignature = BuildConfigurationSignature();
	RefreshPreview(true);
	return bCurrentShapeValid || bWasValid;
}

bool APlutoSplineWall::ShouldShowPreview() const
{
#if UE_BUILD_SHIPPING
	return false;
#else
	if (PlutoSplineWall::CVarPreview.GetValueOnGameThread() == 0 || !GetWorld())
	{
		return false;
	}

	switch (GetWorld()->WorldType)
	{
	case EWorldType::Editor:
	case EWorldType::EditorPreview:
		if (EditorPreview == EPlutoSplineWallEditorPreview::Hidden)
		{
			return false;
		}
#if WITH_EDITOR
		return EditorPreview == EPlutoSplineWallEditorPreview::Always || IsSelectedInEditor();
#else
		return false;
#endif
	case EWorldType::PIE:
		return bShowPreviewInPIE;
	default:
		return true;
	}
#endif
}

void APlutoSplineWall::RefreshPreview(bool bForce)
{
	if (!Preview)
	{
		return;
	}

	const bool bVisible = ShouldShowPreview();
	if (!bForce && bVisible == bLastPreviewVisible)
	{
		return;
	}

	bLastPreviewVisible = bVisible;
	Preview->Flush();
	Preview->SetVisibility(bVisible, true);
	if (!bVisible)
	{
		return;
	}

	DrawValidPreview();
	if (!bCurrentShapeValid)
	{
		DrawInvalidPreview();
	}
}

void APlutoSplineWall::DrawValidPreview()
{
	if (!Preview || LastValidGeometry.PreviewVertices.IsEmpty())
	{
		return;
	}

	TArray<FVector> WorldVertices;
	WorldVertices.Reserve(LastValidGeometry.PreviewVertices.Num());
	for (const FVector& Vertex : LastValidGeometry.PreviewVertices)
	{
		WorldVertices.Add(GetActorTransform().TransformPosition(Vertex));
	}

	const FLinearColor FillLinear(
		PreviewStyle.FillColor.R,
		PreviewStyle.FillColor.G,
		PreviewStyle.FillColor.B,
		PreviewStyle.FillOpacity * PreviewStyle.FillColor.A);
	Preview->DrawMesh(WorldVertices, LastValidGeometry.PreviewIndices, FillLinear.ToFColor(true), SDPG_World, -1.0f);

	const float Bottom = BottomOffset;
	const float Top = BottomOffset + Height;
	const int32 PointCount = LastValidGeometry.SampledPoints.Num();
	const int32 SegmentCount = bClosedLoop ? PointCount : FMath::Max(0, PointCount - 1);
	const FTransform ActorTransform = GetActorTransform();

	for (int32 SegmentIndex = 0; SegmentIndex < SegmentCount; ++SegmentIndex)
	{
		const FVector2D& P0 = LastValidGeometry.SampledPoints[SegmentIndex];
		const FVector2D& P1 = LastValidGeometry.SampledPoints[(SegmentIndex + 1) % PointCount];
		const FVector B0 = ActorTransform.TransformPosition(FVector(P0.X, P0.Y, Bottom));
		const FVector B1 = ActorTransform.TransformPosition(FVector(P1.X, P1.Y, Bottom));
		const FVector T0 = ActorTransform.TransformPosition(FVector(P0.X, P0.Y, Top));
		const FVector T1 = ActorTransform.TransformPosition(FVector(P1.X, P1.Y, Top));
		Preview->DrawLine(B0, B1, PreviewStyle.OutlineColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
		Preview->DrawLine(T0, T1, PreviewStyle.OutlineColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
		Preview->DrawLine(B0, T0, PreviewStyle.OutlineColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
		if (!bClosedLoop && SegmentIndex == SegmentCount - 1)
		{
			Preview->DrawLine(B1, T1, PreviewStyle.OutlineColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
		}

		if (!bClosedLoop)
		{
			const float HalfThickness = FMath::Max(1.0f, OpenWallThickness) * 0.5f;
			const FVector2D R0 = PlutoSplineWall::ComputeOpenWallOffsetPoint(
				LastValidGeometry.SampledPoints,
				SegmentIndex,
				HalfThickness,
				1.0f);
			const FVector2D R1 = PlutoSplineWall::ComputeOpenWallOffsetPoint(
				LastValidGeometry.SampledPoints,
				SegmentIndex + 1,
				HalfThickness,
				1.0f);
			const FVector2D L0 = PlutoSplineWall::ComputeOpenWallOffsetPoint(
				LastValidGeometry.SampledPoints,
				SegmentIndex,
				HalfThickness,
				-1.0f);
			const FVector2D L1 = PlutoSplineWall::ComputeOpenWallOffsetPoint(
				LastValidGeometry.SampledPoints,
				SegmentIndex + 1,
				HalfThickness,
				-1.0f);

			const FVector RB0 = ActorTransform.TransformPosition(FVector(R0.X, R0.Y, Bottom));
			const FVector RB1 = ActorTransform.TransformPosition(FVector(R1.X, R1.Y, Bottom));
			const FVector RT0 = ActorTransform.TransformPosition(FVector(R0.X, R0.Y, Top));
			const FVector RT1 = ActorTransform.TransformPosition(FVector(R1.X, R1.Y, Top));
			const FVector LB0 = ActorTransform.TransformPosition(FVector(L0.X, L0.Y, Bottom));
			const FVector LB1 = ActorTransform.TransformPosition(FVector(L1.X, L1.Y, Bottom));
			const FVector LT0 = ActorTransform.TransformPosition(FVector(L0.X, L0.Y, Top));
			const FVector LT1 = ActorTransform.TransformPosition(FVector(L1.X, L1.Y, Top));

			Preview->DrawLine(RB0, RB1, PreviewStyle.OpenWallWireColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
			Preview->DrawLine(RT0, RT1, PreviewStyle.OpenWallWireColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
			Preview->DrawLine(LB0, LB1, PreviewStyle.OpenWallWireColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
			Preview->DrawLine(LT0, LT1, PreviewStyle.OpenWallWireColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
			if (SegmentIndex == SegmentCount - 1)
			{
				Preview->DrawLine(RB1, RT1, PreviewStyle.OpenWallWireColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
				Preview->DrawLine(LB1, LT1, PreviewStyle.OpenWallWireColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
				Preview->DrawLine(RB1, LB1, PreviewStyle.OpenWallWireColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
				Preview->DrawLine(RT1, LT1, PreviewStyle.OpenWallWireColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
			}
			if (SegmentIndex == 0)
			{
				Preview->DrawLine(RB0, RT0, PreviewStyle.OpenWallWireColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
				Preview->DrawLine(LB0, LT0, PreviewStyle.OpenWallWireColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
				Preview->DrawLine(RB0, LB0, PreviewStyle.OpenWallWireColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
				Preview->DrawLine(RT0, LT0, PreviewStyle.OpenWallWireColor, SDPG_World, PreviewStyle.LineThickness, -1.0f);
			}
		}

		if (PreviewStyle.bShowDirectionArrows)
		{
			const FVector2D Edge = (P1 - P0).GetSafeNormal();
			const float SegmentLength = FVector2D::Distance(P0, P1);
			FVector2D RightNormal(Edge.Y, -Edge.X);
			if (bClosedLoop)
			{
				const bool bCCW = PlutoSplineWall::SignedArea(LastValidGeometry.SampledPoints) > 0.0;
				const FVector2D Outward = bCCW ? RightNormal : -RightNormal;
				RightNormal = Direction == EPlutoSplineWallDirection::ProcessExternalObjects ? -Outward : Outward;
			}

			const FVector ArrowDirection = ActorTransform.TransformVectorNoScale(FVector(RightNormal.X, RightNormal.Y, 0.0f)).GetSafeNormal();
			const int32 ArrowCount = FMath::Max(
				1,
				FMath::FloorToInt(SegmentLength / FMath::Max(50.0f, PreviewStyle.DirectionArrowSpacing)));
			for (int32 ArrowIndex = 0; ArrowIndex < ArrowCount; ++ArrowIndex)
			{
				const float Alpha = static_cast<float>(ArrowIndex + 1) / static_cast<float>(ArrowCount + 1);
				const FVector2D ArrowPoint = FMath::Lerp(P0, P1, Alpha);
				const FVector MidWorld = ActorTransform.TransformPosition(
					FVector(ArrowPoint.X, ArrowPoint.Y, (Bottom + Top) * 0.5f));
				Preview->DrawDirectionalArrow(
					MidWorld - ArrowDirection * 60.0f,
					MidWorld + ArrowDirection * 60.0f,
					24.0f,
					PreviewStyle.DirectionArrowColor,
					-1.0f,
					SDPG_World,
					PreviewStyle.LineThickness);

				if (!bClosedLoop)
				{
					Preview->DrawDirectionalArrow(
						MidWorld + ArrowDirection * 60.0f,
						MidWorld - ArrowDirection * 60.0f,
						24.0f,
						PreviewStyle.DirectionArrowColor,
						-1.0f,
						SDPG_World,
						PreviewStyle.LineThickness);
				}
			}
		}
	}
}

void APlutoSplineWall::DrawInvalidPreview()
{
	if (!Preview)
	{
		return;
	}

	TArray<FVector2D> InvalidPoints;
	if (!BuildSampledPolygon(InvalidPoints))
	{
		return;
	}

	const int32 SegmentCount = bClosedLoop ? InvalidPoints.Num() : InvalidPoints.Num() - 1;
	const FTransform ActorTransform = GetActorTransform();
	const FLinearColor ErrorColor(1.0f, 0.0f, 0.0f, 1.0f);
	for (int32 SegmentIndex = 0; SegmentIndex < SegmentCount; ++SegmentIndex)
	{
		const FVector2D& P0 = InvalidPoints[SegmentIndex];
		const FVector2D& P1 = InvalidPoints[(SegmentIndex + 1) % InvalidPoints.Num()];
		Preview->DrawLine(
			ActorTransform.TransformPosition(FVector(P0.X, P0.Y, BottomOffset + Height * 0.5f)),
			ActorTransform.TransformPosition(FVector(P1.X, P1.Y, BottomOffset + Height * 0.5f)),
			ErrorColor,
			SDPG_Foreground,
			4.0f,
			-1.0f);
	}
}

uint32 APlutoSplineWall::BuildConfigurationSignature() const
{
	uint32 Hash = GetTypeHash(GetActorTransform());
	Hash = HashCombineFast(Hash, GetTypeHash(bClosedLoop));
	Hash = HashCombineFast(Hash, GetTypeHash(Height));
	Hash = HashCombineFast(Hash, GetTypeHash(BottomOffset));
	Hash = HashCombineFast(Hash, GetTypeHash(SampleSpacing));
	Hash = HashCombineFast(Hash, GetTypeHash(OpenWallThickness));
	Hash = HashCombineFast(Hash, GetTypeHash(static_cast<uint8>(Direction)));
	Hash = HashCombineFast(Hash, GetTypeHash(bCollisionTopCap));
	Hash = HashCombineFast(Hash, GetTypeHash(bCollisionBottomCap));
	Hash = HashCombineFast(Hash, GetTypeHash(bPreviewTopCap));
	Hash = HashCombineFast(Hash, GetTypeHash(bPreviewBottomCap));
	Hash = HashCombineFast(Hash, PlutoSplineWall::HashLinearColor(PreviewStyle.FillColor));
	Hash = HashCombineFast(Hash, GetTypeHash(PreviewStyle.FillOpacity));
	Hash = HashCombineFast(Hash, PlutoSplineWall::HashLinearColor(PreviewStyle.OutlineColor));
	Hash = HashCombineFast(Hash, GetTypeHash(PreviewStyle.LineThickness));
	Hash = HashCombineFast(Hash, GetTypeHash(PreviewStyle.bShowDirectionArrows));
	Hash = HashCombineFast(Hash, PlutoSplineWall::HashLinearColor(PreviewStyle.DirectionArrowColor));
	Hash = HashCombineFast(Hash, GetTypeHash(PreviewStyle.DirectionArrowSpacing));
	Hash = HashCombineFast(Hash, PlutoSplineWall::HashLinearColor(PreviewStyle.OpenWallWireColor));
	Hash = HashCombineFast(Hash, GetTypeHash(Spline ? Spline->GetVersion() : 0));
	return Hash;
}

#if WITH_EDITOR
void APlutoSplineWall::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.GetMemberPropertyName()
		== GET_MEMBER_NAME_CHECKED(APlutoSplineWall, AllSplinePointType))
	{
		ApplySplinePointTypeToAll();
	}
	else
	{
		RebuildWall();
	}
}

void APlutoSplineWall::PostEditMove(bool bFinished)
{
	Super::PostEditMove(bFinished);
	RebuildWall();
}

void APlutoSplineWall::PostEditUndo()
{
	Super::PostEditUndo();
	RebuildWall();
}
#endif
