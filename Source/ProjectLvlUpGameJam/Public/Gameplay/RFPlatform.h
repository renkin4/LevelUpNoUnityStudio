// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RFPlatform.generated.h"

class ARFTeleporter;
class UTextRenderComponent;
class ARFWorldSettings;

/**
 * 
 */
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

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Gameplay")
	ARFTeleporter* AttachTeleporter;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* TextRenderer;

	virtual void PostEditMove(bool bFinished) override;
	virtual void PostEditUndo() override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Gameplay")
	int32 CurrentPlatformLevel;

	virtual void CheckCurrentLevel();

	virtual void InitWorldSettings();
	
	UPROPERTY(EditAnywhere , Category = "Flags")
	uint8 bCanRandomizeSpeed : 1;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Gameplay")
	float RotateSpeed;

	FORCEINLINE AActor* GetWorldPivot() const { return WorldPivot; }

	FORCEINLINE int32 GetCurrentPlatformLevel() const { return CurrentPlatformLevel; }

	void RandomizeSpeed();

	bool CanRandomizeSpeed() const { return bCanRandomizeSpeed; }

private:
	static AActor* WorldPivot;
	
	static ARFWorldSettings* RFWorldSettingInstance;

	FVector RotatingAxis;

};
