#include "PluginLoader.hpp"

namespace rz
{

tSharedLib *CPluginLoader::LoadPlugin(const char *asName)
{
	auto NewPlugin = std::make_unique<tSharedLib>(string("./plugins/").append(asName).c_str()); // TODO: fix
	
	auto fnGetPluginExport = NewPlugin->GetExportFunc<pfnGetPluginExport>("RZGetPluginExport");
	
	if(!fnGetPluginExport)
	{
		mpCoreEnv->pLog->Error("Plugin \"%s\" is missing the export function!", asName);
		return false;
	};
	
	auto pPlugin = fnGetPluginExport();
	
	if(!pPlugin)
		return false;
	
	auto pPluginVersion = pPlugin->GetVersion();
	
	if(pPluginVersion != PLUGIN_INTERFACE_VERSION)
	{
		mpCoreEnv->pLog->Error("Plugin \"%s\" has an incompatible version! (%d vs %d)", asName, pPluginVersion, PLUGIN_INTERFACE_VERSION);
		return false;
	};
	
	if(!pPlugin->Init(*mpCoreEnv))
	{
		mpCoreEnv->pLog->Error("Failed to initialize the plugin \"%s\"!", asName);
		return false;
	};
	
	return NewPlugin.release();
};

}; // namespace rz