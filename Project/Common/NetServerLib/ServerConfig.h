//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CAbstractServerConfig
// - 서버 설정 정보
// - 공용 설정(common)은 기본 포함되어 있다.
// - 이 클래스를 상속받아 설정 정보를 확장(추가)한다.
// - 설정 파일은 json 파일로 고정되어 있다. (실행경로\Config\ServerConfig.json)
// 
// CServerConfig
// - CAbstractServerConfig 객체를 참조한다.
//==================================================================================================

#pragma once

#include "pch.h"

#define SERVER_CONFIG_STRING_LENGTH	32

#define SERVER_CONFIG_TAG_COMMON	"Common"
#define SERVER_CONFIG_TAG_GROUP		"Group"
#define SERVER_CONFIG_TAG_FLAVOR	"Flavor"
#define SERVER_CONFIG_TAG_PORT		"Port"
#define SERVER_CONFIG_TAG_LANCLIENT	"LanClient"
#define SERVER_CONFIG_TAG_IP		"IP"
#define SERVER_CONFIG_TAG_COUNT		"Count"

class CAbstractServerConfig
{
public:
	struct DocCommon
	{
		struct DocLanClient
		{
			char Flavor[ SERVER_CONFIG_STRING_LENGTH ] = { 0, };
			char IP[ SERVER_CONFIG_STRING_LENGTH ] = { 0, };
			USHORT Port = 0;
			USHORT Count = 0;
		};

		char Group[ SERVER_CONFIG_STRING_LENGTH ] = { 0, };
		char Flavor[ SERVER_CONFIG_STRING_LENGTH ] = { 0, };
		USHORT Port = 0;
		std::vector<DocLanClient> LanClient;
	};

public:
	CAbstractServerConfig() ;
	virtual ~CAbstractServerConfig();

protected:
	DocCommon common_;

public:
	bool LoadConfig();

public:
	DocCommon* Common();

protected:
	virtual bool _LoadConfigCommon( const char* _file_path ) = 0;
	virtual bool _LoadConfigExtend( const char* _file_path ) = 0;
	virtual void _CreateConfig( const char* _dir_path, const char* _file_path ) = 0;
	virtual bool _IsValidate() = 0;
};

class CServerConfig final
{
	CAbstractServerConfig* config_ = nullptr;

public:
	CServerConfig();
	~CServerConfig();
	void Release();

public:
	void SetConfig( CAbstractServerConfig* _config );
	CAbstractServerConfig* GetConfig();

public:
	bool LoadConfig();
};

