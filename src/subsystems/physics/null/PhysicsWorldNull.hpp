#pragma once

#include "physics/IPhysicsWorld.hpp"

namespace rz
{

using tPhysicsBodyList = std::list<IPhysicsBody*>;

class CPhysicsWorld : public IPhysicsWorld
{
public:
	CPhysicsWorld() = default;
	~CPhysicsWorld() = default;
	
	void Update();
	
	void Clear();
	
	IPhysicsBody *CreateBody();
private:
	tPhysicsBodyList mlstBodies;
};

}; // namespace rz