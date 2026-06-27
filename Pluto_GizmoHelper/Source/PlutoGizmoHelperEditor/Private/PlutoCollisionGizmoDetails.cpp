#include "PlutoCollisionGizmoDetails.h"

#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/SphereComponent.h"
#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "Editor.h"
#include "Engine/Blueprint.h"
#include "Framework/Notifications/NotificationManager.h"
#include "GameFramework/Actor.h"
#include "IDetailPropertyRow.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "PlutoCollisionGizmoComponent.h"
#include "PlutoGizmoHelperEditorSettings.h"
#include "PlutoGizmoHelperSettings.h"
#include "ScopedTransaction.h"
#include "SubobjectData.h"
#include "SubobjectDataSubsystem.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"
#include "UObject/UObjectIterator.h"

namespace
{
	FText L(const TCHAR* ChineseText, const TCHAR* EnglishText)
	{
		return PlutoGizmoHelperEditor::Localized(ChineseText, EnglishText);
	}

	UBlueprint* FindBlueprintContext(const UActorComponent* Component)
	{
		if (!Component || !Component->IsTemplate())
		{
			return nullptr;
		}

		if (UBlueprint* Blueprint = Component->GetTypedOuter<UBlueprint>())
		{
			return Blueprint;
		}

		const AActor* Owner = Component->GetOwner();
		return Owner ? Cast<UBlueprint>(Owner->GetClass()->ClassGeneratedBy) : nullptr;
	}

	void ShowNotification(const FText& Message, SNotificationItem::ECompletionState State)
	{
		FNotificationInfo Info(Message);
		Info.ExpireDuration = 4.0f;
		Info.bFireAndForget = true;

		if (const TSharedPtr<SNotificationItem> Notification = FSlateNotificationManager::Get().AddNotification(Info))
		{
			Notification->SetCompletionState(State);
		}
	}

	UActorComponent* GetComponentFromHandle(const FSubobjectDataHandle& Handle, UBlueprint* Blueprint)
	{
		const FSubobjectData* Data = Handle.GetData();
		if (!Data)
		{
			return nullptr;
		}

		return Blueprint
			? const_cast<UActorComponent*>(Data->GetComponentTemplate())
			: const_cast<UActorComponent*>(Data->GetComponentTemplate());
	}

	void AddLocalizedProperty(
		IDetailCategoryBuilder& Category,
		IDetailLayoutBuilder& DetailBuilder,
		FName PropertyName,
		UClass* OwnerClass,
		const TCHAR* ChineseName,
		const TCHAR* EnglishName)
	{
		const TSharedRef<IPropertyHandle> Handle = DetailBuilder.GetProperty(PropertyName, OwnerClass);
		if (Handle->IsValidHandle())
		{
			Category.AddProperty(Handle).DisplayName(L(ChineseName, EnglishName));
		}
	}

	void SetChildDisplayName(
		const TSharedRef<IPropertyHandle>& ParentHandle,
		FName ChildName,
		const TCHAR* ChineseName,
		const TCHAR* EnglishName)
	{
		if (const TSharedPtr<IPropertyHandle> ChildHandle = ParentHandle->GetChildHandle(ChildName))
		{
			ChildHandle->SetPropertyDisplayName(L(ChineseName, EnglishName));
		}
	}

	void LocalizeStyleChildren(const TSharedRef<IPropertyHandle>& StyleHandle)
	{
		SetChildDisplayName(StyleHandle, GET_MEMBER_NAME_CHECKED(FPlutoCollisionGizmoStyle, bDrawOutline), TEXT("绘制线框"), TEXT("Draw Outline"));
		SetChildDisplayName(StyleHandle, GET_MEMBER_NAME_CHECKED(FPlutoCollisionGizmoStyle, OutlineColor), TEXT("线框颜色"), TEXT("Outline Color"));
		SetChildDisplayName(StyleHandle, GET_MEMBER_NAME_CHECKED(FPlutoCollisionGizmoStyle, LineThickness), TEXT("线框粗细"), TEXT("Line Thickness"));
		SetChildDisplayName(StyleHandle, GET_MEMBER_NAME_CHECKED(FPlutoCollisionGizmoStyle, bDrawFill), TEXT("绘制填充"), TEXT("Draw Fill"));
		SetChildDisplayName(StyleHandle, GET_MEMBER_NAME_CHECKED(FPlutoCollisionGizmoStyle, FillColor), TEXT("填充颜色"), TEXT("Fill Color"));
		SetChildDisplayName(StyleHandle, GET_MEMBER_NAME_CHECKED(FPlutoCollisionGizmoStyle, FillOpacity), TEXT("填充透明度"), TEXT("Fill Opacity"));
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
		.MinDesiredWidth(260.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0.0f, 0.0f, 6.0f, 0.0f)
			[
				SNew(SButton)
				.Text(FText::FromString(TEXT("中文")))
				.IsEnabled_Lambda([]()
				{
					return PlutoGizmoHelperEditor::GetCurrentLanguage() != EPlutoGizmoHelperLanguage::Chinese;
				})
				.OnClicked_Lambda([]()
				{
					PlutoGizmoHelperEditor::SetCurrentLanguage(EPlutoGizmoHelperLanguage::Chinese);
					return FReply::Handled();
				})
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SButton)
				.Text(FText::FromString(TEXT("English")))
				.IsEnabled_Lambda([]()
				{
					return PlutoGizmoHelperEditor::GetCurrentLanguage() != EPlutoGizmoHelperLanguage::English;
				})
				.OnClicked_Lambda([]()
				{
					PlutoGizmoHelperEditor::SetCurrentLanguage(EPlutoGizmoHelperLanguage::English);
					return FReply::Handled();
				})
			]
		];
	}

	void AddLocalizedVisibilityRow(
		IDetailCategoryBuilder& Category,
		const TSharedRef<IPropertyHandle>& VisibilityHandle)
	{
		Category.AddCustomRow(L(TEXT("显示方式"), TEXT("Visibility Mode")))
		.NameContent()
		[
			SNew(STextBlock)
			.Text(L(TEXT("显示方式"), TEXT("Visibility Mode")))
			.Font(IDetailLayoutBuilder::GetDetailFont())
		]
		.ValueContent()
		.MinDesiredWidth(320.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			.Padding(0.0f, 0.0f, 4.0f, 0.0f)
			[
				SNew(SButton)
				.HAlign(HAlign_Center)
				.Text(L(TEXT("始终显示"), TEXT("Always")))
				.IsEnabled_Lambda([VisibilityHandle]()
				{
					uint8 Value = 0;
					return VisibilityHandle->GetValue(Value) == FPropertyAccess::Success
						&& Value != static_cast<uint8>(EPlutoCollisionGizmoVisibility::Always);
				})
				.OnClicked_Lambda([VisibilityHandle]()
				{
					VisibilityHandle->SetValue(static_cast<uint8>(EPlutoCollisionGizmoVisibility::Always));
					return FReply::Handled();
				})
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNew(SButton)
				.HAlign(HAlign_Center)
				.Text(L(TEXT("仅编辑器选中时"), TEXT("Selected In Editor Only")))
				.IsEnabled_Lambda([VisibilityHandle]()
				{
					uint8 Value = 0;
					return VisibilityHandle->GetValue(Value) == FPropertyAccess::Success
						&& Value != static_cast<uint8>(EPlutoCollisionGizmoVisibility::SelectedInEditorOnly);
				})
				.OnClicked_Lambda([VisibilityHandle]()
				{
					VisibilityHandle->SetValue(static_cast<uint8>(EPlutoCollisionGizmoVisibility::SelectedInEditorOnly));
					return FReply::Handled();
				})
			]
		];
	}
}

TSharedRef<IDetailCustomization> FPlutoShapeComponentDetails::MakeInstance()
{
	return MakeShared<FPlutoShapeComponentDetails>();
}

void FPlutoShapeComponentDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	DetailBuilderPtr = &DetailBuilder;

	TArray<TWeakObjectPtr<UObject>> Objects;
	DetailBuilder.GetObjectsBeingCustomized(Objects);
	if (Objects.Num() != 1)
	{
		return;
	}

	UShapeComponent* Shape = Cast<UShapeComponent>(Objects[0].Get());
	if (!Cast<UBoxComponent>(Shape) && !Cast<USphereComponent>(Shape) && !Cast<UCapsuleComponent>(Shape))
	{
		return;
	}

	TargetComponent = Shape;
	const bool bHasGizmo = FindExistingGizmo() != nullptr;

	IDetailCategoryBuilder& Category = DetailBuilder.EditCategory(
		TEXT("PlutoGizmo"),
		L(TEXT("Pluto 可视化"), TEXT("Pluto Gizmo")),
		ECategoryPriority::Important);

	AddLanguageSelector(Category);

	if (Shape->IsTemplate())
	{
		Category.AddCustomRow(L(TEXT("Blueprint 支持"), TEXT("Blueprint Support")))
		.WholeRowContent()
		[
			SNew(STextBlock)
			.Text(L(
				TEXT("v0.1 暂不支持在 Blueprint 编辑器内创建绑定，请在关卡实例中使用。"),
				TEXT("v0.1 does not create bindings in the Blueprint Editor. Use a placed level instance instead.")))
			.ColorAndOpacity(FLinearColor(0.9f, 0.65f, 0.15f))
			.AutoWrapText(true)
		];
		return;
	}

	Category.AddCustomRow(L(TEXT("碰撞可视化"), TEXT("Collision Gizmo")))
	.WholeRowContent()
	[
		SNew(SButton)
		.Text(bHasGizmo
			? L(TEXT("定位已有碰撞 Gizmo"), TEXT("Locate Existing Collision Gizmo"))
			: L(TEXT("创建并绑定碰撞 Gizmo"), TEXT("Create and Bind Collision Gizmo")))
		.ToolTipText(bHasGizmo
			? L(TEXT("选择已经绑定到该碰撞组件的 Gizmo。"), TEXT("Select the gizmo already bound to this collision component."))
			: L(TEXT("创建独立的伴生组件，并绑定到当前 Box、Sphere 或 Capsule。"), TEXT("Create an independent companion component bound to this Box, Sphere, or Capsule.")))
		.OnClicked(this, &FPlutoShapeComponentDetails::HandleCreateOrLocate)
	];
}

bool FPlutoShapeComponentDetails::ResolveSubobjectContext(
	UObject*& OutContext,
	UBlueprint*& OutBlueprint,
	FSubobjectDataHandle& OutTargetHandle,
	FName& OutTargetVariableName) const
{
	UShapeComponent* Target = TargetComponent.Get();
	USubobjectDataSubsystem* Subsystem = USubobjectDataSubsystem::Get();
	if (!Target || !Subsystem)
	{
		return false;
	}

	OutBlueprint = FindBlueprintContext(Target);
	OutContext = OutBlueprint ? static_cast<UObject*>(OutBlueprint) : static_cast<UObject*>(Target->GetOwner());
	if (!OutContext)
	{
		return false;
	}

	TArray<FSubobjectDataHandle> Handles;
	Subsystem->GatherSubobjectData(OutContext, Handles);

	FSubobjectDataHandle RootHandle;
	for (const FSubobjectDataHandle& Handle : Handles)
	{
		const FSubobjectData* Data = Handle.GetData();
		if (Data && (Data->IsActor() || Data->IsRootActor()))
		{
			RootHandle = Handle;
			break;
		}
	}

	if (!RootHandle.IsValid() && Handles.Num() > 0)
	{
		RootHandle = Handles[0].GetData()
			? Handles[0].GetData()->GetRootSubobject()
			: FSubobjectDataHandle::InvalidHandle;
	}

	if (RootHandle.IsValid())
	{
		OutTargetHandle = Subsystem->FindHandleForObject(RootHandle, Target, OutBlueprint);
	}

	if (!OutTargetHandle.IsValid())
	{
		for (const FSubobjectDataHandle& Handle : Handles)
		{
			const FSubobjectData* Data = Handle.GetData();
			if (!Data)
			{
				continue;
			}

			const UObject* CandidateObject = Data->GetObject();
			const UActorComponent* CandidateComponent = Data->GetComponentTemplate();
			if (CandidateObject == Target
				|| CandidateComponent == Target
				|| (Target->IsTemplate() && CandidateComponent && CandidateComponent->GetArchetype() == Target))
			{
				OutTargetHandle = Handle;
				break;
			}
		}
	}

	if (!OutTargetHandle.IsValid())
	{
		return false;
	}

	if (const FSubobjectData* TargetData = OutTargetHandle.GetData())
	{
		OutTargetVariableName = TargetData->GetVariableName();
	}
	if (OutTargetVariableName.IsNone())
	{
		OutTargetVariableName = Target->GetFName();
	}

	return true;
}

UPlutoCollisionGizmoComponent* FPlutoShapeComponentDetails::FindExistingGizmo(FName* OutTargetVariableName) const
{
	UShapeComponent* Target = TargetComponent.Get();
	if (!Target)
	{
		return nullptr;
	}

	if (!Target->IsTemplate())
	{
		AActor* Owner = Target->GetOwner();
		if (!Owner)
		{
			return nullptr;
		}

		const FName TargetName = Target->GetFName();
		if (OutTargetVariableName)
		{
			*OutTargetVariableName = TargetName;
		}

		TInlineComponentArray<UPlutoCollisionGizmoComponent*> Gizmos(Owner);
		for (UPlutoCollisionGizmoComponent* Gizmo : Gizmos)
		{
			if (Gizmo && (Gizmo->GetTargetCollision() == Target || Gizmo->GetTargetComponentName() == TargetName))
			{
				return Gizmo;
			}
		}

		return nullptr;
	}

	UObject* Context = nullptr;
	UBlueprint* Blueprint = nullptr;
	FSubobjectDataHandle TargetHandle;
	FName TargetVariableName;
	if (!ResolveSubobjectContext(Context, Blueprint, TargetHandle, TargetVariableName))
	{
		return nullptr;
	}

	if (OutTargetVariableName)
	{
		*OutTargetVariableName = TargetVariableName;
	}

	TArray<FSubobjectDataHandle> Handles;
	USubobjectDataSubsystem::Get()->GatherSubobjectData(Context, Handles);
	for (const FSubobjectDataHandle& Handle : Handles)
	{
		if (UPlutoCollisionGizmoComponent* Gizmo = Cast<UPlutoCollisionGizmoComponent>(GetComponentFromHandle(Handle, Blueprint)))
		{
			if (Gizmo->GetTargetComponentName() == TargetVariableName)
			{
				return Gizmo;
			}
		}
	}

	return nullptr;
}

FReply FPlutoShapeComponentDetails::HandleCreateOrLocate()
{
	if (UPlutoCollisionGizmoComponent* Existing = FindExistingGizmo())
	{
		if (GEditor)
		{
			GEditor->SelectNone(false, true);
			GEditor->SelectComponent(Existing, true, true, true);
		}
		return FReply::Handled();
	}

	UShapeComponent* Target = TargetComponent.Get();
	if (!Target)
	{
		ShowNotification(
			L(TEXT("碰撞组件已经失效，未创建 Gizmo。"), TEXT("The collision component is no longer valid. No gizmo was created.")),
			SNotificationItem::CS_Fail);
		return FReply::Handled();
	}

	if (!Target->IsTemplate())
	{
		AActor* Owner = Target->GetOwner();
		if (!Owner)
		{
			ShowNotification(
				L(TEXT("碰撞组件没有所属 Actor，未创建 Gizmo。"), TEXT("The collision component has no owning Actor. No gizmo was created.")),
				SNotificationItem::CS_Fail);
			return FReply::Handled();
		}

		const FScopedTransaction Transaction(L(TEXT("创建 Pluto 碰撞 Gizmo"), TEXT("Create Pluto Collision Gizmo")));
		Owner->Modify();
		Target->Modify();

		const FName ComponentName = MakeUniqueObjectName(
			Owner,
			UPlutoCollisionGizmoComponent::StaticClass(),
			*FString::Printf(TEXT("%s_PlutoGizmo"), *Target->GetName()));

		UPlutoCollisionGizmoComponent* Gizmo = NewObject<UPlutoCollisionGizmoComponent>(
			Owner,
			UPlutoCollisionGizmoComponent::StaticClass(),
			ComponentName,
			RF_Transactional);

		if (!Gizmo)
		{
			ShowNotification(
				L(TEXT("无法创建碰撞 Gizmo 组件。"), TEXT("Could not create the collision gizmo component.")),
				SNotificationItem::CS_Fail);
			return FReply::Handled();
		}

		Owner->AddInstanceComponent(Gizmo);
		Gizmo->OnComponentCreated();
		Gizmo->SetupAttachment(Target);
		Gizmo->SetTargetCollisionReference(Target, Target->GetFName());
		Gizmo->RegisterComponent();

		if (DetailBuilderPtr)
		{
			DetailBuilderPtr->ForceRefreshDetails();
		}

		if (GEditor)
		{
			GEditor->SelectNone(false, true);
			GEditor->SelectComponent(Gizmo, true, true, true);
		}

		ShowNotification(
			L(TEXT("已创建并绑定碰撞 Gizmo。"), TEXT("Collision gizmo created and bound.")),
			SNotificationItem::CS_Success);
		return FReply::Handled();
	}

	UObject* Context = nullptr;
	UBlueprint* Blueprint = nullptr;
	FSubobjectDataHandle TargetHandle;
	FName TargetVariableName;
	if (!ResolveSubobjectContext(Context, Blueprint, TargetHandle, TargetVariableName))
	{
		ShowNotification(
			L(
				TEXT("无法解析碰撞组件的编辑上下文，未创建 Gizmo。"),
				TEXT("Could not resolve the collision component editing context. No gizmo was created.")),
			SNotificationItem::CS_Fail);
		return FReply::Handled();
	}

	USubobjectDataSubsystem* Subsystem = USubobjectDataSubsystem::Get();
	const FScopedTransaction Transaction(L(TEXT("创建 Pluto 碰撞 Gizmo"), TEXT("Create Pluto Collision Gizmo")));

	FAddNewSubobjectParams Params;
	Params.ParentHandle = TargetHandle;
	Params.NewClass = UPlutoCollisionGizmoComponent::StaticClass();
	Params.BlueprintContext = Blueprint;
	Params.bConformTransformToParent = true;

	FText FailureReason;
	const FSubobjectDataHandle NewHandle = Subsystem->AddNewSubobject(Params, FailureReason);
	if (NewHandle.IsValid())
	{
		if (FSubobjectData* NewData = NewHandle.GetData())
		{
			if (UPlutoCollisionGizmoComponent* Gizmo = Cast<UPlutoCollisionGizmoComponent>(
				const_cast<UActorComponent*>(NewData->GetComponentTemplate())))
			{
				Gizmo->Modify();
				Gizmo->SetTargetCollisionReference(TargetComponent.Get(), TargetVariableName);
			}
		}

		if (Blueprint)
		{
			Blueprint->Modify();
			FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);
		}

		if (DetailBuilderPtr)
		{
			DetailBuilderPtr->ForceRefreshDetails();
		}

		ShowNotification(
			L(TEXT("已创建并绑定碰撞 Gizmo。"), TEXT("Collision gizmo created and bound.")),
			SNotificationItem::CS_Success);
	}
	else
	{
		const FText Message = FailureReason.IsEmpty()
			? L(TEXT("创建碰撞 Gizmo 失败。"), TEXT("Failed to create collision gizmo."))
			: FText::Format(
				L(TEXT("创建碰撞 Gizmo 失败：{0}"), TEXT("Failed to create collision gizmo: {0}")),
				FailureReason);
		ShowNotification(Message, SNotificationItem::CS_Fail);
	}

	return FReply::Handled();
}

TSharedRef<IDetailCustomization> FPlutoCollisionGizmoComponentDetails::MakeInstance()
{
	return MakeShared<FPlutoCollisionGizmoComponentDetails>();
}

void FPlutoCollisionGizmoComponentDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	DetailBuilder.HideCategory(TEXT("Pluto Gizmo"));
	DetailBuilder.HideCategory(TEXT("Pluto Gizmo|Target"));
	DetailBuilder.HideCategory(TEXT("Pluto Gizmo|Style"));

	TArray<TWeakObjectPtr<UObject>> Objects;
	DetailBuilder.GetObjectsBeingCustomized(Objects);

	IDetailCategoryBuilder& Category = DetailBuilder.EditCategory(
		TEXT("PlutoGizmo"),
		L(TEXT("Pluto 碰撞 Gizmo"), TEXT("Pluto Collision Gizmo")),
		ECategoryPriority::Important);

	AddLanguageSelector(Category);

	const TSharedRef<IPropertyHandle> TargetHandle = DetailBuilder.GetProperty(
		GET_MEMBER_NAME_CHECKED(UPlutoCollisionGizmoComponent, TargetCollision),
		UPlutoCollisionGizmoComponent::StaticClass());
	Category.AddProperty(TargetHandle).DisplayName(L(TEXT("目标碰撞组件"), TEXT("Target Collision")));
	SetChildDisplayName(TargetHandle, GET_MEMBER_NAME_CHECKED(FBaseComponentReference, ComponentProperty), TEXT("组件名称"), TEXT("Component Name"));
	SetChildDisplayName(TargetHandle, GET_MEMBER_NAME_CHECKED(FComponentReference, OtherActor), TEXT("参考 Actor"), TEXT("Referenced Actor"));

	AddLocalizedProperty(Category, DetailBuilder, GET_MEMBER_NAME_CHECKED(UPlutoCollisionGizmoComponent, bGizmoEnabled), UPlutoCollisionGizmoComponent::StaticClass(), TEXT("启用 Gizmo"), TEXT("Gizmo Enabled"));
	AddLocalizedProperty(Category, DetailBuilder, GET_MEMBER_NAME_CHECKED(UPlutoCollisionGizmoComponent, bOverrideProjectStyle), UPlutoCollisionGizmoComponent::StaticClass(), TEXT("覆盖项目默认样式"), TEXT("Override Project Style"));
	AddLocalizedProperty(Category, DetailBuilder, GET_MEMBER_NAME_CHECKED(UPlutoCollisionGizmoComponent, OverrideStyle), UPlutoCollisionGizmoComponent::StaticClass(), TEXT("实例样式"), TEXT("Instance Style"));

	const FSimpleDelegate RefreshDelegate = FSimpleDelegate::CreateLambda([Objects]()
	{
		for (const TWeakObjectPtr<UObject>& Object : Objects)
		{
			if (UPlutoCollisionGizmoComponent* Gizmo = Cast<UPlutoCollisionGizmoComponent>(Object.Get()))
			{
				Gizmo->RefreshGizmo();
			}
		}
	});

	const TSharedRef<IPropertyHandle> EnabledHandle = DetailBuilder.GetProperty(
		GET_MEMBER_NAME_CHECKED(UPlutoCollisionGizmoComponent, bGizmoEnabled),
		UPlutoCollisionGizmoComponent::StaticClass());
	const TSharedRef<IPropertyHandle> VisibilityHandle = DetailBuilder.GetProperty(
		GET_MEMBER_NAME_CHECKED(UPlutoCollisionGizmoComponent, VisibilityMode),
		UPlutoCollisionGizmoComponent::StaticClass());
	const TSharedRef<IPropertyHandle> OverrideHandle = DetailBuilder.GetProperty(
		GET_MEMBER_NAME_CHECKED(UPlutoCollisionGizmoComponent, bOverrideProjectStyle),
		UPlutoCollisionGizmoComponent::StaticClass());
	const TSharedRef<IPropertyHandle> StyleHandle = DetailBuilder.GetProperty(
		GET_MEMBER_NAME_CHECKED(UPlutoCollisionGizmoComponent, OverrideStyle),
		UPlutoCollisionGizmoComponent::StaticClass());

	AddLocalizedVisibilityRow(Category, VisibilityHandle);
	LocalizeStyleChildren(StyleHandle);

	EnabledHandle->SetOnPropertyValueChanged(RefreshDelegate);
	VisibilityHandle->SetOnPropertyValueChanged(RefreshDelegate);
	OverrideHandle->SetOnPropertyValueChanged(RefreshDelegate);
	StyleHandle->SetOnPropertyValueChanged(RefreshDelegate);
	StyleHandle->SetOnChildPropertyValueChanged(RefreshDelegate);

	bool bInvalidTarget = false;
	for (const TWeakObjectPtr<UObject>& Object : Objects)
	{
		const UPlutoCollisionGizmoComponent* Gizmo = Cast<UPlutoCollisionGizmoComponent>(Object.Get());
		bInvalidTarget |= Gizmo && !Gizmo->IsTargetValid();
	}

	if (bInvalidTarget)
	{
		Category.AddCustomRow(L(TEXT("无效目标"), TEXT("Invalid Target")))
		.WholeRowContent()
		[
			SNew(STextBlock)
			.Text(L(
				TEXT("目标必须是同一 Actor 上的 Box、Sphere 或 Capsule Collision。"),
				TEXT("The target must be a Box, Sphere, or Capsule Collision on the same Actor.")))
			.ColorAndOpacity(FLinearColor(1.0f, 0.35f, 0.1f))
			.AutoWrapText(true)
		];
	}
}

TSharedRef<IDetailCustomization> FPlutoGizmoHelperSettingsDetails::MakeInstance()
{
	return MakeShared<FPlutoGizmoHelperSettingsDetails>();
}

void FPlutoGizmoHelperSettingsDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	DetailBuilder.HideCategory(TEXT("Collision Gizmo"));
	IDetailCategoryBuilder& Category = DetailBuilder.EditCategory(
		TEXT("CollisionGizmo"),
		L(TEXT("碰撞 Gizmo"), TEXT("Collision Gizmo")));
	AddLanguageSelector(Category);
	AddLocalizedProperty(Category, DetailBuilder, GET_MEMBER_NAME_CHECKED(UPlutoGizmoHelperSettings, DefaultCollisionStyle), UPlutoGizmoHelperSettings::StaticClass(), TEXT("默认碰撞样式"), TEXT("Default Collision Style"));

	const TSharedRef<IPropertyHandle> StyleHandle = DetailBuilder.GetProperty(
		GET_MEMBER_NAME_CHECKED(UPlutoGizmoHelperSettings, DefaultCollisionStyle),
		UPlutoGizmoHelperSettings::StaticClass());
	LocalizeStyleChildren(StyleHandle);
	const FSimpleDelegate RefreshDelegate = FSimpleDelegate::CreateLambda([]()
	{
		for (TObjectIterator<UPlutoCollisionGizmoComponent> It; It; ++It)
		{
			if (!It->IsTemplate() && IsValid(*It))
			{
				It->RefreshGizmo();
			}
		}
	});
	StyleHandle->SetOnPropertyValueChanged(RefreshDelegate);
	StyleHandle->SetOnChildPropertyValueChanged(RefreshDelegate);
}

TSharedRef<IDetailCustomization> FPlutoGizmoHelperEditorSettingsDetails::MakeInstance()
{
	return MakeShared<FPlutoGizmoHelperEditorSettingsDetails>();
}

void FPlutoGizmoHelperEditorSettingsDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	DetailBuilder.HideCategory(TEXT("General"));
	DetailBuilder.HideProperty(DetailBuilder.GetProperty(
		GET_MEMBER_NAME_CHECKED(UPlutoGizmoHelperEditorSettings, Language),
		UPlutoGizmoHelperEditorSettings::StaticClass()));
	IDetailCategoryBuilder& Category = DetailBuilder.EditCategory(
		TEXT("GeneralLocalized"),
		L(TEXT("常规"), TEXT("General")));
	AddLanguageSelector(Category);
}
