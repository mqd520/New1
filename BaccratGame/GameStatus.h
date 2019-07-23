#pragma once

#include "gameDef/GameDef.h"
using namespace gameDef;


// GameStatus
class GameStatus
{
public:
	GameStatus(EGameStatus status);

protected:
	const EGameStatus status;	// game status

public:
	virtual EGameMainStatus GetCurGameMainStatus();

	virtual EGameStatus GetCurGameStatus();

	virtual EGameStatus GetNextStatus();

	virtual EGameStatus GetLastStatus();

	virtual void Enter();

	virtual void Leave();

	virtual bool IsCompleted();

	virtual void Exit();
};