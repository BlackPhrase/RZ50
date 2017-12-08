#pragma once

#include "core/CoreTypes.hpp"

namespace rz
{

struct IModule;
struct IServiceLocator;

struct IGraphics
{
	
};

using pfnGetGraphics = IModule *(*)(const IServiceLocator &aCoreEnv);

}; // namespace rz