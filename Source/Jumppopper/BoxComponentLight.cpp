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

	for (AActor* actor : Actors)
	{
		if (actor->ActorHasTag("Player"))
		{
				actor->SetActorLocation(FVector(3704, 2820, 510));
		}
	}
	
}


