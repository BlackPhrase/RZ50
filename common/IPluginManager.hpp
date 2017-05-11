#pragma once

namespace rz
{

struct ISubSystem;

struct IPluginManager
{
	virtual ISubSystem *GetSubsystem(const char *asName) = 0;
};

}; // namespace rz