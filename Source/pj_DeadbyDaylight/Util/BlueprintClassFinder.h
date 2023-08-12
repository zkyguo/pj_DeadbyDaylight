// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <pj_DeadbyDaylight/Character/ExorcistCharacter.h>
#include <pj_DeadbyDaylight/Character/DemonCharacter.h>
#include "BlueprintClassFinder.generated.h"


/**
 * 
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API UBlueprintClassFinder : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UBlueprintClassFinder();

	TSubclassOf<ADemonCharacter> DemonCharacterClass;
	TSubclassOf<AExorcistCharacter> ExorcistCharacterClass;
};
