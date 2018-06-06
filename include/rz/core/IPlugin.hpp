/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2018 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

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