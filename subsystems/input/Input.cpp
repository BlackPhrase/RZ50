#include "core/CoreTypes.hpp"
#include "Input.hpp"
#include "input/IInputDevice.hpp"
#include "core/TCoreEnv.hpp"
#include "Mouse.hpp"

namespace rz
{

bool CInput::Init(const TCoreEnv &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("Input");
	mCoreEnv.pLog->Info("Input: Null");
	
	mlstDevices.push_back(new CNullMouse(aCoreEnv));
	return true;
};

void CInput::Shutdown()
{
	for(auto It : mlstDevices)
	{
		//It->Release(); // delete itself
		mlstDevices.remove(It);
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
	// Skip duplication
	for(auto It : mlstDevices)
		if(!strcmp(It->GetName(), aDevice.GetName()))
			return;
	
	mlstDevices.push_back(&aDevice);
};

void CInput::UnregisterDevice(IInputDevice &aDevice)
{
	for(auto It : mlstDevices)
		if(!strcmp(It->GetName(), aDevice.GetName()))
		{
			//It->Release();
			mlstDevices.remove(It);
		};
};

}; // namespace rz