// Fill out your copyright notice in the Description page of Project Settings.


#include "ExorcistCharacter.h"
#include "Components/AudioComponent.h"
#include "pj_DeadbyDaylight/Gameplay/DeadbyDaylightGameMode.h"
#include "pj_DeadbyDaylight/LevelFactory/Generator.h"
#include "pj_DeadbyDaylight/Gameplay/DeadbyDaylightPlayerController.h"


AExorcistCharacter::AExorcistCharacter()
{
	HeartBeat = CreateDefaultSubobject<UAudioComponent>(TEXT("Heart Beat Wav"));
	HeartBeat->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);

}

void AExorcistCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ThisClass::Interact);
}

void AExorcistCharacter::Interact()
{

	
}

