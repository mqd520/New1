#pragma once

#include "GameStatus.h"

// Publish status
class GS_Publish : public GameStatus
{
public:
	//************************************
	// Method:    Constructor
	// Parameter: bool isAutoEnterNext:	whether auto enter next status
	// Parameter: int nDurationTime: total time
	//************************************
	GS_Publish(bool isAutoEnterNext, int nDurationTime);

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