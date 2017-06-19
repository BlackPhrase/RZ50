#include "Core.hpp"
#include "SubSystemManager.hpp"
#include "PluginManager.hpp"
#include "EventManager.hpp"
#include "CmdProcessor.hpp"
#include "CmdLine.hpp"
#include "Config.hpp"
#include "Memory.hpp"
#include "Log.hpp"

#include "EchoEventListener.hpp"
#include "MouseEventListener.hpp"

#ifdef _WIN32
	#include "impl/win/TextConsoleWin.hpp"
#else
	// TODO
#endif

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

#ifdef _WIN32
	mpTextConsole = std::make_unique<CTextConsoleWin>();
#else
	// TODO
#endif

	if(!mpTextConsole->Init())
		return false;

	// Max updates is 30Hz for now
	SetUpdateFreq(30.0f);
	
	mpCmdLine = std::make_unique<CCmdLine>(aInitParams.sCmdLine ? aInitParams.sCmdLine : "");
	
	mpMemory = std::make_unique<CMemory>();
	
	mpConfig = std::make_unique<CConfig>();
	
	// TODO: memory init?
	
	mpLog = std::make_unique<CLog>();
	
	if(!mpLog->Init())
		return false;
	
	mpLog->TraceInit("Core");
	
	mEnv.pConfig = mpConfig.get();
	mEnv.pMemory = mpMemory.get();
	mEnv.pLog = mpLog.get();
	
	mpEventManager = std::make_unique<CEventManager>(mEnv);
	
	mEnv.pEventManager = mpEventManager.get();
	
	//static CEchoEventListener EchoEventListener(mEnv); // TODO: fix lifetime managing
	//mpEventManager->AddListener(EchoEventListener);
	
	static CMouseEventListener MouseEventListener(mEnv); // TODO: fix lifetime managing
	mpEventManager->AddListener(MouseEventListener);
	
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
	
	mpLog->Info("Update freq is %f / TimeStep is %.16f", GetUpdateFreq(), GetTimeStep());
	
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
	
	mpTextConsole->Shutdown();
	
	PrintStats();
};

void CCore::Frame()
{
	//assert(mbInitialized);
	
	if(!mbInitialized || mbWantQuit) // NOTE: we can check for current state
		return;
	
	// Begin frame profiling
	// Start timing
	
	TFrameBeginEvent FrameBeginEvent;
	mpEventManager->BroadcastEvent(FrameBeginEvent); // NOTE: potential timing issues?
	
	static int nFrame = 1; // NOTE: move to stats?
	//mpLog->Debug("Core frame #%d", nFrame);
	
	static auto OldTime = std::chrono::steady_clock::now();
	static double fLag = 0.0f;
	
	auto CurrentTime = std::chrono::steady_clock::now();
	
	auto FrameTime = std::chrono::duration_cast<std::chrono::duration<double>>(CurrentTime - OldTime);
	auto FrameTimeMs = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(CurrentTime - OldTime);
	
	OldTime = CurrentTime;
	
	fLag += FrameTime.count();
	
	// should be some generic interface which will work as redirector
	// it should broadcast the messages to its listeners (log/console/etc which could be
	// optionally dynamically connected)
	// but in that case there wouldn't be possible to access the log from the core environment...
	
	static float fFPS = 0.0f;
	
	//mpSubSystemManager->Update();
	
	// NOTE: when the "exit" command received this loop will still be processing updates
	// So we check for a pending quit flag here to prevent that
	while(fLag >= GetTimeStep() && !mbWantQuit)
	{
		mpLog->Debug("Lag: %fs / FrameTime: %fs (%fms)", fLag, FrameTime.count(), FrameTimeMs.count());

		mpCmdProcessor->Exec();

		mpEventManager->DispatchEvents(); //Update();

		mpSubSystemManager->Update(); // FixedUpdate();
		
		fLag -= GetTimeStep();
	};
	
	//mpSubSystemManager->PostUpdate();
	
	// Gather statistics
	// End frame profiling
	
	mfFrameTimeAcc += FrameTime.count();
	
	// TODO: frametime -> statistics
	
	if(fFPS < mStats.fMinFPS)
		mStats.fMinFPS = fFPS;
	
	if(fFPS > mStats.fMaxFPS)
		mStats.fMaxFPS = fFPS;
	
	TFrameEndEvent FrameEndEvent;
	mpEventManager->BroadcastEvent(FrameEndEvent); // NOTE: potential timing issues?
	
	mStats.nTotalFrames++;
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
	mStats.fAvgFrameTime = mfFrameTimeAcc / mStats.nTotalFrames;
	
	// Print final stats
	mpLog->Info("Statistics:\n"
				 "\t- Total Frames: %d\n"
				 "\t- Min. FPS: %.2f\n"
				 "\t- Max. FPS: %.2f\n"
				 "\t- Avg. FPS: %.2f\n"
				 "\t- Avg. FrameTime %f",
				 // TODO: UPS per core
				 // TODO: Cores?
				 mStats.nTotalFrames,
				 mStats.fMinFPS,
				 mStats.fMaxFPS,
				 mStats.fAvgFPS,
				 mStats.fAvgFrameTime);
};

}; // namespace rz