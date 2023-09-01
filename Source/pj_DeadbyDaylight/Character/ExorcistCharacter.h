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

	UFUNCTION(BlueprintCallable)
	void Interact();
	   
};
