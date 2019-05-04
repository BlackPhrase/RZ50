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

#include <vector>
#include "network/INetServer.hpp"

namespace rz::network
{

struct IRemoteClient;
using tRemoteClientVec = std::vector<IRemoteClient*>;

class CNetServer final : public INetServer
{
public:
	CNetServer() = default;
	~CNetServer() = default;
	
	bool SendData(byte *apData, int anSize) override;
	//bool SendData(IRemoteClient *apClient, byte *apData, int anSize) override;
	//bool SendData(INetAdr *apAdr, byte *apData, int anSize) override;
	
	IRemoteClient *GetClientById(int anID) const override;
	
	void ReconnectAll() override;
	void DisconnectAll() override;
private:
	tRemoteClientVec mvClients;
	
	uint mnMaxClients{0};
};

}; // namespace rz::network