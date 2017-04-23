#pragma once

#include "input/IInput.hpp"

class CLoggedInput : public IInput
{
public:
	CLoggedInput(const IInput &aImpl) : mpImpl(*aImpl){}
	~CLoggedInput() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
private:
	IInput *mpImpl{nullptr};
};