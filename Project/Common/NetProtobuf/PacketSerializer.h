//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CPacket
// - 프로토버프 패킷 추상클래스
// - 추후 프로토버프의 메타 데이터 포인터를 가진 상태로 개선해야 함
//==================================================================================================

#pragma once

#include "Packet.h"
#include "CommonPacket.pb.h"
#include "RpcPacket.pb.h"

class CPacketSerializer
{
private:
	CPacket* packet_;
	char* buffer_;
	int buffer_size_;

public:
	CPacketSerializer();
	~CPacketSerializer();

public:
	void Serialize(CPacket* _packet);
	void Deserialize(char* _buffer);

public:
	CPacket* GetPacket();
	char* GetBuffer();
	int GetBufferSize();

private:
	void _GeneratePacket( COMMON_PACKET::COMMON_PROTOCOL _protocol );
	void _GeneratePacket( RPC_PACKET::RPC_PROTOCOL _protocol );
};