// Copyright Epic Games, Inc. All Rights Reserved.

#include "pj_DeadbyDaylightGameMode.h"
#include "pj_DeadbyDaylightCharacter.h"
#include "UObject/ConstructorHelpers.h"

Apj_DeadbyDaylightGameMode::Apj_DeadbyDaylightGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

