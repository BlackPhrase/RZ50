#include "LoggedSystem.hpp"
#include "System.hpp"

//DECLARE_SUBSYSTEM(CSystem, GetSystemSubSystem)

#ifndef RZ_STATIC_SYSTEM
	extern "C" EXPORT
#endif // RZ_STATIC_SYSTEM

rz::ISubSystem *GetSystemSubSystem()
{
	static rz::ISubSystem *pSystem = 
	
#ifdef RZ_LOGGED_SYSTEM
	new rz::CLoggedSystem(
#endif

	new rz::CSystem()
	
#ifdef RZ_LOGGED_SYSTEM
	);
#endif
	
	return pSystem;
};