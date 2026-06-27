#include "PlutoGizmoHelperEditorSettings.h"

#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"

EPlutoGizmoHelperLanguage PlutoGizmoHelperEditor::GetCurrentLanguage()
{
	return GetDefault<UPlutoGizmoHelperEditorSettings>()->Language;
}

void PlutoGizmoHelperEditor::SetCurrentLanguage(EPlutoGizmoHelperLanguage Language)
{
	UPlutoGizmoHelperEditorSettings* Settings = GetMutableDefault<UPlutoGizmoHelperEditorSettings>();
	if (Settings->Language != Language)
	{
		Settings->Language = Language;
		Settings->SaveConfig();
		NotifyLanguageChanged();
	}
}

FText PlutoGizmoHelperEditor::Localized(const TCHAR* ChineseText, const TCHAR* EnglishText)
{
	return FText::FromString(GetCurrentLanguage() == EPlutoGizmoHelperLanguage::Chinese ? ChineseText : EnglishText);
}

void PlutoGizmoHelperEditor::NotifyLanguageChanged()
{
	if (FModuleManager::Get().IsModuleLoaded(TEXT("PropertyEditor")))
	{
		FModuleManager::GetModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor")).NotifyCustomizationModuleChanged();
	}
}

FText UPlutoGizmoHelperEditorSettings::GetSectionText() const
{
	return PlutoGizmoHelperEditor::Localized(TEXT("Pluto Gizmo Helper 编辑器"), TEXT("Pluto Gizmo Helper Editor"));
}

FText UPlutoGizmoHelperEditorSettings::GetSectionDescription() const
{
	return PlutoGizmoHelperEditor::Localized(
		TEXT("配置 Pluto Gizmo Helper 的编辑器界面语言。"),
		TEXT("Configure the editor UI language for Pluto Gizmo Helper."));
}

#if WITH_EDITOR
void UPlutoGizmoHelperEditorSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	SaveConfig();
	PlutoGizmoHelperEditor::NotifyLanguageChanged();
}
#endif
