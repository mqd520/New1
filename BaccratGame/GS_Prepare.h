#pragma once

#include "GameStatus.h"

class GS_Prepare : public GameStatus
{
public:
	GS_Prepare();

public:
	EGameMainStatus GetCurGameMainStatus() override;

	EGameStatus GetNextStatus() override;

	void Enter() override;
};