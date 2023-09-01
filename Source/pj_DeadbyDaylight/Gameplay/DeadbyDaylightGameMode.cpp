// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadbyDaylightGameMode.h"
#include "DeadbyDaylightPlayerController.h"
#include "WaitingPlayerPawn.h"
#include "DeadbyDaylightHUD.h"
#include "Math/Sobol.h"
#include "Kismet/GameplayStatics.h"

ADeadbyDaylightGameMode::ADeadbyDaylightGameMode()
{
	PlayerControllerClass = ADeadbyDaylightPlayerController::StaticClass();
	DefaultPawnClass = AWaitingPlayerPawn::StaticClass();
	HUDClass = ADeadbyDaylightHUD::StaticClass();
}


