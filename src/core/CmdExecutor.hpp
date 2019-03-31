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

#include <list>

namespace rz
{

class CCore;

struct ICmdArgs;

struct ICmdHandler;
using tCmdHandlerList = std::list<ICmdHandler*>;

class CCmdExecutor final
{
public:
	CCmdExecutor(CCore *apCore);
	~CCmdExecutor();
	
	void Init();
	
	//void AddHandler(const ICmdHandler &aHandler) override;
	void AddHandler(ICmdHandler *apHandler);
	void RemoveHandler(ICmdHandler *apHandler);
	
	bool ExecArgs(const ICmdArgs &aArgs);
	bool ExecString(const char *asText); // ExecText; remove?
private:
	tCmdHandlerList mlstHandlers;
	
	CCore *mpCore{nullptr};
};

}; // namespace rz