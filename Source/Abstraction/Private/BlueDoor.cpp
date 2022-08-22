// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueDoor.h"

ABlueDoor::ABlueDoor()
{
	BlueDoorComponent = CreateDefaultSubobject<UBlueDoorComponent>(TEXT("BlueDoorComponent"));
}