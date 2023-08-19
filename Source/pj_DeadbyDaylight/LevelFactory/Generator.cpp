// Fill out your copyright notice in the Description page of Project Settings.


#include "Generator.h"

// Sets default values
AGenerator::AGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RepairLoopSound = CreateDefaultSubobject<UAudioComponent>(TEXT("Repair loop Wav"));
}

// Called when the game starts or when spawned
void AGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGenerator::AppendRepairGenerator()
{
}

void AGenerator::StartOrStopRepairing(bool isStartRepairing)
{
	if(isStartRepairing)
	{
		RepairLoopSound->SetActive(true, true);
	}
	else
	{
		RepairLoopSound->Deactivate();
	}
}

