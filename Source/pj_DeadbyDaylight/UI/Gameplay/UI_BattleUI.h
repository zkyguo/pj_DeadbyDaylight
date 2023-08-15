// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_ExorcistAvatarBar.h"
#include "UI_BattleUI.generated.h"


/**
 * 
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API UUI_BattleUI : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UUI_ExorcistAvatarBar* ExorcistAvatarBar;

};
