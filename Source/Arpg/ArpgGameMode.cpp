// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Arpg.h"
#include "ArpgGameMode.h"
#include "ArpgPlayerController.h"
#include "ArpgCharacter.h"

AArpgGameMode::AArpgGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AArpgPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}