//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CPacketDispatchChat
// - ��Ŷ �������ݿ� ���� ȣ���
//==================================================================================================
#pragma once

#include "PacketCommon.h"

class CPacketDispatchChat
{
public:
	static void CS_CHAT( unsigned long _session_uid, CPacket_CS_CHAT* _pkt );
};