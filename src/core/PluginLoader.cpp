#include <memory>
#include "PluginLoader.hpp"
#include "core/CoreTypes.hpp"
#include "shiftutil/SharedLib.hpp"
#include "core/IPlugin.hpp"

namespace rz
{

CPluginLoader::CPluginLoader(const IServiceLocator &aCoreEnv) : mCoreEnv(aCoreEnv){}
CPluginLoader::~CPluginLoader() = default;

shiftutil::CSharedLib *CPluginLoader::LoadPlugin(const char *asName)
{
	auto NewPlugin = std::make_unique<shiftutil::CSharedLib>(string("./plugins/").append(asName).c_str()); // TODO: fix
	
	auto fnGetPluginExport = NewPlugin->GetExportFunc<pfnGetPluginExport>("RZGetPluginExport");
	
	if(!fnGetPluginExport)
	{
		mCoreEnv.GetLog().Error("Plugin \"%s\" is missing the export function!", asName);
		return nullptr;
	};
	
	auto pPlugin = fnGetPluginExport();
	
	if(!pPlugin)
		return nullptr;
	
	auto pPluginVersion = pPlugin->GetVersion();
	
	if(pPluginVersion != PLUGIN_INTERFACE_VERSION)
	{
		mCoreEnv.GetLog().Error("Plugin \"%s\" has an incompatible version! (%d vs %d)", asName, pPluginVersion, PLUGIN_INTERFACE_VERSION);
		return nullptr;
	};
	
	if(!pPlugin->Init(mCoreEnv))
	{
		mCoreEnv.GetLog().Error("Failed to initialize the plugin \"%s\"!", asName);
		return nullptr;
	};
	
	return NewPlugin.release();
	
	return nullptr;
};

}; // namespace rz