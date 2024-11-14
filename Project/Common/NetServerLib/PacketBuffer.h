//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CPacketBuffer
// - ¸µ¹öÆÛ
//==================================================================================================

#pragma once

#include "pch.h"

#define PACKETBUFFER_LENGTH_UID sizeof(unsigned long)
#define PACKETBUFFER_LENGTH_SIZE sizeof(unsigned short)

class CPacketBuffer final
{
private:
	char* buffer_;
	int buffer_size_;
	int write_pos_;
	int read_pos_;
	std::mutex mutex_;

public:
	CPacketBuffer();
	~CPacketBuffer();
	void Release();

public:
	void Init( int _buffer_size );
	void Write( unsigned long _session_id, unsigned short _size, char* _data );
	void Read( unsigned long* _session_id, unsigned short* _size, char* _data );

private:
	bool _IsLoopback( int _current_pos );
};