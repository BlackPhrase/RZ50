#include "Core.hpp"
#include "SubSystemManager.hpp"
#include "PluginManager.hpp"
#include "EventManager.hpp"
#include "CmdProcessor.hpp"
#include "CmdLine.hpp"
#include "Memory.hpp"
#include "Log.hpp"

#include "EchoEventListener.hpp"

// TODO: rewrite subsystems to use the core environment in their export funcs
// (pfnGetSubSystem(const TCoreEnv &aCoreEnv) <- pass the env here)
// This way it would be possible to store the reference to env inside the class members

namespace rz
{

CCore::CCore() = default;
CCore::~CCore() = default;

bool CCore::Init(const TCoreInitParams &aInitParams)
{
	// TODO: remove local usage of core env
	
	if(mbInitialized)
		return true;
	
	// Max updates is 30Hz for now
	SetUpdateFreq(30.0f);
	
	mpCmdLine = std::make_unique<CCmdLine>(aInitParams.sCmdLine ? aInitParams.sCmdLine : "");
	
	mpMemory = std::make_unique<CMemory>();
	
	// TODO: memory init?
	
	mpLog = std::make_unique<CLog>();
	
	if(!mpLog->Init())
		return false;
	
	mpLog->TraceInit("Core");
	
	mEnv.pMemory = mpMemory.get();
	mEnv.pLog = mpLog.get();
	
	mpEventManager = std::make_unique<CEventManager>(mEnv);
	
	mEnv.pEventManager = mpEventManager.get();
	
	//static CEchoEventListener EchoEventListener(mEnv); // TODO: fix lifetime managing
	//mpEventManager->AddListener(EchoEventListener);
	
	mpCmdProcessor = std::make_unique<CCmdProcessor>(mEnv, this);
	
	mEnv.pCmdProcessor = mpCmdProcessor.get();
	
	mpSubSystemManager = std::make_unique<CSubSystemManager>();
	
	if(!mpSubSystemManager->Init(mEnv))
		return false;
	
	mpPluginManager = std::make_unique<CPluginManager>();
	
	// TODO: check that we should use plugins (read the config setting)
	// and if should then init plugin manager here
	if(!mpPluginManager->Init(mEnv))
		return false;
	
	mEnv.pPluginManager = mpPluginManager.get();
	
	if(!mpPluginManager->LoadPlugin("TestPlugin"))
		return false;
	
	mpLog->Info("Update freq is %d / TimeStep is %.16f", GetUpdateFreq(), GetTimeStep());
	
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
	
	if(!mbInitialized || mbWantQuit) // NOTE: we can check for current state
		return;
	
	TFrameBeginEvent FrameBeginEvent;
	mpEventManager->BroadcastEvent(FrameBeginEvent); // NOTE: potential timing issues?
	
	static int nFrame = 1; // NOTE: move to stats?
	//mpLog->Debug("Core frame #%d", nFrame);
	
	static auto OldTime = std::chrono::steady_clock::now();
	static double fLag = 0.0f;
	
	auto CurrentTime = std::chrono::steady_clock::now();
	
	auto FrameTime = std::chrono::duration_cast<std::chrono::duration<double>>(CurrentTime - OldTime);
	auto FrameTimeMs = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(CurrentTime - OldTime);
	auto FrameTimeNs = std::chrono::duration_cast<std::chrono::nanoseconds>(CurrentTime - OldTime);
	
	OldTime = CurrentTime;
	
	fLag += FrameTime.count();
	
	// should be some generic interface which will work as redirector
	// it should broadcast the messages to its listeners (log/console/etc which could be
	// optionally dynamically connected)
	// but in that case there wouldn't be possible to access the log from the core environment...
	
	static float fFPS = 0.0f;
	
	// Begin frame profiling
	// Start timing
	
	mpCmdProcessor->Exec();
	
	mpEventManager->DispatchEvents(); //Update();
	
	// Gather statistics
	// End frame profiling
	
	//mpSubSystemManager->Update();
	
	while(fLag >= GetTimeStep())
	{
		mpLog->Debug("Lag: %.16fs / FrameTime: %fs (%fms / %dns)", fLag, FrameTime.count(), FrameTimeMs.count(), FrameTimeNs.count());

		mpSubSystemManager->Update(); // FixedUpdate();
		fLag -= GetTimeStep();
	};
	
	//
	
	// Accumulated count of frametimes
	static double FrameTimeAcc{0.0f};
	FrameTimeAcc += FrameTime.count();
	
	// TODO: frametime -> statistics
	
	if(fFPS < mStats.fMinFPS)
		mStats.fMinFPS = fFPS;
	
	if(fFPS > mStats.fMaxFPS)
		mStats.fMaxFPS = fFPS;
	
	TFrameEndEvent FrameEndEvent;
	mpEventManager->BroadcastEvent(FrameEndEvent); // NOTE: potential timing issues?
	
	nFrame++;
	
	mStats.fAvgFrameTime = FrameTimeAcc / nFrame;
};

void CCore::RequestClose()
{
	mbWantQuit = true;
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
				 "\t- Avg. FPS: %.2f\n"
				 "\t- Avg. FrameTime %.2f",
				 // TODO: UPS per core
				 // TODO: Cores?
				 mStats.fMinFPS,
				 mStats.fMaxFPS,
				 mStats.fAvgFPS,
				 mStats.fAvgFrameTime);
};

}; // namespace rz