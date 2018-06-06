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

#include <list>
#include "core/IModuleContainer.hpp"

namespace rz
{

struct IServiceLocator;

struct IModule;
using tModuleList = std::list<IModule*>;

class CModuleContainer : public IModuleContainer
{
public:
	CModuleContainer(const IServiceLocator &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CModuleContainer() = default;
	
	bool Init();
	void Shutdown();
	
	void Update();
	
	bool Add(const IModule &aModule);
	//void Remove(const IModule &aModule);
	
	IModule *GetByName(const char *asName) const;
	//IModule *GetByIndex(int anID);
private:
	tModuleList mlstModules;
	
	const IServiceLocator &mCoreEnv;
};

}; // namespace rz