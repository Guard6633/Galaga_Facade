// Fill out your copyright notice in the Description page of Project Settings.


#include "FacadeMotherShip.h"
#include "MotherShipArwing.h"
#include "MotherShipExecutor.h"
#include "MotherShipPrydwen.h"

// Sets default values
AFacadeMotherShip::AFacadeMotherShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFacadeMotherShip::BeginPlay()
{
	Super::BeginPlay();
	
	Boss = TArray<AMotherShipBoss*>();
	Phases = TArray<FString>();
}	

// Called every frame
void AFacadeMotherShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFacadeMotherShip::Phase1()
{
	Arwing = GetWorld()->SpawnActor<AMotherShipArwing>(AMotherShipArwing::StaticClass(), FVector(1800, 800, 220), FRotator::ZeroRotator);
	Arwing->SetActorScale3D(FVector(4, 4, 4));
	Boss.Add(Arwing);

	Phases.Empty();
	Phases.Add("AddWeapon");
	Phases.Add("AddShield");
	Phases.Add("ChangeMovement");
	Phases.Add("UpdateStatus");

	MakeChanges(Boss, Phases);

}

void AFacadeMotherShip::Phase2()
{
	Executor = GetWorld()->SpawnActor<AMotherShipExecutor>(AMotherShipExecutor::StaticClass(), FVector(1800, 0, 220), FRotator::ZeroRotator);
	Executor->SetActorScale3D(FVector(4, 4, 4));
	Boss.Add(Executor);

	Phases.Empty();
	Phases.Add("AddWeapon");
	Phases.Add("AddShield");
	Phases.Add("ChangeMovement");
	Phases.Add("UpdateStatus");

	MakeChanges(Boss, Phases);

}

void AFacadeMotherShip::Phase3()
{
	Prydwen = GetWorld()->SpawnActor<AMotherShipPrydwen>(AMotherShipPrydwen::StaticClass(), FVector(1800, -800, 220), FRotator::ZeroRotator);
	Prydwen->SetActorScale3D(FVector(4, 4, 4));
	Boss.Add(Prydwen);

	Phases.Empty();
	Phases.Add("AddWeapon");
	Phases.Add("AddShield");
	Phases.Add("ChangeMovement");
	Phases.Add("UpdateStatus");

	MakeChanges(Boss, Phases);
}

void AFacadeMotherShip::MakeChanges(TArray<class AMotherShipBoss*> _Bosses, TArray<FString> _Phases)
{
	for (AMotherShipBoss* Bosses : _Bosses)
	{
		Bosses->CombatPhases(_Phases);
	}

}

