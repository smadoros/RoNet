//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CSession
// - ���� ���� �� �����Ǵ� ���� ����.
// - iocp�� ����� ���� �ڵ�� �������� �߱��� UID�� ������.
// 
// CSessionMgr
// - CSession ��ü���� �������� ���� ���·� �����Ѵ�.
//==================================================================================================

#pragma once

class CSession final
{
private:
	unsigned long session_uid_;
	SOCKET socket_handle_;
	SOCKADDR_IN socket_addr_;

public:
	CSession( unsigned long _session_uid, SOCKET _handle, SOCKADDR_IN* _addr );
	~CSession();

public:
	unsigned long GetUID();
	SOCKET GetSocket();
	SOCKADDR_IN* GetAddr();
	void Release();
};

class CSessionMgr
{
private:
	concurrency::concurrent_unordered_map<unsigned long, CSession*> sessions_;
	std::atomic<unsigned long> identity_ = 1000000000;
	std::mutex mutex_;

public:
	CSessionMgr();
	~CSessionMgr();
	void Release();

public:
	CSession* AddSession( SOCKET _handle, SOCKADDR_IN* _addr  );
	void DeleteSession( unsigned long _session_uid );
	CSession* GetSession( unsigned long _session_uid );
	void GetSessionUIDs( std::list<unsigned long>& _session_uids );

private:
	unsigned long _GetIdentity();
};

