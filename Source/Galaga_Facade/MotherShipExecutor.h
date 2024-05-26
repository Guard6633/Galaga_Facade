// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MotherShipBoss.h"
#include "MotherShipExecutor.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_FACADE_API AMotherShipExecutor : public AMotherShipBoss
{
	GENERATED_BODY()
	
public:
	AMotherShipExecutor();

	class UStaticMeshComponent* ExecutorMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Phases() override;
	FString BossName() override;

};

UENUM(BlueprintType)
enum class EExecutorPhase : uint8
{
	PhaseNone UMETA(DisplayName = "None"),
	AddWeapon UMETA(DisplayName = "Phase 1"),
	AddShield UMETA(DisplayName = "Phase 2"),
	UpdateStatus UMETA(DisplayName = "Phase 3"),
	ChangeMovement UMETA(DisplayName = "Phase 4")
};
