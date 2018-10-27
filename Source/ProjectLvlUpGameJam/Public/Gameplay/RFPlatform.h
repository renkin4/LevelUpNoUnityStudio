// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RFPlatform.generated.h"

UCLASS()
class PROJECTLVLUPGAMEJAM_API ARFPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARFPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

	UFUNCTION(BlueprintPure, Category = "World", meta = (DisplayName = "Get World Pivot"))
	AActor* K2_GetWorldPivot() const { return GetWorldPivot(); }
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* PlatformSMC;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Gameplay")
	float RotateSpeed;

	FORCEINLINE AActor* GetWorldPivot() const { return WorldPivot; }

private:
	static AActor* WorldPivot;
	
	FVector RotatingAxis;

};
