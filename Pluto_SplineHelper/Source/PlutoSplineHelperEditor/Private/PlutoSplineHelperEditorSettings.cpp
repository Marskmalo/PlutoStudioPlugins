#include "PlutoSplineHelperEditorSettings.h"

#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"

EPlutoSplineHelperLanguage PlutoSplineHelperEditor::GetCurrentLanguage()
{
	return GetDefault<UPlutoSplineHelperEditorSettings>()->Language;
}

void PlutoSplineHelperEditor::SetCurrentLanguage(EPlutoSplineHelperLanguage Language)
{
	UPlutoSplineHelperEditorSettings* Settings = GetMutableDefault<UPlutoSplineHelperEditorSettings>();
	if (Settings->Language != Language)
	{
		Settings->Language = Language;
		Settings->SaveConfig();
		NotifyLanguageChanged();
	}
}

FText PlutoSplineHelperEditor::Localized(const TCHAR* ChineseText, const TCHAR* EnglishText)
{
	return FText::FromString(GetCurrentLanguage() == EPlutoSplineHelperLanguage::Chinese ? ChineseText : EnglishText);
}

void PlutoSplineHelperEditor::NotifyLanguageChanged()
{
	if (FModuleManager::Get().IsModuleLoaded(TEXT("PropertyEditor")))
	{
		FModuleManager::GetModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor")).NotifyCustomizationModuleChanged();
	}
}

FText UPlutoSplineHelperEditorSettings::GetSectionText() const
{
	return PlutoSplineHelperEditor::Localized(TEXT("Pluto Spline Helper 编辑器"), TEXT("Pluto Spline Helper Editor"));
}

FText UPlutoSplineHelperEditorSettings::GetSectionDescription() const
{
	return PlutoSplineHelperEditor::Localized(
		TEXT("配置 Pluto Spline Helper 的编辑器界面语言。"),
		TEXT("Configure the editor UI language for Pluto Spline Helper."));
}

#if WITH_EDITOR
void UPlutoSplineHelperEditorSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	SaveConfig();
	PlutoSplineHelperEditor::NotifyLanguageChanged();
}
#endif
