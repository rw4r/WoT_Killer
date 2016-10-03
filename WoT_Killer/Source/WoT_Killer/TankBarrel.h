// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS()
class WOT_KILLER_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:

	void Elevate(float DegPerSecond);

private:
	
	UPROPERTY(EditAnywhere)
	float MaxDegPerSecond = 20;
	
};
