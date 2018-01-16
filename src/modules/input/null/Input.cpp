#include "core/CoreTypes.hpp"
#include "input/IInputDevice.hpp"
#include "core/IServiceLocator.hpp"
#include "Input.hpp"
#include "Mouse.hpp"

namespace rz
{

bool CInput::Init(const IServiceLocator &aCoreEnv)
{
	mCoreEnv.GetLog().TraceInit("Input");
	mCoreEnv.GetLog().Info("Input: Null");
	
	mlstDevices.push_back(new CNullMouse(aCoreEnv));
	return true;
};

void CInput::Shutdown()
{
	// NOTE: move to destructor?
	
	auto It = mlstDevices.begin();
	while(It != mlstDevices.end())
	{
		//It->Release(); // delete itself
		It = mlstDevices.erase(It);
	};
};

void CInput::Update()
{
	//mCoreEnv.pUpdateLog->TraceUpdate("Input");
	
	mCoreEnv.GetCmdProcessor().BufferText("backward;left;right", ICmdProcessor::InsertMode::Append);
	mCoreEnv.GetCmdProcessor().BufferText("forward", ICmdProcessor::InsertMode::Insert);
	
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