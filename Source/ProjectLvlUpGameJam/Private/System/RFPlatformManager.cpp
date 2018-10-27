// Fill out your copyright notice in the Description page of Project Settings.

#include "RFPlatformManager.h"
#include "RFWorldSettings.h"

ARFWorldSettings* ARFPlatformManager::WorldSettingInstance = nullptr;

ARFPlatformManager::ARFPlatformManager()
{

}

void ARFPlatformManager::DisplayPlatformLevels()
{

}

void ARFPlatformManager::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UWorld* World = GetWorld();

	if (World) 
	{
		WorldSettingInstance = Cast<ARFWorldSettings>(World->GetWorldSettings());
	}
}

void ARFPlatformManager::OnConstruction(const FTransform & Transform)
{
	Super::OnConstruction(Transform);
}

#if WITH_EDITOR
#endif
