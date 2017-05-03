#pragma once

#include <list>
#include "ISubSystem.hpp"
#include "input/IInput.hpp"

struct IInputDevice;
using tInputDeviceList = std::list<IInputDevice*>;

class CInput final : public ISubSystem<IInput>
{
public:
	CInput() = default;
	~CInput() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "Input";}
private:
	tInputDeviceList mlstDevices;
};