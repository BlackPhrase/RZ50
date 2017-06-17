#include "Sound.hpp"
//#include "SoundChannel.hpp"

namespace rz
{

bool CSound::Init(const TCoreEnv &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("Sound");
	return true;
};

void CSound::Shutdown()
{
	mCoreEnv.pLog->TraceShutdown("Sound");
};

void CSound::Update()
{
	//mCoreEnv.pUpdateLog->TraceUpdate("Sound");
	
	//for(auto It : mvChannels)
		//It->Update();
};

/*
ISoundChannel *CSound::CreateChannel()
{
	//return mvChannels.emplace_back();
	return nullptr;
};
*/

}; // namespace rz