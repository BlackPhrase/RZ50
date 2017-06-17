#pragma once

namespace rz
{

struct ISubSystem;
struct TCoreEnv;
struct ISoundWorld;
struct ISoundChannel;

struct ISound
{
	//virtual ISoundWorld *CreateWorld() = 0;
	//virtual ISoundChannel *CreateChannel() = 0;
};

using pfnGetSound = ISubSystem *(*)(const TCoreEnv &aCoreEnv);

}; // namespace rz