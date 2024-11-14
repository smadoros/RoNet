//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CPacketDispatchChat
// - 패킷 프로토콜에 따라서 호출됨
//==================================================================================================
#pragma once

#include "PacketCommon.h"

class CPacketDispatchChat
{
public:
	static void CS_CHAT( unsigned long _session_uid, CPacket_CS_CHAT* _pkt );
};