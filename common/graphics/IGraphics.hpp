#pragma once

#include "core/CoreTypes.hpp"

namespace rz
{

struct TCoreEnv;
struct ISubSystem;

struct IGraphics
{
	
};

using pfnGetGraphics = ISubSystem *(*)(const TCoreEnv &aCoreEnv);

}; // namespace rz