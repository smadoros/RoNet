//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CLanClientPacketFunction
// - 패킷 핸들러
//==================================================================================================

#pragma once

#include "PacketHandler.h"

class CLanClientPacketFunction final : public CAbstractPacketFunction
{
public:
	virtual void Dispatch( unsigned long _uid, char* _message );
};