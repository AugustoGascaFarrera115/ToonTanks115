// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

/**
 * 
 */

class APawnTank;



UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()


private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret Component", meta = (AllowPrivateAccess = "true"))
		float FireRate = 2.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret Component", meta = (AllowPrivateAccess = "true"))
		float FireRange = 500.0f;


	APawnTank* PlayerPawn;


	FTimerHandle FireRateTimerHandle;

	UFUNCTION()
	void CheckFireCondition();


	UFUNCTION()
		float ReturnDistanceToPlayer();


public:

	APawnTurret();

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

	virtual void HandleDestruction() override;


	
};
