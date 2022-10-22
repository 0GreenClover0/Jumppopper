// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxColliderComponent.h"

#include "DisappearingPlatform.h"

UBoxColliderComponent::UBoxColliderComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBoxColliderComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UBoxColliderComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FTimerHandle TimerHandle;
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	for (AActor* actor : Actors)
	{
		if (actor->ActorHasTag("Player"))
		{
			GetOwner()->SetActorHiddenInGame(true);
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
			{
				GetOwner()->SetActorEnableCollision(false); 
			}, 0.8f, false);
			
			IsCollision = true;
		}
	}

	if (IsCollision)
	{
		TimeSinceCollision += DeltaTime;
	}
	
	if (TimeSinceCollision >= 2.5f)
	{
		GetOwner()->SetActorHiddenInGame(false);
		GetOwner()->SetActorEnableCollision(true);
		TimeSinceCollision = 0.f;
		IsCollision = false;
	}

	
	
}


