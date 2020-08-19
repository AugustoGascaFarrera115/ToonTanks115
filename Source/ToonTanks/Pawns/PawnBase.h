// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"


class UCapsuleComponent;
class AProjectileBase;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()



private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Capsule Component",meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Mesh Component",meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMeshComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Mesh Component",meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMeshComponent;

	//COMPONENT VISUAL FACILMENTE EDITABLE
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Projectile Spawn",meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Projectile Class Reference",meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AProjectileBase> ProjectileClassRef;


public:

	APawnBase();


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	virtual void Fire();


	virtual void HandleDestruction();

	virtual void RotateTurretFunction(FVector LookAtTarget);

	

};
