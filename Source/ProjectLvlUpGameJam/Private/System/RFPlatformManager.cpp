// Fill out your copyright notice in the Description page of Project Settings.

#include "RFPlatformManager.h"
#include "RFWorldSettings.h"
#include "EngineUtils.h"
#include "RFPlatform.h"

ARFWorldSettings* ARFPlatformManager::WorldSettingInstance = nullptr;

static int32 RandomizeIterateIndex = 0;

ARFPlatformManager::ARFPlatformManager()
{
	bShouldRandomize = true;
	bShouldRandomizeSpeed = false;

	StartingPlatform = 1;
	AmountOfPlatformPerLevel = 1;
}

void ARFPlatformManager::BeginPlay()
{
	Super::BeginPlay();

	InitManager();

	if (bShouldRandomize)
	{
		RandomizeIterateIndex = StartingPlatform;
		RandomizePlatform();
	}

	if (bShouldRandomizeSpeed)
	{
		RandomizeSpeed();
	}
}

void ARFPlatformManager::RandomizePlatform()
{
	if (RFPlatforms.Contains(RandomizeIterateIndex))
	{
		TArray<ARFPlatform*> & PlatformArrayRef = RFPlatforms[RandomizeIterateIndex].AllRFPlatforms;
		if (PlatformArrayRef.Num() > AmountOfPlatformPerLevel)
		{
			const int32 PickUpLastIndex = PlatformArrayRef.Num() - 1;
			const int32 RandomIndexToDelete = FMath::RandRange(0, PickUpLastIndex);

			ARFPlatform* const PlatformToDelete = PlatformArrayRef[RandomIndexToDelete];

			PlatformArrayRef.Remove(PlatformToDelete);
			PlatformArrayRef.Shrink();

			if (PlatformToDelete) 
			{
				PlatformToDelete->Destroy();
			}

			if (PlatformArrayRef.Num() <= AmountOfPlatformPerLevel) 
			{
				++RandomizeIterateIndex;
			}
			
			RandomizePlatform();
		}
	}
	else 
	{
		RandomizeIterateIndex = StartingPlatform;
	}
}

void ARFPlatformManager::RandomizeSpeed()
{
	for (TActorIterator<AActor> ActorItr(GetWorld(), ARFPlatform::StaticClass()); ActorItr; ++ActorItr)
	{
		ARFPlatform* m_RFPlatform = Cast<ARFPlatform>(*ActorItr);

		if (m_RFPlatform) 
		{
			m_RFPlatform->RandomizeSpeed();
		}

	}
}

void ARFPlatformManager::InitManager()
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
