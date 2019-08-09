#pragma once

#include "GameStatus.h"

class GS_Stop : public GameStatus
{
public:
	GS_Stop();

public:
	//************************************
	// Method:    Get current main status
	//************************************
	EGameMainStatus GetCurGameMainStatus() override;

	//************************************
	// Method:    Get next status
	//************************************
	EGameStatus GetNextStatus() override;
};