#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "PlutoGizmoHelperEditorSettings.generated.h"

UENUM()
enum class EPlutoGizmoHelperLanguage : uint8
{
	Chinese UMETA(DisplayName = "中文"),
	English UMETA(DisplayName = "English")
};

UCLASS(Config = EditorPerProjectUserSettings, DefaultConfig, meta = (DisplayName = "Pluto Gizmo Helper Editor"))
class PLUTOGIZMOHELPEREDITOR_API UPlutoGizmoHelperEditorSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, Category = "General")
	EPlutoGizmoHelperLanguage Language = EPlutoGizmoHelperLanguage::Chinese;

	virtual FName GetContainerName() const override
	{
		return TEXT("Editor");
	}

	virtual FName GetCategoryName() const override
	{
		return TEXT("Plugins");
	}

	virtual FText GetSectionText() const override;
	virtual FText GetSectionDescription() const override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};

namespace PlutoGizmoHelperEditor
{
	PLUTOGIZMOHELPEREDITOR_API EPlutoGizmoHelperLanguage GetCurrentLanguage();
	PLUTOGIZMOHELPEREDITOR_API void SetCurrentLanguage(EPlutoGizmoHelperLanguage Language);
	PLUTOGIZMOHELPEREDITOR_API FText Localized(const TCHAR* ChineseText, const TCHAR* EnglishText);
	PLUTOGIZMOHELPEREDITOR_API void NotifyLanguageChanged();
}
