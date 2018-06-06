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

namespace rz
{

struct IRemoteClient
{
	enum class State : int
	{
		Disconnected = 0, ///< Disconnect and not active
		Connected = 1,    ///< Connected
		Connecting,       ///< Currently connecting or reconnecting
		Disconnecting     ///< Disconnecting
	};
	
	/// Tries to reconnect to the currently connected server (if present)
	virtual bool Reconnect() = 0;
	
	/// Sends a disconnect message to server and closes the connection
	virtual void Disconnect() = 0;
	
	///
	virtual void SetState(State anState) = 0;
	
	///
	virtual State GetState() const = 0;
	
	/// @return true if currently connected to any server
	virtual bool IsConnected() const = 0;
};

}; // namespace rz