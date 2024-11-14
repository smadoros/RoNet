#include "stdafx.h"
#include "Server.h"
#include "ServerParameter.h"
#include "ServerEventHandler.h"
#include "ServerPacketHandler.h"
#include "ServerBackgroudWork.h"
#include "ServerConfigExtend.h"

extern BOOL CtrlHandler( DWORD );

std::shared_ptr<CServer> g_server = NULL;

void Shutdown();

int wmain( int argc, wchar_t* argv[] )
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	SetConsoleCtrlHandler( ( PHANDLER_ROUTINE )CtrlHandler, TRUE );

	g_server = std::make_shared<CServer>();

	//< 서버 파라미터 설정
	CServerParameter* parameter = new CServerParameter();
	parameter->ServerConfig( new CServerConfigExtend() );
	parameter->EventHandler( new CEventFunction<CServerEventFunction>() );
	parameter->PacketHandler( new CPacketFunction<CServerPacketFunction>() );
	parameter->BackgroundWork( (CBackgroundWork*)( new CServerBackgroudWork( "Contents update", 10000 ) ) );

	//< 서버 시작
	if( g_server->Start( &parameter ) )
	{
		while( true )
		{
			std::cout << "(Enter 'quit' to exit)" << std::endl;

			std::string input;
			std::getline( std::cin, input );

			if( input._Equal( "quit" ) )
			{
				break;
			}
		}
	}

	//< 종료 처리
	Shutdown();

	return 0;
}

/// <summary>
/// Console 종료 이벤트
/// </summary>
/// <param name="ctrl_type"></param>
/// <returns></returns>
BOOL CtrlHandler( DWORD ctrl_type )
{
	switch( ctrl_type )
	{
		case CTRL_C_EVENT:
		case CTRL_CLOSE_EVENT:
		case CTRL_LOGOFF_EVENT:
		case CTRL_SHUTDOWN_EVENT:
		case CTRL_BREAK_EVENT:
			{
				Shutdown();
			}
			break;
	}

	return FALSE;
}

/// <summary>
/// 종료
/// </summary>
void Shutdown()
{
	g_server->Close();
	g_server = nullptr;

	_CrtDumpMemoryLeaks();
}