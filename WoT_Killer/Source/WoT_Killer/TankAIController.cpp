// Fill out your copyright notice in the Description page of Project Settings.

#include "WoT_Killer.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	auto PlayerTank = GetPlayerTank();

	/*
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cant find Player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found Player Tank: %s"), *PlayerTank->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("AIController BeginPlay"));
	*/
}


ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { 
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
