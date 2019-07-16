#pragma once
#include "Def.h"
#include "IGPacketSrv.h"

#include "tc/TcpClient.h"
#include "tc/KeepAliveClient.h"
using namespace tc;

namespace pck
{
	// ig包通信服务
	class IGPacketSrvClient : public TcpClient, public IGPacketSrv, public KeepAliveClient
	{
	public:
		//************************************
		// Method:    构造函数
		// Parameter: EServerType localType:	本地服务器类型
		// Parameter: EServerType peerType:		对端服务器类型
		// Parameter: string ip:	ip
		// Parameter: int port:		port
		// Parameter: bool bSendPwd:	是否需要向服务端发送密码
		//************************************
		IGPacketSrvClient(
			string ip = "", int port = 0,
			EServerType localType = EServerType::None,
			EServerType peerType = EServerType::None, bool bSendPwd = true);
		virtual ~IGPacketSrvClient();

	protected:
		bool bSendPwd;				// 是否需要向服务端发送密码
		EServerType peerType;		// 对端服务器类型

	protected:
		//************************************
		// Method:    连接服务端完成事件处理
		// Parameter: pEvt: tcp evt
		//************************************
		virtual void OnConnectSrvCpl(ConnectSrvCplEvt* pEvt) override;

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
		// Method:    向服务端发送密码
		//************************************
		virtual void SendPwd();

		//************************************
		// Method:    发送登录服务端请求包
		//************************************
		virtual void SendLoginSrvRequestPck();

		//************************************
		// Method:    登录服务成功事件处理
		//************************************
		virtual void OnLoginSrvSuccess();

		//************************************
		// Method:    发送心跳包
		//************************************
		virtual void SendKeepAlive(int clientId = 0) override;

		//************************************
		// Method:    丢失心跳包事件处理
		// Parameter: count:	连续丢失次数
		// Parameter: b:	是否已超过允许最大次数
		//************************************
		virtual void OnMissKeepAlive(int count, bool b = true) override;

	public:
		//************************************
		// Method:    发包
		// Parameter: Packet & pck
		//************************************
		virtual void SendPck(Packet& pck);

		//************************************
		// Method:    获取对端服务器类型
		// Returns:   pck::EServerType
		//************************************
		virtual EServerType GetPeerServerType();

		//************************************
		// Method:    退出
		//************************************
		virtual void Exit() override;
	};
}