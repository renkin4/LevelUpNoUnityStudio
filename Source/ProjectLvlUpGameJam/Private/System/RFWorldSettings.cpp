// Fill out your copyright notice in the Description page of Project Settings.

#include "RFWorldSettings.h"
#include "EngineUtils.h"

ARFWorldSettings::ARFWorldSettings()
{
	DistanceBetweenPlatformLevels = 150.f;
	KillZ = -1000.f;
}

AActor* ARFWorldSettings::GetBaseFloor()
{
	if (WorldBaseFloor == nullptr)
	{
		for (TActorIterator<AActor> ActorItr(GetWorld(), AActor::StaticClass()); ActorItr; ++ActorItr)
		{
			AActor* const ActorPtr = Cast<AActor>(*ActorItr);

			if (ActorPtr
				&& ActorPtr->GetName() == TEXT("BaseFloor"))
			{
				WorldBaseFloor = ActorPtr;
				return WorldBaseFloor;
			}
		}
	}
	else 
	{
		return WorldBaseFloor;
	}

	return nullptr;
}

void ARFWorldSettings::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}
