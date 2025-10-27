// Fill out your copyright notice in the Description page of Project Settings.


#include "WheelFront.h"

UWheelFront::UWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 50.0f;
}
