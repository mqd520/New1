#pragma once
#include <vector>
#include <WinSock2.h>
#include <functional>
using namespace std;
using namespace std::placeholders;


#define		TC_ReconnectTime					(3000)					// �Զ��������ʱ��
#define		TC_MaxSendBufLen					(4096)					// Ĭ������ͻ���������
#define		TC_MaxRecvBufLen					(4096)					// Ĭ�������ջ���������
#define		TC_MaxPacketHeadLen					(256)					// ����ͷ�ֽڳ���
#define		TC_MaxPacketLen						(4096)					// �������ֽڳ���
#define		TC_KeepAlive_Timespan				(2 * 1000)				// Ĭ�����������ͼ��ʱ��
#define		TC_KeepAlive_Timeout				(3 * 1000)				// Ĭ����������ʱʱ��
#define		TC_KeepAlive_MaxMissCount			(3)						// Ĭ������ʧ������������
#define		TC_KeepAlive_RecvTimespan			(1 * 1000)				// ����˽��տͻ����������ļ��ʱ��


namespace tc
{
	// socket����
	enum class ESocketType : int
	{
		Accept,			// ���ڽ���������(����˵�socket)
		SendRecvData,	// ������(��)���ݵ�socket
		Connect			// �������ӷ���˵�socket(�ͻ��˵�socket)
	};

	// �첽����״̬
	enum class EAsyncSendStatus : int
	{
		PreSend,	// ׼������
		Sending,	// ���ڷ���
		SendCmp		// �������
	};

	// socket�ź�����
	enum class ESocketSingalType : int
	{
		Read,	// �ɶ�
		Write,	// ��д
		Except	// �쳣
	};

	// socket�¼�����
	enum class ESocketEvtType : int
	{
		RecvNewConn,		// �յ�������
		RecvPeerData,		// �յ��Զ�����
		ConnDisconnect,		// ���ӱ��Ͽ�
		SendPeerData,		// ���ͶԶ�����
		ConnectCpl,			// ���ӷ�������

		None				// ��
	};

	// tcp srv ����
	enum class ETcpSrvType : int
	{
		Server,		// �����
		Client,		// �ͻ���

		None		// ��
	};

	// tcp�¼�����
	enum class ETcpEvtType : int
	{
		RecvNewConn,		// �յ�������
		RecvPeerData,		// �յ��Զ�����
		ConnDisconnect,		// ���ӶϿ�
		ConnectSrvCpl,		// ���ӷ�������

		None				// ��
	};

	// ��־����
	enum class ETcpLogType : int
	{
		Info,		// ��Ϣ
		Warn,		// ����
		Debug,		// ����
		Error,		// ����
		Fatal,		// ���ش���
		Exception,	// ϵͳ�쳣

		None	// ��
	};

	// ���ӶϿ�ԭ��
	enum class EDisconnReason
	{
		Peer,			// �Է��ر�
		Local,			// ���عر�
		Error,			// ����socket����

		Other			// ����ԭ��
	};

	class TcpEvt;
	// tcp�¼��ص�����ָ��
	typedef std::function<void(TcpEvt*, void*, void*)> Fun2;

	// �����ַ
	typedef struct tagNetAddress
	{
		string ip;	// ip
		int port;	// �˿�
	}NetAddress;

	// select����socket���ݽṹ
	typedef struct tagSelectSocketData
	{
		SOCKET	socket;		// socket
		ESocketType type;	// socket����: ESocketType
	}SelectSocketData;

	// ��Զ˷������ݽ��
	typedef struct tagSendPeerDataResult
	{
		TCHAR ip[20];	//�Զ�IP
		int port;		//�Զ˶˿�
		bool success;	//�Ƿ�ɹ�
		int len;		//���������ֽڳ���
		int actualLen;	//ʵ�ʷ����ֽڳ���
	}SendPeerDataResult;

	// socket�ź�����
	typedef struct tagSocketSingalData
	{
		SOCKET socket;					// ���źŵ�socket
		ESocketSingalType singaltype;	// socket�ź�����: ESocketSingalType
		ESocketType sockettype;			// socket����:	ESocketType
	}SocketSingalData;

	// ���ڴ����socket����
	typedef	struct tagProcessingSocketData
	{
		SOCKET socket;			// ���ڴ����socket
		ESocketSingalType type;	// �ź�����: ESocketType
	}ProcessingSocketData;

	// socket��Ϣ����
	typedef struct tagSocketInfoData
	{
		SOCKET socket;		// ������socket
		ESocketType type;	// socket type
		string peerIp;		// �Զ�ip
		int peerPort;		// �Զ˶˿�
		string localIP;		// �����ı���ip
		int localPort;		// �����ı��ض˿�
		int socketId;		// socket id, ����һ��socket
		bool bEnable;		// �Ƿ�����
	}SocketInfoData;

	class Packet;
	// ������
	typedef struct tagPacketData
	{
		Packet* pPck;		// ������
		int cmd;			// ������
		int clientId;		// socket id
		string peerIp;		// peer ip
		int peerPort;		// peer port
	}PacketData;
}

