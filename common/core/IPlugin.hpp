#pragma once

#include "TCoreEnv.hpp"

namespace rz
{

struct IPlugin
{
	virtual bool Init(const TCoreEnv &aCoreEnv) = 0;
	virtual void Shutdown() = 0;
};

typedef IPlugin *(*pfnGetPluginExport)();

}; // namespace rz