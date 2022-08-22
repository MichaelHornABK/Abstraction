// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GoldKeyTrigger.generated.h"

class ATriggerBox;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ABSTRACTION_API UGoldKeyTrigger : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGoldKeyTrigger();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere);
	ATriggerBox* TriggerBox;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
