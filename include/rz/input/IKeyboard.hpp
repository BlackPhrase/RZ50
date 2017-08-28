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