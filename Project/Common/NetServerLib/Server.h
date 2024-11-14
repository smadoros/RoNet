//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CServer
// - 메인 프로그램에서 CServer의 객체를 만들어 서버를 구동한다.
//==================================================================================================

#pragma once

#include "ServerDefine.h"
#include "ServerParameter.h"
#include "ServerConfig.h"
#include "PacketBuffer.h"
#include "ListenThread.h"
#include "WorkerThread.h"
#include "LogicThread.h"
#include "MainThread.h"
#include "Session.h"
#include "LanClient.h"
#include "BackgroundWork.h"
#include "ObjectPool.h"

class CServer final
{
private:
	SOCKET listen_socket_ = INVALID_SOCKET;
	SOCKET udp_socket_ = INVALID_SOCKET;
	HANDLE iocp_handle_ = nullptr;

private:
	CServerConfig server_config_;
	CEventHandler event_handler_;
	CPacketHandler packet_handler_;
	CPacketBuffer packet_buffer_;
	
private:
	CSessionMgr session_mgr_;
	CLanClientMgr lan_client_mgr;
	CBackgroundWorkMgr background_work_mgr;

private:
	CListenThread listen_thread_;
	CWorkerThread worker_thread_;
	CLogicThread logic_thread_;
	CMainThread main_thread_;

private:
	CObjectPool<SOCKET_HANDLE> pool_socket_handle_;
	CObjectPool<OVERLAPPED_IO> pool_overlapped_io_;
		
public:
	bool Start( CServerParameter** _parameter );
	void Close();

	void Send( unsigned long _session_id, const char* _message );
	void Send( std::list<unsigned long> _session_ids, const char* _message );
	void SendAll( const char* _message );

	void Send_UDP( unsigned long _session_id, const char* _message );
	void Send_UDP( std::list<unsigned long> _session_ids, const char* _message );
	void SendAll_UDP( const char* _message );

public:
	SOCKET GetSocket();
	HANDLE GetIOCP();
	CServerConfig* GetServerConfig();
	CSessionMgr* GetSessionMgr();
	CEventHandler* GetEventHandler();
	CPacketHandler* GetPacketHandler();
	CPacketBuffer* GetPacketBuffer();
	CLanClientMgr* GetLanClientMgr();
	CBackgroundWorkMgr* GetBackgroundWorkMgr();
	CObjectPool<SOCKET_HANDLE>* GetObjectPool_SocketHandle();
	CObjectPool<OVERLAPPED_IO>* GetObjectPool_OverlappedIO();

private:
	bool _Init_Config( CServerParameter* _parameter );
	bool _Init_Server( CServerParameter* _parameter );
	bool _Init_Socket( CServerParameter* _parameter );
	bool _Init_IOCP( CServerParameter* _parameter );
	bool _Init_Thread( CServerParameter* _parameter );
	bool _Init_BackgroudWork( CServerParameter* _parameter );
	bool _Init_LanClient( CServerParameter* _parameter );
	void _init_Finalize( CServerParameter** _parameter, bool _success );
};