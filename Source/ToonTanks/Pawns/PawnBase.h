// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"


class UCapsuleComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()



private:
	UPROPERTY(VisibleAnywhere, Category = "Capsule Component",meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere, Category = "Mesh Component",meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Mesh Component",meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Projectile Spawn",meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;
	//COMPONENT VISUAL FACILMENTE EDITABLE

public:
	// Sets default values for this pawn's properties
	APawnBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

};
