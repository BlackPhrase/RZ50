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
	CInput(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CInput() = default;
	
	bool Init(const TCoreEnv &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	void RegisterDevice(IInputDevice &aDevice) override;
	void UnregisterDevice(IInputDevice &aDevice) override;
	
	const char *GetSubSystemName() const override {return "Input";}
private:
	tInputDeviceList mlstDevices;
	
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz