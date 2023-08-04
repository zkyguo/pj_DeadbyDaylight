// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadbyDaylightPlayerController.h"
#include "DeadbyDaylightGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "pj_DeadbyDaylight/UI/UI_PreparePanel.h"
#include "pj_DeadbyDaylight/LevelElement/ElementManager.h"


void ADeadbyDaylightPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld()->IsNetMode(NM_ListenServer))
	{
		HUD = Cast<ADeadbyDaylightHUD>(GetHUD());

		HUD->PreparePanel = CreateWidget<UUI_PreparePanel>(this);
		HUD->PreparePanel->AddToViewport();

		Manager = GetWorld()->SpawnActor<AElementManager>();
		Manager->HUD = HUD;
		Manager->PlayerController = this;
	}

}

void ADeadbyDaylightPlayerController::StartSelectCharacter_Implementation()
{
}

void ADeadbyDaylightPlayerController::ReceivePreparedPlayer_Implementation(const TArray<UTexture2D*>& AllplayerAvatars,
                                                                           const TArray<FText>& PlayerNames)
{
	HUD->PreparePanel->RefreshPlayers(PlayerAvatars, PlayerNames);
	PlayerAvatars = AllplayerAvatars;
}


void ADeadbyDaylightPlayerController::LoadingBattle_Implementation(bool isDemon, int PlayerNum, const FText& PlayerName,
                                                                   UTexture2D* Texture)
{
	//Get gameMode and Send owning player info to Server for joining game.
	ADeadbyDaylightGameMode* GameMode = Cast<ADeadbyDaylightGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	GameMode->ReceiveClientReload(this, isDemon, PlayerNum, PlayerName, Texture);
}









