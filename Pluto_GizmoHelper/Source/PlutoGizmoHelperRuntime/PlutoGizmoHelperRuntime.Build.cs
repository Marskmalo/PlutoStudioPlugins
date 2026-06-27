using UnrealBuildTool;

public class PlutoGizmoHelperRuntime : ModuleRules
{
	public PlutoGizmoHelperRuntime(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"DeveloperSettings",
				"Engine"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"RenderCore"
			});
	}
}
