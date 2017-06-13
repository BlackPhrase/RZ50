#pragma once

namespace rz
{

struct IInputDevice;

struct IInput
{
	virtual void RegisterDevice(IInputDevice &aDevice) = 0;
	virtual void UnregisterDevice(IInputDevice &aDevice) = 0;
};

using pfnGetInput = ISubSystem *(*)();

}; // namespace rz