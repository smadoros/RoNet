//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CServerEventFunction
// - CAbstractEventFunction 상속
// - 델리게이트 형식으로 호출됨
// - 네트워크 이벤트 처리
//==================================================================================================

#pragma once

#include "EventHandler.h"

class CServerEventFunction final : public CAbstractEventFunction
{
public:
	virtual void Connect( unsigned long _uid );
	virtual void Disconnect( unsigned long _uid, bool _explicit );
	virtual void PrefareSend( unsigned long _uid );
	virtual void Send( unsigned long _uid );
	virtual void Receive( unsigned long _uid );
	virtual void PrefareSend_UDP( unsigned long _uid );
	virtual void Send_UDP( unsigned long _uid );
	virtual void Receive_UDP( unsigned long _uid );
};