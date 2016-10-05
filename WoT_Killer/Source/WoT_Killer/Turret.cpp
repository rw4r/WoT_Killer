// Fill out your copyright notice in the Description page of Project Settings.

#include "WoT_Killer.h"
#include "Turret.h"




void UTurret::Traverse(float TraverseSpeed)
{
	TraverseSpeed = FMath::Clamp<float>(TraverseSpeed, -1, +1);

	auto RotationChange = TraverseSpeed * MaxTraverseSpeed * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}

