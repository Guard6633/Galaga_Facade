// Fill out your copyright notice in the Description page of Project Settings.


#include "MotherShipExecutor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AMotherShipExecutor::AMotherShipExecutor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ExecutorMeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> ExecutorMaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));
	ExecutorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ExecutorMesh"));
	ExecutorMesh->SetStaticMesh(ExecutorMeshAsset.Object);
	ExecutorMesh->SetMaterial(0, ExecutorMaterialAsset.Object);
	SetRootComponent(ExecutorMesh);

}

void AMotherShipExecutor::BeginPlay()
{
	Super::BeginPlay();

}

void AMotherShipExecutor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AMotherShipExecutor::Phases()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Realizar Fases"), *BossName()));



}

FString AMotherShipExecutor::BossName()
{
	return "The Executor";
}
