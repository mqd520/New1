#pragma once
#include "Def.h"
#include "IGPacketSrv.h"
#include "ServerSessionMgr.h"
#include "PacketCmd.h"

#include "tc/TcpServer.h"

namespace pck
{
	// IGPacketSrvServer 
	class IGPacketSrvServer : public TcpServer, public IGPacketSrv
	{
	public:
		//************************************
		// Method:    Constructor
		// Parameter: string ip
		// Parameter: int port
		// Parameter: EServerType localType
		// Parameter: bool bRecvPwd: is recv client pwd
		//************************************
		IGPacketSrvServer(
			string ip = "", int port = 0,
			EServerType localType = EServerType::None,
			bool bRecvPwd = true
			);

		virtual ~IGPacketSrvServer();

	protected:
		bool bRecvPwd;				// 是否需要接受客户端密码
		int nCurClientId;			// 当前会话的客户端Id
		ServerSessionMgr serverSessionMgr;		// server session mgr

	protected:
		friend class ServerSession;

		//************************************
		// Method:    Recv new connection evt handle
		// Parameter: pEvt: tcp evt
		//************************************
		virtual void OnRecvNewConnection(RecvNewConnEvt* pEvt) override;

		//************************************
		// Method:    Recv peer data evt handle
		// Parameter: pEvt: tcp evt
		//************************************
		virtual void OnRecvPeerData(RecvPeerDataEvt* pEvt) override;

		//************************************
		// Method:    Connection disconnect evt handle
		// Parameter: pEvt: tcp evt
		//************************************
		virtual void OnConnDisconnect(ConnDisconnectEvt* pEvt) override;

		//************************************
		// Method:    Preprocess packet
		// Parameter: data: packet data
		//************************************
		virtual void PreProcessPck(PacketData& data) override;

		//************************************
		// Method:    登录服务端请求事件处理
		// Returns:   是否认为登录成功 (是: 将发送LoginSrvResultPacket包, 否: 不发送并关闭连接)
		// Parameter: data: packet data
		//************************************
		virtual bool OnLoginSrvRequest(PacketData& data);

		//************************************
		// Method:    处理登录服务端处理结果
		// Parameter: PacketData & data
		// Parameter: success: 是否成功
		//************************************
		virtual void ProcessLoginSrvResult(PacketData& data, bool success = true);

		//************************************
		// Method:    发送登录服务端结果包
		// Parameter: int clientId
		//************************************
		virtual void SendLoginSrvResultPck(int clientId);

		//************************************
		// Method:    session关闭事件处理
		// Parameter: int clientId
		//************************************
		virtual void OnSessionClose(int clientId);

		//************************************
		// Method:    发送心跳包
		//************************************
		virtual void SendKeepAlive(int clientId = 0);

		//************************************
		// Method:    丢失心跳包事件处理
		// Parameter: int clientId
		// Parameter: count:	连续丢失次数
		// Parameter: b:	是否已超过允许最大次数
		//************************************
		virtual void OnMissKeepAlive(int clientId, int count, bool b = true);

	public:
		//************************************
		// Method:    发包
		// Parameter: 包数据
		// Parameter: 客户端id
		//************************************
		virtual void SendPck(Packet& pck, int clientId);

		//************************************
		// Method:    退出
		//************************************
		virtual void Exit() override;

		//************************************
		// Method:    关闭客户端
		// Parameter: int clientId
		// Parameter: bool b
		//************************************
		void CloseClient(int clientId, bool b = true) override;
	};
}