#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class SDockTab;
class UToolMenu;

class PLUTOASSETNAMINGHELPEREDITOR_API FPlutoAssetNamingHelperEditorModule : public IModuleInterface
{
public:
	static const FName TabName;
	static const FName DocumentationTabName;

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void OpenAssetNamingHelper();
	void OpenDocumentation();

private:
	void RegisterMenus();
	void PopulatePlutoMenu(UToolMenu* Menu);
	TSharedRef<SDockTab> SpawnAssetNamingHelperTab(const class FSpawnTabArgs& SpawnTabArgs);
	TSharedRef<SDockTab> SpawnDocumentationTab(const class FSpawnTabArgs& SpawnTabArgs);
};
