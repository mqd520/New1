#pragma once

#include <vector>
#include <minwindef.h>
#include <functional>
using namespace std;
using namespace std::placeholders;

#include "GameEvt.h"


namespace game
{
	// Game evt callback
	typedef std::function<void(GameEvt*, void*)> GameEvtCallback;

	// GameEvtCallbackInfo
	typedef struct tagGameEvtCallbackInfo
	{
		GameEvtCallback fn;		// callback
		EGameEvtType type;		// game evt type
	}GameEvtCallbackInfo;


	// GameEvt Register
	class GameEvtReg
	{
	public:
		GameEvtReg();
		virtual ~GameEvtReg();

	public:
		void* pObj;											// obj
		vector<GameEvtCallbackInfo> vecCallbackInfos;		// callback info list

	protected:
		//************************************
		// Method:    Attach obj
		// Parameter: pObj:	obj
		//************************************
		void AttachObj(void* pObj);

		//************************************
		// Method:    Trigger game evt
		// Parameter: type:	game evt type
		// Parameter: evt:	game evt
		//************************************
		void TriggerEvt(EGameEvtType type, GameEvt& evt);

	public:
		//************************************
		// Method:    Reg game evt callback
		// Parameter: type:	game evt type
		// Parameter: callback
		//************************************
		void RegGameEvt(EGameEvtType type, GameEvtCallback callback);

		//************************************
		// Method:    Remove game evt callback
		// Parameter: type:	game evt type
		// Parameter: callback
		//************************************
		void RemoveGameEvt(EGameEvtType type, GameEvtCallback callback);

		//************************************
		// Method:    Remove game evt callback
		// Parameter: type:	game evt type
		//************************************
		void RemoveGameEvt(EGameEvtType type);

		//************************************
		// Method:    Remove game evt callback
		//************************************
		void RemoveGameEvt();
	};
}