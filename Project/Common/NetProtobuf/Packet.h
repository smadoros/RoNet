//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CPacket
// - ��������� ��Ŷ �߻�Ŭ����
// - ���� ����������� ��Ÿ ������ �����͸� ���� ���·� �����ؾ� ��
//==================================================================================================

#pragma once

#define PACKET_HEADER_TRANSACTION_KEY_LENGTH	24
#define PACKET_HEADER_SIZE						(sizeof(unsigned short) + PACKET_HEADER_TRANSACTION_KEY_LENGTH)

class CPacket
{
private:
	unsigned short protocol_;
	char transaction_key_[ PACKET_HEADER_TRANSACTION_KEY_LENGTH ];

public:
	CPacket( unsigned short _protocol );
	virtual ~CPacket();

public:
	void SetTransactionKey( const char* _transaction_key );
	int GetSize();
	unsigned short GetProtocol();
	const char* GetTransactionKey();

public:
	void Serialize( char* _buffer );
	void Deserialize( char* _buffer );

protected:
	virtual int _GetSize() = 0;
	virtual void _Serialize( char* _buffer ) = 0;
	virtual void _Deserialize( char* _buffer ) = 0;
};

