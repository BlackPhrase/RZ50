#pragma once

#include "IServiceLocator.hpp"

namespace rz
{

// NOTE: maybe it's better to use a string for version?
const auto PLUGIN_INTERFACE_VERSION = 1;

struct TPluginInfo
{
	const char *sName{""};
	const char *sVersion{""};
	const char *sAuthor{""};
	
	//int nVersion{PLUGIN_INTERFACE_VERSION};
};

struct IPlugin
{
	virtual bool Init(const IServiceLocator &aCoreEnv) = 0;
	virtual void Shutdown() = 0;
	
	virtual int GetVersion() const = 0;
	
	//const TPluginInfo &GetInfo() const = 0;
};

using pfnGetPluginExport = IPlugin *(*)();

}; // namespace rz