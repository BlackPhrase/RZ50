#include "Input.hpp"

bool CInput::Init()
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