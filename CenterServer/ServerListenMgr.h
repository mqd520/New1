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
	vector<ServerListenInfo> vecPcks;		// ServerListenInfo��Ϣ����
	Timer t;								// ��ʱ��, �����з���������ServerListenPacket����

private:
	//************************************
	// Method:    ��ʱ���¼�����
	// Parameter: ��ʱ������
	// Parameter: ����
	// Parameter: void * pParam1
	// Parameter: void * pParam2
	//************************************
	void OnTimer(Timer* pTimer, int count, void* pParam1 = NULL, void* pParam2 = NULL);

public:
	//************************************
	// Method:    ��ʼ��
	//************************************
	void Init();

	//************************************
	// Method:    �˳�
	//************************************
	void Exit();

	//************************************
	// Method:    ���ServerListenPacket
	// Parameter: ServerListenPacket pck
	// Parameter: peerIp
	// Parameter: peerPort
	//************************************
	void Add(ServerListenPacket& pck, string peerIp, int peerPort);

	//************************************
	// Method:    �Ƴ�ServerListenPacket
	// Parameter: ServerListenPacket pck
	//************************************
	void Remove(ServerListenPacket& pck);

	//************************************
	// Method:    �Ƴ�ָ��IP��ServerListenPacket
	// Parameter: EServerType type:	����������
	// Parameter: peerIp
	// Parameter: peerPort
	//************************************
	ServerListenPacket Remove(string peerIp, int peerPort);

	//************************************
	// Method:    �Ƴ�ServerListenPacket
	// Parameter: EServerType type:	����������
	//************************************
	void Remove(EServerType type);

	//************************************
	// Method:    �Ƴ�����ServerListenPacket
	//************************************
	void Remove();

	//************************************
	// Method:    ��ȡָ��ip�Ͷ˿ڵ�ServerListenPacket
	// Parameter: peerIp
	// Parameter: peerPort
	//************************************
	ServerListenPacket Get(string peerIp, int peerPort);

	//************************************
	// Method:    ��ȡָ��ip�Ͷ˿ڵ�ServerListenPacket
	// Parameter: EServerType type:	����������
	// Parameter: peerIp
	// Parameter: peerPort
	//************************************
	ServerListenPacket Get(EServerType type, string peerIp, int peerPort);

	//************************************
	// Method:    ��ȡָ�����������͵�ServerListenPacket
	// Parameter: vector<ServerListenPacket> & vec
	// Parameter: EServerType type
	//************************************
	void Get(vector<ServerListenPacket>& vec, EServerType type);

	//************************************
	// Method:    ��ȡ����ServerListenPacket
	// Parameter: vector<ServerListenPacket> & vec
	//************************************
	void Get(vector<ServerListenPacket>& vec);

	//************************************
	// Method:    ��������ServerListenPacket�����ݵ����з�����
	//************************************
	void Send2AllServers();
};