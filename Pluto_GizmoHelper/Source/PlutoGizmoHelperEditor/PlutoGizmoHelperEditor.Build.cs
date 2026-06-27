using UnrealBuildTool;

public class PlutoGizmoHelperEditor : ModuleRules
{
	public PlutoGizmoHelperEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"DeveloperSettings",
				"Engine",
				"PlutoGizmoHelperRuntime"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"InputCore",
				"PropertyEditor",
				"Slate",
				"SlateCore",
				"SubobjectDataInterface",
				"ToolMenus",
				"UnrealEd"
			});
	}
}
