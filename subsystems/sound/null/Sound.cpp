#include "Sound.hpp"
//#include "SoundChannel.hpp"

namespace rz
{

bool CSound::Init(const TCoreEnv &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("Sound");
	mCoreEnv.pLog->Info("Sound: Null");
	return true;
};

void CSound::Shutdown()
{
};

void CSound::Update()
{
	mCoreEnv.pCmdProcessor->Append("play test");
	
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