#pragma once

#include "IPhysics.hpp"

class CPhysics : public IPhysics
{
public:
	CPhysics() = default;
	~CPhysics() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
};