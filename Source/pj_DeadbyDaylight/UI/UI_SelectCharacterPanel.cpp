// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_SelectCharacterPanel.h"
#include "pj_DeadbyDaylight/Character/DemonCharacter.h"
#include "pj_DeadbyDaylight/Character/ExorcistCharacter.h"
#include "Gameplay/UI_BattleUI.h"
#include "Gameplay/UI_EscapeKeyPanel.h"
#include "pj_DeadbyDaylight/Gameplay/DeadbyDaylightPlayerController.h"
#include "pj_DeadbyDaylight/Util/BlueprintClassFinder.h"


UUI_SelectCharacterPanel::UUI_SelectCharacterPanel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UUI_SelectCharacterPanel::NativeConstruct()
{
	Super::NativeConstruct();
	UE_LOG(LogTemp, Warning, TEXT("%s"),*this->GetName());
	DemonButton->OnClicked.AddDynamic(this, &ThisClass::OnDemonButtonClick);
	ExocistButton->OnClicked.AddDynamic(this, &ThisClass::OnExorcistButtonClick);

}

void UUI_SelectCharacterPanel::OnDemonButtonClick()
{
	ADeadbyDaylightPlayerController* PlayerController = Cast<ADeadbyDaylightPlayerController>(GetOwningPlayer());
	PlayerController->SelectCharacter(GetGameInstance()->GetSubsystem<UBlueprintClassFinder>()->DemonCharacterClass);
	bIsNotCharaterSelect = false;
	PlayerController->SetIsDemon(true);
	DemonButton->SetIsEnabled(false);
	ExocistButton->SetIsEnabled(true);
	
}

void UUI_SelectCharacterPanel::OnExorcistButtonClick()
{
	ADeadbyDaylightPlayerController* PlayerController = Cast<ADeadbyDaylightPlayerController>(GetOwningPlayer());
	PlayerController->SelectCharacter(GetGameInstance()->GetSubsystem<UBlueprintClassFinder>()->ExorcistCharacterClass);
	bIsNotCharaterSelect = false;
	PlayerController->SetIsDemon(false);
	ExocistButton->SetIsEnabled(false);
	DemonButton->SetIsEnabled(true);
	
}

void UUI_SelectCharacterPanel::BattleBeginningCountDown()
{
	ADeadbyDaylightHUD* HUD = Cast<ADeadbyDaylightHUD>(GetOwningPlayer()->GetHUD());
	if(BattleBeginCountDown != 0)
	{
		BattleBeginCountDown--;
	}
	else
	{
		HUD->SelectCharacterPanel->CountDownText->SetText(FText::FromString("Game will start soon!"));
		GetWorld()->GetTimerManager().ClearTimer(CountDownTimerHandler);
		
		HUD->BattleUI = CreateWidget<UUI_BattleUI>(GetOwningPlayer(), HUD->BattleUIClass);
		HUD->BattleUI->AddToViewport();

		HUD->EscapeKeyPanel = CreateWidget<UUI_EscapeKeyPanel>(GetOwningPlayer(), HUD->EscapeKeyPanelClass);
		HUD->EscapeKeyPanel->AddToViewport();

		RemoveFromParent();
	}
}

void UUI_SelectCharacterPanel::SelectCharacterBeginCountDown()
{
	if(!bIsNotCharaterSelect)
	{
		GetWorld()->GetTimerManager().ClearTimer(CountDownTimerHandler);
	}
	else
	{
		if(BattleBeginCountDown == 0)
		{
			//if at t = 0, there still not character selected
			GetWorld()->GetTimerManager().ClearTimer(CountDownTimerHandler);
			bIsNotCharaterSelect = true;
			auto PlayerController = Cast<ADeadbyDaylightPlayerController>(GetOwningPlayer());
			if(PlayerController->bIsDemon)
			{
				PlayerController->SelectCharacter(GetGameInstance()->GetSubsystem<UBlueprintClassFinder>()->DemonCharacterClass);
			}
			else
			{
				PlayerController->SelectCharacter(GetGameInstance()->GetSubsystem<UBlueprintClassFinder>()->ExorcistCharacterClass);
			}
		}
		else
		{
			BattleBeginCountDown--;
		}
	}

}

