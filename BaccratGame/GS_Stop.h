#pragma once

#include "GameStatus.h"


// Stop status
class GS_Stop : public GameStatus
{
public:
	GS_Stop();

public:
	//************************************
	// Method:    Get current main status
	//************************************
	EGameMainStatus GetCurGameMainStatus() const override;

	//************************************
	// Method:    Get next status
	//************************************
	EGameStatus GetNextStatus() const override;
};