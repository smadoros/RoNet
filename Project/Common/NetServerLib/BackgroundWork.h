//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CBackgroundWork
// - MainThread loop에서 호출되는 작업
// - 실제 객체는 이 클래스를 상속받아 작업을 정의한다.
// 
// CBackgroundWorkMgr
// - CBackgroundWork 객체들의 소유권을 가진 상태로 관리한다.
//==================================================================================================

#pragma once

#include "EventTimer.h"

#define BACKGROUND_WORK_NAME_LENGTH 32

class CBackgroundWork
{
protected:
	char name_[ BACKGROUND_WORK_NAME_LENGTH ];
	CEventTimer timer_;

public:
	CBackgroundWork( const char* _name, UINT _spawn_term );
	virtual ~CBackgroundWork();
	
public:
	void Init();
	void Start();
	void Update();
	void Release();

protected:
	virtual void _Init() = 0;
	virtual void _Start() = 0;
	virtual void _Update() = 0;
	virtual void _Release() = 0;
};

class CBackgroundWorkMgr
{
	std::vector<CBackgroundWork*> background_works;

public:
	CBackgroundWorkMgr();
	~CBackgroundWorkMgr();
	void Release();

public:
	void Init();
	void Start();
	void Update();

public:
	void AddWork( CBackgroundWork* _background_work );
};