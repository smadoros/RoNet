//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CClientParameter
// - Ŭ���̾�Ʈ �Ķ����(���ڰ�).
// - ��ü�� �������� Ŭ���̾�Ʈ�� �ѱ��.
//==================================================================================================

#pragma once

#include "pch.h"
#include "EventHandler.h"
#include "PacketHandler.h"
#include "CommonDefine.h"

class CClientParameter final
{
private:
	char server_ip[ COMMON_DEFINE_IP_LENGTH ];	//< ���� IP			
	USHORT server_port = 0;						//< ���� ��Ʈ
	CAbstractEventFunction* event_function;		//< �̺�Ʈ �ڵ鷯 ��������Ʈ
	CAbstractPacketFunction* packet_function;	//< ��Ŷ �ڵ鷯 ��������Ʈ

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
