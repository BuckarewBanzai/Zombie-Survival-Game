// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"


enum class EWaveState : uint8;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActorKilled, AActor*, VictimActor, AActor*, KillerActor, AController*, KillerController);


/**
 * 
 */
UCLASS()
class COOPGAME_API ASGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:

	FTimerHandle TimerHandle_BotSpawner;

	FTimerHandle TimerHandle_NextWaveStart;

	UPROPERTY(BlueprintReadOnly, Category = "GameMode")
	int32 WaveCount;

	//Is Boss Wave?
	UPROPERTY(BlueprintReadWrite, Category="GameMode")
 	bool IsABossWave;

	//Modify rate of zombie spawns
	UPROPERTY(EditDefaultsOnly, Category = "GameMode")
	int32 BotSpawnModifier;

	// Bots to spawn in current wave
	UPROPERTY(BlueprintReadWrite, Category="GameMode")
	int32 NrOfBotsToSpawn;

	// Boss to spawn in current wave
	UPROPERTY(BlueprintReadWrite, Category="GameMode")
	int32 NrOfBossToSpawn;

	UPROPERTY(EditDefaultsOnly, Category = "GameMode")
	float TimeBetweenWaves;
	
protected:

	// Hook for BP to spawn a single bot
	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void SpawnNewBot();

	void SpawnBotTimerElapsed();

	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void WaveChange();

	// Start Spawning Bots
	void StartWave();

	// Stop Spawning Bots
	void EndWave();

	// Set timer for next startwave
	void PrepareForNextWave();

	void CheckWaveState();

	void CheckAnyPlayerAlive();

	//Hook into GameOver event and allow actor cleanup, delay before start, etc
	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void GameOverCleanup();

	void GameOver();

	void SetWaveState(EWaveState NewState);

	void RestartDeadPlayers();

public:

	ASGameMode();

	virtual void StartPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(BlueprintAssignable, Category = "GameMode")
	FOnActorKilled OnActorKilled;
};
