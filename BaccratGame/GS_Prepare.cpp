#include "stdafx.h"
#include "GS_Prepare.h"

GS_Prepare::GS_Prepare() :
GameStatus(EGameStatus::Prepare)
{

}

EGameMainStatus GS_Prepare::GetCurGameMainStatus()
{
	return EGameMainStatus::Running;
}

EGameStatus GS_Prepare::GetNextStatus()
{
	return EGameStatus::Bet;
}

void GS_Prepare::Enter()
{

}