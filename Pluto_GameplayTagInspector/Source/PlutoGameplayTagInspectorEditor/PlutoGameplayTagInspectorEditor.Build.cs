using UnrealBuildTool;

public class PlutoGameplayTagInspectorEditor : ModuleRules
{
	public PlutoGameplayTagInspectorEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"GameplayTags",
				"PlutoGameplayTagInspectorRuntime"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"ActorPickerMode",
				"ApplicationCore",
				"EditorStyle",
				"InputCore",
				"LevelEditor",
				"PropertyEditor",
				"Projects",
				"Slate",
				"SlateCore",
				"ToolMenus",
				"UnrealEd"
			});
	}
}
