#include "Input.hpp"
#include "input/IInputDevice.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

bool CInput::Init(const TCoreEnv &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("Input");
	return true;
};

void CInput::Shutdown()
{
	mCoreEnv.pLog->TraceShutdown("Input");
	
	for(auto It : mlstDevices)
	{
		//It->Release();
		//It.erase();
	};
};

void CInput::Update()
{
	//mCoreEnv.pUpdateLog->TraceUpdate("Input");
	
	for(auto It : mlstDevices)
		It->Update();
};

void CInput::RegisterDevice(IInputDevice &aDevice)
{
};

void CInput::UnregisterDevice(IInputDevice &aDevice)
{
};

}; // namespace rz