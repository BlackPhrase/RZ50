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

#include "core/CoreTypes.hpp"
#include "input/IInputDevice.hpp"
#include "core/IServiceLocator.hpp"
#include "Input.hpp"
#include "Mouse.hpp"

namespace rz::input
{

bool CInput::Init(const IServiceLocator &aCoreEnv)
{
	mCoreEnv.GetLog().TraceInit("Input");
	
	mlstDevices.push_back(*new CMouse(aCoreEnv));
	return true;
};

void CInput::Shutdown()
{
	// NOTE: move to destructor?
	
	auto It{mlstDevices.begin()};
	while(It != mlstDevices.end())
	{
		//It->Release(); // delete itself
		It = mlstDevices.erase(It);
	};
};

void CInput::Update()
{
	//mCoreEnv.pUpdateLog->TraceUpdate("Input");
	
	mCoreEnv.GetCmdProcessor().BufferText("backward;left;right", ICmdProcessor::InsertMode::Append);
	mCoreEnv.GetCmdProcessor().BufferText("forward", ICmdProcessor::InsertMode::Insert);
	
	for(auto It : mlstDevices)
		It.get().Update();
};

void CInput::RegisterDevice(IInputDevice &aDevice)
{
	// Prevent duplication
	for(auto It : mlstDevices)
		if(!strcmp(It.get().GetName(), aDevice.GetName()))
			return;
	
	mlstDevices.push_back(aDevice);
};

void CInput::UnregisterDevice(IInputDevice &aDevice)
{
	for(auto It : mlstDevices)
		if(!strcmp(It.get().GetName(), aDevice.GetName()))
		{
			//It->Release();
			mlstDevices.remove(It);
		};
};

}; // namespace rz::input