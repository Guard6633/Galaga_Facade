// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_FacadeGameMode.h"
#include "FacadeMotherShip.h"
#include "Galaga_FacadePawn.h"

AGalaga_FacadeGameMode::AGalaga_FacadeGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_FacadePawn::StaticClass();
	PrimaryActorTick.bCanEverTick = true;

	TimerGame = 0.0f;
	CurrentPhase = EGamePhase::PhaseNone;

}

void AGalaga_FacadeGameMode::BeginPlay()
{
	Facade = GetWorld()->SpawnActor<AFacadeMotherShip>(AFacadeMotherShip::StaticClass());

}

void AGalaga_FacadeGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimerGame += DeltaTime;

	switch (CurrentPhase)
	{
	case EGamePhase::PhaseNone:
		if (TimerGame >= 10.0f)
		{
			Facade->Phase1();
			CurrentPhase = EGamePhase::Phase1;
		}
		break;

	case EGamePhase::Phase1:
		if (TimerGame >= 15.0f)
		{
			Facade->Phase2();
			CurrentPhase = EGamePhase::Phase2;
		}
		break;

	case EGamePhase::Phase2:
		if (TimerGame >= 20.0f)
		{
			Facade->Phase3();
			CurrentPhase = EGamePhase::Phase3;
		}
		break;

	case EGamePhase::Phase3:
		if (TimerGame >= 30.0f)
		{
			// Reset the timer and phase
			TimerGame = 0.0f;
			CurrentPhase = EGamePhase::PhaseNone;
		}
		break;

	case EGamePhase::PhaseComplete:
		// Handle complete phase if needed
		break;

	default:
		break;
	}

}

