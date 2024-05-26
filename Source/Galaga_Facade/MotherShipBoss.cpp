// Fill out your copyright notice in the Description page of Project Settings.


#include "MotherShipBoss.h"
#include "Engine/Engine.h"
#include "MovementBossComponent.h"

// Sets default values
AMotherShipBoss::AMotherShipBoss()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PhaseTimer = 0.0f;
	CurrentPhase = EBossPhase::PhaseNone;

	//Movement = CreateDefaultSubobject<UMovementBossComponent>(TEXT("MovementComponent"));
}

// Called when the game starts or when spawned
void AMotherShipBoss::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMotherShipBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdatePhase(DeltaTime);

}

void AMotherShipBoss::UpdatePhase(float DeltaTime)
{
	PhaseTimer += DeltaTime;

	switch (CurrentPhase)
	{
	case EBossPhase::PhaseNone:
		if (PhaseTimer >= 10.0f)
		{
			CombatPhases({ "AddWeapon", "AddShield", "UpdateStatus" });
			CurrentPhase = EBossPhase::Phase1;
			PhaseTimer = 0.0f;
		}
		break;

	case EBossPhase::Phase1:
		if (PhaseTimer >= 5.0f)
		{
			CombatPhases({ "ChangeMovement", "UpdateStatus" });
			CurrentPhase = EBossPhase::Phase2;
			PhaseTimer = 0.0f;
		}
		break;

	case EBossPhase::Phase2:
		if (PhaseTimer >= 5.0f)
		{
			CombatPhases({ "ChangeMovement", "UpdateStatus" });
			CurrentPhase = EBossPhase::Phase3;
			PhaseTimer = 0.0f;
		}
		break;

	case EBossPhase::Phase3:
		// Implement additional logic if needed
		break;

	default:
		break;
	}
}

void AMotherShipBoss::AddWeapon()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Arma Añadida a la nave: %s"), *BossName()));

	
}

void AMotherShipBoss::AddShield()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Escudo añadido a la nave"), *BossName()));

}

void AMotherShipBoss::UpdateStatus()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Atributos mejorados"), *BossName()));

}
	
void AMotherShipBoss::ChangeMovement()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Cambio de movimiento"), *BossName()));

	//Movement->MoveInSineWave(GetWorld()->GetDeltaSeconds());

}

void AMotherShipBoss::CombatPhases(const TArray<FString>& _Phases)
{
	for (FString Phases : _Phases)
	{
		ChangePhases(Phases);
	}

}

void AMotherShipBoss::ChangePhases(const FString& _Phases)
{
	if (_Phases.Equals("AddWeapon"))
	{
		AddWeapon();
	}
	else if (_Phases.Equals("AddShield"))
	{
		AddShield();
	}
	else if (_Phases.Equals("UpdateStatus"))
	{
		UpdateStatus();
	}
	else if (_Phases.Equals("ChangeMovement"))
	{
		ChangeMovement();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("Phase no valida")));
	}
}
