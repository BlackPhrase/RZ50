#pragma once

namespace rz
{

struct ISubSystem;

struct IGraphics
{
};

using pfnGetGraphics = ISubSystem *(*)();

}; // namespace rz