#pragma once

#include "ISystem.hpp"

class CLoggedSystem : public ISystem
{
public:
	CLoggedSystem(const ISystem &aImpl) : mpImpl(*aImpl){}
	~CLoggedSystem() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
private:
	ISystem *mpImpl{nullptr};
};