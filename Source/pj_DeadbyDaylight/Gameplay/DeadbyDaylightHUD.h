// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include <pj_DeadbyDaylight/UI/UI_PreparePanel.h>
#include <pj_DeadbyDaylight/UI/UI_SelectCharacterPanel.h>
#include "DeadbyDaylightHUD.generated.h"


/**
 * 
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API ADeadbyDaylightHUD : public AHUD
{
	GENERATED_BODY()

public :
	ADeadbyDaylightHUD();

	UPROPERTY(BlueprintReadWrite)
	UUI_PreparePanel* PreparePanel;

	UPROPERTY(BlueprintReadWrite)
	UUI_SelectCharacterPanel* SelectCharacterPanel;

	TSubclassOf<UUI_PreparePanel> PreparePanelClass;
	TSubclassOf<UUI_SelectCharacterPanel> SelectCharacterClass;
};
