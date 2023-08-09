// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadbyDaylightPlayerController.h"
#include "DeadbyDaylightGameMode.h"
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

	if (GetWorld()->IsNetMode(NM_Client) && IsLocalPlayerController())
	{
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
}



void ADeadbyDaylightPlayerController::StartSelectCharacter_Implementation()
{
	

	if(HUD->SelectCharacterClass)
	{
		HUD->SelectCharacterPanel = CreateWidget<UUI_SelectCharacterPanel>(this, HUD->SelectCharacterClass);
		if (HUD->PreparePanel)
		{
			HUD->PreparePanel->RemoveFromViewport();
		}
		HUD->SelectCharacterPanel->AddToViewport();
	}


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
	ADeadbyDaylightGameMode* GameMode = Cast<ADeadbyDaylightGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->ReceiveClientReload(this, isDemon, PlayerNum, FText::FromString(this->GetName()), Texture);
}

void ADeadbyDaylightPlayerController::SelectCharacter_Implementation(TSubclassOf<AGameCharacter> CharacterSelect)
{

}








