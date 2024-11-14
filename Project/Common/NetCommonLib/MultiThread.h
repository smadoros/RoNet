//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CMultiThread
// - �������� �����带 ����, �����Ѵ�.
//==================================================================================================

#pragma once

#include "CommonDefine.h"

class CMultiThread
{
protected:
	char thread_name_[ COMMON_DEFINE_THREAD_NAME_LENGTH ];
	HANDLE* thread_handles_;
	bool thread_run_;
	LPVOID thread_arg_;
	DWORD thread_wait_t_;
	UINT thread_count_;

protected:
	CMultiThread();
	virtual ~CMultiThread();

public:
	bool Begin( const char* _name, LPVOID _arg, DWORD _wait_t, UINT _count );
	void Release();

private:
	static unsigned int WINAPI Run( LPVOID _arg );

protected:
	virtual void _Run() = 0;
};