//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// �������� ����� ���� ���� or �����Ѵ�.
//==================================================================================================

#pragma once

#include "pch.h"

#define SERVER_IO_BUFFER_SIZE		4096							//< IO ���� ������
#define SERVER_IO_MODE_WRITE		1								//< IO Ÿ��(send)
#define SERVER_IO_MODE_READ			0								//< IO Ÿ��(recv)
#define SERVER_PROTOCOL_MODE_TCP	1								//< �������� Ÿ��
#define SERVER_PROTOCOL_MODE_UDP	0								//< �������� Ÿ��
#define SERVER_PACKET_BUFFER_SIZE	(20 * SERVER_IO_BUFFER_SIZE)	//< ��Ŷ ����(������) ������

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