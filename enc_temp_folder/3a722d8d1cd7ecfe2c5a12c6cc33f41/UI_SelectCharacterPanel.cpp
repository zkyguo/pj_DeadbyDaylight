// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_SelectCharacterPanel.h"
#include "pj_DeadbyDaylight/Character/DemonCharacter.h"
#include "pj_DeadbyDaylight/Gameplay/DeadbyDaylightPlayerController.h"


UUI_SelectCharacterPanel::UUI_SelectCharacterPanel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
	static ConstructorHelpers::FClassFinder<UUI_PreparePanel> DemonCharacter_BPClass(TEXT("/Game/Game/Character/BP_DemonCharacter"));
	DemonCharacterClass = DemonCharacter_BPClass.Class;

	static ConstructorHelpers::FClassFinder<UUI_PreparePanel> ExorcistCharacter_BPClass(TEXT("/Game/Game/Character/BP_ExorcistCharacter"));
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
	bIsNotSelect = !bIsNotSelect;
	DemonButton->SetIsEnabled(bIsNotSelect);

	PlayerController->bIsDemon = true;
}

void UUI_SelectCharacterPanel::OnExorcistButtonClick()
{
	ADeadbyDaylightPlayerController* PlayerController = Cast<ADeadbyDaylightPlayerController>(GetOwningPlayer());
	PlayerController->SelectCharacter(ExorcistCharacterClass);
	bIsNotSelect = !bIsNotSelect;
	DemonButton->SetIsEnabled(bIsNotSelect);
	
	PlayerController->bIsDemon = false;
}
