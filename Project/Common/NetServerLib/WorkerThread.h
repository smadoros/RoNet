//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CWorkerThread
// - IOCP ��Ŀ ������ (��Ƽ ������)
//==================================================================================================

#pragma once

#include "MultiThread.h"

class CWorkerThread final : public CMultiThread
{
public:
	virtual void _Run();
};

