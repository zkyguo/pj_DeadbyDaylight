// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintClassFinder.h"

UBlueprintClassFinder::UBlueprintClassFinder()
{
	static ConstructorHelpers::FClassFinder<ADemonCharacter> DemonCharacter_BPClass(TEXT("/Game/Game/Character/BP_DemonCharacter"));
	DemonCharacterClass = DemonCharacter_BPClass.Class;

	static ConstructorHelpers::FClassFinder<AExorcistCharacter> ExorcistCharacter_BPClass(TEXT("/Game/Game/Character/BP_ExorcistCharacter"));
	ExorcistCharacterClass = ExorcistCharacter_BPClass.Class;
}
