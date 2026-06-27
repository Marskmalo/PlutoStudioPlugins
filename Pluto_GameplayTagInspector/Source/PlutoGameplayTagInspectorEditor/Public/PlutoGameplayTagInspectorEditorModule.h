#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Textures/SlateIcon.h"

struct FToolMenuSection;
class SDockTab;
class FSlateStyleSet;
class UToolMenu;

class PLUTOGAMEPLAYTAGINSPECTOREDITOR_API FPlutoGameplayTagInspectorEditorModule : public IModuleInterface
{
public:
	static const FName TabName;
	static const FName DocumentationTabName;

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void OpenInspectorTab();
	void OpenDocumentationTab();

private:
	void RegisterStyle();
	void UnregisterStyle();
	FSlateIcon GetPluginMenuIcon() const;
	const FSlateBrush* GetPluginTabBrush() const;
	FSlateIcon GetDocumentationIcon() const;
	const FSlateBrush* GetDocumentationTabBrush() const;
	void RegisterMenus();
	void PopulatePlutoMenu(UToolMenu* Menu);
	void PopulateLanguageMenu(UToolMenu* Menu);
	void AddOpenInspectorEntry(FToolMenuSection& Section);
	void AddOpenDocumentationEntry(FToolMenuSection& Section);
	TSharedRef<SDockTab> SpawnInspectorTab(const class FSpawnTabArgs& SpawnTabArgs);
	TSharedRef<SDockTab> SpawnDocumentationTab(const class FSpawnTabArgs& SpawnTabArgs);

private:
	TSharedPtr<FSlateStyleSet> StyleSet;
	bool bHasCustomMenuIcon = false;
	bool bHasCustomTabIcon = false;
};
