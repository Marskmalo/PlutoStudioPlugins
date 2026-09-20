#include "PlutoAssetNamingHelperEditorModule.h"

#include "Framework/Docking/TabManager.h"
#include "SPlutoAssetNamingHelperPanel.h"
#include "SPlutoAssetNamingHelperDocumentationPanel.h"
#include "Styling/AppStyle.h"
#include "ToolMenus.h"
#include "Widgets/Docking/SDockTab.h"

#define LOCTEXT_NAMESPACE "PlutoAssetNamingHelperEditor"

const FName FPlutoAssetNamingHelperEditorModule::TabName(TEXT("PlutoAssetNamingHelper"));
const FName FPlutoAssetNamingHelperEditorModule::DocumentationTabName(TEXT("PlutoAssetNamingHelperDocumentation"));

void FPlutoAssetNamingHelperEditorModule::StartupModule()
{
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
		TabName,
		FOnSpawnTab::CreateRaw(this, &FPlutoAssetNamingHelperEditorModule::SpawnAssetNamingHelperTab))
		.SetDisplayName(LOCTEXT("TabTitle", "Pluto 资产命名助手"))
		.SetTooltipText(LOCTEXT("TabTooltip", "扫描资产名称，解释问题并生成安全的重命名建议。"))
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Search"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
		DocumentationTabName,
		FOnSpawnTab::CreateRaw(this, &FPlutoAssetNamingHelperEditorModule::SpawnDocumentationTab))
		.SetDisplayName(LOCTEXT("DocumentationTabTitle", "Pluto 资产命名助手使用文档"))
		.SetTooltipText(LOCTEXT("DocumentationTabTooltip", "查看插件目录中的 Markdown 使用文档。"))
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Documentation"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	UToolMenus::RegisterStartupCallback(
		FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FPlutoAssetNamingHelperEditorModule::RegisterMenus));
}

void FPlutoAssetNamingHelperEditorModule::ShutdownModule()
{
	if (UToolMenus::TryGet() != nullptr)
	{
		UToolMenus::UnRegisterStartupCallback(this);
		UToolMenus::UnregisterOwner(this);
	}

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TabName);
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(DocumentationTabName);
}

void FPlutoAssetNamingHelperEditorModule::OpenAssetNamingHelper()
{
	FGlobalTabmanager::Get()->TryInvokeTab(TabName);
}

void FPlutoAssetNamingHelperEditorModule::OpenDocumentation()
{
	FGlobalTabmanager::Get()->TryInvokeTab(DocumentationTabName);
}

void FPlutoAssetNamingHelperEditorModule::RegisterMenus()
{
	FToolMenuOwnerScoped OwnerScoped(this);

	UToolMenu* MainMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu");
	FToolMenuSection& PlutoMainSection = MainMenu->FindOrAddSection(NAME_None);

	UToolMenu* PlutoMenu = nullptr;
	if (PlutoMainSection.FindEntry("PlutoMenu") == nullptr)
	{
		FToolMenuEntry& PlutoEntry = PlutoMainSection.AddSubMenu(
			"PlutoMenu",
			LOCTEXT("PlutoMenuLabel", "Pluto"),
			LOCTEXT("PlutoMenuTooltip", "打开 Pluto Studio 编辑器工具。"),
			FNewToolMenuChoice(),
			false,
			FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Tools"));
		PlutoEntry.Owner = FToolMenuOwner(TEXT("PlutoSharedMenu"));
		PlutoEntry.InsertPosition = FToolMenuInsert("Help", EToolMenuInsertType::After);
		PlutoMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.PlutoMenu");
	}
	else
	{
		PlutoMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.PlutoMenu");
	}

	PopulatePlutoMenu(PlutoMenu);

	UToolMenu* WindowMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
	FToolMenuSection& WindowSection = WindowMenu->FindOrAddSection("WindowLayout");
	WindowSection.AddMenuEntry(
		"OpenPlutoAssetNamingHelper",
		LOCTEXT("WindowEntryLabel", "Pluto 资产命名助手"),
		LOCTEXT("WindowEntryTooltip", "打开 Pluto 资产命名审计与重命名规划面板。"),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Search"),
		FUIAction(FExecuteAction::CreateRaw(this, &FPlutoAssetNamingHelperEditorModule::OpenAssetNamingHelper)));
}

void FPlutoAssetNamingHelperEditorModule::PopulatePlutoMenu(UToolMenu* Menu)
{
	FToolMenuSection& ToolsSection = Menu->FindOrAddSection("PlutoToolsSection");
	ToolsSection.AddMenuEntry(
		"OpenPlutoAssetNamingHelper",
		LOCTEXT("PlutoEntryLabel", "资产命名助手"),
		LOCTEXT("PlutoEntryTooltip", "扫描指定文件夹中的资产命名，并生成易读的问题说明与建议名称。"),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Search"),
		FUIAction(FExecuteAction::CreateRaw(this, &FPlutoAssetNamingHelperEditorModule::OpenAssetNamingHelper)));
}

TSharedRef<SDockTab> FPlutoAssetNamingHelperEditorModule::SpawnAssetNamingHelperTab(const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SPlutoAssetNamingHelperPanel)
		];
}

TSharedRef<SDockTab> FPlutoAssetNamingHelperEditorModule::SpawnDocumentationTab(const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SPlutoAssetNamingHelperDocumentationPanel)
		];
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPlutoAssetNamingHelperEditorModule, PlutoAssetNamingHelperEditor)
