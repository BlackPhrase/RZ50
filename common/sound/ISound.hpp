#pragma once

namespace rz
{

struct ISubSystem;
struct TCoreEnv;
struct ISoundWorld;
struct ISoundChannel;

struct ISound
{
	virtual const ISoundWorld &CreateWorld() = 0;
	virtual void DestroyWorld(ISoundWorld &aWorld) = 0;
	
	// SetActiveWorld
	virtual void SetCurrentWorld(const ISoundWorld &aWorld) = 0;
	virtual ISoundWorld *GetCurrentWorld() const = 0;
	
	//virtual ISoundChannel *CreateChannel() = 0;
};

using pfnGetSound = ISubSystem *(*)(const TCoreEnv &aCoreEnv);

}; // namespace rz