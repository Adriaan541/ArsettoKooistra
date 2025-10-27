// Fill out your copyright notice in the Description page of Project Settings.


#include "CarPawn.h"

#include "WheelFront.h"
#include "EnhancedInputComponent.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"



ACarPawn::ACarPawn()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring arm component"));
	SpringArmComponent->SetupAttachment(GetMesh());

	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetCollisionProfileName(FName("Car"));

	ChaosWheeledVehicleMovementComponent = CastChecked<UChaosWheeledVehicleMovementComponent>(GetVehicleMovement());
}

void ACarPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EIC->BindAction(HandbrakeAction, ETriggerEvent::Started, this, &ACarPawn::StartHandbrake);
		EIC->BindAction(HandbrakeAction, ETriggerEvent::Completed, this, &ACarPawn::StopHandbrake);

		EIC->BindAction(GearUpChangeAction, ETriggerEvent::Triggered, this, &ACarPawn::GearUpChange);
		EIC->BindAction(GearDownChangeAction, ETriggerEvent::Triggered, this, &ACarPawn::GearDownChange);

		EIC->BindAction(ThrottleAction, ETriggerEvent::Triggered, this, &ACarPawn::Throttle);
		EIC->BindAction(BrakeAction, ETriggerEvent::Triggered, this, &ACarPawn::Brake);
		
		EIC->BindAction(CameraLookAction, ETriggerEvent::Triggered, this, &ACarPawn::CameraLook);
	}
}

void ACarPawn::StartHandbrake(const FInputActionValue& value)
{
}

void ACarPawn::StopHandbrake(const FInputActionValue& value)
{
}

void ACarPawn::GearUpChange(const FInputActionValue& value)
{
}

void ACarPawn::GearDownChange(const FInputActionValue& value)
{
}

void ACarPawn::Throttle(const FInputActionValue& value)
{
}

void ACarPawn::Brake(const FInputActionValue& value)
{
}

void ACarPawn::CameraLook(const FInputActionValue& value)
{
}