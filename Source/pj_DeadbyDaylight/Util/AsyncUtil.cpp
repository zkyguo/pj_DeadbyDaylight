// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncUtil.h"

UObject* UAsyncUtil::Delay(UObject* WorldContextObject, float duration, const FSimpleDelegate& callback)
{
    UAsyncUtil* Helper = NewObject<UAsyncUtil>();
    Helper->Init(WorldContextObject, duration, callback);
    return Helper;
}

void UAsyncUtil::Init(UObject* WorldContextObject, float Duration, const FSimpleDelegate& callback)
{
    this->Callback = callback;

    if (WorldContextObject)
    {
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UAsyncUtil::OnDelayCompleted, Duration, false);
    }
}

void UAsyncUtil::OnDelayCompleted()
{
    Callback.ExecuteIfBound();

    // Make sure to clean up the util object when we're done
    TimerHandle.Invalidate();
    this->ConditionalBeginDestroy();
}
