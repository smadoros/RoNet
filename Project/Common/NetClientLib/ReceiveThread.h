#pragma once

#include "SingleThread.h"

class CReceiveThread final : public CSingleThread
{
public:
	virtual void _Run();
};