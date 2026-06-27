using UnrealBuildTool;

public class PlutoSplineHelperEditor : ModuleRules
{
	public PlutoSplineHelperEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"DeveloperSettings",
				"Engine",
				"PlutoSplineHelperRuntime"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"PropertyEditor",
				"Slate",
				"SlateCore",
				"UnrealEd"
			});
	}
}
