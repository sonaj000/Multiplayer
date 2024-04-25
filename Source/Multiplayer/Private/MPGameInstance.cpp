// Fill out your copyright notice in the Description page of Project Settings.


#include "MPGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

UMPGameInstance::UMPGameInstance(const FObjectInitializer& ObjectInitializer)
{
	//called upon initialization in the editor and play. 
	UE_LOG(LogTemp, Warning, TEXT("Constructor"));
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/UI/WBP_MainMenu"));
	if (!ensure(MenuBPClass.Class != nullptr)) return;

	MenuClass = MenuBPClass.Class;

}

void UMPGameInstance::Init()
{
	//only called after editor starts play. 
	UE_LOG(LogTemp, Warning, TEXT("Found class : %s"), *MenuClass->GetName());
}

void UMPGameInstance::LoadMenu()
{
	if (IsValid(MenuClass))
	{
		UUserWidget* WMenu = CreateWidget<UUserWidget>(this, MenuClass);
		if (IsValid(WMenu))
		{
			WMenu->AddToViewport();
		}
	}
}


void UMPGameInstance::Host()
{
	UWorld* CurrentWorld = GetWorld();
	CurrentWorld->ServerTravel("/Game/Maps/ThirdPersonMap?listen"); //listen server
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, TEXT("Hosting now!!!"));
	}
}
void UMPGameInstance::Join(const FString& Address)
{
	APlayerController* playercontroller = GetFirstLocalPlayerController();
	playercontroller->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 5, FColor::Red, FString::Printf(TEXT("Joining now!!!%s"), *Address));
	}
}


