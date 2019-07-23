#include "stdafx.h"
#include "GameStatus.h"

GameStatus::GameStatus(EGameStatus status) :
status(status)
{

}

EGameMainStatus GameStatus::GetCurGameMainStatus()
{
	return EGameMainStatus::None;
}

EGameStatus GameStatus::GetCurGameStatus()
{
	return status;
}

EGameStatus GameStatus::GetNextStatus()
{
	return EGameStatus::None;
}

EGameStatus GameStatus::GetLastStatus()
{
	return EGameStatus::None;
}

void GameStatus::Enter()
{

}

void GameStatus::Leave()
{

}

bool GameStatus::IsCompleted()
{
	return false;
}

void GameStatus::Exit()
{

}