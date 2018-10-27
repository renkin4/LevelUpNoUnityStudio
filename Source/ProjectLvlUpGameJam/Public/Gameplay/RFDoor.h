// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RFDoor.generated.h"

class UInstantInteractableComp;

/**
 * 
 */
UCLASS()
class PROJECTLVLUPGAMEJAM_API ARFDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARFDoor();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* DoorSMC;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Interact", meta = (AllowPrivateAccess = "true"))
	UInstantInteractableComp *  InteractableComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
};
