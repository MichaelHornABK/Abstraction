// Fill out your copyright notice in the Description page of Project Settings.


#include "GoldDoor.h"

AGoldDoor::AGoldDoor()
{
	GoldDoorComponent = CreateDefaultSubobject<UGoldDoorComponent>(TEXT("GoldDoorComponent"));
}