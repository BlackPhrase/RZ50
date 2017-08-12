#include "PluginManager.hpp"
#include "core/CoreTypes.hpp"
#include "core/TCoreEnv.hpp"
#include "core/IPlugin.hpp"
#include "PluginLoader.hpp"

namespace rz
{

CPluginManager::CPluginManager(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
CPluginManager::~CPluginManager() = default;

bool CPluginManager::Init(TCoreEnv &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("PluginManager");
	
	aCoreEnv.pPluginManager = this;
	
	mpLoader = std::make_unique<CPluginLoader>();
	return true;
};

void CPluginManager::Shutdown()
{
	mCoreEnv.pLog->TraceShutdown("PluginManager");
	
	UnloadAllPlugins();
};

bool CPluginManager::LoadPlugin(const char *asName) const
{
	// No name?
	if(!asName || !*asName)
	{
		mCoreEnv.pLog->Error("Cannot load a plugin with no name specified!");
		return false;
	};
	
	// Already loaded
	for(auto It : mlstPluginLibs)
		if(!strcmp(It->GetName(), asName))
			return true;
	
	//fs::path PluginsFolderPath = fs::current_path().append("plugins");
	
	auto PluginLib = mpLoader->LoadPlugin(asName);
	
	if(!PluginLib)
	{
		mCoreEnv.pLog->Error("Failed to load the plugin \"%s\"!", asName);
		return false;
	};
	
	//mlstPluginLibs.push_back(PluginLib);
	return true;
};

void CPluginManager::UnloadAllPlugins()
{
	// TODO
	
	for(auto It : mlstPlugins)
		It->Shutdown();
	
	mlstPlugins.clear();
};

}; // namespace rz