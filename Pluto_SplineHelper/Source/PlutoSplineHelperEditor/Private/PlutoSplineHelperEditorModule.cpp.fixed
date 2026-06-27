#include "PlutoSplineHelperEditorModule.h"

#include "Framework/Notifications/NotificationManager.h"
#include "Modules/ModuleManager.h"
#include "PlutoSplineHelperEditorSettings.h"
#include "PlutoSplineWallActor.h"
#include "PlutoSplineWallDetails.h"
#include "PropertyEditorModule.h"
#include "Widgets/Notifications/SNotificationList.h"

IMPLEMENT_MODULE(FPlutoSplineHelperEditorModule, PlutoSplineHelperEditor)

void FPlutoSplineHelperEditorModule::StartupModule()
{
	FPropertyEditorModule& PropertyEditor = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyEditor.RegisterCustomClassLayout(
		APlutoSplineWall::StaticClass()->GetFName(),
		FOnGetDetailCustomizationInstance::CreateStatic(&FPlutoSplineWallDetails::MakeInstance));
	PropertyEditor.RegisterCustomClassLayout(
		UPlutoSplineHelperEditorSettings::StaticClass()->GetFName(),
		FOnGetDetailCustomizationInstance::CreateStatic(&FPlutoSplineHelperEditorSettingsDetails::MakeInstance));
	PropertyEditor.NotifyCustomizationModuleChanged();

	ValidationFailedHandle = APlutoSplineWall::OnValidationFailed().AddRaw(
		this,
		&FPlutoSplineHelperEditorModule::HandleValidationFailed);
}

void FPlutoSplineHelperEditorModule::ShutdownModule()
{
	APlutoSplineWall::OnValidationFailed().Remove(ValidationFailedHandle);

	if (FModuleManager::Get().IsModuleLoaded(TEXT("PropertyEditor")))
	{
		FPropertyEditorModule& PropertyEditor = FModuleManager::GetModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
		PropertyEditor.UnregisterCustomClassLayout(APlutoSplineWall::StaticClass()->GetFName());
		PropertyEditor.UnregisterCustomClassLayout(UPlutoSplineHelperEditorSettings::StaticClass()->GetFName());
	}
}

void FPlutoSplineHelperEditorModule::HandleValidationFailed(APlutoSplineWall* Wall)
{
	FNotificationInfo Info(PlutoSplineHelperEditor::Localized(
		TEXT("Spline 自相交或形状无效，已保留最后一次有效碰撞。"),
		TEXT("The spline is self-intersecting or invalid. The last valid collision shape was preserved.")));
	Info.ExpireDuration = 5.0f;
	Info.bFireAndForget = true;

	if (const TSharedPtr<SNotificationItem> Notification = FSlateNotificationManager::Get().AddNotification(Info))
	{
		Notification->SetCompletionState(SNotificationItem::CS_Fail);
	}
}
