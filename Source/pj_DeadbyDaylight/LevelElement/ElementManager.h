// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

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
	class ADeadbyDaylightHUD* HUD;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	class ADeadbyDaylightPlayerController* PlayerController;


};
