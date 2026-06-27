#include "PlutoGameplayTagInspectorEditorSettings.h"

EPlutoGameplayTagInspectorLanguage PlutoGameplayTagInspectorEditor::GetCurrentLanguage()
{
	return GetDefault<UPlutoGameplayTagInspectorEditorSettings>()->Language;
}

void PlutoGameplayTagInspectorEditor::SetCurrentLanguage(EPlutoGameplayTagInspectorLanguage InLanguage)
{
	UPlutoGameplayTagInspectorEditorSettings* Settings = GetMutableDefault<UPlutoGameplayTagInspectorEditorSettings>();
	Settings->Language = InLanguage;
	Settings->SaveConfig();
}

FText PlutoGameplayTagInspectorEditor::MakeLocalizedText(const FString& ChineseText, const FString& EnglishText)
{
	return GetCurrentLanguage() == EPlutoGameplayTagInspectorLanguage::Chinese
		? FText::FromString(ChineseText)
		: FText::FromString(EnglishText);
}

FText PlutoGameplayTagInspectorEditor::MakeLocalizedText(const TCHAR* ChineseText, const TCHAR* EnglishText)
{
	return MakeLocalizedText(FString(ChineseText), FString(EnglishText));
}
