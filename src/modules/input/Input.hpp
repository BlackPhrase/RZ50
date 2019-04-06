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
#include <functional>
#include "input/IInput.hpp"

namespace rz::input
{

struct IInputDevice;
using tInputDeviceList = std::list<std::reference_wrapper<IInputDevice>>;

class CInput final : public IInput
{
public:
	CInput(const IServiceLocator &aCoreEnv, IInputImpl *apImpl) : mCoreEnv(aCoreEnv), mpImpl(apImpl){}
	~CInput() = default;
	
	bool Init(const IServiceLocator &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	void AttachToWindow(IWindow *apWindow) override;
	
	void RegisterDevice(IInputDevice &aDevice) override;
	void UnregisterDevice(IInputDevice &aDevice) override;
	
	IInputDevice *GetDevice(IInputDevice::Type aeType, int anIndex) const override
	{
		if(auto It : mlstDevices)
			if(It.get().GetType() == aeType)
				return It;
		
		return nullptr;
	};
private:
	tInputDeviceList mlstDevices;
	
	const IServiceLocator &mCoreEnv;
	
	IInputImpl *mpImpl{nullptr};
};

}; // namespace rz::input