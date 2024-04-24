// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	int MoveValue = 10;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true)) //meta allows a widget to show up on the editor. 
	FVector TargetLocation;
private:
	UPROPERTY()
	FVector StartLocation;

	UPROPERTY()
	FVector GlobalTargetLocation;

};
