#pragma once
#include "Def.h"

#include "tc/PacketSrv.h"
#include "tc/Packet.h"
using namespace tc;

namespace pck
{
	// IGPacketSrv
	class IGPacketSrv : public PacketSrv
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: void * pObj: TcpService
		// Parameter: EServerType localType:	���ط���������
		// Parameter: EServerType peerType:		�Զ˷���������
		//************************************
		IGPacketSrv(EServerType localType = EServerType::None);
		virtual ~IGPacketSrv();

	protected:
		EServerType localType;		// ���ط���������
		EServerType peerType;		// peer server type

	protected:
		//************************************
		// Method:    ��ȡ��ͷ����
		//************************************
		virtual PacketHead* GetPacketHead(int cmd, int len) override;

		//************************************
		// Method:    ��ȡ��ͷ����
		//************************************
		virtual int GetPacketHeadLen() override;

		//************************************
		// Method:    �������建����
		// Parameter: PacketHead * pHead:	��ͷ
		// Parameter: pBuf:		������
		// Parameter: len:		����������
		// Parameter: int * len1 ʵ�ʻ���������
		//************************************
		virtual BYTE* ParsePacketBody(PacketHead* pHead, BYTE* pBuf, int len, int* len1) override;

		//************************************
		// Method:    ������ת���ɰ�
		// Parameter: cmd:		������
		// Parameter: pBuf:		������
		// Parameter: len:		����������
		//************************************
		virtual Packet* BufToPacket(int cmd, BYTE* pBuf, int len) override;

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
		virtual void SendPacket(Packet& pck, int clientId = 0) override;

	public:
		//************************************
		// Method:    ��ȡ���ط���������
		// Returns:   pck::EServerType
		//************************************
		virtual EServerType GetLocalServerType();

		//************************************
		// Method:    ��ȡ�Զ˷���������
		// Returns:   pck::EServerType
		//************************************
		virtual EServerType GetPeerServerType();
	};
}