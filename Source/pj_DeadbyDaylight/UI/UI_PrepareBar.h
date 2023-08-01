// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Texture2D.h"
#include "UI_PrepareBar.generated.h"

/**
 * 
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API UUI_PrepareBar : public UUserWidget
{
	GENERATED_BODY()

public :

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	bool isLoaded;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UTexture2D* CharacterAvatar;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	FText PlayerName;
};
