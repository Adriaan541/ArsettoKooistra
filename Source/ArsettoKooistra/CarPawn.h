// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "WheelFront.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "CarPawn.generated.h"

class UInputMappingContext;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class ARSETTOKOOISTRA_API ACarPawn : public AWheeledVehiclePawn
{
	GENERATED_BODY()

protected:
	void StartHandbrake(const FInputActionValue& value);
	void StopHandbrake(const FInputActionValue& value);

	void GearUpChange(const FInputActionValue& value);
	void GearDownChange(const FInputActionValue& value);

	void Throttle(const FInputActionValue& value);

	void Brake(const FInputActionValue& value);

	void CameraLook(const FInputActionValue& value);
	

public:
	ACarPawn();

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* HandbrakeAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* GearUpChangeAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* GearDownChangeAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* ThrottleAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* BrakeAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* CameraLookAction;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditAnywhere)
	UCameraComponent* CameraComponent;

	TObjectPtr<UChaosWheeledVehicleMovementComponent> ChaosWheeledVehicleMovementComponent;
};
