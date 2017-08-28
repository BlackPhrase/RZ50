#pragma once

namespace rz
{

struct IInputDevice;
struct TCoreEnv;

struct IInput
{
	virtual void RegisterDevice(IInputDevice &aDevice) = 0;
	virtual void UnregisterDevice(IInputDevice &aDevice) = 0;
};

using pfnGetInput = ISubSystem *(*)(const TCoreEnv &aCoreEnv);

}; // namespace rz