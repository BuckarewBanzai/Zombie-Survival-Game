// Fill out your copyright notice in the Description page of Project Settings.

#include "SPlayerState.h"




void ASPlayerState::AddScore(float ScoreDelta)
{
	Score += ScoreDelta;
}

void ASPlayerState::SubtractScore(float ScoreDelta)
{
	Score -= ScoreDelta;
}