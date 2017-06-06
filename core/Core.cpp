#include "Core.hpp"
#include "SubSystemManager.hpp"
#include "Memory.hpp"
#include "Log.hpp"

namespace rz
{

CCore::CCore() = default;

bool CCore::Init(const TCoreInitParams &aParams)
{
	if(mbInitialized)
		return true;
	
	mpMemory = std::make_unique<CMemory>();
	mpLog = std::make_unique<CLog>();
	mpSubSystemManager = std::make_unique<CSubSystemManager>();
	
	mEnv.pMemory = mpMemory.get();
	mEnv.pLog = mpLog.get();
	
	if(!mpSubSystemManager->Init(mEnv))
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
	//assert(mbInitialized);
	
	float fFPS = 0.0f;
	
	// Begin frame profiling
	// Start timing
	
	//mpEventHandler->Que(Event);
	//mpEventHandler->Update();
	
	mpSubSystemManager->Update();
	
	// Gather statistics
	// End frame profiling
	
	if(fFPS < mStats.fMinFPS)
		mStats.fMinFPS = fFPS;
	
	if(fFPS > mStats.fMaxFPS)
		mStats.fMaxFPS = fFPS;
};

bool CCore::RegisterSubSystem(const ISubSystem &apSubSystem)
{
	return mpSubSystemManager->Add(apSubSystem);
};

ISubSystem *CCore::GetSubSystem(const char *asName) const
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