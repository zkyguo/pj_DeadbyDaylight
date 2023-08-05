// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "UI_PrepareBar.generated.h"

/**
 * 
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API UUI_PrepareBar : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public :

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	bool isLoaded;

	UPROPERTY(meta = (BindWidget))
	UImage* CharacterAvatar;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	FText PlayerName = FText::FromString("");
};
