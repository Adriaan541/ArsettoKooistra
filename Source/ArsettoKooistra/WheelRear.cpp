// Fill out your copyright notice in the Description page of Project Settings.


#include "WheelRear.h"

UWheelRear::UWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}
