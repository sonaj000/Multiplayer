// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MPGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API UMPGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UMPGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init();

	UFUNCTION(Exec) //allows call from cmd
	void Host();

	UFUNCTION(Exec)
	void Join(const FString &Address);

};
