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
	static constexpr int32 MaxInspectorTabCount = 3;

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
	FName GetInspectorTabName(int32 InstanceIndex) const;
	FText GetInspectorTabDisplayName(int32 InstanceIndex) const;
	TSharedRef<SDockTab> SpawnInspectorTab(const class FSpawnTabArgs& SpawnTabArgs, int32 InstanceIndex);
	void HandleInspectorTabClosed(TSharedRef<SDockTab> ClosedTab, int32 InstanceIndex);
	TSharedRef<SDockTab> SpawnDocumentationTab(const class FSpawnTabArgs& SpawnTabArgs);

private:
	TSharedPtr<FSlateStyleSet> StyleSet;
	TStaticArray<TWeakPtr<SDockTab>, MaxInspectorTabCount> InspectorTabs;
	bool bHasCustomMenuIcon = false;
	bool bHasCustomTabIcon = false;
};
