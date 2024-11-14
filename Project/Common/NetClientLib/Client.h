#pragma once

#include "ClientDefine.h"
#include "ClientParameter.h"
#include "ReceiveThread.h"

class CClient final
{
private:
	unsigned long client_uid_ = 0;
	SOCKET connect_socket_ = INVALID_SOCKET;
	SOCKADDR_IN socket_addr_;
	BYTE connect_state_ = CLIENT_STATE_DISCONNECTED;

private:
	CEventHandler event_handler_;
	CPacketHandler packet_handler_;
	CReceiveThread receive_thread_;

public:
	bool Start( CClientParameter** _parameter );
	void Close();
	bool Send( const char* _message, int _length );
	bool Send_UDP( const char* _message, int _length );

public:
	unsigned long GetUID();
	SOCKET GetSocket();
	CEventHandler* GetEventHandler();
	CPacketHandler* GetPacketHandler();
	
public:
	void SetState( BYTE _state );
	bool IsConnect();
	bool IsDisconnect();
	bool IsPending();
	
private:
	bool _Init_Client( CClientParameter* _parameter );
	bool _Init_Socket( CClientParameter* _parameter );
	bool _Init_Thread( CClientParameter* _parameter );
	void _init_Finalize( CClientParameter** _parameter, bool _success );

private:
	unsigned long _GetIdentity();
};