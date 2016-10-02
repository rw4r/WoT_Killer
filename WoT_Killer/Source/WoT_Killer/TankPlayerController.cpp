// Fill out your copyright notice in the Description page of Project Settings.

#include "WoT_Killer.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s"), *ControlledTank->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //OUT param
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//Find the crosshair position
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto CrosshairScreenLocation = FVector2D(ViewPortSizeX * CrossHairX, ViewPortSizeY * CrossHairY);
	FVector LookDirection;
	//Deproject
	if (GetLookDirection(CrosshairScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D CrosshairScreenLocation, FVector& LookDirection) const
{
	
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(CrosshairScreenLocation.X, CrosshairScreenLocation.Y, CameraWorldLocation, LookDirection);
		
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}
