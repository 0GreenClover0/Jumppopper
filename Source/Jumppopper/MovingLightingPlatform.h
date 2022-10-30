// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingLightingPlatform.generated.h"

UCLASS()
class JUMPPOPPER_API AMovingLightingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingLightingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	bool GetIsLight() const;

private:
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector PlatformVelocity = FVector(400.f, 0.f, 0.f);	
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float MovedDistance = 500.f;		//Distance between StartLocation and CurrentLocation
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector Offset;		// (StartLocation - Offset) in BeginPlay to make every MovingPlatform different
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float LightRate = 2.f;
	FVector	StartLocation;
	float Opacity;
	UPROPERTY(EditAnywhere)
	float OpacityTime = 0.35;

	UPROPERTY(EditAnywhere)
	UMaterial* OnMaterial;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UMaterialInterface* Material;
	UMaterialInstanceDynamic* DynamicMaterial;
	
	FTimerHandle LightRateHandle;
	bool IsLight = true;

	UFUNCTION()
	void CheckLight();

};
