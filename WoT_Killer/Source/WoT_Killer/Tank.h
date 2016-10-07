// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"	//paste new classes above


class UTankBarrel;
class UTankAimingComponent;
class UTurret;
class AProjectile;

UCLASS()
class WOT_KILLER_API ATank : public APawn
{
	GENERATED_BODY()

public:

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Fire Control")
		void Fire();

protected:

	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//Projectile Speed
	UPROPERTY(EditAnywhere, Category = Firing, meta = (ClampMin = "0", ClampMax = "1000000", UIMin = "0", UIMax = "1000000"))
		float LaunchSpeed = 100000; 

	//Reload Time
	UPROPERTY(EditDefaultsOnly, Category = Firing, meta = (ClampMin = "0", ClampMax = "720", UIMin = "0", UIMax = "720"))
		float ReloadTime = 5;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	//Local Barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;

};
