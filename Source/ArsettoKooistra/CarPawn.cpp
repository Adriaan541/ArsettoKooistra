// Fill out your copyright notice in the Description page of Project Settings.


#include "CarPawn.h"

#include "WheelFront.h"
#include "EnhancedInputComponent.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"



ACarPawn::ACarPawn()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetMesh());
	SpringArmComponent->TargetArmLength = 500.0f;
	SpringArmComponent->SocketOffset.Z = 180.0f;
	SpringArmComponent->bInheritPitch = false;
	SpringArmComponent->bInheritRoll = false;
	SpringArmComponent->bEnableCameraRotationLag = true;
	SpringArmComponent->CameraLagSpeed = 1.0f;
	SpringArmComponent->CameraLagMaxDistance = 100.0f;
	SpringArmComponent->bAutoActivate = true;
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetCollisionProfileName(FName("Car"));

	ChaosWheeledVehicleMovementComponent = CastChecked<UChaosWheeledVehicleMovementComponent>(GetVehicleMovement());
}

void ACarPawn::SetupPlayerInputComponent(UInputComponent* Input)
{
	Super::SetupPlayerInputComponent(Input);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(Input))
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

void ACarPawn::StartHandbrake(const FInputActionValue& Value)
{
}

void ACarPawn::StopHandbrake(const FInputActionValue& Value)
{
}

void ACarPawn::GearUpChange(const FInputActionValue& Value)
{
}

void ACarPawn::GearDownChange(const FInputActionValue& Value)
{
}

void ACarPawn::Throttle(const FInputActionValue& Value)
{
}

void ACarPawn::Brake(const FInputActionValue& Value)
{
}

void ACarPawn::CameraLook(const FInputActionValue& Value)
{
}