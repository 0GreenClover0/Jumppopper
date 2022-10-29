// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingLightingPlatform.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"

// Sets default values
AMovingLightingPlatform::AMovingLightingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = StaticMeshComponent;
	OnMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OnMaterial"));
	OffMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OffMaterial"));

}

// Called when the game starts or when spawned
void AMovingLightingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation() - Offset;
	GetWorldTimerManager().SetTimer(LightRateHandle,this, &AMovingLightingPlatform::checkLight, LightRate, true);
}

// Called every frame
void AMovingLightingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += PlatformVelocity * DeltaTime * CurrentLocation.GetSafeNormal();
	SetActorLocation(CurrentLocation);

	float Distance = FVector::Dist(StartLocation, CurrentLocation);

	if (Distance > MovedDistance)
	{
		PlatformVelocity = -PlatformVelocity;
		StartLocation = CurrentLocation;
	}

}

bool AMovingLightingPlatform::GetIsLight()
{
	return IsLight;
}

void AMovingLightingPlatform::checkLight()
{
	if (!IsLight)
	{
		StaticMeshComponent->SetMaterial(0, OffMaterial);
		IsLight = true;
	}
	else
	{
		StaticMeshComponent->SetMaterial(0, OnMaterial);
		IsLight = false;
	}
}

