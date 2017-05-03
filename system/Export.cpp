#include "LoggedSystem.hpp"
#include "System.hpp"

//DECLARE_SUBSYSTEM(CSystem, GetSystemSubSystem)

#ifndef RZ_STATIC_SYSTEM
	extern "C" EXPORT
#endif // RZ_STATIC_SYSTEM

ISubSystem *GetSystemSubSystem()
{
	static ISubSystem *pSystem = 
	
#ifdef RZ_LOGGED_SYSTEM
	new CLoggedSystem(
#endif

	new CSystem()
	
#ifdef RZ_LOGGED_SYSTEM
	);
#endif
	
	return pSystem;
};