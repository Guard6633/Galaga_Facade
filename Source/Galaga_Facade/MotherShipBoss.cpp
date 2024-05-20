// Fill out your copyright notice in the Description page of Project Settings.


#include "MotherShipBoss.h"

// Sets default values
AMotherShipBoss::AMotherShipBoss()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

void AMotherShipBoss::UpdateWeapons()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Inspeccion de la nave en general"), *TituloTripulacion()));
}

void AMotherShipBoss::UpdateShield()
{

}

void AMotherShipBoss::UpdateStatus()
{

}

void AMotherShipBoss::UpdateMovement()
{

}

void AMotherShipBoss::CombatPhases(const TArray<FString>& _Phases)
{

}

void ChangePhases(const FString& _Phases)
{

}
