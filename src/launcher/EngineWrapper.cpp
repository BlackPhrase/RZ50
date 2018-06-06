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

/// @file

#include <cstdio>
#include "EngineWrapper.hpp"

bool CEngineWrapper::Init(const rz::ICore::TInitParams &aInitParams)
{
	if(mpCore)
		return mpCore->Init(aInitParams);

	return false;
};

void CEngineWrapper::Shutdown()
{
	if(mpCore)
		mpCore->Shutdown();
};

void CEngineWrapper::Run()
{
	if(!mpCore)
		return;

	while(!mpCore->IsCloseRequested()) //WantQuit())
	{
		//if(!ProcessEvents())
			//break;
		//else
			mpCore->Frame(); // update the core and each registered module
	};
	
	//Shutdown();
};

const rz::IServiceLocator *CEngineWrapper::GetEnv() const
{
	if(mpCore)
		return &mpCore->GetEnv();

	return nullptr;
};