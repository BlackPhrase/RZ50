#include "SoundWorld.hpp"

namespace rz
{

void CSoundWorld::Update()
{
	for(auto It : mvActiveSounds)
		It->Update();
};

void CSoundWorld::Clear()
{
};

void CSoundWorld::BroadcastSound(const Vec3f &aPos, const char *asSample)
{
	TSoundNetMsg SoundBroadcast(aPos, asSample);
	mpServer->BroadcastMsg(TSoundNetMsg);
};

}; // namespace rz