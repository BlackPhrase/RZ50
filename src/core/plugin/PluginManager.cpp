/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2019 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "PluginManager.hpp"
#include "core/CoreTypes.hpp"
#include "core/IServiceLocator.hpp"
#include "core/IPlugin.hpp"
#include "PluginLoader.hpp"

namespace rz::core::plugin
{

CPluginManager::CPluginManager(const IServiceLocator &aCoreEnv) : mCoreEnv(aCoreEnv){}
CPluginManager::~CPluginManager() = default;

bool CPluginManager::Init()
{
	mCoreEnv.GetLog().TraceInit("PluginManager");
	
	mpLoader = std::make_unique<CPluginLoader>(mCoreEnv);
	return true;
};

void CPluginManager::Shutdown()
{
	mCoreEnv.GetLog().TraceShutdown("PluginManager");
	
	UnloadAllPlugins();
};

bool CPluginManager::LoadPlugin(const char *asName)
{
	// No name?
	if(!asName || !*asName)
	{
		mCoreEnv.GetLog().Error("Cannot load a plugin with no name specified!");
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
		mCoreEnv.GetLog().Error("Failed to load the plugin \"%s\"!", asName);
		return false;
	};
	
	mlstPluginLibs.push_back(PluginLib);
	return true;
};

void CPluginManager::UnloadAllPlugins()
{
	// TODO
	
	for(auto It : mlstPlugins)
		It->Shutdown();
	
	mlstPlugins.clear();
};

}; // namespace rz::core::plugin