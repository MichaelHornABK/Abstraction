// Fill out your copyright notice in the Description page of Project Settings.


#include "PurpleDoor.h"

APurpleDoor::APurpleDoor()
{
	PurpleDoorComponent = CreateDefaultSubobject<UPurpleDoorComponent>(TEXT("PurpleDoorComponent"));
}