// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


APawnTank::APawnTank()
{
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArmComponent->SetupAttachment(RootComponent);


    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void APawnTank::BeginPlay()
{
	Super::BeginPlay();

    PlayerControllerReference = Cast<APlayerController>(GetController());
	
}

void APawnTank::HandleDestruction()
{
    Super::HandleDestruction();
}

// Called every frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    Rotate();
    Move();


    if (PlayerControllerReference)
    {
        FHitResult TraceHitResult;
        PlayerControllerReference->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, TraceHitResult);
        FVector HitLocation = TraceHitResult.ImpactPoint;

        RotateTurretFunction(HitLocation);


        //GLog->Log("Vector actor hit: %s" + HitLocation.ToString());

    }



}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward",this,&APawnTank::CalculateMoveInput);
    PlayerInputComponent->BindAxis("Turn",this,&APawnTank::CalculateRotationInput);
    PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &APawnTank::Fire);

}
void APawnTank::CalculateMoveInput(float Value) 
{
    MoveDirection = FVector(Value * MoveSpeed * GetWorld()->DeltaTimeSeconds,0,0);
}

void APawnTank::CalculateRotationInput(float Value) 
{
    float RotateAmount = Value * RotateSpeed * GetWorld()->DeltaTimeSeconds;
    FRotator Rotation = FRotator(0,RotateAmount,0);
    RotationDirection = FQuat(Rotation);
}

void APawnTank::Move() 
{
    AddActorLocalOffset(MoveDirection,true);
}

void APawnTank::Rotate() 
{
    AddActorLocalRotation(RotationDirection,true);
}
