//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CWorkerThread
// - IOCP 워커 스레드 (멀티 스레드)
//==================================================================================================

#pragma once

#include "MultiThread.h"

class CWorkerThread final : public CMultiThread
{
public:
	virtual void _Run();
};

