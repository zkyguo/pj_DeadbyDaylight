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


void ADeadbyDaylightGameMode::ReceiveClientReload(ADeadbyDaylightPlayerController* player, bool isPlayerDemon, int32 PlayerCount,
                                                                 const FText& playerName, UTexture2D* PlayerIcon)
{
	if (!PlayersInGame.Contains(player))
	{
		PlayersName.Add(playerName);
		int32 playerIndex = PlayersInGame.Add(player);
		PlayerAvatars.Add(PlayerIcon);
		PlayerGold.Add(player, 0);

		if (isPlayerDemon)
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

void ADeadbyDaylightGameMode::BattleTimeCountDown()
{
	GameTimeCountDown--;

	if(!GameTimeCountDown == 0)
	{
		//Every 7 sec, sync Current remaining Game time to all client
		if(GameTimeCountDown % 7 == 0)
		{
			for (auto Player : PlayersInGame)
			{
				Player->ReplicatedBattleTime(GameTimeCountDown);
			}
		}
		else
		{
			//If Exorcist escaped, send win message
			for (auto Player : PlayersInGame)
			{
				for (int32 PlayerIndex : EscapedExorcistPlayerIndex)
				{
					if(Player->MyPlayerIndex == PlayerIndex)
					{
						Player->ReceiveGameOverMessage(true);
						continue;
					}
				}
			}

		}
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(GameTimerHandle);
		//If there still exorcist didnt escaped, the exorcist loses
		if(EscapedExorcistPlayerIndex.Num() > 0)
		{
			
			for (auto Player : ExorcistInGame)
			{
				Player->ReceiveGameOverMessage(false);
			}

			for (auto Player : DemonInGame)
			{
				Player->ReceiveGameOverMessage(true);
			}
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
		GetWorldTimerManager().SetTimer(GameTimerHandle, this, &ThisClass::BeginBattle, 5.1f, false);
		for (int32 i = 0; i < PlayersInGame.Num(); i++)
		{
			PlayersInGame[i]->ReceiveBattleBegin(i, DemonPlayerID);
		}

		GetWorldTimerManager().SetTimer(GameTimerHandle, this, &ThisClass::BattleTimeCountDown, .997f, true);
	}
}

void ADeadbyDaylightGameMode::BeginBattle()
{
	TArray<AActor*>PlayerStarts;
	UGameplayStatics::GetAllActorsOfClass(this, ADeadbyDaylightPlayerStart::StaticClass(), PlayerStarts);

	for (int i = 0; i < PlayerStarts.Num(); i++)
	{
		ADeadbyDaylightPlayerStart* PlayerStart = Cast<ADeadbyDaylightPlayerStart>(PlayerStarts[i]);
		if(PlayerStart->bIsDemon)
		{
			DemonPlayerStarts.Add(PlayerStart);
		}
		else
		{
			ExorcistPlayerStarts.Add(PlayerStart);
		}
	}

	//Spawn Demon character to demon game start
	TArray<ADeadbyDaylightPlayerStart*> Copy;
	for (auto PlayerStart : DemonPlayerStarts)
	{
		auto CopyStart = DuplicateObject<ADeadbyDaylightPlayerStart>(PlayerStart, PlayerStart->GetOuter(), TEXT("DemonStart"));
		FVector location = CopyStart->GetActorLocation();
		Copy.Add(CopyStart);
	}

	for (auto Player : DemonInGame)
	{
		Player->GetPawn()->Destroyed();
		if(PlayersClass.Find(Player))
		{
			int32 randomIndex = FMath::RandRange(0, DemonPlayerStarts.Num() - 1);

			FVector location = DemonPlayerStarts[randomIndex]->GetActorTransform().GetLocation();
			FRotator rotation(0, 0, 0);

			auto DemonActor = GetWorld()->SpawnActor<AGameCharacter>(*PlayersClass.Find(Player),location, rotation);
			Player->Possess(DemonActor);
			PlayerCharacterByController.Add(Player, DemonActor);
		}
	}

	Copy.Empty();
	for (auto PlayerStart : ExorcistPlayerStarts)
	{
		Copy.Add(DuplicateObject<ADeadbyDaylightPlayerStart>(PlayerStart, PlayerStart->GetOuter(), TEXT("DemonStart")));
	}
	for (auto Player : ExorcistInGame)
	{
		Player->GetPawn()->Destroyed();
		if (PlayersClass.Find(Player))
		{
			int32 randomIndex = FMath::RandRange(0, ExorcistPlayerStarts.Num() - 1);

			FVector location = ExorcistPlayerStarts[randomIndex]->GetActorTransform().GetLocation();
			int32 StartSize = ExorcistPlayerStarts[randomIndex]->CharacterStartSize;
			FRotator rotation(0, 0, 0);

			FVector SpawnLocation(
				FMath::RandRange(StartSize * -50., StartSize * 50.) + location.X,
				FMath::RandRange(StartSize * -50., StartSize * 50.) + location.Y,
				location.Z
			);

			auto ExorcistActor = GetWorld()->SpawnActor<AGameCharacter>(*PlayersClass.Find(Player), SpawnLocation, rotation);
			Player->Possess(ExorcistActor);
			PlayerCharacterByController.Add(Player, ExorcistActor);
		}
	}

	
	GetWorld()->GetTimerManager().SetTimer(GameTimerHandle, this, &ThisClass::ReplicatePlayerCharacter, 1.1f);

	//setup escape passsword
	for(int i = 0;i < 4;i++)
	{
		int32 randomIndex = FMath::RandRange(0, 10);
		EscapeKeyword.Add(randomIndex);
	}

	
}

void ADeadbyDaylightGameMode::ReplicatePlayerCharacter()
{
	for (auto player : PlayersInGame)
	{
		if(PlayerCharacterByController.Find(player))
		{
			player->ReceiveMyCharacter(*PlayerCharacterByController.Find(player));
		}
	}
}