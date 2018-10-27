// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "RFPlatformManager.generated.h"

class ARFWorldSettings;
class ARFPlatform;

USTRUCT(BlueprintType)
struct FPlaformInfo 
{
	GENERATED_USTRUCT_BODY()

public:
	FPlaformInfo() 
	{
		AllRFPlatforms = TArray<ARFPlatform*>();
		AllRFPlatforms.Reserve(5);
	}

	UPROPERTY(VisibleAnywhere, Transient, Category = "Platforms")
	TArray<ARFPlatform*> AllRFPlatforms;
};

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class PROJECTLVLUPGAMEJAM_API ARFPlatformManager : public AInfo
{
	GENERATED_BODY()
	
public:
	ARFPlatformManager();
	
	/**  */
	UFUNCTION(CallInEditor, Category = "Platforms")
	void DisplayPlatformLevels();
	
	/**  */
	virtual void PostInitializeComponents() override;

	/**  */
	virtual void OnConstruction(const FTransform& Transform) override;

	/** Levels */
	UPROPERTY(EditAnywhere , Category = "Platforms", AdvancedDisplay)
	TMap<uint8, FPlaformInfo> RFPlatforms;

	UPROPERTY(EditAnywhere, Category = "Platforms")
	uint8 AmountOfPlatformPerLevel;

protected:


private:
	static ARFWorldSettings*  WorldSettingInstance;
};
