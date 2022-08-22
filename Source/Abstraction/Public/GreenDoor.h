// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "GreenDoorComponent.h"
#include "GreenDoor.generated.h"


class UDoorInteractionComponent;

UCLASS()
class ABSTRACTION_API AGreenDoor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AGreenDoor();
protected:
	UPROPERTY(EditAnywhere, NoClear);
	UGreenDoorComponent* GreenDoorComponent;
};


