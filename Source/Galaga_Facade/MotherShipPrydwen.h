// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MotherShipBoss.h"
#include "MotherShipPrydwen.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_FACADE_API AMotherShipPrydwen : public AMotherShipBoss
{
	GENERATED_BODY()

public:
	AMotherShipPrydwen();

	class UStaticMeshComponent* PrydwenMesh;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Phases() override;
	FString BossName() override;

};
