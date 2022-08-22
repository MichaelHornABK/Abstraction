// Fill out your copyright notice in the Description page of Project Settings.


#include "RedKeyTrigger.h"
#include "Engine/TriggerBox.h"
#include "Engine/World.h"

// Sets default values for this component's properties
URedKeyTrigger::URedKeyTrigger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URedKeyTrigger::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void URedKeyTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (TriggerBox && GetWorld() && GetWorld()->GetFirstLocalPlayerFromController())
	{
		APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		if (PlayerPawn && TriggerBox->IsOverlappingActor(PlayerPawn) && !PlayerPawn->Tags.Contains("RedKey"))
		{
			PlayerPawn->Tags.Add("RedKey");
		}
	}

	// ...
}

