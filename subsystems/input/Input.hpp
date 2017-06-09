#pragma once

#include <list>
#include "core/ISubSystem.hpp"
#include "input/IInput.hpp"

namespace rz
{

struct IInputDevice;
using tInputDeviceList = std::list<IInputDevice*>;

class CInput final : public ISubSystem, IInput
{
public:
	CInput() = default;
	~CInput() = default;
	
	bool Init(const TCoreEnv &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	void RegisterDevice(IInputDevice &aDevice) override;
	void UnregisterDevice(IInputDevice &aDevice) override;
	
	const char *GetSubSystemName() const override {return "Input";}
private:
	tInputDeviceList mlstDevices;
	
	const TCoreEnv *mpCoreEnv{nullptr};
};

}; // namespace rz