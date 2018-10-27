// Fill out your copyright notice in the Description page of Project Settings.

#include "RFPlatformManager.h"
#include "RFWorldSettings.h"
#include "EngineUtils.h"
#include "RFPlatform.h"

ARFWorldSettings* ARFPlatformManager::WorldSettingInstance = nullptr;

ARFPlatformManager::ARFPlatformManager()
{
	AmountOfPlatformPerLevel = 1;
}

void ARFPlatformManager::DisplayPlatformLevels()
{
	RFPlatforms.Reset();
	RFPlatforms.Reserve(100);

	for (TActorIterator<AActor> ActorItr(GetWorld(), ARFPlatform::StaticClass()); ActorItr; ++ActorItr) 
	{
		ARFPlatform* m_RFPlatform = Cast<ARFPlatform>(*ActorItr);
			
		if (m_RFPlatform) 
		{
			FPlaformInfo& PlatformInfoRef = RFPlatforms.FindOrAdd(m_RFPlatform->GetCurrentPlatformLevel());
			PlatformInfoRef.AllRFPlatforms.AddUnique(m_RFPlatform);
		}
	}

	RFPlatforms.Shrink();
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
