#pragma once

#include "tc/Timer.h"
using namespace tc;

#include "pck/Def.h"
#include "pck/IGPacket.h"
using namespace pck;


// ServerListenInfo
typedef struct tagServerListenInfo
{
	ServerListenPacket pck;
	string strPeerIp;
	int nPeerPort;
}ServerListenInfo;


// ServerListenPacket data Mgr
class ServerListenMgr final
{
public:
	ServerListenMgr(void);

private:
	vector<ServerListenInfo> vecPcks;		// ServerListenInfo信息集合
	Timer t;								// 定时器, 向所有服务器发送ServerListenPacket集合

private:
	//************************************
	// Method:    定时器事件处理
	// Parameter: 定时器对象
	// Parameter: 次数
	// Parameter: void * pParam1
	// Parameter: void * pParam2
	//************************************
	void OnTimer(Timer* pTimer, int count, void* pParam1 = NULL, void* pParam2 = NULL);

public:
	//************************************
	// Method:    初始化
	//************************************
	void Init();

	//************************************
	// Method:    退出
	//************************************
	void Exit();

	//************************************
	// Method:    添加ServerListenPacket
	// Parameter: ServerListenPacket pck
	// Parameter: peerIp
	// Parameter: peerPort
	//************************************
	void Add(ServerListenPacket& pck, string peerIp, int peerPort);

	//************************************
	// Method:    移除ServerListenPacket
	// Parameter: ServerListenPacket pck
	//************************************
	void Remove(ServerListenPacket& pck);

	//************************************
	// Method:    移除指定IP的ServerListenPacket
	// Parameter: EServerType type:	服务器类型
	// Parameter: peerIp
	// Parameter: peerPort
	//************************************
	ServerListenPacket Remove(string peerIp, int peerPort);

	//************************************
	// Method:    移除ServerListenPacket
	// Parameter: EServerType type:	服务器类型
	//************************************
	void Remove(EServerType type);

	//************************************
	// Method:    移除所有ServerListenPacket
	//************************************
	void Remove();

	//************************************
	// Method:    获取指定ip和端口的ServerListenPacket
	// Parameter: peerIp
	// Parameter: peerPort
	//************************************
	ServerListenPacket Get(string peerIp, int peerPort);

	//************************************
	// Method:    获取指定ip和端口的ServerListenPacket
	// Parameter: EServerType type:	服务器类型
	// Parameter: peerIp
	// Parameter: peerPort
	//************************************
	ServerListenPacket Get(EServerType type, string peerIp, int peerPort);

	//************************************
	// Method:    获取指定服务器类型的ServerListenPacket
	// Parameter: vector<ServerListenPacket> & vec
	// Parameter: EServerType type
	//************************************
	void Get(vector<ServerListenPacket>& vec, EServerType type);

	//************************************
	// Method:    获取所有ServerListenPacket
	// Parameter: vector<ServerListenPacket> & vec
	//************************************
	void Get(vector<ServerListenPacket>& vec);

	//************************************
	// Method:    发送所有ServerListenPacket包数据到所有服务器
	//************************************
	void Send2AllServers();
};