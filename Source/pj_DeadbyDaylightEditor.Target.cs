// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class pj_DeadbyDaylightEditorTarget : TargetRules
{
	public pj_DeadbyDaylightEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("pj_DeadbyDaylight");
	}
}
