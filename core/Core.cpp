#include "Core.hpp"
#include "SubSystemManager.hpp"
#include "Memory.hpp"
#include "Log.hpp"

namespace rz
{

bool CCore::Init()
{
	if(mbInitialized)
		return true;
	
	mpMemory = std::make_unique<CMemory>();
	mpLog = std::make_unique<CLog>();
	mpSubSystemManager = std::make_unique<CSubSystemManager>();
	
	mCoreEnv.pMemory = mpMemory.get();
	mCoreEnv.pLog = mpLog.get();
	
	if(!mpSubSystemManager->Init(mCoreEnv))
		return false;
	
	mbInitialized = true;
	return true;
};

void CCore::Shutdown()
{
	if(!mbInitialized)
		return;
	
	mpSubSystemManager->Shutdown();
	
	PrintStats();
};

void CCore::Frame()
{
	float fFPS = 0.0f;
	
	// Begin frame profiling
	// Start timing
	
	//CEvent Event = mpEventHandler->PollEvent();
	
	//mpEventHandler->QueueEvent(Event);
	
	mpSubSystemManager->Update();
	
	// Gather statistics
	// End frame profiling
	
	if(fFPS < mStats.fMinFPS)
		mStats.fMinFPS = fFPS;
	
	if(fFPS > mStats.fMaxFPS)
		mStats.fMaxFPS = fFPS;
};

bool CCore::AddSubSystem(ISubSystem *apSubSystem)
{
	return mpSubSystemManager->Add(apSubSystem);
};

ISubSystem *CCore::GetSubSystem(const char *asName)
{
	return mpSubSystemManager->GetByName(asName);
};

void CCore::PrintStats()
{
	mpLog->Write("Statistics:"
				 "Min. FPS: %f"
				 "Max. FPS: %f"
				 "Avg. FPS: %f",
				 mStats.fMinFPS,
				 mStats.fMaxFPS,
				 mStats.fAvgFPS);
};

}; // namespace rz