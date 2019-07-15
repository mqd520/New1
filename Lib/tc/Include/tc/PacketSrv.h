#pragma once
#include "PacketHead.h"
#include "Packet.h"
#include "MemoryStream.h"
#include "TcpEvt.h"

namespace tc
{
	// ���ڰ���ͨ�ŷ���
	class PacketSrv
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: void * pObj:	TcpServce
		// Parameter: bool bBigByteOrder:	�Ƿ�ʹ�ô���ֽ���
		//************************************
		PacketSrv(void* pObj = NULL, bool bBigByteOrder = true);
		virtual ~PacketSrv();

	protected:
		MemoryStream ms;			// �ڴ�������
		void* pObjPS;				// ������tcp�������
		bool bBigByteOrder;			// �Ƿ���ô���ֽ���

	private:
		//************************************
		// Method:    ��ȡ�Զ�ip
		// Parameter: int clientId
		//************************************
		string GetPeerIp(int clientId = 0);

		//************************************
		// Method:    ��ȡ�Զ�port
		// Parameter: int clientId
		//************************************
		int GetPeerPort(int clientId = 0);

	protected:
		//************************************
		// Method:    ����TcpServce����
		// Parameter: void pObj
		//************************************
		virtual void AttachTcpServiceObj(void* pObj);

		//************************************
		// Method:    ��ȡ��ͷ����
		// Parameter: ������
		// Parameter: ���峤��
		//************************************
		virtual PacketHead* GetPacketHead(int cmd, int len);

		//************************************
		// Method:    ��ȡ��ͷ����
		//************************************
		virtual int GetPacketHeadLen();

		//************************************
		// Method:    ������ջ���������
		// Parameter: pBuf:		������
		// Parameter: len:		����������
		// Parameter: clientId:	�ͻ���id
		//************************************
		virtual void ProcessRecvBuf(BYTE* pBuf, int len, int clientId = 0);

		//************************************
		// Method:    ������
		//************************************
		virtual void ParsePacket(vector<PacketData>& vec);

		//************************************
		// Method:    ������ͷ������
		// Parameter: pBuf:		������
		// Parameter: len:		����������
		//************************************
		virtual PacketHead* ParsePacketHead(BYTE* pBuf, int len);

		//************************************
		// Method:    �������建����
		// Parameter: PacketHead * pHead:	��ͷ
		// Parameter: pBuf:		������
		// Parameter: len:		����������
		// Parameter: int * len1 ʵ�ʻ���������
		//************************************
		virtual BYTE* ParsePacketBody(PacketHead* pHead, BYTE* pBuf, int len, int* len1);

		//************************************
		// Method:    ������ת���ɰ�
		// Parameter: cmd:		������
		// Parameter: pBuf:		������
		// Parameter: len:		����������
		//************************************
		virtual Packet* BufToPacket(int cmd, BYTE* pBuf, int len);

		//************************************
		// Method:    Ԥ�������
		// Parameter: data:	������
		//************************************
		virtual void PreProcessPck(PacketData& pd);

		//************************************
		// Method:    ������¼��������
		// Parameter: data:	������
		//************************************
		virtual void OnProcessPck(PacketData& pd);

		//************************************
		// Method:    ���ɰ�������
		// Returns:   �������ֽڳ���
		// Parameter: Packet & pck
		// Parameter: BYTE * pBuf:	������
		// Parameter: int len:		����������
		// Parameter: void * pHeadParam1:	��ͷ���Ӳ���1
		// Parameter: void * pHeadParam2:	��ͷ���Ӳ���2
		// Parameter: void * pPacketParam1:	���帽�Ӳ���1
		// Parameter: void * pPacketParam2: ���帽�Ӳ���2
		//************************************
		virtual int BuildPacketBuf(Packet& pck, BYTE* pBuf, int len,
			void* pHeadParam1 = NULL, void* pHeadParam2 = NULL, void* pPacketParam1 = NULL, void* pPacketParam2 = NULL);

		//************************************
		// Method:    ���ɰ�ͷ������
		// Returns:   �������ֽڳ���
		// Parameter: int cmd:	������
		// Parameter: int len:	���峤��
		// Parameter: BYTE * pBuf:	������
		// Parameter: int nLen:		����������
		// Parameter: void * pParam1:	��ͷ���Ӳ���1
		// Parameter: void * pParam2:	��ͷ���Ӳ���
		//************************************
		virtual int BuildPacketHeadBuf(int cmd, int len, BYTE* pBuf, int nLen, void* pParam1 = NULL, void* pParam2 = NULL);

		//************************************
		// Method:    ���ɰ��建����
		// Returns:   �������ֽڳ���
		// Parameter: Packet & pck
		// Parameter: BYTE * pBuf:	������
		// Parameter: int len:		����������
		// Parameter: void * pParam1:	���帽�Ӳ���1
		// Parameter: void * pParam2:	���帽�Ӳ���2
		//************************************
		virtual int BuildPacketBodyBuf(Packet& pck, BYTE* pBuf, int len, void* pParam1 = NULL, void* pParam2 = NULL);

		//************************************
		// Method:    ����
		// Parameter: Packet & pck
		// Parameter: int clientId
		//************************************
		virtual void SendPacket(Packet& pck, int clientId = 0);

		//************************************
		// Method:    ����
		// Parameter: BYTE * pBuf:	������
		// Parameter: int len:		����������
		// Parameter: int clientId
		//************************************
		virtual void SendPacketBuf(BYTE* pBuf, int len, int clientId = 0);

	public:
		//************************************
		// Method:    �Ƿ�ʹ�ô���ֽ���
		//************************************
		bool IsBigByteOrder() const;

		//************************************
		// Method:    �˳�
		//************************************
		virtual void Exit();
	};
}