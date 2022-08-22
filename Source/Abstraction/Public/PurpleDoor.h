// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "PurpleDoorComponent.h"
#include "PurpleDoor.generated.h"


class UDoorInteractionComponent;

UCLASS()
class ABSTRACTION_API APurpleDoor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	APurpleDoor();
protected:
	UPROPERTY(EditAnywhere, NoClear);
	UPurpleDoorComponent* PurpleDoorComponent;
};


