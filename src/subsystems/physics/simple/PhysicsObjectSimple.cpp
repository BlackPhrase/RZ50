#include "PhysicsObject.hpp"

namespace rz
{

void CPhysicsObject::Update(float afDeltaTime)
{
	mvPosition += mvVelocity * afDeltaTime;
};

}; // namespace rz