// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"


class UProjectileMovementComponent;

UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()


private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Component", meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement115;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Component", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* ProjectileMeshComponent;
	
	UPROPERTY(EditDefaultsOnly,Category = "Projectile Damage")
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Movement", meta = (AllowPrivateAccess = "true"))
		float MovementSpeed = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Damage", meta = (AllowPrivateAccess = "true"))
		float Damage = 100.0f;


	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Sets default values for this actor's properties
	AProjectileBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

};
