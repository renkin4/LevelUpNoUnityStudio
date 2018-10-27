// Fill out your copyright notice in the Description page of Project Settings.

#include "RFDoor.h"
#include "InstantInteractableComp.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARFDoor::ARFDoor()
{
	DoorSMC = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	DoorSMC->SetCanEverAffectNavigation(false);
	DoorSMC->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	DoorSMC->SetGenerateOverlapEvents(false);
	DoorSMC->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	RootComponent = DoorSMC;

	InteractableComp = CreateDefaultSubobject<UInstantInteractableComp>(TEXT("Interactable Comp"));

	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ARFDoor::BeginPlay()
{
	Super::BeginPlay();
	
}
