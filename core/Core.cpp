#include "Core.hpp"
#include "SubSystemManager.hpp"
#include "PluginManager.hpp"
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
	
	// TODO: memory init?
	
	mpLog = std::make_unique<CLog>();
	
	if(!mpLog->Init())
		return false;
	
	mpLog->TraceInit("Core");
	
	mEnv.pMemory = mpMemory.get();
	mEnv.pLog = mpLog.get();
	
	mpSubSystemManager = std::make_unique<CSubSystemManager>();
	
	// TODO: check that we should use plugins (read the config setting)
	// and if should then init plugin manager here
	if(!mpSubSystemManager->Init(mEnv))
		return false;
	
	mpPluginManager = std::make_unique<CPluginManager>();
	
	if(!mpPluginManager->Init(mEnv))
		return false;
	
	mEnv.pPluginManager = mpPluginManager.get();
	
	if(!mpPluginManager->LoadPlugin("TestPlugin"))
		return false;
	
	mbInitialized = true;
	return true;
};

void CCore::Shutdown()
{
	if(!mbInitialized)
		return;
	
	mpPluginManager->Shutdown();
	mpSubSystemManager->Shutdown();
	
	mpLog->TraceShutdown("Core");
	
	PrintStats();
};

void CCore::Frame()
{
	//assert(mbInitialized);
	
	if(!mbInitialized || mbWantQuit) // we can check for current state
		return;
	
	static int nFrame = 0;
	mpLog->Debug("Core frame #%d", nFrame + 1);
	// should be some generic interface which will work as redirector
	// it should broadcast the messages to its listeners (log/console/etc which could be
	// optionally dynamically connected)
	// but in that case there wouldn't be possible to access the log from the core environment...
	
	if(nFrame >= 100)
		mbWantQuit = true;
	
	static float fFPS = 0.0f;
	
	// Begin frame profiling
	// Start timing
	
	auto TimePreFrame = std::chrono::steady_clock::now();
	
	//mpEventHandler->Update();
	
	//FrameBegin() event;
	
	mpSubSystemManager->Update();
	
	// Gather statistics
	// End frame profiling
	
	auto TimePostFrame = std::chrono::steady_clock::now();
	
	auto FrameTime = std::chrono::duration_cast<std::chrono::duration<double>>(TimePostFrame - TimePreFrame);
	
	mpLog->Debug("FrameTime: %f", FrameTime.count());
	
	// TODO: frametime -> statistics
	// TODO: avg. frametime?
	
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
	// Print final stats
	mpLog->Info("Statistics:\n"
				 "\t- Min. FPS: %.2f\n"
				 "\t- Max. FPS: %.2f\n"
				 "\t- Avg. FPS: %.2f",
				 // TODO: UPS per core
				 // TODO: Cores?
				 mStats.fMinFPS,
				 mStats.fMaxFPS,
				 mStats.fAvgFPS);
};

}; // namespace rz