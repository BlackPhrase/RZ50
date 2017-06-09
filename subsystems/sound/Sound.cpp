#include "Sound.hpp"

bool CSound::Init(const TCoreEnv &aCoreEnv)
{
	mpCoreEnv = &aCoreEnv;
	
	mpCoreEnv->pLog->TraceInit("Sound");
	return true;
};

void CSound::Shutdown()
{
	mpCoreEnv->pLog->TraceShutdown("Sound");
};

void CSound::Update()
{
	//mpCoreEnv->pUpdateLog->TraceUpdate("Sound");
	
	for(auto It : mvChannels)
		It->Update();
};

ISoundChannel *CSound::CreateChannel()
{
	return mvChannels.emplace_back();
};