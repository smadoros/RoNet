#include "stdafx.h"
#include "ServerConfigExtend.h"
#include "json/json.h"
#include "json/writer.h"

/// <summary>
/// Common 설정값 load
/// </summary>
/// <param name="_file_path"></param>
/// <returns></returns>
bool CServerConfigExtend::_LoadConfigCommon( const char* _file_path )
{
	std::ifstream config_input_stream;
	config_input_stream.open( _file_path, std::ifstream::binary );

	Json::Value json_root;
	config_input_stream >> json_root;
	config_input_stream.close();

	Json::Value json_common = json_root[ SERVER_CONFIG_TAG_COMMON ];

	sprintf_s( common_.Group, SERVER_CONFIG_STRING_LENGTH, "%s", json_common[ SERVER_CONFIG_TAG_GROUP ].asCString() );
	sprintf_s( common_.Flavor, SERVER_CONFIG_STRING_LENGTH, "%s", json_common[ SERVER_CONFIG_TAG_FLAVOR ].asCString() );
	common_.Port = json_common[ SERVER_CONFIG_TAG_PORT ].asUInt();

	Json::Value json_lan_client = json_common[ SERVER_CONFIG_TAG_LANCLIENT ];

	for( Json::ValueIterator iter = json_lan_client.begin(); iter != json_lan_client.end(); iter++ )
	{
		DocCommon::DocLanClient lan_client;
		sprintf_s( lan_client.Flavor, SERVER_CONFIG_STRING_LENGTH, "%s", ( *iter )[ SERVER_CONFIG_TAG_FLAVOR ].asCString() );
		sprintf_s( lan_client.IP, SERVER_CONFIG_STRING_LENGTH, "%s", ( *iter )[ SERVER_CONFIG_TAG_IP ].asCString() );
		lan_client.Port = ( *iter )[ SERVER_CONFIG_TAG_PORT ].asUInt();
		lan_client.Count = ( *iter )[ SERVER_CONFIG_TAG_COUNT ].asUInt();

		common_.LanClient.push_back( lan_client );
	}

	return true;
}

/// <summary>
/// 확장된 설정값 load
/// </summary>
/// <param name="_file_path"></param>
/// <returns></returns>
bool CServerConfigExtend::_LoadConfigExtend( const char* _file_path )
{
	std::ifstream config_input_stream;
	config_input_stream.open( _file_path, std::ifstream::binary );

	Json::Value json_root;
	config_input_stream >> json_root;
	config_input_stream.close();

	Json::Value json_extend = json_root[ SERVER_CONFIG_TAG_EXTEND ];
	extend_.ExValue1 = json_extend[ SERVER_CONFIG_TAG_EXVALUE1 ].asUInt();
	extend_.ExValue2 = json_extend[ SERVER_CONFIG_TAG_EXVALUE2 ].asUInt();
	extend_.ExValue3 = json_extend[ SERVER_CONFIG_TAG_EXVALUE3 ].asUInt();

	return true;
}

/// <summary>
/// Default 설정 파일 생성
/// </summary>
/// <param name="_dir_path">설정파일 디렉토리</param>
/// <param name="_file_path">설정파일 경로</param>
void CServerConfigExtend::_CreateConfig( const char* _dir_path, const char* _file_path )
{
	if( GetFileAttributesA( _dir_path ) != 0 )
	{
		CreateDirectoryA( _dir_path, nullptr );
	}

	std::ifstream config_input_stream;
	config_input_stream.open( _file_path, std::ifstream::binary );

	if( false == config_input_stream.is_open() )
	{
		Json::Value root;

		Json::Value lanclient_info;
		lanclient_info[ SERVER_CONFIG_TAG_FLAVOR ] = "";
		lanclient_info[ SERVER_CONFIG_TAG_IP ] = "0.0.0.0";
		lanclient_info[ SERVER_CONFIG_TAG_PORT ] = 0;
		lanclient_info[ SERVER_CONFIG_TAG_COUNT ] = 0;

		Json::Value default_config_common;
		default_config_common[ SERVER_CONFIG_TAG_GROUP ] = "";
		default_config_common[ SERVER_CONFIG_TAG_FLAVOR ] = "";
		default_config_common[ SERVER_CONFIG_TAG_PORT ] = 0;
		default_config_common[ SERVER_CONFIG_TAG_LANCLIENT ].append( lanclient_info );

		Json::Value default_config_extend;
		default_config_extend[ SERVER_CONFIG_TAG_EXVALUE1 ] = 0;
		default_config_extend[ SERVER_CONFIG_TAG_EXVALUE2 ] = 0;
		default_config_extend[ SERVER_CONFIG_TAG_EXVALUE3 ] = 0;

		root[ SERVER_CONFIG_TAG_COMMON ] = default_config_common;
		root[ SERVER_CONFIG_TAG_EXTEND ] = default_config_extend;

		//< output
		std::ofstream config_output_stream( _file_path );

		Json::StreamWriterBuilder builder;
		builder[ "commentStyle" ] = "None";
		builder[ "indentation" ] = "	";

		std::unique_ptr<Json::StreamWriter> writer( builder.newStreamWriter() );
		writer->write( root, &config_output_stream );

		config_output_stream.close();
	}

	config_input_stream.close();
}

/// <summary>
/// 설정 파일 유효성 검증
/// </summary>
/// <returns></returns>
bool CServerConfigExtend::_IsValidate()
{
	if( 0 == std::strcmp( "", common_.Flavor ) )
	{
		return false;
	}

	if( 0 == std::strcmp( "", common_.Group ) )
	{
		return false;
	}

	if( 0 == common_.Port )
	{
		return false;
	}

	for( const CAbstractServerConfig::DocCommon::DocLanClient lan : common_.LanClient )
	{
		if( 0 < lan.Count )
		{
			if( 0 == std::strcmp( "", lan.Flavor ) )
			{
				return false;
			}

			if( 0 == std::strcmp( "", lan.IP ) )
			{
				return false;
			}

			if( 0 == lan.Port )
			{
				return false;
			}
		}
	}

	return true;
}