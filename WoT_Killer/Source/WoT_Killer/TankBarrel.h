// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class WOT_KILLER_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:

	void Elevate(float DegPerSecond);

private:
	
	UPROPERTY(EditAnywhere, Category = Setup, meta = (ClampMin = "0", ClampMax = "45", UIMin = "0", UIMax = "45"))
		float MaxDegPerSecond = 30;

	UPROPERTY(EditAnywhere, Category = Setup, meta = (ClampMin = "0", ClampMax = "45", UIMin = "0", UIMax = "45"))
		float MaxElevation = 30;

	UPROPERTY(EditAnywhere, Category = Setup, meta = (ClampMin = "0", ClampMax = "45", UIMin = "0", UIMax = "45"))
		float MaxDepression = 15;

	
};
