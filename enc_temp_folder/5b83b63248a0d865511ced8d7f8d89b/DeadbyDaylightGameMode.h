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
	 * @brief Setup Game start.
	 */
	UFUNCTION(BlueprintCallable, Category = "Before Game Start")
	void BeginBattle();

	/**
	 * @brief Update Character Selection from other client
	 */
	UFUNCTION(BlueprintCallable, Category = "Before Game Start")
	void UpdateSelectedCharacter(ADeadbyDaylightPlayerController* PlayerController, TSubclassOf<AGameCharacter> CharacterSelected);

	/**
	 * @brief Server send Client the players who joined game
	 */
	UFUNCTION(BlueprintCallable, Category = "Before Game Start")
	void ReceiveClientReload(ADeadbyDaylightPlayerController* player, bool isPlayerGhost, int32 PlayerInGame, const FText& playerName, UTexture2D* PlayerIcon);

	/**
	 * @brief Sync character of all client
	 */
	UFUNCTION(BlueprintCallable, Category = "Before Game Start")
	void ReplicatePlayerCharacter();


	/**
	 * @brief Server count down the time remaining of current battle
	 */
	UFUNCTION(BlueprintCallable, Category = "During Game")
	void BattleTimeCountDown();


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
	TArray<int32> EscapedExorcistPlayerIndex;
	TArray<int32> EscapeKeyword;

private:

	TMap<ADeadbyDaylightPlayerController*, TSubclassOf<AGameCharacter>> PlayersClass;
	FTimerHandle GameTimerHandle;
public :
	//Game Timer
	int32 GameTimeCountDown = 600;
};
