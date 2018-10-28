// Fill out your copyright notice in the Description page of Project Settings.

#include "RFGameMode.h"
#include "RFPlayerController.h"
#include "RFCharacter.h"
#include "RFHUD.h"
#include "RFWorldSettings.h"

ARFGameMode::ARFGameMode(const class FObjectInitializer & ObjectInitializer)
	:Super(ObjectInitializer)
{
	PlayerControllerClass = ARFPlayerController::StaticClass();
	DefaultPawnClass = ARFCharacter::StaticClass();
	HUDClass = ARFHUD::StaticClass();

	PrimaryActorTick.bCanEverTick = false;
}

ARFWorldSettings* ARFGameMode::GetRFWorldSettings() const
{
	UWorld* const World = GetWorld();
	
	if (World) 
	{
		return Cast<ARFWorldSettings>(World->GetWorldSettings());
	}

	return nullptr;
}

