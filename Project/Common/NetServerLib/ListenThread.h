//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CListenThread
// - 소켓 리스닝 스레드 (싱글스레드)
//==================================================================================================

#pragma once

#include "SingleThread.h"

class CListenThread final : public CSingleThread
{
public:
	virtual void _Run();
};