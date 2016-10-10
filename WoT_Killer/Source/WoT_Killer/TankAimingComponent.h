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

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;
	UTurret* Turret = nullptr;

	void AimBarrel(FVector AimDirection);

	//Projectile Speed
	UPROPERTY(EditAnywhere, Category = Firing, meta = (ClampMin = "0", ClampMax = "1000000", UIMin = "0", UIMax = "1000000"))
		float LaunchSpeed = 100000;
	
};
