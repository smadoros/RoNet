//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CClientPacketFunction
// - CAbstractPacketFunction ���
// - ��������Ʈ �������� ȣ���
// - ��Ŷ ������ ó��
//==================================================================================================

#pragma once

#include "PacketHandler.h"

class CClientPacketFunction final : public CAbstractPacketFunction
{
public:
	virtual void Dispatch( unsigned long _uid, char* _message );
};