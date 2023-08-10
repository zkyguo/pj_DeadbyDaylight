// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DeadbyDaylightHUD.h"
#include "pj_DeadbyDaylight/LevelElement/ElementManager.h"
#include <pj_DeadbyDaylight/Character/GameCharacter.h>
#include "DeadbyDaylightPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API ADeadbyDaylightPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:

	ADeadbyDaylightPlayerController();

	UPROPERTY(VisibleAnywhere)
	ADeadbyDaylightHUD* HUD;

	UPROPERTY(VisibleAnywhere)
	AElementManager* Manager;

	UPROPERTY(BlueprintReadWrite)
	bool bIsDemon;

	UPROPERTY(BlueprintReadWrite)
	TArray<UTexture2D*> PlayerAvatars;

	UPROPERTY(BlueprintReadWrite)
	int32 MyPlayerIndex;

	UPROPERTY(BlueprintReadWrite)
	TArray<int32> DemonPlayersIndexInGame;

	/**
	 * @brief C2S, Client Send player Join Game request to Server
	 */
	UFUNCTION(BlueprintCallable,Server, Reliable)
	void LoadingBattle(bool isDemon, int PlayerNum,const FText& PlayerName, UTexture2D* Texture);

	/**
	 * @brief S2C, Client Receive prepared players from server
	 */
	UFUNCTION(BlueprintCallable, Client, Reliable)
	void ReceivePreparedPlayer(const TArray<UTexture2D*>& AllplayerAvatars, const TArray<FText>& PlayerNames);

	/**
	* @brief S2C, Server tells client to start Character selection
	*/
	UFUNCTION(BlueprintCallable, Client, Reliable)
	void StartSelectCharacter();

	/**
	 * @brief C2S, Server receive character which Client select
	 */
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void SelectCharacter(TSubclassOf<AGameCharacter> CharacterSelect);

	/**
	 * @brief S2C, Client receive character selection from other client
	 */
	UFUNCTION(BlueprintCallable, Client, Reliable)
	void ReceiveCharacterSelect(int32 OtherIndex, FName PlayerName, TSubclassOf<AGameCharacter> SelectedCharacter);

	/**
	 * @brief S2C,Client receive battle start information from Server
	 */
	UFUNCTION(BlueprintCallable, Client, Reliable)
	void ReceiveBattleBegin(int32 MyIndex, const TArray<int32>& DemonPlayersIndex);

private:

	

};
