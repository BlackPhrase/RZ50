#include "Sound.hpp"

bool CSound::Init(const TCoreEnvironment &aCoreEnv)
{
	return true;
};

void CSound::Shutdown()
{
};

void CSound::Update()
{
	for(auto It : mvChannels)
		It->Update();
};

ISoundChannel *CSound::CreateChannel()
{
	return mvChannels.emplace_back();
};