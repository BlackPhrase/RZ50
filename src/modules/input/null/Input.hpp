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