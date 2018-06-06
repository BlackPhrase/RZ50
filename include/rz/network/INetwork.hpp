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

struct ISubSystem;
struct TCoreEnv;
struct INetServer;
struct INetClient;

struct INetwork
{
	virtual INetServer *StartServer() = 0;
	virtual INetClient *StartClient() = 0;
};

using pfnGetNetwork = ISubSystem *(*)(const TCoreEnv &aCoreEnv);

}; // namespace rz