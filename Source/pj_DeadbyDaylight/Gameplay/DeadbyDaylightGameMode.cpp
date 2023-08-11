// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadbyDaylightGameMode.h"
#include "DeadbyDaylightPlayerController.h"
#include "WaitingPlayerPawn.h"
#include "DeadbyDaylightHUD.h"

ADeadbyDaylightGameMode::ADeadbyDaylightGameMode()
{
	PlayerControllerClass = ADeadbyDaylightPlayerController::StaticClass();
	DefaultPawnClass = AWaitingPlayerPawn::StaticClass();
	HUDClass = ADeadbyDaylightHUD::StaticClass();
}


void ADeadbyDaylightGameMode::ReceiveClientReload(ADeadbyDaylightPlayerController* player, bool isPlayerDemon, int32 PlayerCount,
                                                                 const FText& playerName, UTexture2D* PlayerIcon)
{
	if (!PlayersInGame.Contains(player))
	{
		PlayersName.Add(playerName);
		int32 playerIndex = PlayersInGame.Add(player);
		PlayerAvatars.Add(PlayerIcon);
		PlayerGold.Add(player, 0);

		if (playerIndex == 0)
		{
			DemonInGame.Add(player);
			DemonPlayerID.Add(playerIndex);
		}
		else
		{
			ExorcistInGame.Add(player);
		}
	}

	for (auto Players : PlayersInGame)
	{
		//Server load all client into game
		Players->ReceivePreparedPlayer(PlayerAvatars, PlayersName);
	}

	if (PlayersInGame.Num() == PlayerCount)
	{
		for (auto player : PlayersInGame)
		{
			player->StartSelectCharacter();
		}
	}

}

void ADeadbyDaylightGameMode::UpdateSelectedCharacter(ADeadbyDaylightPlayerController* PlayerController,
	TSubclassOf<AGameCharacter> CharacterSelected)
{
	PlayersClass.Add(PlayerController, CharacterSelected);

	for (int32 i = 0; i < PlayersInGame.Num(); i++)
	{
		int32 index = PlayersInGame.Find(PlayerController);
		PlayersInGame[i]->ReceiveCharacterSelect(index,*PlayersName[index].ToString(), CharacterSelected);
	}
	if(PlayersClass.Num() == PlayersInGame.Num())
	{
		//Begin Battle start count down
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::BeginBattle, 5.1f, false);
	}
}

void ADeadbyDaylightGameMode::BeginBattle()
{
	for (int32 i = 0; i < PlayersInGame.Num(); i++)
	{
		PlayersInGame[i]->ReceiveBattleBegin(i, DemonPlayerID);
	}
}
