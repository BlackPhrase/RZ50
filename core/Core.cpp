#include <iostream>
#include "Core.hpp"
#include "SubSystemManager.hpp"
#include "Memory.hpp"
#include "Log.hpp"

namespace rz
{

CCore::CCore() = default;
CCore::~CCore() = default;

bool CCore::Init(const TCoreInitParams &aInitParams)
{
	if(mbInitialized)
		return true;
	
	mpMemory = std::make_unique<CMemory>();
	mpLog = std::make_unique<CLog>();
	mpSubSystemManager = std::make_unique<CSubSystemManager>();
	
	if(!mpLog->Init())
		return false;
	
	mpLog->TraceInit("Core");
	
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
	
	mpLog->TraceShutdown("Core");
	
	PrintStats();
};

void CCore::Frame()
{
	//assert(mbInitialized);
	
	static int nFrame = 0;
	mpLog->Info("Core frame #%d", nFrame + 1);
	// should be some generic interface which will work as redirector
	// it should broadcast the messages to its listeners (log/console/etc which could be
	// optionally dynamically connected)
	// but in that case there wouldn't be possible to access the log from the core environment...
	
	if(nFrame >= 1000)
		mbWantQuit = true;
	
	static float fFPS = 0.0f;
	
	// Begin frame profiling
	// Start timing
	
	//mpEventHandler->Update();
	
	//FrameBegin() event;
	
	mpSubSystemManager->Update();
	
	// Gather statistics
	// End frame profiling
	
	if(fFPS < mStats.fMinFPS)
		mStats.fMinFPS = fFPS;
	
	if(fFPS > mStats.fMaxFPS)
		mStats.fMaxFPS = fFPS;
	
	// FrameEnd() event;
	
	nFrame++;
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
	mpLog->Info("Statistics:\n"
				 "\t- Min. FPS: %.2f\n"
				 "\t- Max. FPS: %.2f\n"
				 "\t- Avg. FPS: %.2f",
				 mStats.fMinFPS,
				 mStats.fMaxFPS,
				 mStats.fAvgFPS);
};

}; // namespace rz