// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "GoldDoorComponent.h"
#include "GoldDoor.generated.h"


class UDoorInteractionComponent;

UCLASS()
class ABSTRACTION_API AGoldDoor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AGoldDoor();
protected:
	UPROPERTY(EditAnywhere, NoClear);
	UGoldDoorComponent* GoldDoorComponent;
};


