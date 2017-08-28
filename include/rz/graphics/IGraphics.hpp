#pragma once

#include "core/CoreTypes.hpp"

namespace rz
{

struct ISubSystem;
struct TCoreEnv;

struct IGraphics
{
	
};

using pfnGetGraphics = ISubSystem *(*)(const TCoreEnv &aCoreEnv);

}; // namespace rz