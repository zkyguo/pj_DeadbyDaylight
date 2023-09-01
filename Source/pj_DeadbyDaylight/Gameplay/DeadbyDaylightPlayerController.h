// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DeadbyDaylightHUD.h"
#include "pj_DeadbyDaylight/LevelElement/ElementManager.h"
#include <pj_DeadbyDaylight/Character/GameCharacter.h>
#include "pj_DeadbyDaylight/Enum/EPlayerState.h"
#include "pj_DeadbyDaylight/LevelFactory/Generator.h"
#include <pj_DeadbyDaylight/Enum/EGameItemType.h>
#include "DeadbyDaylightPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API ADeadbyDaylightPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:

	ADeadbyDaylightPlayerController();

	UPROPERTY(VisibleAnywhere)
	ADeadbyDaylightHUD* HUD;

	UPROPERTY(VisibleAnywhere)
	AElementManager* Manager;

};
