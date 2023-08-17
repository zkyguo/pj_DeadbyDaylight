// Fill out your copyright notice in the Description page of Project Settings.


#include "ExorcistCharacter.h"
#include "."
#include "Components/AudioComponent.h"
#include "pj_DeadbyDaylight/Gameplay/DeadbyDaylightGameMode.h"

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
	if(PlayerController->CharacterState == EPlayerState::Normal)
	{
		if(PlayerController->NearItemType == EGameItemType::Cross)
		{
			
		}
		else if(PlayerController->NearItemType == EGameItemType::HitDownExorcist)
		{
			
		}
		else if (PlayerController->NearItemType == EGameItemType::Generator)
		{
			if(PlayerController->InteractingGenerator)
			{
				StartRepairGenerator(this, PlayerController->InteractingGenerator);
			}
		}
	}
}

void AExorcistCharacter::StartRepairGenerator_Implementation(AGameCharacter* RepairPlayer, AGenerator* Generator)
{
	ADeadbyDaylightGameMode* GameMode = Cast<ADeadbyDaylightGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->RepairGenerator(this, Generator, PlayerController);

}
