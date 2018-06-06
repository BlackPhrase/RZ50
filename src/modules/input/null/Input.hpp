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
#include "input/IInput.hpp"

namespace rz
{

struct IInputDevice;
using tInputDeviceList = std::list<IInputDevice*>;

class CInput final : public IInput
{
public:
	CInput(const IServiceLocator &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CInput() = default;
	
	bool Init(const IServiceLocator &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	void RegisterDevice(IInputDevice &aDevice) override;
	void UnregisterDevice(IInputDevice &aDevice) override;
private:
	tInputDeviceList mlstDevices;
	
	const IServiceLocator &mCoreEnv;
};

}; // namespace rz