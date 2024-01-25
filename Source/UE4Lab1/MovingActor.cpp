// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	MoveToNextPoint();
}

void AMovingActor::MoveToNextPoint()
{
	if (CurrentPoint == nullptr || CurrentPoint == SecondPoint) 
	{
		CurrentPoint = FirstPoint;
	}
	else 
	{ 
		CurrentPoint = SecondPoint; 
	}
}


void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FirstPoint == nullptr || SecondPoint == nullptr) {
		return;
	}

	if (CurrentPoint) {
		FVector Delta = GetActorLocation() - CurrentPoint->GetActorLocation();
		float DistanceToGoal = Delta.Size();

		if (DistanceToGoal < 100) {
			MoveToNextPoint();
		}
		Delta.Normalize();

		FRotator NewLookAt = FRotationMatrix::MakeFromX(Delta).Rotator();
		NewLookAt.Pitch = 0.0f;
		NewLookAt.Yaw += -180.0f;
		NewLookAt.Roll = 0.0f;

		FQuat slerpedRotation = FMath::Lerp(FQuat(GetActorRotation()), FQuat(NewLookAt), 0.08f);
		SetActorRotation(slerpedRotation);

		FVector lerp2 = FMath::VInterpConstantTo(GetActorLocation(), CurrentPoint->GetActorLocation(), DeltaTime, 600.f);
		SetActorLocation(lerp2);
	}
}

