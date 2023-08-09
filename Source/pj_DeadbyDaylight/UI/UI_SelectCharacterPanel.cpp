// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_SelectCharacterPanel.h"
#include "pj_DeadbyDaylight/Character/DemonCharacter.h"

void UUI_SelectCharacterPanel::NativeConstruct()
{
	Super::NativeConstruct();
	DemonButton->OnClicked.AddDynamic(this, &ThisClass::OnDemonButtonClick);

}

void UUI_SelectCharacterPanel::OnDemonButtonClick()
{
	auto Player = Cast<ADemonCharacter>(GetOwningPlayer());
}
