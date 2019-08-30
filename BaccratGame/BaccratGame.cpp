// BaccratGame.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "InitService.h"
#include "BaccratService.h"

#define TableId		(71)		// Table Id

int _tmain(int argc, _TCHAR* argv[])
{
	InitService::OnMainRun();




	char ch[1024] = { 0 };
	while (true)
	{
		string cmd = gets_s(ch);

		if (cmd == "101")	// init table
		{
			vector<int> vec = { TableId };
			BaccratService::GetInstance()->GetGameSrvMgr()->CreateGameService(vec);
		}
		else if (cmd == "102")
		{
			GameService* pSrv = BaccratService::GetInstance()->GetGameSrvMgr()->GetGameSrv(TableId);
			TableData result = pSrv->GetTableDataMgr()->GetTableData();
			result.nId = 1;
		}

		else if (cmd == "201")	// dealer enter game
		{
			GameService* pSrv = BaccratService::GetInstance()->GetGameSrvMgr()->GetGameSrv(TableId);
			pSrv->GetDealerMgr()->DealerEnterGame("30001汉字");
		}

		else if (cmd == "301")	// start table
		{
			GameService* pSrv = BaccratService::GetInstance()->GetGameSrvMgr()->GetGameSrv(TableId);
			pSrv->GetGameProcess()->StartTable();
		}
		else if (cmd == "302")	// start bet
		{
			GameService* pSrv = BaccratService::GetInstance()->GetGameSrvMgr()->GetGameSrv(TableId);
			pSrv->GetGameProcess()->StartBet();
		}
		else if (cmd == "303")	// stop bet
		{
			GameService* pSrv = BaccratService::GetInstance()->GetGameSrvMgr()->GetGameSrv(TableId);
			pSrv->GetGameProcess()->StopBet();
		}
	}

	InitService::OnMainExit();
	return 0;
}