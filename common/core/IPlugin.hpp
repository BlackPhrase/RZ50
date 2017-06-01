#pragma once

#include "CoreEnv.hpp"

namespace rz
{

struct IPlugin
{
	virtual bool Init(const TCoreEnv &aCoreEnv) = 0;
	virtual void Shutdown() = 0;
};

}; // namespace rz