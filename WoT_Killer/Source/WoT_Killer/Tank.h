// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"	//paste new classes above


class UTankBarrel;
class UTankAimingComponent;
class UTankMovementComponent;
class UTurret;
class AProjectile;

UCLASS()
class WOT_KILLER_API ATank : public APawn
{
	GENERATED_BODY()

public:

	void AimAt(FVector HitLocation);


	UFUNCTION(BlueprintCallable, Category = "Fire Control")
		void Fire();

protected:

	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	//Projectile Speed
	UPROPERTY(EditAnywhere, Category = Firing, meta = (ClampMin = "0", ClampMax = "1000000", UIMin = "0", UIMax = "1000000"))
		float LaunchSpeed = 100000; 

	//Reload Time
	UPROPERTY(EditDefaultsOnly, Category = Firing, meta = (ClampMin = "0", ClampMax = "720", UIMin = "0", UIMax = "720"))
		float ReloadTime = 5;

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	double LastFireTime = 0;

	UTankBarrel* Barrel = nullptr;

};
