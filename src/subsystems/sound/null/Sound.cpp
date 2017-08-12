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
	
	if(mpWorld)
		mpWorld->Update();
};

/*
ISoundChannel *CSound::CreateChannel()
{
	//return mvChannels.emplace_back();
	return nullptr;
};
*/

const ISoundWorld &CSound::CreateWorld()
{
	return new CSoundWorldNull();
};

void CSound::DestroyWorld(ISoundWorld &aWorld)
{
	delete &aWorld;
};

void CSound::SetCurrentWorld(const ISoundWorld &aWorld)
{
	if(*mpWorld != aWorld)
		*mpWorld = aWorld;
};

//ISoundWorld *CSound::GetCurrentWorld() const {return mpWorld;}

}; // namespace rz