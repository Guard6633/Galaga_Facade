// Fill out your copyright notice in the Description page of Project Settings.


#include "MotherShipPrydwen.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AMotherShipPrydwen::AMotherShipPrydwen()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PrydwenMeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> PrydwenMaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Water_Lake.M_Water_Lake'"));
	PrydwenMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PrydwenMesh"));
	PrydwenMesh->SetStaticMesh(PrydwenMeshAsset.Object);
	PrydwenMesh->SetMaterial(0, PrydwenMaterialAsset.Object);
	SetRootComponent(PrydwenMesh);


}

void AMotherShipPrydwen::BeginPlay()
{
	Super::BeginPlay();


}

void AMotherShipPrydwen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AMotherShipPrydwen::Phases()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Realizar Fases"), *BossName()));

}

FString AMotherShipPrydwen::BossName()
{

	return "Prydwen";
}
