// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RFPickUp.generated.h"

class UInstantInteractableComp;
class UBoxComponent;

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

	/**  */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Interact", meta = (AllowPrivateAccess = "true"))
	UInstantInteractableComp* InteractableComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* PickUPSMC;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Root", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* RootBox;

};
