// Fill out your copyright notice in the Description page of Project Settings.

#include "BoxComponentLight.h"
#include "MovingLightingPlatform.h"

UBoxComponentLight::UBoxComponentLight()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBoxComponentLight::BeginPlay()
{
	Super::BeginPlay();
}

void UBoxComponentLight::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);
	AMovingLightingPlatform* Platform = Cast<AMovingLightingPlatform>(GetOwner());

	if (Platform->GetIsLight())
	{
		Platform->SetActorHiddenInGame(true);
		Platform->SetActorEnableCollision(false);
	}
	else if (!Platform->GetIsLight())
	{
		Platform->SetActorHiddenInGame(false);
		Platform->SetActorEnableCollision(true);
	}
	
}


