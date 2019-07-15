#pragma once

#include <string>
#include <vector>
using namespace std;

#include "pck/Def.h"
using namespace pck;


// session data
typedef struct tagSessionData
{
	int nClientId;			// client id
	string strClientIp;		// client ip
	int nClientPort;		// client port
	EServerType peerType;	// peer server type
	void* pParam1;			// 
	void* pParam2;			// 
}SessionData;


// session data mgr
class SessionDataMgr
{
public:
	SessionDataMgr();
	virtual ~SessionDataMgr();

protected:
	vector<SessionData> vecDatas;	// session data list

public:
	virtual void Add(SessionData& data);

	virtual void Remove(EServerType peerType);

	virtual SessionData Remove(int clientId);

	virtual SessionData Remove(string ip, int port);

	virtual void Remove(SessionData& data);

	virtual void Remove();

	virtual void Get(vector<SessionData>& vec, EServerType peerType);

	virtual SessionData Get(int clientId);

	virtual SessionData Get(string ip, int port);

	virtual void Get(vector<SessionData>& vec);
};