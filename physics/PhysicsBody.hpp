#pragma once

#include "physics/IPhysicsBody.hpp"

namespace rz
{

class CPhysicsBody : public IPhysicsBody
{
public:
	CPhysicsBody() = default;
	~CPhysicsBody() = default;
	
	void SetPos(const tVec3f &avPos);
	const tVec3f &GetPos() const;
	
	//void SetVelocity(float afVelocity);
	//float GetVelocity();
	
	void AddForce();
private:
};

}; // namespace rz