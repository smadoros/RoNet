//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CClientParameter
// - 클라이언트 파라미터(인자값).
// - 객체의 소유권을 클라이언트로 넘긴다.
//==================================================================================================

#pragma once

#include "pch.h"
#include "EventHandler.h"
#include "PacketHandler.h"
#include "CommonDefine.h"

class CClientParameter final
{
private:
	char server_ip[ COMMON_DEFINE_IP_LENGTH ];	//< 접속 IP			
	USHORT server_port = 0;						//< 접속 포트
	CAbstractEventFunction* event_function;		//< 이벤트 핸들러 델리게이트
	CAbstractPacketFunction* packet_function;	//< 패킷 핸들러 델리게이트

public:
	CClientParameter();
	~CClientParameter();

	void IP( const char* _ip );
	const char* IP();

	void Port( USHORT _port );
	USHORT Port();

	void EventHandler( CAbstractEventFunction* _handler );
	CAbstractEventFunction* EventHandler();

	void PacketHandler( CAbstractPacketFunction* _handler );
	CAbstractPacketFunction* PacketHandler();
};
