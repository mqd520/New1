#include "stdafx.h"
#include "GS_Stop.h"

GS_Stop::GS_Stop() :
GameStatus(EGameStatus::Stop, false, 0)
{

}

EGameMainStatus GS_Stop::GetCurGameMainStatus() const
{
	return EGameMainStatus::Stop;
}

EGameStatus GS_Stop::GetNextStatus() const
{
	return EGameStatus::Prepare;
}