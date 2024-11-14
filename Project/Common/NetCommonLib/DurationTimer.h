//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CDurationTimer
// - 시간 경과를 확인하고, 수집기에 적재한다.
//==================================================================================================

#pragma once

#include "pch.h"
#include "Accumulate.h"

class CDurationTimer final
{
	std::chrono::system_clock::time_point old_tp_;
	bool is_start_;
	CAccumulate* accumulate_;

public:
	CDurationTimer();
	CDurationTimer( CAccumulate* _accumulate );
	~CDurationTimer();

public:
	void SetAccumululate( CAccumulate* _accumulate );
	void Start();
	long Stop();
};

