#pragma once

#include "ISubSystem.hpp"
#include "physics/IPhysics.hpp"

class CLoggedPhysics : public ISubSystem<IPhysics>
{
public:
	CLoggedPhysics(const IPhysics &aImpl) : mpImpl(*aImpl){}
	~CLoggedPhysics() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	const char *GetSubSystemName() const {return "Physics;}
private:
	IPhysics *mpImpl{nullptr};
};