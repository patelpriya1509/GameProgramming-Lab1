// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActor.generated.h"

UCLASS(abstract)
class UE4LAB1_API ABaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseActor();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Root Component")
	class USceneComponent* RootTransformComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Actor Visual")
	class UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
