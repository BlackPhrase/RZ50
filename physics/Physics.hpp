#pragma once

#include "ISubSystem.hpp"
#include "physics/IPhysics.hpp"

class CPhysics : public ISubSystem<IPhysics>
{
public:
	CPhysics() = default;
	~CPhysics() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	const char *GetSubSystemName() const {return "Physics";}
};