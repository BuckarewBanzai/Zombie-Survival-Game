// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CoopGameServerTarget : TargetRules //Change this line according to the name of your project
{
    public CoopGameServerTarget(TargetInfo Target) : base(Target) //Change this line according to the name of your project
    {
        Type = TargetType.Server;

        ExtraModuleNames.Add("CoopGame"); //Change this line according to the name of your project
    }
}