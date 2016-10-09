// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Place description here.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class WOT_KILLER_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float Throttle);
	
	//In Newtons
	UPROPERTY(EditDefaultsOnly, Category = Setup, meta = (ClampMin = "0", ClampMax = "999999999999", UIMin = "0", UIMax = "999999999999"))
		float TrackMaxDrivingForce = 400000;
	
};
