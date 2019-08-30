#pragma once

#include "GameStatus.h"


// Prepare status
class GS_Prepare : public GameStatus
{
public:
	//************************************
	// Method:    Constructor
	// Parameter: bool isAutoEnterNext:	whether auto enter next status
	// Parameter: int nDurationTime: total time
	//************************************
	GS_Prepare(bool isAutoEnterNext, int nDurationTime);

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