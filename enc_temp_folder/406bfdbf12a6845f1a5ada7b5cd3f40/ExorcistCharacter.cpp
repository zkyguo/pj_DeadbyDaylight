// Fill out your copyright notice in the Description page of Project Settings.


#include "ExorcistCharacter.h"

#include "Components/AudioComponent.h"

AExorcistCharacter::AExorcistCharacter()
{
	HeartBeat = CreateDefaultSubobject<UAudioComponent>(TEXT("Heart Beat Wav"));
	HeartBeat->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
}
