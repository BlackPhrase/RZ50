#pragma once

#include <list>
#include "input/IInput.hpp"

struct IInputDevice;
using tInputDeviceList = std::list<IInputDevice*>;

class CInput : public IInput
{
public:
	CInput() = default;
	~CInput() = default;
	
	bool Init();
	void Shutdown();
	
	void Update();
private:
	tInputDeviceList mlstDevices;
};