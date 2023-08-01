// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadbyDaylightPlayerController.h"


void ADeadbyDaylightPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if(GetWorld()->IsNetMode(NM_ListenServer))
	{
		HUD = Cast<ADeadbyDaylightHUD>(GetHUD());
	}
}
