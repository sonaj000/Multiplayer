// Fill out your copyright notice in the Description page of Project Settings.


#include "MPGameInstance.h"

UMPGameInstance::UMPGameInstance(const FObjectInitializer& ObjectInitializer)
{
	//called upon initialization in the editor and play. 
	UE_LOG(LogTemp, Warning, TEXT("Constructor"));
}

void UMPGameInstance::Init()
{
	//only called after editor starts play. 
	UE_LOG(LogTemp, Warning, TEXT("init"));
}

void UMPGameInstance::Host()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, TEXT("Hosting now!!!"));
	}
	UWorld* CurrentWorld = GetWorld();

	CurrentWorld->ServerTravel("/Game/Maps/ThirdPersonMap?listen"); //listen server
}
void UMPGameInstance::Join(const FString& Address)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 5, FColor::Red, FString::Printf(TEXT("Joining now!!!%s"), *Address));
	}
	APlayerController* playercontroller = GetFirstLocalPlayerController();
	playercontroller->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}


