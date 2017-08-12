#pragma once

#include "physics/IPhysicsWorld.hpp"

namespace rz
{

class CPhysicsObject;

// Simple Physics World Implementation
class CPhysicsWorld : public IPhysicsWorld
{
public:
	CPhysicsWorld() = default;
	~CPhysicsWorld() = default;
	
	void Update();
	
	void Simulate(float afDeltaTime);
	
	void AddObject(const CPhysicsObject &aObject);
	
	void SetGravity(const CVec3f &avGravity){mvGravity = avGravity;}
	const CVec3f &GetGravity() const {return mvGravity;}
private:
	tPhysicsObjectVec mvObjects;
	
	CVec3f mvGravity{0.0f, 0.0f, 0.0f};
};

}; // namespace rz