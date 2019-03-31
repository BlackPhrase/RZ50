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

#pragma once

#include <memory>
#include <list>
#include "konbini/shared_lib.hpp"
#include "core/plugin/IPluginManager.hpp"

namespace rz::core::plugin
{

struct IServiceLocator;
class CPluginLoader;

using tSharedLib = class konbini::shared_lib;
using tSharedLibList = std::list<tSharedLib*>;

struct IPlugin;
using tPluginList = std::list<IPlugin*>;

class CPluginHandle;
using tPluginHandleList = std::list<CPluginHandle*>;

class CPluginHandle
{
public:
	//CPluginHandle(tSharedLib ahLib, IPlugin *apPlugin)
	//	: mhLib(ahLib), mpPlugin(apPlugin){}
	~CPluginHandle() = default;
	
	bool Init(const IServiceLocator &aCoreEnv);
	void Shutdown();
private:
	tSharedLib mhLib{0};
	IPlugin *mpPlugin{nullptr};
};

class CPluginManager final : public IPluginManager
{
public:
	CPluginManager(const IServiceLocator &aCoreEnv);
	~CPluginManager();
	
	bool Init();
	void Shutdown();
	
	bool LoadPlugin(const char *asName) override;
	void UnloadAllPlugins();
private:
	tSharedLibList mlstPluginLibs;
	tPluginList mlstPlugins;
	
	//tPluginHandleList mlstPlugins;
	
	std::unique_ptr<CPluginLoader> mpLoader;
	
	const IServiceLocator &mCoreEnv;
};

}; // namespace rz::core::plugin