// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DeadbyDaylightHUD.h"
#include "pj_DeadbyDaylight/LevelElement/ElementManager.h"
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

	UPROPERTY(VisibleAnywhere)
	ADeadbyDaylightHUD* HUD;

	UPROPERTY(VisibleAnywhere)
	AElementManager* Manager;

	UPROPERTY(BlueprintReadWrite)
	bool bIsDemon;

public :

	UFUNCTION(BlueprintCallable,Server, Reliable)
	void LoadingBattle(bool isDemon, int PlayerNum,const FText& PlayerName, UTexture2D* Texture);
};
