using UnrealBuildTool;

public class PlutoSplineHelperRuntime : ModuleRules
{
	public PlutoSplineHelperRuntime(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"GeometryCore",
				"GeometryFramework"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"PhysicsCore",
				"RenderCore"
			});
	}
}
