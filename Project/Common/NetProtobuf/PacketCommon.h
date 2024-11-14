//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// 프로토버프 CommonPacket
//==================================================================================================

#pragma once

#include "Packet.h"
#include "CommonPacket.pb.h"

class CPacket_CS_CHAT final : public CPacket
{
public:
	COMMON_PACKET::PB_CS_CHAT data;

public:
	CPacket_CS_CHAT() : CPacket(COMMON_PACKET::CS_CHAT) {}

protected:
	virtual int _GetSize() { return (int)data.ByteSizeLong(); }
	virtual void _Serialize(char* _buffer) { data.SerializeToArray(_buffer + PACKET_HEADER_SIZE, _GetSize()); }
	virtual void _Deserialize(char* _buffer) { data.ParseFromArray(_buffer + PACKET_HEADER_SIZE, GetSize()); }
};