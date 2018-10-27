// Fill out your copyright notice in the Description page of Project Settings.

#include "RFPickUp.h"
#include "InteractableComp.h"

// Sets default values
ARFPickUp::ARFPickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// interactable Component
	InteractableComp = CreateDefaultSubobject<UInteractableComp>(TEXT("Interactable Component"));

}

// Called when the game starts or when spawned
void ARFPickUp::BeginPlay()
{
	Super::BeginPlay();
	
}
