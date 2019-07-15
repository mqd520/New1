#pragma once

#include <WinSock2.h>
#include <vector>
#include <queue>
#include "Def.h"
#include "ThreadLock.h"

using namespace std;

namespace tc
{
	// socket���ݹ�����
	class SocketDataMgr
	{
	public:
		SocketDataMgr();
		~SocketDataMgr();

	private:
		vector<SocketInfoData> vecSocketData;	// socket���ݼ���
		CThreadLock lock1;						// �߳���, ���: vecSocketData

		queue<SOCKET> quRemovedSockets;			// removed sockets

	private:
		//************************************
		// Method:    ����һ��socket id
		//************************************
		int CreateSocketId(SOCKET socket);

	public:
		//************************************
		// Method:    ���һ��socket
		// Parameter: SOCKET socket:	socket
		// Parameter: ESocketType type:	socket����
		// Parameter: bEnable: �Ƿ���������
		//************************************
		void Add(SOCKET socket, ESocketType type, bool bEnable = true);

		//************************************
		// Method:    �Ƴ�һ��socket
		// Parameter: SOCKET socket:	socket
		//************************************
		SocketInfoData Remove(SOCKET socket);

		//************************************
		// Method:    �Ƴ�һ��socket
		// Parameter: SOCKET socket:	socket
		// Parameter: ESocketType type:	socket type
		//************************************
		SocketInfoData Remove(SOCKET socket, ESocketType type);

		//************************************
		// Method:    �������socket
		//************************************
		void Clear();

		//************************************
		// Method:    ��ȡָ�����͵�socket���ݼ���
		// Parameter: ESocketType type:	socket����
		//************************************
		vector<SOCKET> GetSocketData(ESocketType type);

		//************************************
		// Method:    ��ȡ����socket����
		//************************************
		vector<SocketInfoData> GetSocketData();

		//************************************
		// Method:    ��ȡsocket data
		//************************************
		SocketInfoData GetSocketData(SOCKET socket);

		//************************************
		// Method:    ��ȡsocket data
		//************************************
		SocketInfoData GetSocketData(int socketId);

		//************************************
		// Method:    ��ȡָ��socket������
		// Parameter: SOCKET socket:	socket
		//************************************
		ESocketType GetSocketType(SOCKET socket);

		//************************************
		// Method:    Enable Socket
		// Parameter: SOCKET socket
		// Parameter: bool bEnable
		//************************************
		void EnableSocket(SOCKET socket, bool bEnable = true);

		void ProcessRemovedSocket();
	};
}