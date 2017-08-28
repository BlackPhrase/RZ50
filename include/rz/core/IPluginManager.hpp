#pragma once

namespace rz
{

struct IPluginManager
{
	virtual bool LoadPlugin(const char *asName) = 0;
};

}; // namespace rz