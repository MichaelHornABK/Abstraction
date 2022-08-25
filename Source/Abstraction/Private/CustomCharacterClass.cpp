// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomCharacterClass.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/DamageType.h"
#include "MyHealthComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/InputComponent.h"
#include "DamageHandlerComponent.h"

// Sets default values
ACustomCharacterClass::ACustomCharacterClass(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<UMyHealthComponent>(TEXT("HealthComponent"));
	DamageHandlerComponent = CreateDefaultSubobject<UDamageHandlerComponent>(TEXT("DamageHandlerComponent"));
	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
	ParticleSystemComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACustomCharacterClass::BeginPlay()
{
	Super::BeginPlay();
	//use possess/unpossess
	PC = GetWorld()->GetFirstPlayerController();
}

// Called every frame
void ACustomCharacterClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACustomCharacterClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	FInputActionBinding* Binding;
	//these functions fire off events
	//interaction component listens to them
	Binding = &PlayerInputComponent->BindAction(FName("InteractionStart"), IE_Pressed, this, &ACustomCharacterClass::InteractionStartRequested);
	Binding = &PlayerInputComponent->BindAction(FName("InteractionCancel"), IE_Pressed, this, &ACustomCharacterClass::InteractionCancelRequested);
}

void  ACustomCharacterClass::FellOutOfWorld(const UDamageType& dmgType)
{
	HealthComponent->SetCurrentHealth(0.0f);
	OnDeath(true);
}

float ACustomCharacterClass::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float Damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	UE_LOG(LogTemp, Warning, TEXT("ACustomCharacterClass::TakeDamage Damage %.2f"), Damage);
	if (HealthComponent && !HealthComponent->IsDead())
	{
		HealthComponent->TakeDamage(Damage);
		if (HealthComponent->IsDead())
		{
			OnDeath(false);
		}
	}
	return Damage;
}

const bool ACustomCharacterClass::IsAlive() const
{
	if (HealthComponent)
	{
		return !HealthComponent->IsDead();
	}
	return false;
}

const float ACustomCharacterClass::GetCurrentHealth() const
{
	if (HealthComponent)
	{
		return HealthComponent->GetCurrentHealth();
	}
	return 0.0f;
}

void ACustomCharacterClass::SetOnFire(float BaseDamage, float DamageTotalTime, float TakeDamageInterval)
{
	if (DamageHandlerComponent)
	{
		DamageHandlerComponent->TakeFireDamage(BaseDamage, DamageTotalTime, TakeDamageInterval);
	}
}

void ACustomCharacterClass::OnDeath(bool IsFellOut)
{
	GetWorld()->GetTimerManager().SetTimer(RestartLevelTimerHandle, this, &ACustomCharacterClass::OnDeathTimerFinished, TimeRestartLevelAfterDeath, false);
}

void ACustomCharacterClass::OnDeathTimerFinished()
{
	APlayerController* PlayerController = GetController<APlayerController>();
	if (PlayerController)
	{
		PlayerController->RestartLevel();
	}
}

void ACustomCharacterClass::InteractionStartRequested()
{
	OnInteractionStartRequested.Broadcast();
}

void ACustomCharacterClass::InteractionCancelRequested()
{
	OnInteractionCancelRequested.Broadcast();
}

void ACustomCharacterClass::HandleItemCollected()
{
	ItemsCollected++;
	// Play Effects here.
	//PC->PlayerCameraManager->PlayCameraShake(CamShake, 1.0f);
	PC->PlayDynamicForceFeedback(ForceFeedbackIntensity, ForceFeedbackDuration, true, false, true, false,
		EDynamicForceFeedbackAction::Start);

	ItemCollected();
}