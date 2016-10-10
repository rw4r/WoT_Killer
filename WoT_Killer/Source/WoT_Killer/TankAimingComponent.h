// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked

};

class UTankBarrel; //Forward Declaration
class UTurret;
class AProjectile;

//Holds barrel's properties.
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WOT_KILLER_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadonly, Category = "State")
		EFiringState FiringState = EFiringState::Reloading;

public:	

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialize(UTankBarrel* BarrelToSet, UTurret* TurretToSet);

	virtual void BeginPlay() override;
	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Fire Control")
		void Fire();

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UTankBarrel* Barrel = nullptr;
	UTurret* Turret = nullptr;

	void AimBarrel(FVector AimDirection);

	//Reload Time
	UPROPERTY(EditDefaultsOnly, Category = Firing, meta = (ClampMin = "0", ClampMax = "720", UIMin = "0", UIMax = "720"))
		float ReloadTime = 5;

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	//Projectile Speed
	UPROPERTY(EditAnywhere, Category = Firing, meta = (ClampMin = "0", ClampMax = "1000000", UIMin = "0", UIMax = "1000000"))
		float LaunchSpeed = 100000;

	double LastFireTime = 0;

	bool IsBarrelMoving();

	FVector AimDirection;
};






