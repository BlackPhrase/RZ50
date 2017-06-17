#include "core/CoreTypes.hpp"
#include "Physics.hpp"

//DECLARE_SUBSYSTEM(CPhysics, GetPhysicsSubSystem)

C_EXPORT rz::ISubSystem *GetPhysics(const rz::TCoreEnv &aCoreEnv)
{
	static rz::CPhysics Physics(aCoreEnv);
	return &Physics;
};