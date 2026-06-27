#include "PlutoGizmoHelperEditorModule.h"

#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Modules/ModuleManager.h"
#include "PlutoCollisionGizmoComponent.h"
#include "PlutoCollisionGizmoDetails.h"
#include "PlutoGizmoHelperEditorSettings.h"
#include "PlutoGizmoHelperSettings.h"
#include "PropertyEditorModule.h"

IMPLEMENT_MODULE(FPlutoGizmoHelperEditorModule, PlutoGizmoHelperEditor)

void FPlutoGizmoHelperEditorModule::StartupModule()
{
	RegisterDetailsCustomizations();
}

void FPlutoGizmoHelperEditorModule::ShutdownModule()
{
	UnregisterDetailsCustomizations();
}

void FPlutoGizmoHelperEditorModule::RegisterDetailsCustomizations()
{
	FPropertyEditorModule& PropertyEditor = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));

	PropertyEditor.RegisterCustomClassLayout(
		UBoxComponent::StaticClass()->GetFName(),
		FOnGetDetailCustomizationInstance::CreateStatic(&FPlutoShapeComponentDetails::MakeInstance));
	PropertyEditor.RegisterCustomClassLayout(
		USphereComponent::StaticClass()->GetFName(),
		FOnGetDetailCustomizationInstance::CreateStatic(&FPlutoShapeComponentDetails::MakeInstance));
	PropertyEditor.RegisterCustomClassLayout(
		UCapsuleComponent::StaticClass()->GetFName(),
		FOnGetDetailCustomizationInstance::CreateStatic(&FPlutoShapeComponentDetails::MakeInstance));
	PropertyEditor.RegisterCustomClassLayout(
		UPlutoCollisionGizmoComponent::StaticClass()->GetFName(),
		FOnGetDetailCustomizationInstance::CreateStatic(&FPlutoCollisionGizmoComponentDetails::MakeInstance));
	PropertyEditor.RegisterCustomClassLayout(
		UPlutoGizmoHelperSettings::StaticClass()->GetFName(),
		FOnGetDetailCustomizationInstance::CreateStatic(&FPlutoGizmoHelperSettingsDetails::MakeInstance));
	PropertyEditor.RegisterCustomClassLayout(
		UPlutoGizmoHelperEditorSettings::StaticClass()->GetFName(),
		FOnGetDetailCustomizationInstance::CreateStatic(&FPlutoGizmoHelperEditorSettingsDetails::MakeInstance));

	PropertyEditor.NotifyCustomizationModuleChanged();
}

void FPlutoGizmoHelperEditorModule::UnregisterDetailsCustomizations()
{
	if (!FModuleManager::Get().IsModuleLoaded(TEXT("PropertyEditor")))
	{
		return;
	}

	FPropertyEditorModule& PropertyEditor = FModuleManager::GetModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyEditor.UnregisterCustomClassLayout(UBoxComponent::StaticClass()->GetFName());
	PropertyEditor.UnregisterCustomClassLayout(USphereComponent::StaticClass()->GetFName());
	PropertyEditor.UnregisterCustomClassLayout(UCapsuleComponent::StaticClass()->GetFName());
	PropertyEditor.UnregisterCustomClassLayout(UPlutoCollisionGizmoComponent::StaticClass()->GetFName());
	PropertyEditor.UnregisterCustomClassLayout(UPlutoGizmoHelperSettings::StaticClass()->GetFName());
	PropertyEditor.UnregisterCustomClassLayout(UPlutoGizmoHelperEditorSettings::StaticClass()->GetFName());
}
