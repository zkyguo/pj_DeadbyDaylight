// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_PreparePanel.h"

void UUI_PreparePanel::NativeConstruct()
{
	Super::NativeConstruct();
}

void UUI_PreparePanel::RefreshPlayers(const TArray<UTexture2D*>& PlayerAvatar, TArray<FText> PlayerName)
{
    for (int32 i = 0; i < PlayerAvatar.Num(); i++)
    {
        UUI_PrepareBar* BarToUpdate = nullptr;

        switch (i)
        {
        case 0:
            BarToUpdate = Player1_bar;
            break;
        case 1:
            BarToUpdate = Player2_bar;
            break;
        case 2:
            BarToUpdate = Player3_bar;
            break;
        case 3:
            BarToUpdate = Player4_bar;
            break;
        case 4:
            BarToUpdate = Player5_bar;
            break;
        }

        BarToUpdate->isLoaded = true;
        BarToUpdate->PlayerName = PlayerName[i];
        BarToUpdate->CharacterAvatar->SetBrushFromTexture(PlayerAvatar[i]);
    }
}
