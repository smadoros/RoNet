#include "stdafx.h"
#include "ClientEventHandler.h"

CClientEventFunction::CClientEventFunction()
{
	timer_.SetAccumululate( &time_accumulater_ );
}

CClientEventFunction::~CClientEventFunction()
{
}

void CClientEventFunction::Connect( unsigned long _uid )
{
	printf_s( "[Client: %d] (Event) Connect\n", _uid );
}

void CClientEventFunction::Disconnect( unsigned long _uid, bool _explicit )
{
	printf_s( "[Client: %d] (Event) Disconnect\n", _uid );
}

void CClientEventFunction::PrefareSend( unsigned long _uid )
{
	printf_s( "[Client: %d] (Event) Ready to send\n", _uid );

	timer_.Start();
}

void CClientEventFunction::Send( unsigned long _uid )
{
	printf_s( "[Client: %d] (Event) Send\n", _uid );
}

void CClientEventFunction::Receive( unsigned long _uid )
{
	unsigned long elapsed_t = timer_.Stop();

	if( 0 <= elapsed_t )
	{
		printf_s( "[Client: %d] (Event) Receive (latency:%dms)\n", _uid, elapsed_t );
	}
	else
	{
		printf_s( "[Client: %d] (Event) Receive\n", _uid );
	}
}

void CClientEventFunction::PrefareSend_UDP( unsigned long _uid )
{
	printf_s( "[Client: %d] (Event) Ready to send (udp)\n", _uid );
}

void CClientEventFunction::Send_UDP( unsigned long _uid )
{
	printf_s( "[Client: %d] (Event) Send (udp)\n", _uid );
}

void CClientEventFunction::Receive_UDP( unsigned long _uid )
{
	printf_s( "[Client: %d] (Event) Receive (udp)\n", _uid );
}
