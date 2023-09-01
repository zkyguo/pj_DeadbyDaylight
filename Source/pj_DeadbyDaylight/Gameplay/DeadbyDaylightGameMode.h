// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "pj_DeadbyDaylight/Character/GameCharacter.h"
#include "TimerManager.h"
#include "DeadbyDaylightPlayerStart.h"
#include "DeadbyDaylightGameMode.generated.h"

/**
 * t
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API ADeadbyDaylightGameMode : public AGameModeBase
{
	GENERATED_BODY()

public :
	ADeadbyDaylightGameMode();

public :

	//Game Timer
	int32 GameTimeCountDown = 605;
};
