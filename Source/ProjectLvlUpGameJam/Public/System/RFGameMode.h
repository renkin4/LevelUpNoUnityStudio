// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "RFGameMode.generated.h"

class ARFWorldSettings;

/**
 * 
 */
UCLASS()
class PROJECTLVLUPGAMEJAM_API ARFGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Gameplay")
	ARFWorldSettings* GetRFWorldSettings() const;

};
