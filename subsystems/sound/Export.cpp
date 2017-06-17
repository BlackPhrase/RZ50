#include "core/CoreTypes.hpp"
#include "core/TCoreEnv.hpp"
#include "Sound.hpp"

//DECLARE_SUBSYSTEM("Sound", GetSoundSubSystem)

C_EXPORT rz::ISubSystem *GetSound(const rz::TCoreEnv &aCoreEnv)
{
	static rz::CSound Sound(aCoreEnv);
	return &Sound;
};