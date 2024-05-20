// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_FacadeGameMode.h"
#include "Galaga_FacadePawn.h"

AGalaga_FacadeGameMode::AGalaga_FacadeGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_FacadePawn::StaticClass();
}

