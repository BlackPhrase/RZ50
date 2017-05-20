#include "LoggedSound.hpp"
#include "Sound.hpp"

//DECLARE_SUBSYSTEM("Sound", GetSoundSubSystem)

#ifndef RZ_STATIC_SOUND
	extern "C" EXPORT
#endif // RZ_STATIC_SOUND

rz::ISubSystem *GetSoundSubSystem()
{
	static rz::ISubSystem *pSoundSystem = 
	
#ifdef RZ_LOGGED_SOUND
	new rz::CLoggedSound(
#endif

	new rz::CSound()
	
#ifdef RZ_LOGGED_SOUND
	);
#endif
	
	return pSoundSystem;
};