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


void ADeadbyDaylightGameMode::ReceiveClientReload_Implementation(ADeadbyDaylightPlayerController* player, bool isPlayerDemon, int32 PlayerCount,
                                                                 const FText& playerName, UTexture2D* PlayerIcon)
{
	PlayersName.Add(playerName);
	int32 playerIndex = PlayersInGame.Add(player);
	PlayerAvatars.Add(PlayerIcon);
	PlayerGold.Add(player, 0);

	if(isPlayerDemon)
	{
		DemonInGame.Add(player);
		DemonPlayerID.Add(playerIndex);
	}
	else
	{
		ExocistInGame.Add(player);
	}

	for (auto Players : PlayersInGame)
	{
		//Server load all client into game
		Players->ReceivePreparedPlayer(PlayerAvatars, PlayersName);
	}

	if(PlayersInGame.Num() == PlayerCount)
	{
		for (auto player : PlayersInGame)
		{
			player->StartSelectCharacter();
		}
	}
}
