// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "pj_DeadbyDaylight/Character/GameCharacter.h"
#include "TimerManager.h"
#include "DeadbyDaylightPlayerStart.h"
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
	void ReceiveClientReload(ADeadbyDaylightPlayerController* player, bool isPlayerGhost, int32 PlayerInGame, const FText& playerName, UTexture2D* PlayerIcon);

	/**
	 * @brief All player in game
	 */
	UPROPERTY(BlueprintReadWrite)
	TArray<ADeadbyDaylightPlayerController*>PlayersInGame;

	/**
	 * @brief All playerName in game
	 */
	UPROPERTY(BlueprintReadWrite)
	TArray<FText>PlayersName;

	/**
	 * @brief All demon player index(ID)
	 */
	UPROPERTY(BlueprintReadWrite)
	TArray<int32>DemonPlayerID;

	/**
	 * @brief All player Icon
	 */
	UPROPERTY(BlueprintReadWrite)
	TArray<UTexture2D*>PlayerAvatars;

	/**
	 * @brief All player current gold 
	 */
	UPROPERTY(BlueprintReadWrite)
	TMap<ADeadbyDaylightPlayerController*, int32>PlayerGold;

	UPROPERTY(BlueprintReadWrite)
	TArray<ADeadbyDaylightPlayerController*>DemonInGame;

	UPROPERTY(BlueprintReadWrite)
	TArray<ADeadbyDaylightPlayerController*>ExorcistInGame;

	/**
	 * @brief Each pawn and his controller
	 */
	UPROPERTY(BlueprintReadWrite)
	TMap<ADeadbyDaylightPlayerController*, AGameCharacter*> PlayerCharacterByController;

	TArray<ADeadbyDaylightPlayerStart*> DemonPlayerStarts;
	TArray<ADeadbyDaylightPlayerStart*> ExorcistPlayerStarts;

	TArray<int32> EscapeKeyword;

private:
	/**
	 * @brief Update Character Selection from other client
	 */
	UFUNCTION(BlueprintCallable)
	void UpdateSelectedCharacter(ADeadbyDaylightPlayerController* PlayerController,TSubclassOf<AGameCharacter> CharacterSelected);

	UFUNCTION(BlueprintCallable)
	void ReplicatePlayerCharacter();

	/**
	 * @brief Setup Game start.
	 */
	UFUNCTION(BlueprintCallable)
	void BeginBattle();

	TMap<ADeadbyDaylightPlayerController*, TSubclassOf<AGameCharacter>> PlayersClass;

	FTimerHandle TimerHandle;
};
