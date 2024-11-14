#pragma once

//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// 프로토버프 RpcPacket
//==================================================================================================

#pragma once

#include "Packet.h"
#include "RpcPacket.pb.h"

class CPacket_CS_NOTIFY final : public CPacket
{
public:
	RPC_PACKET::PB_CS_NOTIFY data;

public:
	CPacket_CS_NOTIFY() : CPacket(RPC_PACKET::CS_NOTIFY) {}

protected:
	virtual int _GetSize() { return (int)data.ByteSizeLong(); }
	virtual void _Serialize(char* _buffer) { data.SerializeToArray(_buffer + PACKET_HEADER_SIZE, _GetSize()); }
	virtual void _Deserialize(char* _buffer) { data.ParseFromArray(_buffer + PACKET_HEADER_SIZE, _GetSize()); }
};