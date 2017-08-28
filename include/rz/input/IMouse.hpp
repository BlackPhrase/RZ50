#pragma once

#include "IInputDevice.hpp"

namespace rz
{

struct IMouse : public IInputDevice
{
	enum class Button : int
	{
		Left,
		Right,
		Middle
	};
	
	virtual bool IsButtonPressed(Button aeButton) const = 0;
	
	const char *GetName() const override final {return "Mouse";}
};

}; // namespace rz