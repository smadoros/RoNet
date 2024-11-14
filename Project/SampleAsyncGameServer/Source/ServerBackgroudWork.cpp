#include "stdafx.h"
#include "ServerBackgroudWork.h"
#include "Server.h"

extern std::shared_ptr<CServer> g_server;

CServerBackgroudWork::CServerBackgroudWork( const char* _name, UINT _spawn_time )
	: CBackgroundWork( _name, _spawn_time )
{
}

CServerBackgroudWork::~CServerBackgroudWork()
{
}

void CServerBackgroudWork::_Init()
{
	printf_s( "[Background : %s] Init\n", this->name_ );
}

void CServerBackgroudWork::_Start()
{
	printf_s( "[Background : %s] Start\n", this->name_ );
}

void CServerBackgroudWork::_Update()
{
	//< to do
}

void CServerBackgroudWork::_Release()
{
	printf_s( "[Background : %s] Release\n", this->name_ );
}