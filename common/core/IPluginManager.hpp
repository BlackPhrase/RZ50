#pragma once

namespace rz
{

struct IPluginManager
{
	virtual bool LoadPlugin(const char *asName) const = 0;
};

}; // namespace rz