// Copyright Epic Games, Inc. All Rights Reserved.

#include "JumppopperPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "JumppopperCharacter.h"
#include "Engine/World.h"

AJumppopperPlayerController::AJumppopperPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void AJumppopperPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AJumppopperPlayerController::MoveForward(float scale)
{
	APawn* const PlayerPawn = GetPawn();
	if (PlayerPawn)
	{
		PlayerPawn->AddMovementInput(FVector(90.f, 0.f, 0.f), scale, false);
	}
}

void AJumppopperPlayerController::MoveRight(float scale)
{
	APawn* const PlayerPawn = GetPawn();
	if (PlayerPawn)
	{
		PlayerPawn->AddMovementInput(FVector(0.f, 90.f, 0.f), scale, false);
	}
}

void AJumppopperPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AJumppopperPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AJumppopperPlayerController::MoveRight);
}
