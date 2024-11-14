#include "stdafx.h"
#include "ClientPacketHandler.h"

void CClientPacketFunction::Dispatch( unsigned long _uid, char* _message )
{
	printf_s( "[Client: %d] (PacketDispath) %s\n", _uid, _message );
}