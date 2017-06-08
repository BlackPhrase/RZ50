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
	for(auto It : mlstPluginLibs)
		if(!strcmp(It->GetName(), asName))
			return true;
	
	auto NewPlugin = std::make_unique<tSharedLib>(asName);
	
	auto fnGetPluginExport = NewPlugin->GetExportFunc<pfnGetPluginExport>("RZGetPluginExport");
	
	if(!fnGetPluginExport)
		return false;
	
	auto pPlugin = fnGetPluginExport();
	
	if(!pPlugin)
		return false;
	
	if(!pPlugin->Init(*mpCoreEnv))
		return false;
	
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