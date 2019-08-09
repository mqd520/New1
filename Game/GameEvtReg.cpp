#include "stdafx.h"
#include "Include/game/GameEvtReg.h"

namespace game
{
	typedef vector<GameEvtCallbackInfo>::iterator IT;	//	vector<GameEvtCallbackInfo>::iterator

	GameEvtReg::GameEvtReg() : 
		pObj(nullptr)
	{

	}

	GameEvtReg::~GameEvtReg()
	{

	}

	void GameEvtReg::AttachObj(void* pObj)
	{
		this->pObj = pObj;
	}

	void GameEvtReg::TriggerEvt(EGameEvtType type, GameEvt& evt)
	{
		for (IT it = vecCallbackInfos.begin(); it != vecCallbackInfos.end(); it++)
		{
			if (it->type == type)
			{
				if (!it->fn._Empty())
				{
					it->fn(&evt, pObj);
				}
			}
		}
	}

	void GameEvtReg::RegGameEvt(EGameEvtType type, GameEvtCallback callback)
	{
		bool b = false;
		for (IT it = vecCallbackInfos.begin(); it != vecCallbackInfos.end(); it++)
		{
			if (it->type == type && it->fn.target_type() == callback.target_type())
			{
				b = true;
				break;
			}
		}

		if (!b)
		{
			vecCallbackInfos.push_back({ callback, type });
		}
	}

	void GameEvtReg::RemoveGameEvt(EGameEvtType type, GameEvtCallback callback)
	{
		IT it1 = vecCallbackInfos.end();
		for (IT it = vecCallbackInfos.begin(); it != vecCallbackInfos.end(); it++)
		{
			if (it->type == type && it->fn.target_type() == callback.target_type())
			{
				it1 = it;
				break;
			}
		}

		if (it1 != vecCallbackInfos.end())
		{
			vecCallbackInfos.erase(it1);
		}
	}

	void GameEvtReg::RemoveGameEvt(EGameEvtType type)
	{
		for (IT it = vecCallbackInfos.begin(); it != vecCallbackInfos.end();)
		{
			if (it->type == type)
			{
				it = vecCallbackInfos.erase(it);
			}
			else
			{
				it++;
			}
		}
	}

	void GameEvtReg::RemoveGameEvt()
	{
		vecCallbackInfos.clear();
	}
}