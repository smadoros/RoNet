//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CDateTime
// - �ð� ���� ��ƿ��Ƽ (�̱���)
//==================================================================================================

#pragma once

#include "pch.h"
#include "Singleton.h"

class CDateTime final : public CSingleton<CDateTime>
{
public:
	std::string GetDateTimeStr( const char* _format, BYTE _timezone );
};