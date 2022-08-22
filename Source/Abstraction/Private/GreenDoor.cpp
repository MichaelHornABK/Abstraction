// Fill out your copyright notice in the Description page of Project Settings.


#include "GreenDoor.h"

AGreenDoor::AGreenDoor()
{
	GreenDoorComponent = CreateDefaultSubobject<UGreenDoorComponent>(TEXT("GreenDoorComponent"));
}