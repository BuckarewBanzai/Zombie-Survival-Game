// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class COOPGAME_API ASPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:

	//Store player name in state class. Data here persists on death/respawn.
	UPROPERTY(BlueprintReadWrite, Category = "PlayerState" )
 	FString PlayerNameState;

	UFUNCTION(BlueprintCallable, Category = "PlayerState")
	void AddScore(float ScoreDelta);

	UFUNCTION(BlueprintCallable, Category = "PlayerState")
	void SubtractScore(float ScoreDelta);
	
};
