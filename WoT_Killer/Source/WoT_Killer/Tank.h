// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"	//paste new classes above


class UTankBarrel;
class UTurret;
class AProjectile;

UCLASS()
class WOT_KILLER_API ATank : public APawn
{
	GENERATED_BODY()

public:


	UFUNCTION(BlueprintCallable, Category = "Fire Control")
		void Fire();

protected:

	virtual void BeginPlay() override;


private:
	// Sets default values for this pawn's properties
	ATank();

	//Reload Time
	UPROPERTY(EditDefaultsOnly, Category = Firing, meta = (ClampMin = "0", ClampMax = "720", UIMin = "0", UIMax = "720"))
		float ReloadTime = 5;

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	//Projectile Speed
	UPROPERTY(EditAnywhere, Category = Firing, meta = (ClampMin = "0", ClampMax = "1000000", UIMin = "0", UIMax = "1000000"))
		float LaunchSpeed = 100000;

	double LastFireTime = 0;

	UTankBarrel* Barrel = nullptr;

};
