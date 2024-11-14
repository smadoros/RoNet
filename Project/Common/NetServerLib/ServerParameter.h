//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CServerParameter
// - 서버 파라미터(인자값).
// - 객체의 소유권을 서버로 넘긴다.
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
	CAbstractServerConfig* server_config;			//< 서버 설정 객체
	CAbstractEventFunction* event_function;			//< 이벤트 핸들러 델리게이트
	CAbstractPacketFunction* packet_function;		//< 패킷 핸들러 델리게이트
	std::vector<CBackgroundWork*> background_works;	//< 백그라운드 실행 객체

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
