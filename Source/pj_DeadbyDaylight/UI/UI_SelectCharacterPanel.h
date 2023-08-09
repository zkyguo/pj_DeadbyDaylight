// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/Button.h>
#include "UI_SelectCharacterPanel.generated.h"


/**
 * 
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API UUI_SelectCharacterPanel : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
	UButton* DemonButton;

	UPROPERTY(meta = (BindWidget))
	UButton* ExocistButton;

	UFUNCTION(BlueprintCallable)
	void OnDemonButtonClick();
};
