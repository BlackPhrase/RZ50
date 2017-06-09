#include "Sound.hpp"

//DECLARE_SUBSYSTEM("Sound", GetSoundSubSystem)

C_EXPORT rz::ISubSystem *GetSoundSubSystem()
{
	static CSound Sound;
	return &Sound;
};