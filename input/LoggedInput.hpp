#pragma once

#include "IInput.hpp"

class CLoggedInput : public IInput
{
public:
	CLoggedInput(const IInput &aImpl) : mpImpl(*aImpl){}
	~CLoggedInput() = default;
	
	bool Init();
	void Shutdown();
	
	void Update();
private:
	IInput *mpImpl{nullptr};
};