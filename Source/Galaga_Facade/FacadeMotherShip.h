// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FacadeMotherShip.generated.h"

UCLASS()
class GALAGA_FACADE_API AFacadeMotherShip : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacadeMotherShip();

protected:
	TArray<class AMotherShipBoss*> Boss;
	TArray<FString> Phases;

	class AMotherShipArwing* Arwing;
	class AMotherShipExecutor* Executor;
	class AMotherShipPrydwen* Prydwen;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Phase1();
	void Phase2();
	void Phase3();


private:
	void MakeChanges(TArray<class AMotherShipBoss*> _Bosses, TArray<FString> Phases);

};
