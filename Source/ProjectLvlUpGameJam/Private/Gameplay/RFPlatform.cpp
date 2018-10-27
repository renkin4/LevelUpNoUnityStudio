// Fill out your copyright notice in the Description page of Project Settings.

#include "RFPlatform.h"
#include "RFWorldSettings.h"
#include "RFCharacter.h"
#include "RFTeleporter.h"

#if WITH_EDITORONLY_DATA
#include "Components/TextRenderComponent.h"
#endif

AActor* ARFPlatform::WorldPivot = nullptr;

ARFWorldSettings* ARFPlatform::RFWorldSettingInstance = nullptr;

AActor* ARFPlatform::WorldBaseFloor = nullptr;

static float ImpulseForceAmount = 500.f;

// Sets default values
ARFPlatform::ARFPlatform()
{
	RotateSpeed = 30.f;
	RotatingAxis = FVector();
	CurrentPlatformLevel = 0;

	PlatformSMC = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	RootComponent = PlatformSMC;

	PrimaryActorTick.bCanEverTick = true;

#if WITH_EDITORONLY_DATA
	TextRenderer = CreateEditorOnlyDefaultSubobject<UTextRenderComponent>(TEXT("Text Renderer"));
	TextRenderer->SetupAttachment(RootComponent);
	TextRenderer->RelativeLocation = FVector().UpVector * 50.f;
#endif
}

#if WITH_EDITORONLY_DATA
void ARFPlatform::PostEditMove(bool bFinished)
{
	Super::PostEditMove(bFinished);

	CheckCurrentLevel();
}

void ARFPlatform::PostEditUndo()
{
	Super::PostEditUndo();

	CheckCurrentLevel();
}

void ARFPlatform::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	const FName & PropertyName =( PropertyChangedEvent.Property != NULL )? PropertyChangedEvent.GetPropertyName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(ARFPlatform, AttachTeleporter)) 
	{
		if (AttachTeleporter != nullptr) 
		{
			AttachTeleporter->AttachedPlatform = this;
			AttachTeleporter->TeleportTo(GetActorLocation(), GetActorRotation());
		}
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void ARFPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARFPlatform::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	InitWorldSettings();
	CheckCurrentLevel();
}

void ARFPlatform::CheckCurrentLevel()
{
	if (RFWorldSettingInstance
		&& RFWorldSettingInstance->WorldBaseFloor)
	{
		const float BaseFloorHeight = RFWorldSettingInstance->WorldBaseFloor->GetActorLocation().Z;

		CurrentPlatformLevel = FMath::Max(FMath::FloorToInt((GetActorLocation().Z - BaseFloorHeight) / RFWorldSettingInstance->DistanceBetweenPlatformLevels), 0);
	}
	else 
	{
		InitWorldSettings();
	}

#if WITH_EDITORONLY_DATA
	const FString CurrentLevelString = FString::Printf(TEXT("%d"), CurrentPlatformLevel);
	TextRenderer->SetText(FText::FromString(CurrentLevelString));
#endif
}

void ARFPlatform::InitWorldSettings()
{
	UWorld* const World = GetWorld();

	if (World)
	{
		RFWorldSettingInstance = CastChecked<ARFWorldSettings>(World->GetWorldSettings());
		WorldPivot = RFWorldSettingInstance->WorldPivot;
		WorldBaseFloor = RFWorldSettingInstance->WorldBaseFloor;

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
	const FVector NextLocation = GetActorLocation().RotateAngleAxis(RotateSpeed * DeltaTime, RotatingAxis.GetSafeNormal());
	// Copy A new Rotation into Teleportation Logic
	const FRotator NextRotation = FRotationMatrix::MakeFromX(RotatingAxis - GetActorLocation()).Rotator();
	
	FHitResult HitResult(ForceInit);

	SetActorRotation(NextRotation, ETeleportType::TeleportPhysics);

	SetActorLocation(NextLocation, true, &HitResult);

	if (HitResult.bBlockingHit
		&& !FMath::IsNearlyEqual(HitResult.ImpactNormal.Z,FVector().UpVector.Z * -1, 0.1f))
	{
		ARFCharacter* const Character = Cast<ARFCharacter>(HitResult.GetActor());

		if (IsValid(Character)) 
		{
			Character->LaunchCharacter((NextLocation- PreviousLocation).GetSafeNormal() * ImpulseForceAmount, true, false);
		}

		RotateSpeed *= -1.f;
	}
}
