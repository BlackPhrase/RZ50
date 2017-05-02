#pragma once

#include "ISubSystem.hpp"
#include "input/IInput.hpp"

class CLoggedInput : public ISubSystem<IInput>
{
public:
	CLoggedInput(const IInput &aImpl) : mpImpl(*aImpl){}
	~CLoggedInput() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	const char *GetSubSystemName() const {return "Input";}
private:
	IInput *mpImpl{nullptr};
};