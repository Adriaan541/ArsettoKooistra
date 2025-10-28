// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Car.h"
#include "GameFramework/GameModeBase.h"
#include "ArsettoKooistraGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ARSETTOKOOISTRA_API AArsettoKooistraGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	ACar* Car;
};
