// Fill out your copyright notice in the Description page of Project Settings.

#include "RFPlatform.h"
#include "RFWorldSettings.h"
#include "RFCharacter.h"

AActor* ARFPlatform::WorldPivot = nullptr;

static float ImpulseForceAmount = 500.f;

// Sets default values
ARFPlatform::ARFPlatform()
{
	RotateSpeed = 1.f;
	RotatingAxis = FVector();

	PlatformSMC = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	RootComponent = PlatformSMC;

	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARFPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARFPlatform::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UWorld* const World = GetWorld();

	if (World) 
	{
		WorldPivot = CastChecked<ARFWorldSettings>(World->GetWorldSettings())->WorldPivot;

		if (WorldPivot) 
		{
			RotatingAxis = FVector(WorldPivot->GetActorLocation().X, WorldPivot->GetActorLocation().Y, GetActorLocation().Z);
		}
	}
	
}

// Called every frame
void ARFPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector PreviousLocation = GetActorLocation();
	// Copy the current loc to Next
	const FVector NextLocation = GetActorLocation().RotateAngleAxis(RotateSpeed, RotatingAxis.GetSafeNormal());
	// Copy A new Rotation into Teleportation Logic
	const FRotator NextRotation = FRotationMatrix::MakeFromX(RotatingAxis - GetActorLocation()).Rotator();
	
	FHitResult HitResult(ForceInit);

	SetActorRotation(NextRotation, ETeleportType::TeleportPhysics);

	SetActorLocation(NextLocation, true, &HitResult);

	if (HitResult.bBlockingHit) 
	{
		
		ARFCharacter* const Character = Cast<ARFCharacter>(HitResult.GetActor());

		if (IsValid(Character)) 
		{
			Character->LaunchCharacter((NextLocation- PreviousLocation).GetSafeNormal() * ImpulseForceAmount, true, false);
		}
	}
}
