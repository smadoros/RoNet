#include "stdafx.h"
#include "ServerEventHandler.h"

void CServerEventFunction::Connect( unsigned long _uid )
{
	printf_s( "[Session: %d] (Event) Connect\n", _uid );
}

void CServerEventFunction::Disconnect( unsigned long _uid, bool _explicit )
{
	printf_s( "[Session: %d] (Event) Disconnect\n", _uid );
}

void CServerEventFunction::PrefareSend( unsigned long _uid )
{
	printf_s( "[Session: %d] (Event) Ready to send\n", _uid );
}

void CServerEventFunction::Send( unsigned long _uid )
{
	printf_s( "[Session: %d] (Event) Send\n", _uid );
}

void CServerEventFunction::Receive( unsigned long _uid )
{
	printf_s( "[Session: %d] (Event) Receive\n", _uid );
}

void CServerEventFunction::PrefareSend_UDP( unsigned long _uid )
{
	printf_s( "[Session: %d] (Event) Ready to send (udp)\n", _uid );
}

void CServerEventFunction::Send_UDP( unsigned long _uid )
{
	printf_s( "[Session: %d] (Event) Send (udp)\n", _uid );
}

void CServerEventFunction::Receive_UDP( unsigned long _uid )
{
	printf_s( "[Session: %d] (Event) Receive (udp)\n", _uid );
}