#pragma once

#include "physics/IPhysics.hpp"

namespace rz
{

class CPhysics : public IPhysics
{
public:
	CPhysics() = default;
	~CPhysics() = default;
	
	void Update();
	
	const IPhysicsWorld &CreateWorld();
	
	void SetActiveWorld(const IPhysicsWorld &aWorld);
	const IPhysicsWorld &GetActiveWorld() const;
private:
	tPhysicsWorldVec mvWorlds;
};

}; // namespace rz