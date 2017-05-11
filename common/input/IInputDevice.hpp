#pragma once

namespace rz
{

struct IInputDevice
{
	virtual const char *GetName() const = 0;
	virtual const char *GetType() const = 0;
	
	virtual void Update() = 0;
};

}; // namespace rz