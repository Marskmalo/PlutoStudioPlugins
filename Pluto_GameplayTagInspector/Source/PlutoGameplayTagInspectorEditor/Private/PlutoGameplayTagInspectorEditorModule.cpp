#include "PlutoGameplayTagInspectorEditorModule.h"

#include "Brushes/SlateImageBrush.h"
#include "Framework/Docking/TabManager.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "PlutoGameplayTagInspectorEditorSettings.h"
#include "SPlutoGameplayTagInspectorDocumentationPanel.h"
#include "SPlutoGameplayTagInspectorPanel.h"
#include "Styling/AppStyle.h"
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "ToolMenus.h"
#include "Widgets/Docking/SDockTab.h"

const FName FPlutoGameplayTagInspectorEditorModule::TabName(TEXT("PlutoGameplayTagInspector"));
const FName FPlutoGameplayTagInspectorEditorModule::DocumentationTabName(TEXT("PlutoGameplayTagInspectorDocumentation"));

namespace PlutoGameplayTagInspectorEditorStyle
{
	const FName StyleSetName(TEXT("PlutoGameplayTagInspectorStyle"));
	const FName MenuIconName(TEXT("PlutoGameplayTagInspector.MenuIcon"));
	const FName TabIconName(TEXT("PlutoGameplayTagInspector.TabIcon"));
	const TCHAR* ResourcesFolder = TEXT("Resources");
	const TCHAR* PluginBrowserIconFile = TEXT("Icon128.png");
	const TCHAR* MenuIconFile = TEXT("Icon20.png");
	const TCHAR* TabIconFile = TEXT("Icon16.png");
}

void FPlutoGameplayTagInspectorEditorModule::StartupModule()
{
	RegisterStyle();

	for (int32 InstanceIndex = 0; InstanceIndex < MaxInspectorTabCount; ++InstanceIndex)
	{
		FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
			GetInspectorTabName(InstanceIndex),
			FOnSpawnTab::CreateRaw(this, &FPlutoGameplayTagInspectorEditorModule::SpawnInspectorTab, InstanceIndex))
			.SetDisplayName(GetInspectorTabDisplayName(InstanceIndex))
			.SetIcon(GetPluginMenuIcon())
			.SetMenuType(ETabSpawnerMenuType::Hidden);
	}

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
		DocumentationTabName,
		FOnSpawnTab::CreateRaw(this, &FPlutoGameplayTagInspectorEditorModule::SpawnDocumentationTab))
		.SetDisplayName(PlutoGameplayTagInspectorEditor::MakeLocalizedText(
			TEXT("Pluto GameplayTag 使用文档"),
			TEXT("Pluto GameplayTag Documentation")))
		.SetIcon(GetDocumentationIcon())
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	UToolMenus::RegisterStartupCallback(
		FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FPlutoGameplayTagInspectorEditorModule::RegisterMenus));
}

void FPlutoGameplayTagInspectorEditorModule::ShutdownModule()
{
	if (UToolMenus::TryGet() != nullptr)
	{
		UToolMenus::UnRegisterStartupCallback(this);
		UToolMenus::UnregisterOwner(this);
	}

	for (int32 InstanceIndex = 0; InstanceIndex < MaxInspectorTabCount; ++InstanceIndex)
	{
		FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(GetInspectorTabName(InstanceIndex));
		InspectorTabs[InstanceIndex].Reset();
	}
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(DocumentationTabName);
	UnregisterStyle();
}

void FPlutoGameplayTagInspectorEditorModule::OpenInspectorTab()
{
	for (int32 InstanceIndex = 0; InstanceIndex < MaxInspectorTabCount; ++InstanceIndex)
	{
		if (!InspectorTabs[InstanceIndex].IsValid())
		{
			FGlobalTabmanager::Get()->TryInvokeTab(GetInspectorTabName(InstanceIndex));
			return;
		}
	}

	FGlobalTabmanager::Get()->TryInvokeTab(GetInspectorTabName(MaxInspectorTabCount - 1));
}

void FPlutoGameplayTagInspectorEditorModule::OpenDocumentationTab()
{
	FGlobalTabmanager::Get()->TryInvokeTab(DocumentationTabName);
}

void FPlutoGameplayTagInspectorEditorModule::RegisterStyle()
{
	if (StyleSet.IsValid())
	{
		return;
	}

	TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("Pluto_GameplayTagInspector"));
	if (!Plugin.IsValid())
	{
		return;
	}

	const FString ResourcesPath = FPaths::Combine(Plugin->GetBaseDir(), PlutoGameplayTagInspectorEditorStyle::ResourcesFolder);
	StyleSet = MakeShared<FSlateStyleSet>(PlutoGameplayTagInspectorEditorStyle::StyleSetName);
	StyleSet->SetContentRoot(ResourcesPath);
	bHasCustomMenuIcon = false;
	bHasCustomTabIcon = false;

	const FString MenuIconPath = FPaths::Combine(ResourcesPath, PlutoGameplayTagInspectorEditorStyle::MenuIconFile);
	if (FPaths::FileExists(MenuIconPath))
	{
		bHasCustomMenuIcon = true;
		StyleSet->Set(
			PlutoGameplayTagInspectorEditorStyle::MenuIconName,
			new FSlateImageBrush(MenuIconPath, FVector2D(20.0f, 20.0f)));
	}

	const FString TabIconPath = FPaths::Combine(ResourcesPath, PlutoGameplayTagInspectorEditorStyle::TabIconFile);
	if (FPaths::FileExists(TabIconPath))
	{
		bHasCustomTabIcon = true;
		StyleSet->Set(
			PlutoGameplayTagInspectorEditorStyle::TabIconName,
			new FSlateImageBrush(TabIconPath, FVector2D(16.0f, 16.0f)));
	}

	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet);
}

void FPlutoGameplayTagInspectorEditorModule::UnregisterStyle()
{
	if (!StyleSet.IsValid())
	{
		return;
	}

	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet);
	StyleSet.Reset();
	bHasCustomMenuIcon = false;
	bHasCustomTabIcon = false;
}

FSlateIcon FPlutoGameplayTagInspectorEditorModule::GetPluginMenuIcon() const
{
	if (StyleSet.IsValid() && bHasCustomMenuIcon)
	{
		return FSlateIcon(PlutoGameplayTagInspectorEditorStyle::StyleSetName, PlutoGameplayTagInspectorEditorStyle::MenuIconName);
	}

	return FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Search");
}

const FSlateBrush* FPlutoGameplayTagInspectorEditorModule::GetPluginTabBrush() const
{
	if (StyleSet.IsValid() && bHasCustomTabIcon)
	{
		return StyleSet->GetBrush(PlutoGameplayTagInspectorEditorStyle::TabIconName);
	}

	return FAppStyle::Get().GetBrush("Icons.Search");
}

FSlateIcon FPlutoGameplayTagInspectorEditorModule::GetDocumentationIcon() const
{
	return FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Documentation");
}

const FSlateBrush* FPlutoGameplayTagInspectorEditorModule::GetDocumentationTabBrush() const
{
	return FAppStyle::Get().GetBrush("Icons.Documentation");
}

void FPlutoGameplayTagInspectorEditorModule::RegisterMenus()
{
	FToolMenuOwnerScoped OwnerScoped(this);

	UToolMenu* MainMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu");
	FToolMenuSection& PlutoMainSection = MainMenu->FindOrAddSection(NAME_None);

	UToolMenu* PlutoMenu = nullptr;
	if (PlutoMainSection.FindEntry("PlutoMenu") == nullptr)
	{
		FToolMenuEntry& PlutoEntry = PlutoMainSection.AddSubMenu(
			"PlutoMenu",
			PlutoGameplayTagInspectorEditor::MakeLocalizedText(TEXT("Pluto"), TEXT("Pluto")),
			PlutoGameplayTagInspectorEditor::MakeLocalizedText(
				TEXT("\u6253\u5f00 Pluto \u76f8\u5173\u5de5\u5177\u3002"),
				TEXT("Open Pluto tools.")),
			FNewToolMenuChoice(),
			false,
			GetPluginMenuIcon());
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
	AddOpenInspectorEntry(WindowSection);
}

void FPlutoGameplayTagInspectorEditorModule::PopulatePlutoMenu(UToolMenu* Menu)
{
	FToolMenuSection& ToolsSection = Menu->AddSection("PlutoToolsSection");
	AddOpenInspectorEntry(ToolsSection);
	AddOpenDocumentationEntry(ToolsSection);

	FToolMenuSection& LanguageSection = Menu->AddSection("PlutoLanguageSection");
	LanguageSection.AddSubMenu(
		"PlutoLanguageMenu",
		PlutoGameplayTagInspectorEditor::MakeLocalizedText(TEXT("\u8bed\u8a00"), TEXT("Language")),
		PlutoGameplayTagInspectorEditor::MakeLocalizedText(
			TEXT("\u5207\u6362\u68c0\u67e5\u5668\u754c\u9762\u8bed\u8a00\u3002"),
			TEXT("Switch the inspector language.")),
		FNewToolMenuDelegate::CreateRaw(this, &FPlutoGameplayTagInspectorEditorModule::PopulateLanguageMenu),
		false,
		GetPluginMenuIcon());
}

void FPlutoGameplayTagInspectorEditorModule::PopulateLanguageMenu(UToolMenu* Menu)
{
	FToolMenuSection& Section = Menu->AddSection("PlutoLanguageItems");

	Section.AddMenuEntry(
		"PlutoLanguageChinese",
		PlutoGameplayTagInspectorEditor::MakeLocalizedText(TEXT("\u4e2d\u6587"), TEXT("Chinese")),
		PlutoGameplayTagInspectorEditor::MakeLocalizedText(
			TEXT("\u5c06\u68c0\u67e5\u5668\u754c\u9762\u5207\u6362\u4e3a\u4e2d\u6587\u3002"),
			TEXT("Switch the inspector UI to Chinese.")),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateLambda([]()
		{
			PlutoGameplayTagInspectorEditor::SetCurrentLanguage(EPlutoGameplayTagInspectorLanguage::Chinese);
		})));

	Section.AddMenuEntry(
		"PlutoLanguageEnglish",
		PlutoGameplayTagInspectorEditor::MakeLocalizedText(TEXT("\u82f1\u6587"), TEXT("English")),
		PlutoGameplayTagInspectorEditor::MakeLocalizedText(
			TEXT("\u5c06\u68c0\u67e5\u5668\u754c\u9762\u5207\u6362\u4e3a\u82f1\u6587\u3002"),
			TEXT("Switch the inspector UI to English.")),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateLambda([]()
		{
			PlutoGameplayTagInspectorEditor::SetCurrentLanguage(EPlutoGameplayTagInspectorLanguage::English);
		})));
}

void FPlutoGameplayTagInspectorEditorModule::AddOpenInspectorEntry(FToolMenuSection& Section)
{
	Section.AddMenuEntry(
		"OpenPlutoGameplayTagInspector",
		PlutoGameplayTagInspectorEditor::MakeLocalizedText(
			TEXT("Pluto GameplayTag \u68c0\u67e5\u5668"),
			TEXT("Pluto GameplayTag Inspector")),
		PlutoGameplayTagInspectorEditor::MakeLocalizedText(
			TEXT("\u6253\u5f00 Pluto GameplayTag \u68c0\u67e5\u9762\u677f\uff0c\u6700\u591a\u540c\u65f6\u6253\u5f00 3 \u4e2a\u5b9e\u4f8b\u3002"),
			TEXT("Open a Pluto gameplay tag inspector panel, up to 3 simultaneous instances.")),
		GetPluginMenuIcon(),
		FUIAction(FExecuteAction::CreateRaw(this, &FPlutoGameplayTagInspectorEditorModule::OpenInspectorTab)));
}

void FPlutoGameplayTagInspectorEditorModule::AddOpenDocumentationEntry(FToolMenuSection& Section)
{
	Section.AddMenuEntry(
		"OpenPlutoGameplayTagInspectorDocumentation",
		PlutoGameplayTagInspectorEditor::MakeLocalizedText(
			TEXT("Pluto GameplayTag 使用文档"),
			TEXT("Pluto GameplayTag Documentation")),
		PlutoGameplayTagInspectorEditor::MakeLocalizedText(
			TEXT("打开 Pluto GameplayTag Inspector 的本地使用文档。"),
			TEXT("Open the local documentation for Pluto GameplayTag Inspector.")),
		GetDocumentationIcon(),
		FUIAction(FExecuteAction::CreateRaw(this, &FPlutoGameplayTagInspectorEditorModule::OpenDocumentationTab)));
}

FName FPlutoGameplayTagInspectorEditorModule::GetInspectorTabName(int32 InstanceIndex) const
{
	if (InstanceIndex <= 0)
	{
		return TabName;
	}

	return FName(*FString::Printf(TEXT("%s_%d"), *TabName.ToString(), InstanceIndex + 1));
}

FText FPlutoGameplayTagInspectorEditorModule::GetInspectorTabDisplayName(int32 InstanceIndex) const
{
	if (InstanceIndex <= 0)
	{
		return PlutoGameplayTagInspectorEditor::MakeLocalizedText(
			TEXT("Pluto GameplayTag \u68c0\u67e5\u5668"),
			TEXT("Pluto GameplayTag Inspector"));
	}

	return PlutoGameplayTagInspectorEditor::MakeLocalizedText(
		*FString::Printf(TEXT("Pluto GameplayTag \u68c0\u67e5\u5668 %d"), InstanceIndex + 1),
		*FString::Printf(TEXT("Pluto GameplayTag Inspector %d"), InstanceIndex + 1));
}

TSharedRef<SDockTab> FPlutoGameplayTagInspectorEditorModule::SpawnInspectorTab(const FSpawnTabArgs& SpawnTabArgs, int32 InstanceIndex)
{
	const TSharedRef<SDockTab> DockTab =
		SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		.Label(GetInspectorTabDisplayName(InstanceIndex))
		.OnTabClosed(SDockTab::FOnTabClosedCallback::CreateRaw(
			this,
			&FPlutoGameplayTagInspectorEditorModule::HandleInspectorTabClosed,
			InstanceIndex))
		[
			SNew(SPlutoGameplayTagInspectorPanel)
		];

	if (InstanceIndex >= 0 && InstanceIndex < MaxInspectorTabCount)
	{
		InspectorTabs[InstanceIndex] = DockTab;
	}

	DockTab->SetTabIcon(GetPluginTabBrush());
	return DockTab;
}

void FPlutoGameplayTagInspectorEditorModule::HandleInspectorTabClosed(TSharedRef<SDockTab> ClosedTab, int32 InstanceIndex)
{
	if (InstanceIndex >= 0 && InstanceIndex < MaxInspectorTabCount)
	{
		InspectorTabs[InstanceIndex].Reset();
	}
}

TSharedRef<SDockTab> FPlutoGameplayTagInspectorEditorModule::SpawnDocumentationTab(const FSpawnTabArgs& SpawnTabArgs)
{
	const TSharedRef<SDockTab> DockTab =
		SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SPlutoGameplayTagInspectorDocumentationPanel)
		];

	DockTab->SetTabIcon(GetDocumentationTabBrush());
	return DockTab;
}

IMPLEMENT_MODULE(FPlutoGameplayTagInspectorEditorModule, PlutoGameplayTagInspectorEditor)
