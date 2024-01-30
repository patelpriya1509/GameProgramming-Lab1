// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "OrbitActor.generated.h"

/**
 * 
 */
UCLASS()
class UE4LAB1_API AOrbitActor : public ABaseActor
{
	GENERATED_BODY()
	
public:
	AOrbitActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround")
	class AActor* RotateAroundActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround")
	float RotationSpeed = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround")
	FVector RotationRadius = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround")
	FVector RotationAxis = FVector::UpVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround", meta = (ClampMin = "0.0", ClampMax = "360.0", UMin = "0.0", UIMax = "360.0"))
	float InitialRotationAngle = 0.f;

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	float CurrentAngle = 0.f;

public:
	void Reset();
};
