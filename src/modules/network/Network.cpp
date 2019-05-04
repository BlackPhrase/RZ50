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

#include "Network.hpp"
#include "NetServer.hpp"
#include "NetClient.hpp"

namespace rz::network
{

CNetwork::CNetwork(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
CNetwork::~CNetwork() = default;

void CNetwork::Update()
{
	//mCoreEnv.pUpdateLog->TraceUpdate("Network");
	
	//if(mpServer)
		//mpServer->Update();
	
	//if(mpClient)
		//mpClient->Update();
};

INetServer *CNetwork::StartServer()
{
	mpServer = std::make_unique<CNetServer>();
	return mpServer.get();
};

INetClient *CNetwork::StartClient()
{
	mpClient = std::make_unique<CNetClient>();
	return mpClient.get();
};

}; // namespace rz::network