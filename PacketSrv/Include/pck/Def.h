#pragma once

#define		PCR_PacketHeadLen					(7)						// ��ͷ����
#define		PCR_PacketHeadMask					(32616)					// ��ͷmask
#define		PCR_MaxPacketLen					(2048)					// �����ܳ���
#define		PCR_Version							(0x0007)				// �汾
#define		PCR_Connect_Timeout					(2 * 1000)				// ��֤�ͻ�������͵�¼���������ʱʱ��
#define		PCR_KeepAlive_Timespan				(3 * 1000)				// Ĭ�����������ͼ��ʱ��
#define		PCR_KeepAlive_Timeout				(11 * 1000)				// Ĭ����������ʱʱ��
#define		PCR_KeepAlive_MaxMissCount			(3)						// Ĭ������ʧ������������
#define		PCR_KeepAlive_RecvTimespan			(1 * 1000)				// ����˽��տͻ����������ļ��ʱ��

namespace pck
{
	// Server type
	enum class EServerType : int
	{
		Plaza = 3,				// Plaza
		Center = 5,				// Center

		None = -1				// None
	};

	// Server Id
	enum class EServerId : int
	{
		Plaza		= 1,		// Plaza

		None					// None
	};
}