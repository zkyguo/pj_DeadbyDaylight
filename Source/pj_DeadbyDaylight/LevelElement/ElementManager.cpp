// Fill out your copyright notice in the Description page of Project Settings.


#include "ElementManager.h"
#include <pj_DeadbyDaylight/Gameplay/DeadbyDaylightHUD.h>
#include <pj_DeadbyDaylight/Gameplay/DeadbyDaylightPlayerController.h>

// Sets default values
AElementManager::AElementManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AElementManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AElementManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

