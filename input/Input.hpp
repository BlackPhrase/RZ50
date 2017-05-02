#pragma once

#include <list>
#include "ISubSystem.hpp"
#include "input/IInput.hpp"

struct IInputDevice;
using tInputDeviceList = std::list<IInputDevice*>;

class CInput : public ISubSystem<IInput>
{
public:
	CInput() = default;
	~CInput() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	const char *GetSubSystemName() const {return "Input";}
private:
	tInputDeviceList mlstDevices;
};