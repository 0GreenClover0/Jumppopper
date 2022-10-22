// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class JUMPPOPPER_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector PlatformVelocity = FVector(0.f, 400.f, 0.f);	
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float MovedDistance = 400.f;		//Distance between StartLocation and CurrentLocation
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector Offset;		// (StartLocation - Offset) in BeginPlay to make every MovingPlatform different
	
	FVector	StartLocation;

};
