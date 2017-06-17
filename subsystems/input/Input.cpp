#include "Input.hpp"
#include "input/IInputDevice.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

bool CInput::Init(const TCoreEnv &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("Input");
	mCoreEnv.pLog->Info("Input: Null");
	return true;
};

void CInput::Shutdown()
{
	for(auto It : mlstDevices)
	{
		//It->Release();
		//It.erase();
	};
};

void CInput::Update()
{
	//mCoreEnv.pUpdateLog->TraceUpdate("Input");
	
	mCoreEnv.pCmdProcessor->Append("forward");
	mCoreEnv.pCmdProcessor->Append("backward");
	mCoreEnv.pCmdProcessor->Append("left");
	mCoreEnv.pCmdProcessor->Append("right");
	
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