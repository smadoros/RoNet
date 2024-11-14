#include "stdafx.h"
#include "Client.h"
#include "ClientParameter.h"
#include "ClientEventHandler.h"
#include "ClientPacketHandler.h"
#include "PacketSerializer.h"
#include "PacketCommon.h"

extern BOOL CtrlHandler( DWORD );

std::shared_ptr<CClient> g_client = NULL;

void Shutdown();

int wmain( int argc, wchar_t* argv[] )
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	SetConsoleCtrlHandler( ( PHANDLER_ROUTINE )CtrlHandler, TRUE );

	g_client = std::make_shared<CClient>();
	
	//< 클라이언트 파라미터 설정
	CClientParameter* parameter = new CClientParameter();
	parameter->IP( "127.0.0.1" );
	parameter->Port( 15000 );
	parameter->EventHandler( new CEventFunction<CClientEventFunction>() );
	parameter->PacketHandler( new CPacketFunction<CClientPacketFunction>() );

	//< 클라이언트 시작
	if( g_client->Start( &parameter ) )
	{
		while( true )
		{
			std::cout << "> Chat message : (Enter 'quit' to exit)" << std::endl;

			std::string input;
			std::getline( std::cin, input );

			if( input._Equal( "quit" ) )
			{
				break;
			}

			if( false == g_client->IsConnect() )
			{
				continue;
			}

			CPacket_CS_CHAT* pkt = new CPacket_CS_CHAT();
			pkt->SetTransactionKey("@423=A51K");
			pkt->data.set_message( input );

			CPacketSerializer serializer;
			serializer.Serialize( pkt );

			g_client->Send( serializer.GetBuffer(), serializer.GetBufferSize() );
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
	google::protobuf::ShutdownProtobufLibrary();

	g_client->Close();
	g_client = nullptr;

	_CrtDumpMemoryLeaks();
}
