//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CLanClient
// - 서버 간 통신을 위한 클라이언트
// 
// CLanClientMgr
// - CLanClient 객체들의 소유권을 가진 상태로 관리한다.
//==================================================================================================

#pragma once

#include "CommonDefine.h"
#include "EventTimer.h"
#include "Client.h"

class CLanClient final
{
private:
	concurrency::concurrent_vector<CClient*> clients_;
	std::atomic<USHORT> identity_ = 0;
	USHORT connect_count_;
	CHAR connect_ip_[ COMMON_DEFINE_IP_LENGTH ];
	USHORT connect_port_;

public:
	CLanClient();
	~CLanClient();
	void Release();

public:
	bool Init( const char* _ip, USHORT _port, USHORT _count );
	bool Send( const char* _message );
	void ReConnect();

private:
	CClient* _GetClient();
};

class CLanClientMgr
{
private:
	concurrency::concurrent_unordered_map<std::string, CLanClient*> lan_clients_;
	CEventTimer timer_;
	std::mutex mutex_;

public:
	CLanClientMgr();
	~CLanClientMgr();
	void Release();

public:
	bool Send( std::string _flavor, char* _message );
	void Update();

public:
	CLanClient* AddLanClient( std::string _flavor, std::string _ip, USHORT _port, USHORT _count );
	CLanClient* GetLanClient( std::string _flavor );
};