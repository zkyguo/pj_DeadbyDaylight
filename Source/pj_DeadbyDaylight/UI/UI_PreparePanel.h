// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_PrepareBar.h"
#include "UI_PreparePanel.generated.h"


/**
 * 
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API UUI_PreparePanel : public UUserWidget
{
	GENERATED_BODY()

public :

	UPROPERTY(meta = (BindWidget))
	UUI_PrepareBar* Player1_bar;

	UPROPERTY(meta = (BindWidget))
	UUI_PrepareBar* Player2_bar;

	UPROPERTY(meta = (BindWidget))
	UUI_PrepareBar* Player3_bar;

	UPROPERTY(meta = (BindWidget))
	UUI_PrepareBar* Player4_bar;

	UPROPERTY(meta = (BindWidget))
	UUI_PrepareBar* Player5_bar;
};
