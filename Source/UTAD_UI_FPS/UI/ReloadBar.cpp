// Fill out your copyright notice in the Description page of Project Settings.


#include "ReloadBar.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "../TP_WeaponComponent.h"
#include "Components/ProgressBar.h"

void UReloadBar::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible); 
	AUTAD_UI_FPSCharacter* Character = Cast<AUTAD_UI_FPSCharacter>(GetOwningPlayerPawn());
	if (Character)
	{
		Character->GetAttachedWeaponComponent()->OnReload.BindUObject(this, &UReloadBar::UpdateReloadBarValue);
	}
}

void UReloadBar::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UReloadBar::UpdateReloadBarValue(float NewValue)
{
	ReloadBar->SetPercent(NewValue);
}
