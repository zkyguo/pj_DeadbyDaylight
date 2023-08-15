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


void ADeadbyDaylightPlayerController::ReceiveBattleBegin_Implementation(int32 MyIndex, const TArray<int32>& DemonPlayersIndex)
{
	MyPlayerIndex = MyIndex;
	DemonPlayersIndexInGame = DemonPlayersIndex;
	GetWorld()->GetTimerManager().ClearTimer(HUD->SelectCharacterPanel->CountDownTimerHandler);
	HUD->SelectCharacterPanel->BattleBeginCountDown = 5;

	GetWorld()->GetTimerManager().SetTimer(HUD->SelectCharacterPanel->CountDownTimerHandler, HUD->SelectCharacterPanel, &UUI_SelectCharacterPanel::BattleBeginningCountDown, 1.f,true);
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
	ADeadbyDaylightGameMode* GameMode = Cast<ADeadbyDaylightGameMode>(GetWorld()->GetAuthGameMode());

	GameMode->UpdateSelectedCharacter(this, CharacterSelect);
}

void ADeadbyDaylightPlayerController::ReceiveCharacterSelect_Implementation(int32 OtherIndex, FName PlayerName,
	TSubclassOf<AGameCharacter> SelectedCharacter)
{
	bool islocal = IsLocalPlayerController();
	UE_LOG(LogTemp,Warning,TEXT("Player %d selects %s as character, is local : %hhd"), OtherIndex, *SelectedCharacter->GetName(), islocal)
}


void ADeadbyDaylightPlayerController::ReceiveMyCharacter_Implementation(AGameCharacter* MyCharacter)
{
	if (Cast<AExorcistCharacter>(MyCharacter))
	{
		MyDemonCharacter = Cast<ADemonCharacter>(MyCharacter);
	}
	else if (Cast<AExorcistCharacter>(MyCharacter))
	{
		MyExorcistCharacte = Cast<AExorcistCharacter>(MyCharacter);
	}
}


void ADeadbyDaylightPlayerController::ReplicatedBattleTime_Implementation(int32 BattleTime)
{
}


void ADeadbyDaylightPlayerController::ReceiveGameOverMessage_Implementation(bool isVictory)
{
}




