#pragma once

#include <string>
using namespace std;

class GameService;


// Game dealer mgr
class DealerMgr
{
public:
	DealerMgr(int nTableId);

private:
	int nTableId;				// table Id
	string strDealerNo;			// dealer no

private:
	GameService* pGameSrv;		// game service obj

public:
	//************************************
	// Method:    Init
	//************************************
	void Init();

	//************************************
	// Method:    Exit
	//************************************
	void Exit();

	//************************************
	// Method:    Get Table Id
	//************************************
	int GetTableId() const;

	//************************************
	// Method:    Attach game service
	// Parameter: GameService * pSrv
	//************************************
	void AttachGameService(GameService* pSrv);

	//************************************
	// Method:    Has dealer
	//************************************
	bool hasDealer() const;

	//************************************
	// Method:    Get dealer no
	//************************************
	string GetDealerNo() const;

	//************************************
	// Method:    Dealer enter game
	// Parameter: strDealerNo: dealer no
	//************************************
	void DealerEnterGame(string strDealerNo);

	//************************************
	// Method:    Dealer leaver game
	//************************************
	void DealerLeaveGame();
};