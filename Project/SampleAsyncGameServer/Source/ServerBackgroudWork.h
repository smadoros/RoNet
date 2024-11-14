//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CServerBackgroudWork
// - CBackgroundWork ���
// - Server-MainThread���� �ֱ������� ȣ���
// - �񵿱� ������Ʈ ������ ó��
//==================================================================================================

#pragma once

#include "BackgroundWork.h"

class CServerBackgroudWork final : public CBackgroundWork
{
public:
	CServerBackgroudWork( const char* _name, UINT _spawn_time );
	virtual ~CServerBackgroudWork();

	virtual void _Init();
	virtual void _Start();
	virtual void _Update();
	virtual void _Release();
};
