//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CListenThread
// - ���� ������ ������ (�̱۽�����)
//==================================================================================================

#pragma once

#include "SingleThread.h"

class CListenThread final : public CSingleThread
{
public:
	virtual void _Run();
};