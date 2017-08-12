#include "Core.hpp"
#include "SubSystemContainer.hpp"
#include "EventDispatcher.hpp"
#include "PluginManager.hpp"
#include "StatsPrinter.hpp"
#include "CmdProcessor.hpp"
#include "ConfigFactory.hpp"
#include "CmdLine.hpp"
#include "core/IConfig.hpp"
#include "IniConfig.hpp"
#include "Memory.hpp"
#include "Log.hpp"

#include "testing/EchoEventListener.hpp"
#include "testing/MouseEventListener.hpp"

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
	// TODO: remove local usage of core env?
	
	if(mbInitialized)
		return true;

#ifdef _WIN32
	mpTextConsole = std::make_unique<CTextConsoleWin>();
#else
	// TODO
#endif

	if(!mpTextConsole->Init())
		return false;
	
	mpCmdLine = std::make_unique<CCmdLine>(aInitParams.sCmdLine);
	mpMemory = std::make_unique<CMemory>();
	
	//mpConfigFactory = std::make_unique<CConfigFactory>();
	//mpConfig = std::make_unique<IConfig>();
	
	mpConfig = std::make_unique<CIniConfig>("EngineConfig-Test.ini");
	
	mpLog = std::make_unique<CLog>();
	
	if(!mpLog->Init(mEnv))
		return false;
	
	mpLog->TraceInit("Core");
	
	// NOTE: Max updates is 30Hz for now
	SetUpdateFreq(30.0f);
	
	mpConfig->Init(mEnv);
	
	mpMemory->Init(mEnv);
	
	mpEventDispatcher = std::make_unique<CEventDispatcher>(mEnv);
	
	mpEventDispatcher->Init(mEnv);
	
	//static CEchoEventListener EchoEventListener(mEnv); // TODO: fix lifetime managing
	//mpEventDispatcher->AddListener(EchoEventListener);
	
	static CMouseEventListener MouseEventListener(mEnv); // TODO: fix lifetime managing
	mpEventDispatcher->AddListener(MouseEventListener);
	
	mpCmdProcessor = std::make_unique<CCmdProcessor>(mEnv, this);
	
	//mpCmdProcessor->Init(mEnv);
	
	mpSubSystemContainer = std::make_unique<CSubSystemContainer>(mEnv);
	
	if(!mpSubSystemContainer->Init(mEnv))
		return false;
	
	mpPluginManager = std::make_unique<CPluginManager>(mEnv);
	
	mpStatsPrinter = std::make_unique<CStatsPrinter>();
	
	// TODO: check that we should use plugins (read the config setting)
	// and if should then init plugin manager here
	if(!mpPluginManager->Init(mEnv))
		return false;
	
	mpPluginManager->LoadPlugin("TestPlugin");
	
	mpLog->Debug("Config: [General] Test: %s", mpConfig->GetString("General:Test", "Default"));
	
	mpLog->Info("Update freq is %f / TimeStep is %.16f", GetUpdateFreq(), GetTimeStep());
	
	mbInitialized = true;
	return true;
};

void CCore::Shutdown()
{
	if(!mbInitialized)
		return;
	
	mpPluginManager->Shutdown();
	mpSubSystemContainer->Shutdown();
	
	mpLog->TraceShutdown("Core");
	
	mpTextConsole->Shutdown();
	
	// Print final stats
	mpStatsPrinter->PrintToLog(mStats, mpLog.get());
};

void CCore::Frame()
{
	//ASSERT(mbInitialized);
	
	if(!mbInitialized || mbWantQuit) // NOTE: we can check for current state
		return;
	
	// Begin frame profiling
	// Start timing
	
	TFrameBeginEvent FrameBeginEvent;
	mpEventDispatcher->BroadcastEvent(FrameBeginEvent); // NOTE: potential timing issues?
	
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
	
	//mpSubSystemContainer->Update();
	
	// NOTE: when the "exit" command received this loop will still be processing updates
	// So we check for a pending quit flag here to prevent that
	while(fLag >= GetTimeStep() && !mbWantQuit)
	{
		mpLog->Debug("Lag: %fs / FrameTime: %fs (%fms)", fLag, FrameTime.count(), FrameTimeMs.count());

		mpCmdProcessor->ExecBuffer();

		mpEventDispatcher->DispatchEvents(); //Update();

		mpSubSystemContainer->Update(); // FixedUpdate();
		
		fLag -= GetTimeStep();
	};
	
	//mpSubSystemContainer->PostUpdate();
	
	// Gather statistics
	// End frame profiling
	
	mfFrameTimeAcc += FrameTime.count();
	
	// TODO: frametime -> statistics
	
	if(fFPS < mStats.fMinFPS)
		mStats.fMinFPS = fFPS;
	
	if(fFPS > mStats.fMaxFPS)
		mStats.fMaxFPS = fFPS;
	
	TFrameEndEvent FrameEndEvent;
	mpEventDispatcher->BroadcastEvent(FrameEndEvent); // NOTE: potential timing issues?
	
	mStats.nTotalFrames++;
	
	mStats.fAvgFrameTime = mfFrameTimeAcc / mStats.nTotalFrames;
};

void CCore::RequestClose()
{
	mbWantQuit = true;
};

}; // namespace rz