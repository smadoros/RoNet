//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CMainThread
// - ���� ������ (�̱� ������)
//==================================================================================================

#pragma once

#include "SingleThread.h"

class CMainThread final : public CSingleThread
{
public:
	virtual void _Run();
};