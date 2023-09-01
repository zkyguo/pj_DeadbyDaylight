// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadbyDaylightPlayerController.h"
#include "DeadbyDaylightGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "pj_DeadbyDaylight/UI/UI_PreparePanel.h"
#include "pj_DeadbyDaylight/UI/UI_SelectCharacterPanel.h"
#include "pj_DeadbyDaylight/LevelElement/ElementManager.h"



ADeadbyDaylightPlayerController::ADeadbyDaylightPlayerController()
{
	UE_LOG(LogTemp, Warning, TEXT("Player : %s"), *this->GetName());
}

void ADeadbyDaylightPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = Cast<ADeadbyDaylightHUD>(GetHUD());

	if (HUD->PreparePanelClass)
	{
		HUD->PreparePanel = CreateWidget<UUI_PreparePanel>(this, HUD->PreparePanelClass);
		HUD->PreparePanel->AddToViewport();

		Manager = GetWorld()->SpawnActor<AElementManager>();
		Manager->HUD = HUD;
		Manager->PlayerController = this;
	}
}






