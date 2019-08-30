#pragma once

#include <string>
using namespace std;

namespace db
{
	// Table data
	class TableData
	{
	public:
		int nId;				// table Id
		string strTableName;	// table name
		string dk_passport;		// dk_passport
		string dk_password;		// dk_password
		int dk_dtAmount;		// dk_dtAmount
		string DealerNo;		// DealerNo
		string VisitPwd;		// VisitPwd
		int nGameType;			// game type
		int nTypeId;			// type id
		int dk_mcid10000;		// dk_mcid10000
		int dk_seatMin;			// dk_seatMin
		int dk_dtDelayBet;		// dk_dtDelayBet
		int dk_publishresult;	// dk_publishresult
		int dk_mode;			// start new game round model, refer to ENewGameRoundModel
		int dk_dtprepare;		// dk_dtprepare
		int dk_dtstartbet;		// dk_dtstartbet
		int dk_dtstopbet;		// dk_dtstopbet
		int dk_dtdeal;			// dk_dtdeal
		int dk_dtshow;			// dk_dtshow
		int dk_dtwait;			// dk_dtwait
		int dk_mbettime;		// dk_mbettime
		int dk_dtMiPower;		// dk_dtMiPower
		int dk_dtMiTime1;		// dk_dtMiTime1
		int dk_dtMiTime2;		// dk_dtMiTime2
		int Type1;				// Type
		int Type2;				// Type
		int Type3;				// Type
		int nGroupCount;		// group count
		int nSeatCount;			// seat count
		int dk_accprofit_first;	// dk_accprofit_first
		int dk_videotype;		// dk_videotype
		int dk_mcid10060;		// dk_mcid10060		

	public:
		TableData(){};
	};
}