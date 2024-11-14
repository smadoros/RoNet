//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CDateTime
// - 시간 관련 유틸리티 (싱글톤)
//==================================================================================================

#pragma once

#include "pch.h"
#include "Singleton.h"

class CDateTime final : public CSingleton<CDateTime>
{
public:
	std::string GetDateTimeStr( const char* _format, BYTE _timezone );
};