#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PlutoGameplayTagInspectorEditorSettings.generated.h"

UENUM()
enum class EPlutoGameplayTagInspectorLanguage : uint8
{
	Chinese,
	English
};

UCLASS(Config = EditorPerProjectUserSettings)
class PLUTOGAMEPLAYTAGINSPECTOREDITOR_API UPlutoGameplayTagInspectorEditorSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, Category = "General", meta = (DisplayName = "Language", ToolTip = "Inspector UI language.\n检查器界面语言。"))
	EPlutoGameplayTagInspectorLanguage Language = EPlutoGameplayTagInspectorLanguage::Chinese;
};

namespace PlutoGameplayTagInspectorEditor
{
	PLUTOGAMEPLAYTAGINSPECTOREDITOR_API EPlutoGameplayTagInspectorLanguage GetCurrentLanguage();
	PLUTOGAMEPLAYTAGINSPECTOREDITOR_API void SetCurrentLanguage(EPlutoGameplayTagInspectorLanguage InLanguage);
	PLUTOGAMEPLAYTAGINSPECTOREDITOR_API FText MakeLocalizedText(const FString& ChineseText, const FString& EnglishText);
	PLUTOGAMEPLAYTAGINSPECTOREDITOR_API FText MakeLocalizedText(const TCHAR* ChineseText, const TCHAR* EnglishText);
}
