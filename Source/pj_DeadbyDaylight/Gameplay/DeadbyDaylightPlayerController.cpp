// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadbyDaylightPlayerController.h"
#include "pj_DeadbyDaylight/UI/UI_PreparePanel.h"
#include "Kismet/KismetSystemLibrary.h"
#include "pj_DeadbyDaylight/LevelElement/ElementManager.h"

void ADeadbyDaylightPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if(GetWorld()->IsNetMode(NM_ListenServer))
	{
		HUD = Cast<ADeadbyDaylightHUD>(GetHUD());
		HUD->PreparePanel = CreateWidget<UUI_PreparePanel>(this);
		HUD->PreparePanel->AddToViewport();
		Manager = GetWorld()->SpawnActor<AElementManager>();
		Manager->HUD = HUD;
		Manager->PlayerController = this;

		FLatentActionInfo Info;
		Info.Linkage = 0;
		Info.CallbackTarget = this;
		Info.ExecutionFunction = NAME_None; //Delay callback
		Info.UUID = GetUniqueID();

		UKismetSystemLibrary::Delay(this, 2.0f, Info);
	}
}
