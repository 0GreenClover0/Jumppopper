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
}

// Called when the game starts or when spawned
void AMovingLightingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation() - Offset;
	GetWorldTimerManager().SetTimer(LightRateHandle,this, &AMovingLightingPlatform::CheckLight, LightRate, true);
	Material = StaticMeshComponent->GetMaterial(0);
	DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);
	StaticMeshComponent->SetMaterial(0, DynamicMaterial);
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

	if (!IsLight)
	{
		DynamicMaterial->GetScalarParameterValue(TEXT("Opacity"), Opacity);
		float NewValue = FMath::FInterpConstantTo(Opacity, 0.0, DeltaTime, OpacityTime);
		DynamicMaterial->SetScalarParameterValue(TEXT("Opacity"), NewValue);
	}
	else
	{
		DynamicMaterial->SetScalarParameterValue(TEXT("Opacity"), 0.9);
	}
	
}

bool AMovingLightingPlatform::GetIsLight() const
{
	return IsLight;
}

void AMovingLightingPlatform::CheckLight()
{
	if (!GetIsLight())
	{
		IsLight = true;
	}
	else  //if lighting on 
	{
		IsLight = false;
	}
}

