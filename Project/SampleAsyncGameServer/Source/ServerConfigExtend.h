//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CServerConfigExtend
// - CAbstractServerConfig 상속
// - CAbstractServerConfig.Common 설정값 이외에 추가 설정값을 넣을 수 있도록 확장 가능.
//==================================================================================================

#pragma once

#include "ServerConfig.h"

#define SERVER_CONFIG_TAG_EXTEND	"Extend"
#define SERVER_CONFIG_TAG_EXVALUE1	"ExValue1"
#define SERVER_CONFIG_TAG_EXVALUE2	"ExValue2"
#define SERVER_CONFIG_TAG_EXVALUE3	"ExValue3"

class CServerConfigExtend final : public CAbstractServerConfig
{
public:
	struct DocExtend
	{
		unsigned int ExValue1 = 0;
		unsigned int ExValue2 = 0;
		unsigned int ExValue3 = 0;
	};

	DocExtend extend_;

public:
	CServerConfigExtend() {};
	virtual ~CServerConfigExtend() {};

public:
	virtual bool _LoadConfigCommon( const char* _file_path );
	virtual bool _LoadConfigExtend( const char* _file_path );
	virtual void _CreateConfig( const char* _dir_path, const char* _file_path );
	virtual bool _IsValidate();
};

