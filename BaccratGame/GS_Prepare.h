#pragma once

#include "GameStatus.h"

class GS_Prepare : public GameStatus
{
public:
	//************************************
	// Method:    Constructor
	// Parameter: int nDurationTime:	duration time
	//************************************
	GS_Prepare(int nDurationTime);

public:
	//************************************
	// Method:    Get current main status
	//************************************
	EGameMainStatus GetCurGameMainStatus() override;

	//************************************
	// Method:    Get next status
	//************************************
	EGameStatus GetNextStatus() override;

	//************************************
	// Method:    Enter
	//************************************
	void Enter() override;

	//************************************
	// Method:    Is completed
	//************************************
	bool IsCompleted() override;
};