// Fill out your copyright notice in the Description page of Project Settings.

#include "RFPlayerController.h"

int32 ARFPlayerController::AmountOfDeath = 0;

void ARFPlayerController::ResetAmountOfDeath()
{
	AmountOfDeath = 0;
}

void ARFPlayerController::UnFreeze()
{
	ServerRestartPlayer();
	++AmountOfDeath;
	++AmountOfDeathInThisLevel;
}
