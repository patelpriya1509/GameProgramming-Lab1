// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitActor.h"


AOrbitActor::AOrbitActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AOrbitActor::BeginPlay()
{
	Super::BeginPlay();
	Reset();
}

void AOrbitActor::Reset()
{
	CurrentAngle = InitialRotationAngle;
	if (RotateAroundActor == nullptr) {
		return;
	}

	if (RotationRadius == FVector::ZeroVector) {
		RotationRadius = GetActorLocation() - RotateAroundActor->GetActorLocation();
		}
}

void AOrbitActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (RotateAroundActor != nullptr) {
		CurrentAngle += RotationSpeed * DeltaTime;
		if (CurrentAngle > 360.0f) 	CurrentAngle -= 360.0f;

	const FVector NewLocation = RotateAroundActor->GetActorLocation() + RotationRadius.RotateAngleAxis(CurrentAngle, RotationAxis);

	FQuat NewRotation = FRotator(0, CurrentAngle, 0).Quaternion();
	SetActorLocationAndRotation(NewLocation, NewRotation);
	}
}