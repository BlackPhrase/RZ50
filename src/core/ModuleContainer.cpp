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

#include "ModuleContainer.hpp"
#include "core/IModule.hpp"
#include "core/IServiceLocator.hpp"
#include "core/CoreTypes.hpp"

namespace rz::core
{

bool CModuleContainer::Init()
{
	mCoreEnv.GetLog().TraceInit("ModuleManager");
	return true;
};

void CModuleContainer::Shutdown()
{
	mCoreEnv.GetLog().TraceShutdown("ModuleManager");
	
	for(auto It : mlstModules)
	{
		mCoreEnv.GetLog().TraceShutdown(string(It->GetModuleName()).append(" Module").c_str());
		It->Shutdown();
	};
};

void CModuleContainer::Update()
{
	for(auto It : mlstModules)
	{
		//mpUpdateLog->TraceUpdate(It->GetModuleName());
		//It->Update();
	};
};

bool CModuleContainer::Add(const IModule &aModule)
{
	const char *sName = aModule.GetModuleName();
	
	for(auto It : mlstModules)
		if(!strcmp(It->GetModuleName(), sName))
		{
			mCoreEnv.GetLog().Error("Cannot register the module %s - already registered!", sName);
			return false;
		};
	
	auto *pModule = const_cast<IModule*>(&aModule);
	mlstModules.push_back(pModule);
	
	pModule->Init(mCoreEnv); // temp
	return true;
};

//void CModuleContainer::Remove(const IModule &aModule)
//{
//};

IModule *CModuleContainer::GetByName(const char *asName) const
{
	for(auto It : mlstModules)
		if(!strcmp(It->GetModuleName(), asName))
			return It;
	
	return nullptr;
};

}; // namespace rz::core