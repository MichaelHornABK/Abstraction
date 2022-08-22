// Fill out your copyright notice in the Description page of Project Settings.


#include "RedDoor.h"

ARedDoor::ARedDoor()
{
	RedDoorComponent = CreateDefaultSubobject<URedDoorComponent>(TEXT("RedDoorComponent"));
}