// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakePart.generated.h"

UCLASS()
class TESTPROJECT_API ASnakePart : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnakePart();
	//FVector PrevPosition;
	FVector PrevPos;
	//AActor APrePos = PrevPos;
	class ASnakeGameMode* GetSnakeGameMode();
	ASnakePart* LastNextPart();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ASnakePart* Next;
	ASnakePart* Prev;
};
