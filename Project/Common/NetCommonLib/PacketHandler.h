//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CAbstractPacketFunction
// - ��Ŷ �ڵ鷯
// 
// CPacketFunction<T>
// - CAbstractPacketFunction�� ��ӹ޴´�.
// 
// CPacketHandler
// - CPacketFunction<T> ��ü�� �������� ���� ���·� �����Ѵ�.
//==================================================================================================

#pragma once

#include "pch.h"

class CAbstractPacketFunction
{
public:
	virtual void Dispatch( unsigned long _uid, char* _message ) = 0;
};

template<typename T>
class CPacketFunction final : public CAbstractPacketFunction
{
private:
	T packet_handler;

private:
	std::function<void( T&, unsigned long, char* )> func = &T::Dispatch;

public:
	virtual void Dispatch( unsigned long _uid, char* _message ) { func( packet_handler, _uid, _message ); }
};

class CPacketHandler final
{
private:
	CAbstractPacketFunction* instance_ = nullptr;

public:
	void Init( CAbstractPacketFunction* _instance );
	void Release();

public:
	void Dispatch( unsigned long _uid, char* _message );
};
