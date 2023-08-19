// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameCharacter.h"
#include "ExorcistCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API AExorcistCharacter : public AGameCharacter
{
	GENERATED_BODY()

public :
	AExorcistCharacter();

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = Sound, meta = (AllowPrivateAccess = "true"))
	UAudioComponent* HeartBeat;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool isRepairingGenerator;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool isHitDown;

	UFUNCTION(BlueprintCallable)
	void Interact();

	/**
	 * @brief S2C, Client update Start Repair info from Server(UI, Bar)
	 */
	UFUNCTION(BlueprintCallable, Client, Reliable)
	void MyPlayerStartRepairGenerator();

	/**
	 * @brief C2S, Server receive Repairing message from a player who is starting repair a generator
	 * @param RepairPlayer 
	 * @param Generator 
	 */
	UFUNCTION(BlueprintCallable, Server ,Reliable)
	void StartRepairGenerator(AGameCharacter* RepairPlayer, class AGenerator* Generator);

	UFUNCTION(BlueprintCallable)
	int32 GetPlayerIndex();
};
