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

public :
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
	 * @brief C2S, Server receive Client
	 */
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void SelectCharacterConfirmation(AGameCharacter* SelectCharacter);

};
