// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RFTeleporter.generated.h"

class ARFPlatform;

/**
 * 
 */
UCLASS()
class PROJECTLVLUPGAMEJAM_API ARFTeleporter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARFTeleporter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, Transient, Category = "Gameplay")
	ARFPlatform* AttachedPlatform;
	
};
