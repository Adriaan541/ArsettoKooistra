// Fill out your copyright notice in the Description page of Project Settings.


#include "ArsettoKooistraGameMode.h"

#include "Car.h"
#include "Kismet/GameplayStatics.h"

void AArsettoKooistraGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	{
		Car = Cast<ACar>(PlayerPawn);
		if (!Car)
		{
			UE_LOG(LogTemp, Error, TEXT("%s is not a car"), *Car->GetActorNameOrLabel());
		}
	}
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
}
