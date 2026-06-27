#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "PlutoSplineHelperEditorSettings.generated.h"

UENUM()
enum class EPlutoSplineHelperLanguage : uint8
{
	Chinese UMETA(DisplayName = "中文"),
	English UMETA(DisplayName = "English")
};

UCLASS(Config = EditorPerProjectUserSettings, DefaultConfig, meta = (DisplayName = "Pluto Spline Helper Editor"))
class PLUTOSPLINEHELPEREDITOR_API UPlutoSplineHelperEditorSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, Category = "General")
	EPlutoSplineHelperLanguage Language = EPlutoSplineHelperLanguage::Chinese;

	virtual FName GetContainerName() const override { return TEXT("Editor"); }
	virtual FName GetCategoryName() const override { return TEXT("Plugins"); }
	virtual FText GetSectionText() const override;
	virtual FText GetSectionDescription() const override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};

namespace PlutoSplineHelperEditor
{
	PLUTOSPLINEHELPEREDITOR_API EPlutoSplineHelperLanguage GetCurrentLanguage();
	PLUTOSPLINEHELPEREDITOR_API void SetCurrentLanguage(EPlutoSplineHelperLanguage Language);
	PLUTOSPLINEHELPEREDITOR_API FText Localized(const TCHAR* ChineseText, const TCHAR* EnglishText);
	PLUTOSPLINEHELPEREDITOR_API void NotifyLanguageChanged();
}
