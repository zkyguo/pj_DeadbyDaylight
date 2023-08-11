// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_SelectCharacterPanel.h"
#include "pj_DeadbyDaylight/Character/DemonCharacter.h"
#include "pj_DeadbyDaylight/Character/ExorcistCharacter.h"
#include "Gameplay/UI_BattleUI.h"
#include "Gameplay/UI_EscapeKeyPanel.h"
#include "pj_DeadbyDaylight/Gameplay/DeadbyDaylightPlayerController.h"


UUI_SelectCharacterPanel::UUI_SelectCharacterPanel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
	static ConstructorHelpers::FClassFinder<ADemonCharacter> DemonCharacter_BPClass(TEXT("/Game/Game/Character/BP_DemonCharacter"));
	DemonCharacterClass = DemonCharacter_BPClass.Class;

	static ConstructorHelpers::FClassFinder<AExorcistCharacter> ExorcistCharacter_BPClass(TEXT("/Game/Game/Character/BP_ExorcistCharacter"));
	ExorcistCharacterClass = ExorcistCharacter_BPClass.Class;

}

void UUI_SelectCharacterPanel::NativeConstruct()
{
	Super::NativeConstruct();

	DemonButton->OnClicked.AddDynamic(this, &ThisClass::OnDemonButtonClick);
	ExocistButton->OnClicked.AddDynamic(this, &ThisClass::OnExorcistButtonClick);

}

void UUI_SelectCharacterPanel::OnDemonButtonClick()
{
	ADeadbyDaylightPlayerController* PlayerController = Cast<ADeadbyDaylightPlayerController>(GetOwningPlayer());
	PlayerController->SelectCharacter(DemonCharacterClass);
	DemonButton->SetIsEnabled(false);
	ExocistButton->SetIsEnabled(true);
	bIsCharaterSelect = true; 
	PlayerController->bIsDemon = true;
}

void UUI_SelectCharacterPanel::OnExorcistButtonClick()
{
	ADeadbyDaylightPlayerController* PlayerController = Cast<ADeadbyDaylightPlayerController>(GetOwningPlayer());
	PlayerController->SelectCharacter(ExorcistCharacterClass);
	ExocistButton->SetIsEnabled(false);
	DemonButton->SetIsEnabled(true);
	bIsCharaterSelect = true;
	PlayerController->bIsDemon = false;
}

void UUI_SelectCharacterPanel::BattleBeginningCountDown()
{
	if(BattleBeginCountDown != 0)
	{
		BattleBeginCountDown--;
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(CountDownTimerHandler);
		ADeadbyDaylightHUD* HUD = Cast<ADeadbyDaylightHUD>(GetOwningPlayer()->GetHUD());
		HUD->BattleUI = CreateWidget<UUI_BattleUI>(GetOwningPlayer(), HUD->BattleUIClass);
		HUD->BattleUI->AddToViewport();

		HUD->EscapeKeyPanel = CreateWidget<UUI_EscapeKeyPanel>(GetOwningPlayer(), HUD->EscapeKeyPanelClass);
		HUD->EscapeKeyPanel->AddToViewport();

		RemoveFromParent();
	}
}

void UUI_SelectCharacterPanel::SelectCharacterBeginCountDown()
{
	if(bIsCharaterSelect)
	{
		GetWorld()->GetTimerManager().ClearTimer(CountDownTimerHandler);
	}
	else
	{
		if(BattleBeginCountDown == 0)
		{
			//if at t = 0, there still not character selected
			GetWorld()->GetTimerManager().ClearTimer(CountDownTimerHandler);
			bIsCharaterSelect = false;
			auto PlayerController = Cast<ADeadbyDaylightPlayerController>(GetOwningPlayer());
			if(PlayerController->bIsDemon)
			{
				PlayerController->SelectCharacter(DemonCharacterClass);
			}
			else
			{
				PlayerController->SelectCharacter(ExorcistCharacterClass);
			}
		}
		else
		{
			BattleBeginCountDown--;
		}
	}

}

