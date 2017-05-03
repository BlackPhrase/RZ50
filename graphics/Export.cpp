/*
#include "LoggedGraphics.hpp"
#include "Graphics.hpp"

//DECLARE_SUBSYSTEM(CGraphics, GetGraphicsSubSystem)

#ifndef RZ_STATIC_GRAPHICS
	extern "C" EXPORT
#endif // RZ_STATIC_GRAPHICS

ISubSystem *GetGraphicsSubSystem()
{
	static ISubSystem *pGraphics = 
	
#ifdef RZ_LOGGED_GRAPHICS
	new CLoggedGraphics(
#endif

	new CGraphics()
	
#ifdef RZ_LOGGED_GRAPHICS
	);
#endif
	
	return pGraphics;
};
*/