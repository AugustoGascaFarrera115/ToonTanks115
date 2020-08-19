// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComponent;


	BaseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMeshComponent->SetupAttachment(RootComponent);

	TurretMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMeshComponent->SetupAttachment(BaseMeshComponent);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMeshComponent);


}

// Called when the game starts or when spawned
void APawnBase::BeginPlay()
{
	Super::BeginPlay();

}

void APawnBase::Fire()
{
	//get projectile spawn location && Rotation 
	UE_LOG(LogTemp, Warning, TEXT("fIRE function succesfully !!!!"));
}

void APawnBase::HandleDestruction()
{
}

void APawnBase::RotateTurretFunction(FVector LookAtTarget)
{

	//update turret mesh rotation  to face towards the lookattarget passes in from child classes


	//turret mesh setworldRotation()...


	FVector LookAtTargetClean = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMeshComponent->GetComponentLocation().Z);
	FVector StartLocation = TurretMeshComponent->GetComponentLocation();

	FRotator TurretRotation = FVector(LookAtTarget - StartLocation).Rotation();


	//turret prepared to rotate to the player
	TurretMeshComponent->SetWorldRotation(TurretRotation);

}

// Called every frame
void APawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

// Called to bind functionality to input
void APawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}





