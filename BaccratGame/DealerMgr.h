#pragma once

#include <string>
using namespace std;


// Game dealer mgr
class DealerMgr
{
public:
	DealerMgr(int nTableId);

private:
	int nTableId;				// table Id
	string strDealerNo;			// dealer no

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
	int GetTableId();

	//************************************
	// Method:    Has dealer
	//************************************
	bool hasDealer();

	//************************************
	// Method:    Get dealer no
	//************************************
	string GetDealerNo();

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