// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadbyDaylightHUD.h"

ADeadbyDaylightHUD::ADeadbyDaylightHUD()
{
	static ConstructorHelpers::FClassFinder<UUI_PreparePanel> PreparePanel_BPClass(TEXT("/Game/Asset/UI/BeforeBattle/BP_PreparePanel"));
	PreparePanelClass = PreparePanel_BPClass.Class;

	static ConstructorHelpers::FClassFinder<UUI_SelectCharacterPanel> SelectCharacter_BPClass(TEXT("/Game/Asset/UI/BeforeBattle/BP_SelectCharacterPanel"));
	SelectCharacterClass = SelectCharacter_BPClass.Class;

	static ConstructorHelpers::FClassFinder<UUI_BattleUI> BattleUI_BPClass(TEXT("/Game/Asset/UI/GamePlay/BP_BattleUI"));
	BattleUIClass = BattleUI_BPClass.Class;

	static ConstructorHelpers::FClassFinder<UUI_EscapeKeyPanel> EscapeKeyPanel_BPClass(TEXT("/Game/Asset/UI/GamePlay/BP_EscapeKeyPanel"));
	EscapeKeyPanelClass = EscapeKeyPanel_BPClass.Class;
}
