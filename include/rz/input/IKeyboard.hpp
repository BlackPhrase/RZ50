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

#include "IInputDevice.hpp"

namespace rz
{

struct IKeyboard : public IInputDevice
{
	enum class Key : int
	{
		W,
		A,
		S,
		D,
		
		E,
		R,
		
		Esc,
		
		Left,
		Right,
		Up,
		Down,
		
		Space,
		Enter,
		Tab,
		CapsLock,
		
		LeftShift,
		RightShift,
		
		LeftCtrl,
		RightCtrl,
		
		LeftAlt,
		RightAlt,
		
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
		
		Zero,
		One,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		
		Num1,
		Num2,
		Num3,
		Num4,
		Num5,
		Num6,
		Num7,
		Num8,
		Num9,
		Num0,
		
		// TODO
	};
	
	virtual bool IsKeyDown(Key aeKey) const = 0;
	virtual bool IsAnyKeyDown() const = 0;
	
	const char *GetDeviceName() const {return "Keyboard";}
};

}; // namespace rz