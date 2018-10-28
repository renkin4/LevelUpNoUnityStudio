// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "RFWorldSettings.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTLVLUPGAMEJAM_API ARFWorldSettings : public AWorldSettings
{
	GENERATED_BODY()
	
public:
	ARFWorldSettings();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Gameplay")
	int32 LevelRoundTime;

	/** Pivot */
	UPROPERTY(EditInstanceOnly , Category = "Gameplay")
	AActor* WorldPivot;
	
	/** Distance between Levels */
	UPROPERTY(EditInstanceOnly, Category = "Gameplay", AdvancedDisplay)
	float DistanceBetweenPlatformLevels;

	/** Base Floor for calculating Distance for next level */
	UPROPERTY(EditInstanceOnly, Category = "Gameplay", AdvancedDisplay)
	AActor* WorldBaseFloor;

	/** Maximum Height */
	UPROPERTY(EditInstanceOnly, Category = "Gameplay", AdvancedDisplay)
	AActor* WorldBaseCeiling;

	AActor* GetBaseFloor();



protected:
	virtual void PostInitializeComponents() override;

};
