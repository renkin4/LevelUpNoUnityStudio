// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "RFPlatformManager.generated.h"

class ARFWorldSettings;

/**
 * 
 */
UCLASS()
class PROJECTLVLUPGAMEJAM_API ARFPlatformManager : public AInfo
{
	GENERATED_BODY()
	
public:
	ARFPlatformManager();
	
	/**  */
	UFUNCTION(CallInEditor, Category = "Debug")
	void DisplayPlatformLevels();
	
	/**  */
	virtual void PostInitializeComponents() override;

	/**  */
	virtual void OnConstruction(const FTransform& Transform) override;

#if WITH_EDITOR
#endif

private:
	static ARFWorldSettings*  WorldSettingInstance;
};
