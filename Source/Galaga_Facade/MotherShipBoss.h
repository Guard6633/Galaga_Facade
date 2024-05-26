// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MotherShipBoss.generated.h"

UCLASS()
class GALAGA_FACADE_API AMotherShipBoss : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMotherShipBoss();

	//class AWeapon* Weapon;
	//class UMovementBossComponent* Movement;

private:

	float PhaseTimer;

	EBossPhase CurrentPhase;
		

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddWeapon();
	void AddShield();
	void UpdateStatus();
	void ChangeMovement();

	void CombatPhases(const TArray<FString>& _Phases);

	virtual void Phases() PURE_VIRTUAL(AMotherShipBoss::Phases, );
	virtual FString BossName() PURE_VIRTUAL(AMotherShipBoss::BossName, return "";);

private:
	void ChangePhases(const FString& _Phases);
	void UpdatePhase(float DeltaTime);
};

UENUM(BlueprintType)
enum class EBossPhase : uint8
{
	PhaseNone UMETA(DisplayName = "None"),
	Phase1 UMETA(DisplayName = "Phase 1"),
	Phase2 UMETA(DisplayName = "Phase 2"),
	Phase3 UMETA(DisplayName = "Phase 3")
};