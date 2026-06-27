using UnrealBuildTool;

public class PlutoGameplayTagInspectorRuntime : ModuleRules
{
	public PlutoGameplayTagInspectorRuntime(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"GameplayTags"
			});
	}
}
