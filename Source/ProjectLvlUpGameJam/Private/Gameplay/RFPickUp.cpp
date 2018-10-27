// Fill out your copyright notice in the Description page of Project Settings.

#include "RFPickUp.h"
#include "InstantInteractableComp.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ARFPickUp::ARFPickUp()
{
	RootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Root"));
	RootBox->SetCanEverAffectNavigation(false);
	RootBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	RootBox->SetGenerateOverlapEvents(false);
	RootBox->InitBoxExtent(FVector().OneVector * 150.f);
	RootComponent = RootBox;

	PickUPSMC = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	PickUPSMC->SetCanEverAffectNavigation(false);
	PickUPSMC->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	PickUPSMC->SetGenerateOverlapEvents(false);
	PickUPSMC->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	PickUPSMC->SetupAttachment(RootComponent);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// interactable Component
	InteractableComp = CreateDefaultSubobject<UInstantInteractableComp>(TEXT("Interactable Component"));
}

// Called when the game starts or when spawned
void ARFPickUp::BeginPlay()
{
	Super::BeginPlay();
	
}
