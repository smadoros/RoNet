//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// 서버에서 사용할 값을 정의 or 선언한다.
//==================================================================================================

#pragma once

#include "pch.h"

#define SERVER_IO_BUFFER_SIZE		4096							//< IO 버퍼 사이즈
#define SERVER_IO_MODE_WRITE		1								//< IO 타입(send)
#define SERVER_IO_MODE_READ			0								//< IO 타입(recv)
#define SERVER_PROTOCOL_MODE_TCP	1								//< 프로토콜 타입
#define SERVER_PROTOCOL_MODE_UDP	0								//< 프로토콜 타입
#define SERVER_PACKET_BUFFER_SIZE	(20 * SERVER_IO_BUFFER_SIZE)	//< 패킷 버퍼(링버퍼) 사이즈

typedef struct
{
	SOCKET		  socket;
	SOCKADDR_IN	  addr_info;
	unsigned long session_id;
} SOCKET_HANDLE, *LP_SOCKET_HANDLE;

typedef struct
{
	WSAOVERLAPPED	overlapped;
	WSABUF			wsa_buf;
	char			buffer[ SERVER_IO_BUFFER_SIZE ];
	BYTE			rw_mode;
	BYTE			protocol_mode;
} OVERLAPPED_IO, *LP_OVERLAPPED_IO;