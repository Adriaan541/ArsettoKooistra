// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CarPawn.h"
#include "Car.generated.h"

/**
 * 
 */
UCLASS()
class ARSETTOKOOISTRA_API ACar : public ACarPawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Chassis;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TireFL;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TireFR;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TireRL;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TireRR;

public:
	ACar();
};
