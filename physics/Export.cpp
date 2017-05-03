#include "LoggedPhysics.hpp"
#include "Physics.hpp"

//DECLARE_SUBSYSTEM(CPhysics, GetPhysicsSubSystem)

#ifndef RZ_STATIC_PHYSICS
	extern "C" EXPORT
#endif // RZ_STATIC_PHYSICS

ISubSystem *GetSystemSubSystem()
{
	static ISubSystem *pPhysics = 
	
#ifdef RZ_LOGGED_PHYSICS
	new CLoggedPhysics(
#endif

	new CPhysics()
	
#ifdef RZ_LOGGED_PHYSICS
	);
#endif
	
	return pPhysics;
};