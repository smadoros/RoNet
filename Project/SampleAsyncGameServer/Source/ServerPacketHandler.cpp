#include "stdafx.h"
#include "ServerPacketHandler.h"
#include "Server.h"
#include "PacketCommon.h"
#include "PacketSerializer.h"
#include "PacketDispatch.h"

void CServerPacketFunction::Dispatch( unsigned long _uid, char* _message )
{
	CPacketSerializer serializer;
	serializer.Deserialize( _message );

	//< 델리게이트 형식으로 바꿔야 함.

	COMMON_PACKET::COMMON_PROTOCOL protocol = (COMMON_PACKET::COMMON_PROTOCOL)(serializer.GetPacket()->GetProtocol());

	if( COMMON_PACKET::CS_CHAT == protocol )
	{
		printf_s( "[Session: %d] (PacketDispath: %d)\n", _uid, protocol );

		CPacketDispatchChat::CS_CHAT( _uid, (CPacket_CS_CHAT*)serializer.GetPacket() );
	}
	else
	{
		printf_s( "[Session: %d] (PacketDispath: %d) Unknown protocol\n", _uid, protocol );
	}
}