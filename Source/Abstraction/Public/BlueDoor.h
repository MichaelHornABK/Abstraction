// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "BlueDoorComponent.h"
#include "BlueDoor.generated.h"


class UDoorInteractionComponent;

UCLASS()
class ABSTRACTION_API ABlueDoor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	ABlueDoor();
protected:
	UPROPERTY(EditAnywhere, NoClear);
	UBlueDoorComponent* BlueDoorComponent;
};


