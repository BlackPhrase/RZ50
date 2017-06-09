#include "Physics.hpp"

//DECLARE_SUBSYSTEM(CPhysics, GetPhysicsSubSystem)

C_EXPORT rz::ISubSystem *GetSystemSubSystem()
{
	static CPhysics Physics;
	return &Physics;
};