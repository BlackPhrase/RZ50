#include "LoggedSound.hpp"
#include "Sound.hpp"

//DECLARE_SUBSYSTEM("Sound", GetSoundSubSystem)

#ifndef RZ_STATIC_SOUND
	extern "C" EXPORT
#endif // RZ_STATIC_SOUND

ISubSystem *GetSoundSubSystem()
{
	static ISubSystem *pSoundSystem = 
	
#ifdef RZ_LOGGED_SOUND
	new CLoggedSound(
#endif

	new CSound()
	
#ifdef RZ_LOGGED_SOUND
	);
#endif
	
	return pSoundSystem;
};