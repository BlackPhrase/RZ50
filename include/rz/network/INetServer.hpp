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

#include "core/CoreTypes.hpp"

namespace rz
{

struct IRemoteClient;

struct INetServer
{
	///
	virtual bool SendData(byte *apData, int anSize) = 0;
	
	/// Tries to get a client by it's id
	/// @return nullptr if not found
	virtual IRemoteClient *GetClientById(int anID) const = 0;
	
	/// Causes any connected client to be reconnected
	virtual void ReconnectAll() = 0; // BroadcastReconnect
	
	/// Causes any connected client to be disconnected
	virtual void DisconnectAll() = 0; // BroadcastDisconnect
};

}; // namespace rz