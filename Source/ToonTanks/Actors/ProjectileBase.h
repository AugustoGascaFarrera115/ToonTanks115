// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"


class UProjctileMovementComponent;

UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()


private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Component", meta = (AllowPrivateSAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement115;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Component", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* ProjectileMeshComponent;
	
	UPROPERTY(EditDefaultsOnly,Category = "Projectile Damage")
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateSAcess = "true"))
		float MovementSpeed = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateSAcess = "true"))
		float Damage = 100.0f;

public:	
	// Sets default values for this actor's properties
	AProjectileBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

};
