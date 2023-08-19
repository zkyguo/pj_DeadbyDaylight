// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <pj_DeadbyDaylight/Character/ExorcistCharacter.h>
#include "Components/AudioComponent.h"
#include "Generator.generated.h"


UCLASS()
class PJ_DEADBYDAYLIGHT_API AGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Sound, meta = (AllowPrivateAccess = "true"))
	UAudioComponent* RepairLoopSound;

	UPROPERTY(BlueprintReadWrite, Category = Client)
	bool isRepaired = false;

	UPROPERTY(BlueprintReadWrite, Category = Server)
	TMap<AExorcistCharacter*, FVector> RepairingPlayerLocation;

	FTimerHandle RepaireGeneratorHandle;

	UFUNCTION(BlueprintCallable)
	void AppendRepairGenerator();

	UFUNCTION(BlueprintCallable)
	void StartOrStopRepairing(bool isStartRepairing);
};
