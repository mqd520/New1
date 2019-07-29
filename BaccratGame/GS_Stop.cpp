#include "stdafx.h"
#include "GS_Stop.h"

GS_Stop::GS_Stop() :
GameStatus(EGameStatus::Stop)
{

}

EGameMainStatus GS_Stop::GetCurGameMainStatus()
{
	return EGameMainStatus::Stop;
}

EGameStatus GS_Stop::GetNextStatus()
{
	return EGameStatus::Prepare;
}