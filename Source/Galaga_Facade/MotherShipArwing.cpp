// Fill out your copyright notice in the Description page of Project Settings.


#include "MotherShipArwing.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AMotherShipArwing::AMotherShipArwing()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ArwingMeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> ArwingMaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Panel.M_Tech_Panel'"));
	ArwingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArwingMesh"));
	ArwingMesh->SetStaticMesh(ArwingMeshAsset.Object);
	ArwingMesh->SetMaterial(0, ArwingMaterialAsset.Object);
	SetRootComponent(ArwingMesh);


}

void AMotherShipArwing::BeginPlay()
{
	Super::BeginPlay();


}

void AMotherShipArwing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMotherShipArwing::Phases()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Realizar Fases"), *BossName()));


}

FString AMotherShipArwing::BossName()
{
	return "Arwing";
}
