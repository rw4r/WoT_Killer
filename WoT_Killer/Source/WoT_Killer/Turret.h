// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Turret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class WOT_KILLER_API UTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	void Traverse(float TraverseSpeed);

private:

	UPROPERTY(EditAnywhere, Category = Setup, meta = (ClampMin = "0", ClampMax = "45", UIMin = "0", UIMax = "45"))
		float MaxTraverseSpeed = 30;
	
};
