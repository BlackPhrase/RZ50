#include "core/CoreTypes.hpp"
#include "PluginImpl.hpp"

C_EXPORT rz::IPlugin *RZGetPluginExport()
{
	static CPluginImpl Plugin;
	return &Plugin;
};