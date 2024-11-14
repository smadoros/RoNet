//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CServerBackgroudWork
// - CBackgroundWork 상속
// - Server-MainThread에서 주기적으로 호출됨
// - 비동기 업데이트 컨텐츠 처리
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
