// Fill out your copyright notice in the Description page of Project Settings.

#include "WoT_Killer.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ContrlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		ContrlledTank->AimAt(PlayerTank->GetActorLocation());
		ContrlledTank->Fire();
	}
	else { return; }
}
