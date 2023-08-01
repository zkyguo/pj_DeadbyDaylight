// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AsyncUtil.generated.h"

/**
 * 
 */
UCLASS()
class PJ_DEADBYDAYLIGHT_API UAsyncUtil : public UObject
{
	GENERATED_BODY()

public :

	// Static function to trigger Delay
	static UObject* Delay(UObject* WorldContextObject, float duration, const FSimpleDelegate& Callback = NULL);


	// Function to initialize and start the delay
	void Init(UObject* WorldContextObject, float Duration, const FSimpleDelegate& Callback);

	// Function to be called when the delay is over
	void OnDelayCompleted();

private:
	FTimerHandle TimerHandle;
	FSimpleDelegate Callback;
};
