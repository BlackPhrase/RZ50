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

}; // namespace rz