#include "LoggedInput.hpp"
#include "Input.hpp"

//DECLARE_SUBSYSTEM(CInput, GetInputSubSystem)

#ifndef RZ_STATIC_INPUT
	extern "C" EXPORT
#endif // RZ_STATIC_INPUT

ISubSystem *GetInputSubSystem()
{
	static ISubSystem *pInput = 
	
#ifdef RZ_LOGGED_INPUT
	new CLoggedInput(
#endif

	new CInput()
	
#ifdef RZ_LOGGED_INPUT
	);
#endif
	
	return pInput;
};