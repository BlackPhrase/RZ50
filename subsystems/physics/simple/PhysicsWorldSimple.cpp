#include "PhysicsWorld.hpp"
#include "PhysicsObject.hpp"

namespace rz
{

void CPhysicsWorld::Simulate(float afDeltaTime)
{
	for(auto It : mvObjects)
		It->Update(afDeltaTime);
};

}; // namespace rz