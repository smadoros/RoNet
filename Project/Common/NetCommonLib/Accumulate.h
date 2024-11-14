//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CAccumulate
// - Numeric 값을 수집하여, 정보를 제공한다.
//==================================================================================================

#pragma once

#include "pch.h"

class CAccumulate final
{
	std::atomic<unsigned long> count_;
	std::atomic<unsigned long> accum_;

public:
	CAccumulate();
	~CAccumulate();

public:
	void Add( unsigned long _ms_t );
	unsigned long Avg();
	unsigned long Count();
	void Reset();
};