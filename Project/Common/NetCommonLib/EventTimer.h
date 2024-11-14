//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CEventTimer
// - IsSpawn �Լ��� ���� ������ �ð��� ����ߴ��� Ȯ���Ͽ�, �̺�Ʈ�� ó���Ѵ�.
//==================================================================================================

#pragma once

#include "pch.h"

class CEventTimer final
{
	UINT term_time_;
	std::chrono::system_clock::time_point old_tp_;

public:
	CEventTimer();
	~CEventTimer();

public:
	void Reset();
	bool IsSpawn();
	unsigned long GetElapsedTime();
	unsigned long GetElapsedTime( std::chrono::system_clock::time_point _tp );
	void SetOldTp( std::chrono::system_clock::time_point _tp );
	void SetTermTime( UINT _term_time );
};

