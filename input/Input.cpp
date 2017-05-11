#include "Input.hpp"

namespace rz
{

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

}; // namespace rz