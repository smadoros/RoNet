//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CAbstractEventFunction
// - 이벤트 핸들러
// 
// CEventFunction<T>
// - CAbstractEventFunction을 상속받는다.
// 
// CEventHandler
// - CEventFunction<T> 객체의 소유권을 가진 상태로 관리한다.
//==================================================================================================

#pragma once

#include "pch.h"

class CAbstractEventFunction
{
public:
	virtual void Connect( unsigned long _uid ) = 0;
	virtual void Disconnect( unsigned long _uid, bool _explicit ) = 0;
	virtual void PrefareSend( unsigned long _uid ) = 0;
	virtual void Send( unsigned long _uid ) = 0;
	virtual void Receive( unsigned long _uid ) = 0;
	virtual void PrefareSend_UDP( unsigned long _uid ) = 0;
	virtual void Send_UDP( unsigned long _uid ) = 0;
	virtual void Receive_UDP( unsigned long _uid ) = 0;
};

template<typename T>
class CEventFunction final : public CAbstractEventFunction
{
private:
	T event_handler;

private:
	std::function<void( T&, unsigned long )> func_connect = &T::Connect;
	std::function<void( T&, unsigned long, bool )> func_disconnect = &T::Disconnect;
	std::function<void( T&, unsigned long )> func_prefare_send = &T::PrefareSend;
	std::function<void( T&, unsigned long )> func_send = &T::Send;
	std::function<void( T&, unsigned long )> func_receive = &T::Receive;
	std::function<void( T&, unsigned long )> func_prefare_send_udp = &T::PrefareSend_UDP;
	std::function<void( T&, unsigned long )> func_send_udp = &T::Send_UDP;
	std::function<void( T&, unsigned long )> func_receive_udp = &T::Receive_UDP;

public:
	virtual void Connect( unsigned long _uid ) { func_connect( event_handler, _uid ); }
	virtual void Disconnect( unsigned long _uid, bool _explicit ) { func_disconnect( event_handler, _uid, _explicit ); }
	virtual void PrefareSend( unsigned long _uid ) { func_prefare_send( event_handler, _uid ); }
	virtual void Send( unsigned long _uid ) { func_send( event_handler, _uid ); }
	virtual void Receive( unsigned long _uid ) { func_receive( event_handler, _uid ); }
	virtual void PrefareSend_UDP( unsigned long _uid ) { func_prefare_send_udp( event_handler, _uid ); }
	virtual void Send_UDP( unsigned long _uid ) { func_send_udp( event_handler, _uid ); }
	virtual void Receive_UDP( unsigned long _uid ) { func_receive_udp( event_handler, _uid ); }
};

class CEventHandler final
{
private:
	CAbstractEventFunction* instance_ = nullptr;

public:
	void Init( CAbstractEventFunction* _instance );
	void Release();

public:
	void Connect( unsigned long _uid );
	void Disconnect( unsigned long _uid, bool _explicit );
	void PrefareSend( unsigned long _uid );
	void Send( unsigned long _uid );
	void Receive( unsigned long _uid );
	void PrefareSend_UDP( unsigned long _uid );
	void Send_UDP( unsigned long _uid );
	void Receive_UDP( unsigned long _uid );
};
