//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CLanClientPacketFunction
// - ��Ŷ �ڵ鷯
//==================================================================================================

#pragma once

#include "PacketHandler.h"

class CLanClientPacketFunction final : public CAbstractPacketFunction
{
public:
	virtual void Dispatch( unsigned long _uid, char* _message );
};