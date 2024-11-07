// Copyright Epic Games, Inc. All Rights Reserved.

#include "SteamSystemGameMode.h"
#include "SteamSystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASteamSystemGameMode::ASteamSystemGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
