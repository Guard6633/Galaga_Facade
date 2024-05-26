// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_FacadeGameMode.generated.h"

UCLASS(MinimalAPI)
class AGalaga_FacadeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_FacadeGameMode();

	float TimerGame;

private:
	EGamePhase CurrentPhase;


protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	class AFacadeMotherShip* Facade;


};

UENUM(BlueprintType)
enum class EGamePhase : uint8
{
	PhaseNone UMETA(DisplayName = "None"),
	Phase1 UMETA(DisplayName = "Phase 1"),
	Phase2 UMETA(DisplayName = "Phase 2"),
	Phase3 UMETA(DisplayName = "Phase 3"),
	PhaseComplete UMETA(DisplayName = "Complete")
};
