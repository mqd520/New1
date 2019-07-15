#include "stdafx.h"
#include "BAAdminWebSiteService.h"
#include "Log.h"
#include "CenterService.h"
#include "Config.h"

#include "com/HttpRequest.h"
#include "com/HttpResponse.h"
#include "com/CommonTool.h"
#include "com/StringTool.h"
using namespace com;

#include "pck/ServerListenPacket.h"
using namespace pck;

#include "json/json.h"
#include "json/reader.h"
#include "json/writer.h"


#define MaxHttpResponseLen			(1024)			// max http response buf len


const char* reqPaths[] = { "/GetPlazaSrvAddr" };				// 允许的请求路径集合
const int nReqCount = sizeof(reqPaths) / sizeof(char*);			// 允许的请求路径集合长度


BAAdminWebSiteService::BAAdminWebSiteService(string ip /*= ""*/, int port /*= 0*/) :
TcpServer(ip, port)
{

}

BAAdminWebSiteService::~BAAdminWebSiteService()
{

}

void BAAdminWebSiteService::OnRecvNewConnection(RecvNewConnEvt* pEvt)
{
	__super::OnRecvNewConnection(pEvt);
}

void BAAdminWebSiteService::OnRecvPeerData(RecvPeerDataEvt* pEvt)
{
	HttpRequest req;
	HttpRequest::Parse(req, pEvt->GetRecvBuf(), pEvt->GetBufLen());

	bool b = false;
	if (req.method == "GET")
	{
		for (int i = 0; i < nReqCount; i++)
		{
			if (reqPaths[i] == req.path)
			{
				b = true;
				break;
			}
		}
	}

	WriteLog(b ? ELogType::Info : ELogType::Debug, true,
		"recv backstage website http request, url: %s, method: %s, ip: %s", req.url.c_str(), req.method.c_str(), pEvt->GetPeerIp().c_str());

	if (b)
	{
		Json::Value root;

		vector<ServerListenPacket> vec;
		CenterService::GetInstance()->GetServerListenPacketMgr()->Get(vec, EServerType::Plaza);
		if ((int)vec.size() > 0)
		{
			root["port"] = Json::Value(vec[0].nH5Port);
			root["ip"] = Json::Value(CommonTool::ConvertIP(vec[0].nIP));
			root["domainame"] = Json::Value(vec[0].strDomainName);
			root["wssport"] = Json::Value(vec[0].nWssPort);
		}


		Json::FastWriter fw;
		string jsonStr = fw.write(root);

		HttpResponse response;
		response.SetResponseContent((BYTE*)jsonStr.c_str(), jsonStr.size());

		BYTE buf[MaxHttpResponseLen] = { 0 };
		int len = response.BuildBuf(buf, MaxHttpResponseLen);
		__super::Send(pEvt->GetSendRecvSocketId(), buf, len);
	}

	__super::CloseClient(pEvt->GetSendRecvSocketId());
}

void BAAdminWebSiteService::Init()
{
	__super::Init();

	vector<string> vec;
	StringTool::Split(_cfg.ba.strAllowIps, vec, ",");

	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		__super::AddAllowIP(*it);
	}
}