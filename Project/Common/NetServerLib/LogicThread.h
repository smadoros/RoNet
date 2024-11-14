//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CLogicThread
// - 로직 스레드 (싱글 스레드)
//==================================================================================================

#pragma once

#include "SingleThread.h"

class CLogicThread final : public CSingleThread
{
public:
	virtual void _Run();
};