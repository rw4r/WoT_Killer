// Fill out your copyright notice in the Description page of Project Settings.

#include "WoT_Killer.h"
#include "TankBarrel.h"




void UTankBarrel::Elevate(float DegPerSecond)
{
	DegPerSecond = FMath::Clamp<float>(DegPerSecond, -1, +1);

	auto ElevationChange = DegPerSecond * MaxDegPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto Elevation = FMath::Clamp<float>(RawNewElevation, MaxDepression, MaxElevation);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}