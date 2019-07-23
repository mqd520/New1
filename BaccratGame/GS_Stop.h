#pragma once

#include "GameStatus.h"

class GS_Stop : public GameStatus
{
public:
	GS_Stop();

public:
	EGameMainStatus GetCurGameMainStatus() override;

	EGameStatus GetNextStatus() override;

	void Enter() override;
};