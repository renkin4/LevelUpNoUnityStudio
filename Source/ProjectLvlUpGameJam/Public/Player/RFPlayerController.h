// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RFPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTLVLUPGAMEJAM_API ARFPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Gameplay")
	int32 GetAmountOfDeath() const { return AmountOfDeath; }

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void ResetAmountOfDeath();

	UPROPERTY(BlueprintReadOnly, Category = "")
	int32 AmountOfDeathInThisLevel;

protected:
	virtual void UnFreeze() override;

public:
	static int32 AmountOfDeath;

};
