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

namespace rz::input
{

struct IInputDevice;
struct IWindow;

struct IInput
{
	///
	virtual void AttachToWindow(IWindow *apWindow) = 0;
	
	///
	virtual void RegisterDevice(IInputDevice &aDevice) = 0;
	
	///
	virtual void UnregisterDevice(IInputDevice &aDevice) = 0;
	
	///
	virtual IInputDevice *GetDevice(IInputDevice::Type aeType, int anIndex = 0) const = 0;
	
	///
	template<typename T>
	inline T *GetDevice(int anIndex = 0) const {return static_cast<T*>(GetDevice(T::Type, anIndex));}
};

}; // namespace rz::input