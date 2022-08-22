// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "RedDoorComponent.h"
#include "RedDoor.generated.h"


class UDoorInteractionComponent;

UCLASS()
class ABSTRACTION_API ARedDoor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	ARedDoor();
protected:
	UPROPERTY(EditAnywhere, NoClear);
	URedDoorComponent* RedDoorComponent;
};


