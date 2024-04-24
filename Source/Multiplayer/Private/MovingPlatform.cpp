// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority()) //is on the server
	{
		UE_LOG(LogTemp, Warning, TEXT("it is moving cause authority"));
		FVector ActorLoc = GetActorLocation();
		float JourneyLength = (GlobalTargetLocation - StartLocation).Size();
		float JourneyTraveled = (ActorLoc - StartLocation).Size();

		if (JourneyTraveled >= JourneyLength)
		{
			FVector Swap = StartLocation;
			StartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;
		}

		FVector Direction = (GlobalTargetLocation -	StartLocation).GetSafeNormal();
		ActorLoc += MoveValue * DeltaTime * Direction ;
		SetActorLocation(ActorLoc);
	}
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
	StartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
	
}
