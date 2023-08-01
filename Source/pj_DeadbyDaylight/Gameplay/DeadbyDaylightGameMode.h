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
	 * @brief Server side, receive client loaidng game request
	 * @param player
	 * @param isPlayerGhost
	 * @param PlayerInGame
	 * @param playerName
	 * @param PlayerIcon
	 */
	void ReceiveClientReload(APlayerController* player, bool isPlayerGhost, int PlayerInGame, const FText& playerName, UTexture2D* PlayerIcon);

	UPROPERTY(BlueprintReadWrite)
	TArray<APlayerController*>PlayersInGame;
};
