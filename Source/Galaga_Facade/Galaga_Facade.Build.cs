// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Galaga_Facade : ModuleRules
{
	public Galaga_Facade(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
