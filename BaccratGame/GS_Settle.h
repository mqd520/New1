#pragma once

#include "GameStatus.h"

// Settle status
class GS_Settle : public GameStatus
{
public:
	//************************************
	// Method:    Constructor
	// Parameter: bool isAutoEnterNext:	whether auto enter next status
	// Parameter: int nDurationTime: total time
	//************************************
	GS_Settle(bool isAutoEnterNext, int nDurationTime);

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