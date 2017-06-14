#pragma once

#include "core/CoreTypes.hpp"

namespace rz
{

struct ISubSystem;

struct IGraphics
{
	
};

using pfnGetGraphics = ISubSystem *(*)();

}; // namespace rz