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

	Arwing = GetWorld()->SpawnActor<AMotherShipArwing>(AMotherShipArwing::StaticClass());
	Executor = GetWorld()->SpawnActor<AMotherShipExecutor>(AMotherShipExecutor::StaticClass());
	Prydwen = GetWorld()->SpawnActor<AMotherShipPrydwen>(AMotherShipPrydwen::StaticClass());

	Boss.Add(Arwing);
	Boss.Add(Executor);
	Boss.Add(Prydwen);
}

// Called every frame
void AFacadeMotherShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFacadeMotherShip::Phase1()
{
	Phases.Empty();
	Phases.Add("UpdateWeapons");
	Phases.Add("UpdateShield");
	Phases.Add("UpdateStatus");
	Phases.Add("Phases");

	MakeChanges(Boss, Phases);

}

void AFacadeMotherShip::Phase2()
{
	Phases.Empty();
	Phases.Add("UpdateWeapons");
	Phases.Add("UpdateShield");
	Phases.Add("UpdateStatus");
	Phases.Add("Phases");

	MakeChanges(Boss, Phases);

}

void AFacadeMotherShip::Phase3()
{
	Phases.Empty();
	Phases.Add("UpdateWeapons");
	Phases.Add("UpdateShield");
	Phases.Add("UpdateStatus");
	Phases.Add("Phases");

	MakeChanges(Boss, Phases);
}

void AFacadeMotherShip::MakeChanges(TArray<class AMotherShipBoss*> _Bosses, TArray<FString> _Phases)
{
	for (AMotherShipBoss* Bosses : _Bosses)
	{
		Bosses->CombatPhases(_Phases);
	}

}

