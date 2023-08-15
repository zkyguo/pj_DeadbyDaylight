// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/Image.h>
#include <Components/TextBlock.h>
#include "UI_ExorcistAvatarBar.generated.h"



/**
 * 
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API UUI_ExorcistAvatarBar : public UUserWidget
{
	GENERATED_BODY()

public :

	UPROPERTY(meta=(BindWidget),BlueprintReadWrite)
	UImage* ExorcistAvatar_0;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UImage* ExorcistAvatar_1;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UImage* ExorcistAvatar_2;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UImage* ExorcistAvatar_3;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* ExorcistStatusText_0;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* ExorcistStatusText_1;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* ExorcistStatusText_2;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* ExorcistStatusText_3;
};
