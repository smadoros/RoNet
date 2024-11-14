//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CServerParameter
// - ���� �Ķ����(���ڰ�).
// - ��ü�� �������� ������ �ѱ��.
//==================================================================================================

#pragma once

#include "pch.h"
#include "CommonDefine.h"
#include "ServerConfig.h"
#include "EventHandler.h"
#include "PacketHandler.h"
#include "BackgroundWork.h"

class CServerParameter final
{
private:
	CAbstractServerConfig* server_config;			//< ���� ���� ��ü
	CAbstractEventFunction* event_function;			//< �̺�Ʈ �ڵ鷯 ��������Ʈ
	CAbstractPacketFunction* packet_function;		//< ��Ŷ �ڵ鷯 ��������Ʈ
	std::vector<CBackgroundWork*> background_works;	//< ��׶��� ���� ��ü

public:
	CServerParameter();
	~CServerParameter();

	void ServerConfig( CAbstractServerConfig* _config );
	CAbstractServerConfig* ServerConfig();

	void EventHandler( CAbstractEventFunction* _handler );
	CAbstractEventFunction* EventHandler();

	void PacketHandler( CAbstractPacketFunction* _handler );
	CAbstractPacketFunction* PacketHandler();

	void BackgroundWork( CBackgroundWork* _work );
	CBackgroundWork* BackgroundWork();
};
