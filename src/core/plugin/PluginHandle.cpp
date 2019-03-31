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

#include "PluginHandle.hpp"
#include "PluginManager.hpp"
#include "core/IPlugin.hpp"

namespace rz::core::plugin
{

bool CPluginHandle::Init(const IServiceLocator &aCoreEnv)
{
	if(mpPlugin)
		return mpPlugin->Init(aCoreEnv);
	
	return false;
};

void CPluginHandle::Shutdown()
{
	if(mpPlugin)
		mpPlugin->Shutdown();
};

}; // namespace rz::core::plugin