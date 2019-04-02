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

struct IInputDevice
{
	enum class Type : int
	{
		Keyboard,
		Mouse,
		Gamepad
	};
	
	//virtual void Release() = 0;
	
	virtual void Update() = 0;
	
	virtual const char *GetName() const = 0; // GetDeviceName?
	//virtual Type GetType() const = 0; // GetDeviceType?
};

}; // namespace rz::input