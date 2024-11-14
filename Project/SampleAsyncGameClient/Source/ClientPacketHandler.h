//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CClientPacketFunction
// - CAbstractPacketFunction 상속
// - 델리게이트 형식으로 호출됨
// - 패킷 컨텐츠 처리
//==================================================================================================

#pragma once

#include "PacketHandler.h"

class CClientPacketFunction final : public CAbstractPacketFunction
{
public:
	virtual void Dispatch( unsigned long _uid, char* _message );
};