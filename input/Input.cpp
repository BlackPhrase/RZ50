#include "Input.hpp"

bool CInput::Init(const TCoreEnvironment &aCoreEnv)
{
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
	for(auto It : mlstDevices)
		It->Update();
};