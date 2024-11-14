#include "stdafx.h"
#include "PacketDispatch.h"
#include "Server.h"

extern std::shared_ptr<CServer> g_server;

void CPacketDispatchChat::CS_CHAT( unsigned long _session_uid, CPacket_CS_CHAT* _pkt )
{
	//< send tcp
	char echo_msg[ 256 ] = { 0, };
	sprintf_s( echo_msg, 256, "Echo : %s", _pkt->data.message().c_str() );
	g_server->Send( _session_uid, echo_msg );

	//< send udp
	char broadcast_msg[ 256 ] = { 0, };
	sprintf_s( broadcast_msg, 256, "Broadcast : %s (From Session:%d)", _pkt->data.message().c_str(), _session_uid );
	g_server->SendAll_UDP( broadcast_msg );
}