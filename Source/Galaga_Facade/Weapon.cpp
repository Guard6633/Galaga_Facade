// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Galaga_FacadeProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/Material.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> WeaponMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> WeaponMaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile'"));
	//static ConstructorHelpers::FObjectFinder<USoundBase> FireSoundAsset(TEXT("SoundWave'/Game/TwinStick/Audio/TwinStickFire.TwinStickFire'"));
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	//FireSound = FireSoundAsset.Object;
	WeaponMesh->SetStaticMesh(WeaponMeshAsset.Object);
	WeaponMesh->SetMaterial(0, WeaponMaterialAsset.Object);
	SetRootComponent(WeaponMesh);

	

}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::Fire()
{
	FVector FireDirection = GetActorForwardVector();
	FVector SpawnLocation = GetActorLocation() + FireDirection * 100;

	Projectile = GetWorld()->SpawnActor<AGalaga_FacadeProjectile>(AGalaga_FacadeProjectile::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
	Projectile->SetActorScale3D(FVector(0.5, 0.5, 0.5));

	//UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());

}
