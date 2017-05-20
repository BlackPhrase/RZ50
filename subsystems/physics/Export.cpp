#include "LoggedPhysics.hpp"
#include "Physics.hpp"

//DECLARE_SUBSYSTEM(CPhysics, GetPhysicsSubSystem)

#ifndef RZ_STATIC_PHYSICS
	extern "C" EXPORT
#endif // RZ_STATIC_PHYSICS

rz::ISubSystem *GetSystemSubSystem()
{
	static rz::ISubSystem *pPhysics = 
	
#ifdef RZ_LOGGED_PHYSICS
	new rz::CLoggedPhysics(
#endif

	new rz::CPhysics()
	
#ifdef RZ_LOGGED_PHYSICS
	);
#endif
	
	return pPhysics;
};