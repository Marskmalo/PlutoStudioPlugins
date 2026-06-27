#include "PlutoSplineWallDetails.h"

#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "PlutoSplineHelperEditorSettings.h"
#include "PlutoSplineWallActor.h"
#include "ScopedTransaction.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"

namespace
{
	FText L(const TCHAR* ChineseText, const TCHAR* EnglishText)
	{
		return PlutoSplineHelperEditor::Localized(ChineseText, EnglishText);
	}

	void AddLanguageSelector(IDetailCategoryBuilder& Category)
	{
		Category.AddCustomRow(L(TEXT("界面语言"), TEXT("UI Language")))
		.NameContent()
		[
			SNew(STextBlock)
			.Text(L(TEXT("界面语言"), TEXT("UI Language")))
			.Font(IDetailLayoutBuilder::GetDetailFont())
		]
		.ValueContent()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0.0f, 0.0f, 6.0f, 0.0f)
			[
				SNew(SButton)
				.Text(FText::FromString(TEXT("中文")))
				.IsEnabled_Lambda([] { return PlutoSplineHelperEditor::GetCurrentLanguage() != EPlutoSplineHelperLanguage::Chinese; })
				.OnClicked_Lambda([]
				{
					PlutoSplineHelperEditor::SetCurrentLanguage(EPlutoSplineHelperLanguage::Chinese);
					return FReply::Handled();
				})
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SButton)
				.Text(FText::FromString(TEXT("English")))
				.IsEnabled_Lambda([] { return PlutoSplineHelperEditor::GetCurrentLanguage() != EPlutoSplineHelperLanguage::English; })
				.OnClicked_Lambda([]
				{
					PlutoSplineHelperEditor::SetCurrentLanguage(EPlutoSplineHelperLanguage::English);
					return FReply::Handled();
				})
			]
		];
	}

	void AddProperty(
		IDetailCategoryBuilder& Category,
		IDetailLayoutBuilder& DetailBuilder,
		FName PropertyName,
		const TCHAR* ChineseName,
		const TCHAR* EnglishName)
	{
		const TSharedRef<IPropertyHandle> Handle = DetailBuilder.GetProperty(PropertyName, APlutoSplineWall::StaticClass());
		if (Handle->IsValidHandle())
		{
			Category.AddProperty(Handle).DisplayName(L(ChineseName, EnglishName));
		}
	}

	void SetStyleChildName(
		const TSharedRef<IPropertyHandle>& StyleHandle,
		FName ChildName,
		const TCHAR* ChineseName,
		const TCHAR* EnglishName)
	{
		if (const TSharedPtr<IPropertyHandle> Child = StyleHandle->GetChildHandle(ChildName))
		{
			Child->SetPropertyDisplayName(L(ChineseName, EnglishName));
		}
	}
}

TSharedRef<IDetailCustomization> FPlutoSplineWallDetails::MakeInstance()
{
	return MakeShared<FPlutoSplineWallDetails>();
}

void FPlutoSplineWallDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	DetailBuilder.HideCategory(TEXT("Pluto Spline Wall"));
	DetailBuilder.HideCategory(TEXT("Pluto Spline Wall|Geometry"));
	DetailBuilder.HideCategory(TEXT("Pluto Spline Wall|Caps"));
	DetailBuilder.HideCategory(TEXT("Pluto Spline Wall|Preview"));

	TArray<TWeakObjectPtr<UObject>> Objects;
	DetailBuilder.GetObjectsBeingCustomized(Objects);

	IDetailCategoryBuilder& General = DetailBuilder.EditCategory(
		TEXT("PlutoSplineWall"),
		L(TEXT("Pluto Spline 空气墙"), TEXT("Pluto Spline Wall")),
		ECategoryPriority::Important);
	AddLanguageSelector(General);

	IDetailCategoryBuilder& Geometry = DetailBuilder.EditCategory(
		TEXT("PlutoSplineGeometry"),
		L(TEXT("几何与方向"), TEXT("Geometry and Direction")),
		ECategoryPriority::Important);
	AddProperty(Geometry, DetailBuilder, GET_MEMBER_NAME_CHECKED(APlutoSplineWall, bClosedLoop), TEXT("自动闭环"), TEXT("Closed Loop"));
	AddProperty(Geometry, DetailBuilder, GET_MEMBER_NAME_CHECKED(APlutoSplineWall, Height), TEXT("墙体高度"), TEXT("Wall Height"));
	AddProperty(Geometry, DetailBuilder, GET_MEMBER_NAME_CHECKED(APlutoSplineWall, BottomOffset), TEXT("底部偏移"), TEXT("Bottom Offset"));
	AddProperty(Geometry, DetailBuilder, GET_MEMBER_NAME_CHECKED(APlutoSplineWall, SampleSpacing), TEXT("曲线采样间距"), TEXT("Curve Sample Spacing"));
	AddProperty(Geometry, DetailBuilder, GET_MEMBER_NAME_CHECKED(APlutoSplineWall, OpenWallThickness), TEXT("开放墙厚度"), TEXT("Open Wall Thickness"));
	AddProperty(Geometry, DetailBuilder, GET_MEMBER_NAME_CHECKED(APlutoSplineWall, AllSplinePointType), TEXT("全部样条点类型"), TEXT("All Spline Point Types"));
	Geometry.AddCustomRow(L(TEXT("重新应用点类型"), TEXT("Reapply Point Type")))
	.NameContent()
	[
		SNew(STextBlock)
		.Text(L(TEXT("批量设置"), TEXT("Batch Apply")))
		.ToolTipText(L(
			TEXT("将上方类型重新应用到所有现有样条点；之后仍可单独覆写任意点。"),
			TEXT("Reapply the selected type to all existing points. Individual points can still be overridden afterward.")))
		.Font(IDetailLayoutBuilder::GetDetailFont())
	]
	.ValueContent()
	[
		SNew(SButton)
		.Text(L(TEXT("应用到所有点"), TEXT("Apply To All Points")))
		.OnClicked_Lambda([Objects]
		{
			const FScopedTransaction Transaction(L(TEXT("批量设置样条点类型"), TEXT("Set All Spline Point Types")));
			for (const TWeakObjectPtr<UObject>& Object : Objects)
			{
				if (APlutoSplineWall* Wall = Cast<APlutoSplineWall>(Object.Get()))
				{
					Wall->Modify();
					Wall->ApplySplinePointTypeToAll();
				}
			}
			return FReply::Handled();
		})
	];
	AddProperty(Geometry, DetailBuilder, GET_MEMBER_NAME_CHECKED(APlutoSplineWall, Direction), TEXT("处理方向"), TEXT("Processing Direction"));

	IDetailCategoryBuilder& Caps = DetailBuilder.EditCategory(
		TEXT("PlutoSplineCaps"),
		L(TEXT("顶盖与底盖"), TEXT("Top and Bottom Caps")),
		ECategoryPriority::Important);
	AddProperty(Caps, DetailBuilder, GET_MEMBER_NAME_CHECKED(APlutoSplineWall, bCollisionTopCap), TEXT("顶盖参与碰撞"), TEXT("Collision Top Cap"));
	AddProperty(Caps, DetailBuilder, GET_MEMBER_NAME_CHECKED(APlutoSplineWall, bCollisionBottomCap), TEXT("底盖参与碰撞"), TEXT("Collision Bottom Cap"));
	AddProperty(Caps, DetailBuilder, GET_MEMBER_NAME_CHECKED(APlutoSplineWall, bPreviewTopCap), TEXT("显示顶盖"), TEXT("Preview Top Cap"));
	AddProperty(Caps, DetailBuilder, GET_MEMBER_NAME_CHECKED(APlutoSplineWall, bPreviewBottomCap), TEXT("显示底盖"), TEXT("Preview Bottom Cap"));

	IDetailCategoryBuilder& Preview = DetailBuilder.EditCategory(
		TEXT("PlutoSplinePreview"),
		L(TEXT("区域预览"), TEXT("Region Preview")),
		ECategoryPriority::Important);
	AddProperty(Preview, DetailBuilder, GET_MEMBER_NAME_CHECKED(APlutoSplineWall, EditorPreview), TEXT("编辑器预览"), TEXT("Editor Preview"));
	AddProperty(Preview, DetailBuilder, GET_MEMBER_NAME_CHECKED(APlutoSplineWall, bShowPreviewInPIE), TEXT("PIE 中显示"), TEXT("Show In PIE"));
	AddProperty(Preview, DetailBuilder, GET_MEMBER_NAME_CHECKED(APlutoSplineWall, PreviewStyle), TEXT("预览样式"), TEXT("Preview Style"));

	const TSharedRef<IPropertyHandle> StyleHandle = DetailBuilder.GetProperty(
		GET_MEMBER_NAME_CHECKED(APlutoSplineWall, PreviewStyle),
		APlutoSplineWall::StaticClass());
	SetStyleChildName(StyleHandle, GET_MEMBER_NAME_CHECKED(FPlutoSplineWallPreviewStyle, FillColor), TEXT("填充颜色"), TEXT("Fill Color"));
	SetStyleChildName(StyleHandle, GET_MEMBER_NAME_CHECKED(FPlutoSplineWallPreviewStyle, FillOpacity), TEXT("填充透明度"), TEXT("Fill Opacity"));
	SetStyleChildName(StyleHandle, GET_MEMBER_NAME_CHECKED(FPlutoSplineWallPreviewStyle, OutlineColor), TEXT("线框颜色"), TEXT("Outline Color"));
	SetStyleChildName(StyleHandle, GET_MEMBER_NAME_CHECKED(FPlutoSplineWallPreviewStyle, LineThickness), TEXT("线框粗细"), TEXT("Line Thickness"));
	SetStyleChildName(StyleHandle, GET_MEMBER_NAME_CHECKED(FPlutoSplineWallPreviewStyle, bShowDirectionArrows), TEXT("显示方向箭头"), TEXT("Show Direction Arrows"));
	SetStyleChildName(StyleHandle, GET_MEMBER_NAME_CHECKED(FPlutoSplineWallPreviewStyle, DirectionArrowColor), TEXT("方向箭头颜色"), TEXT("Direction Arrow Color"));
	SetStyleChildName(StyleHandle, GET_MEMBER_NAME_CHECKED(FPlutoSplineWallPreviewStyle, DirectionArrowSpacing), TEXT("方向箭头间距"), TEXT("Direction Arrow Spacing"));
	SetStyleChildName(StyleHandle, GET_MEMBER_NAME_CHECKED(FPlutoSplineWallPreviewStyle, OpenWallWireColor), TEXT("开放墙线框颜色"), TEXT("Open Wall Wire Color"));

	for (const TWeakObjectPtr<UObject>& Object : Objects)
	{
		if (const APlutoSplineWall* Wall = Cast<APlutoSplineWall>(Object.Get()); Wall && !Wall->IsCurrentShapeValid())
		{
			General.AddCustomRow(L(TEXT("形状错误"), TEXT("Shape Error")))
			.WholeRowContent()
			[
				SNew(STextBlock)
				.Text(L(
					TEXT("Spline 自相交或退化，当前仍使用最后一次有效碰撞形状。"),
					TEXT("The spline is self-intersecting or degenerate. The last valid collision shape remains active.")))
				.ColorAndOpacity(FLinearColor::Red)
				.AutoWrapText(true)
			];
			break;
		}
	}
}

TSharedRef<IDetailCustomization> FPlutoSplineHelperEditorSettingsDetails::MakeInstance()
{
	return MakeShared<FPlutoSplineHelperEditorSettingsDetails>();
}

void FPlutoSplineHelperEditorSettingsDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	DetailBuilder.HideCategory(TEXT("General"));
	DetailBuilder.HideProperty(DetailBuilder.GetProperty(
		GET_MEMBER_NAME_CHECKED(UPlutoSplineHelperEditorSettings, Language),
		UPlutoSplineHelperEditorSettings::StaticClass()));

	IDetailCategoryBuilder& Category = DetailBuilder.EditCategory(
		TEXT("GeneralLocalized"),
		L(TEXT("常规"), TEXT("General")));
	AddLanguageSelector(Category);
}
