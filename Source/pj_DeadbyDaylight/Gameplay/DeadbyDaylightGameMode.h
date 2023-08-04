// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DeadbyDaylightGameMode.generated.h"

/**
 * t
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API ADeadbyDaylightGameMode : public AGameModeBase
{
	GENERATED_BODY()

public :
	ADeadbyDaylightGameMode();


	/**
	 * @brief Server send Client the players who joined game
	 */
	UFUNCTION(BlueprintCallable, Server,Reliable)
	void ReceiveClientReload(ADeadbyDaylightPlayerController* player, bool isPlayerGhost, int32 PlayerInGame, const FText& playerName, UTexture2D* PlayerIcon);



	UPROPERTY(BlueprintReadWrite)
	TArray<ADeadbyDaylightPlayerController*>PlayersInGame;

	UPROPERTY(BlueprintReadWrite)
	TArray<FText>PlayersName;

	UPROPERTY(BlueprintReadWrite)
	TArray<int32>DemonPlayerID;

	UPROPERTY(BlueprintReadWrite)
	TArray<UTexture2D*>PlayerAvatars;


	UPROPERTY(BlueprintReadWrite)
	TMap<ADeadbyDaylightPlayerController*, int32>PlayerGold;

	UPROPERTY(BlueprintReadWrite)
	TArray<ADeadbyDaylightPlayerController*>DemonInGame;

	UPROPERTY(BlueprintReadWrite)
	TArray<ADeadbyDaylightPlayerController*>ExocistInGame;
};
