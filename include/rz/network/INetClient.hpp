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

struct INetClient
{
	/// Tries to connect to specified hostname
	virtual bool Connect(const char *asHostName) = 0;
	
	/// Tries to reconnect to the currently connected server (if present)
	virtual bool Reconnect() = 0;
	
	/// Sends a disconnect message to server and closes the connection
	virtual void Disconnect() = 0;
	
	/// Send the specified data to the server
	virtual bool SendData(byte *apData, int anSize) = 0;
	
	/// @return true if currently connected to any server
	virtual bool IsConnected() const = 0;
};

}; // namespace rz