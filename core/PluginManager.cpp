#include <memory>
#include "PluginManager.hpp"
#include "core/TCoreEnv.hpp"
#include "core/IPlugin.hpp"

namespace rz
{

bool CPluginManager::Init(const TCoreEnv &aCoreEnv)
{
	mpCoreEnv = &aCoreEnv;
	
	mpCoreEnv->pLog->TraceInit("PluginManager");
	return true;
};

void CPluginManager::Shutdown()
{
	mpCoreEnv->pLog->TraceShutdown("PluginManager");
	
	UnloadAllPlugins();
};

bool CPluginManager::LoadPlugin(const char *asName)
{
	if(!asName || !*asName)
	{
		return false;
	};
	
	for(auto It : mlstPluginLibs)
		if(!strcmp(It->GetName(), asName))
			return true;
	
	auto NewPlugin = std::make_unique<tSharedLib>(asName);
	
	auto fnGetPluginExport = NewPlugin->GetExportFunc<pfnGetPluginExport>("RZGetPluginExport");
	
	bool bLoadFailed{false};
	
	if(!fnGetPluginExport)
	{
		mpCoreEnv->pLog->Error("Plugin \"%s\" is missing the export function!", asName);
		bLoadFailed = true; // return false;
	};
	
	auto pPlugin = fnGetPluginExport();
	
	if(!pPlugin)
		bLoadFailed = true; //return false;
	
	auto pPluginVersion = pPlugin->GetVersion();
	
	if(pPluginVersion != PLUGIN_INTERFACE_VERSION)
	{
		mpCoreEnv->pLog->Error("Plugin \"%s\" has an incompatible version! (%d vs %d)", asName, pPluginVersion, PLUGIN_INTERFACE_VERSION);
		bLoadFailed = true; //return false;
	};
	
	if(!pPlugin->Init(*mpCoreEnv))
	{
		mpCoreEnv->pLog->Error("Failed to initialize the plugin \"%s\"!", asName);
		bLoadFailed = true; //return false;
	};
	
	if(bLoadFailed)
	{
		mpCoreEnv->pLog->Error("Failed to load the plugin \"%s\"!", asName);
		return false;
	};
	
	mlstPluginLibs.push_back(NewPlugin.release());
	return true;
};

void CPluginManager::UnloadAllPlugins()
{
	// TODO
};

void CPluginManager::RegisterSubSystem(const ISubSystem &aSubSystem)
{
};

void CPluginManager::UnregisterSubSystem(const ISubSystem &aSubSystem)
{
};

void *CPluginManager::GetSubSystem(const char *asName) const
{
	return nullptr;
};

}; // namespace rz