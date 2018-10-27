// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RFPickUp.generated.h"

class UInteractableComp;

UCLASS()
class PROJECTLVLUPGAMEJAM_API ARFPickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARFPickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Interact", meta = (AllowPrivateAccess = "true"))
	UInteractableComp* InteractableComp;

	
};
