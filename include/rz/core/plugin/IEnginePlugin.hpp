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

#include "IServiceLocator.hpp"

namespace rz::core::plugin
{

// NOTE: maybe it's better to use a string for version?
constexpr auto PLUGIN_INTERFACE_VERSION{1};

struct IEnginePlugin
{
	///
	virtual bool Init(const IServiceLocator &aCoreEnv) = 0;
	
	///
	virtual void Shutdown() = 0;
	
	struct Info
	{
		Info(const char *asName, const char *asVersion, const char *asAuthor)
			: msName(asName), msVersion(asVersion), msAuthor(asAuthor){}
		
		const char *msName{""};
		const char *msVersion{""};
		const char *msAuthor{""};
		
		//int nVersion{PLUGIN_INTERFACE_VERSION};
	};

	///
	virtual void GetInfo(const Info &arInfo) const = 0;
};

using pfnGetPluginExport = IEnginePlugin *(*)(IEnginePlugin::Info &arInfo);

}; // namespace rz::core::plugin