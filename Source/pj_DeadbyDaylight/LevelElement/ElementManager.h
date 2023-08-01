// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <pj_DeadbyDaylight/Gameplay/DeadbyDaylightHUD.h>
#include <pj_DeadbyDaylight/Gameplay/DeadbyDaylightPlayerController.h>
#include "ElementManager.generated.h"


UCLASS()
class PJ_DEADBYDAYLIGHT_API AElementManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElementManager();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	ADeadbyDaylightHUD* HUD;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	ADeadbyDaylightPlayerController* PlayerController;


};
