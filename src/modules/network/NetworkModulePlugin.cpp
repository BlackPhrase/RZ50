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

#include "NetworkModulePlugin.hpp"
#include "Network.hpp"
#include "core/IServiceLocator.hpp"

namespace rz::network
{

bool CNetworkModulePlugin::OnLoad(const core::IServiceLocator &aCoreEnv)
{
	aCoreEnv.pLog->TraceInit("Network System: Null");
	
	mpNetwork = std::make_unique<CNetwork>(aCoreEnv);
	
	mpNetwork->Init();
	return true;
};

void CNetworkModulePlugin::OnUnload()
{
	mpNetwork->Shutdown();
};

}; // namespace rz::network