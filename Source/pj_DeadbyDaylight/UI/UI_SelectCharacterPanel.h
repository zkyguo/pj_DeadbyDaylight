// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/Button.h>
#include <Components/TextBlock.h>
#include <pj_DeadbyDaylight/Character/ExorcistCharacter.h>
#include <pj_DeadbyDaylight/Character/DemonCharacter.h>
#include "UI_SelectCharacterPanel.generated.h"




/**
 * 
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API UUI_SelectCharacterPanel : public UUserWidget
{
	GENERATED_BODY()

public :
	UUI_SelectCharacterPanel(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	bool bIsNotSelect = true;;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	int32 BattleBeginCountDown;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	FTimerHandle CountDownTimerHandler;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* CountDownText;

	UFUNCTION(BlueprintCallable)
	void BattleBeginningCountDown();

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
	UButton* DemonButton;

	UPROPERTY(meta = (BindWidget))
	UButton* ExocistButton;

	TSubclassOf<ADemonCharacter> DemonCharacterClass;
	TSubclassOf<AExorcistCharacter> ExorcistCharacterClass;

	UFUNCTION(BlueprintCallable)
	void OnDemonButtonClick();

	UFUNCTION(BlueprintCallable)
	void OnExorcistButtonClick();

	
};
