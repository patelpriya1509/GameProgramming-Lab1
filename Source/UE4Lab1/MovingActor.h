// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "MovingActor.generated.h"

/**
 * 
 */
UCLASS()
class UE4LAB1_API AMovingActor : public ABaseActor
{
	GENERATED_BODY()
	
public:
	AMovingActor();

	UPROPERTY(EditInstanceOnly, Category = "Movement Point")
	class AActor* FirstPoint;

	UPROPERTY(EditInstanceOnly, Category = "Movement Point")
	class AActor* SecondPoint;

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	class AActor* CurrentPoint;

	void MoveToNextPoint();
};
