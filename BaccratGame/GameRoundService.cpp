#include "stdafx.h"
#include "GameRoundService.h"

GameRoundService::GameRoundService(int nTableId) :
nTableId(nTableId),
nGameRoundId(0),
strGameRoundNo("")
{

}

void GameRoundService::Init()
{

}

void GameRoundService::Exit()
{

}

void GameRoundService::LoadGameRoundData()
{
	// ...
}

int GameRoundService::GetTableId()
{
	return nTableId;
}

int GameRoundService::GetGameRoundId()
{
	return nGameRoundId;
}

string GameRoundService::GetGameRoundNo()
{
	return strGameRoundNo;
}

void GameRoundService::CreateNewRound()
{

}

void GameRoundService::SettleGameRound()
{

}