// Fill out your copyright notice in the Description page of Project Settings.


#include "Car.h"

#include "ChaosWheeledVehicleMovementComponent.h"
#include "WheelRear.h"

ACar::ACar()
{
	Chassis = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Chassis"));
	Chassis->SetupAttachment(GetMesh());

	TireFL = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TireFrontLeft"));
	TireFL->SetupAttachment(GetMesh(), FName("VisWheel_FL"));

	TireFR = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TireFrontRight"));
	TireFR->SetupAttachment(GetMesh(), FName("VisWheel_FR"));
	TireFR->SetRelativeRotation(FRotator(0, 180, 0));

	TireRL = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TireRearLeft"));
	TireRL->SetupAttachment(GetMesh(), FName("VisWheel_BL"));

	TireRR = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TireRearRight"));
	TireRR->SetupAttachment(GetMesh(), FName("VisWheel_BR"));
	TireRR->SetRelativeRotation(FRotator(0, 180, 0));

	ChaosWheeledVehicleMovementComponent->WheelSetups.SetNum(4);

	ChaosWheeledVehicleMovementComponent->WheelSetups[0].WheelClass = UWheelFront::StaticClass();
	ChaosWheeledVehicleMovementComponent->WheelSetups[0].BoneName = FName("PhysicsWheel_FL");
	ChaosWheeledVehicleMovementComponent->WheelSetups[0].AdditionalOffset = FVector::Zero();

	ChaosWheeledVehicleMovementComponent->WheelSetups[1].WheelClass = UWheelFront::StaticClass();
	ChaosWheeledVehicleMovementComponent->WheelSetups[1].BoneName = FName("PhysicsWheel_FR");
	ChaosWheeledVehicleMovementComponent->WheelSetups[1].AdditionalOffset = FVector::Zero();

	ChaosWheeledVehicleMovementComponent->WheelSetups[2].WheelClass = UWheelRear::StaticClass();
	ChaosWheeledVehicleMovementComponent->WheelSetups[2].BoneName = FName("PhysicsWheel_BR");
	ChaosWheeledVehicleMovementComponent->WheelSetups[2].AdditionalOffset = FVector::Zero();

	ChaosWheeledVehicleMovementComponent->WheelSetups[3].WheelClass = UWheelRear::StaticClass();
	ChaosWheeledVehicleMovementComponent->WheelSetups[3].BoneName = FName("PhysicsWheel_BR");
	ChaosWheeledVehicleMovementComponent->WheelSetups[3].AdditionalOffset = FVector::Zero();
}
