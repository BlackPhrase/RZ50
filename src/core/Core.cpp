/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2018 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Core.hpp"
#include "ServiceLocator.hpp"
#include "ModuleContainer.hpp"
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

bool CCore::Init(const TInitParams &aInitParams)
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
	
	mpEnv = std::make_unique<CServiceLocator>();
	
	mpConfigFactory = std::make_unique<CConfigFactory>();
	//mpConfig = std::make_unique<IConfig>(); // TODO: destructor should be accessible
	
	mpConfig = std::make_unique<CIniConfig>("EngineConfig-Test.ini");
	
	mpEnv->ProvideConfig(*mpConfig.get());
	
	IConfig *pConfig = mpConfigFactory->LoadFromFile("EngineConfig-Test.ini");
	
	//if(pConfig)
		//mpLog->Debug("Loaded config: %s", pConfig->GetName());
	
	mpLog = std::make_unique<CLog>();
	
	mpEnv->ProvideLog(*mpLog.get());
	
	mpLog->TraceInit("Core");
	
	// NOTE: Max update rate is 30Hz for now
	SetUpdateFreq(30.0f);
	
	//mpEnv->ProvideConfig(*mpConfig.get());
	
	mpEnv->ProvideMemory(*mpMemory.get());
	
	mpEventDispatcher = std::make_unique<CEventDispatcher>(*mpEnv.get());
	
	mpEnv->ProvideEventDispatcher(*mpEventDispatcher.get());
	
	//mpEventDispatcher->AddListener(*new CEchoEventListener(*mpEnv.get()));
	
	mpEventDispatcher->AddListener(*new CMouseEventListener(*mpEnv.get()));
	
	mpCmdProcessor = std::make_unique<CCmdProcessor>(*mpEnv.get());
	
	mpCmdProcessor->Init(*mpEnv.get(), this);
	
	mpModuleContainer = std::make_unique<CModuleContainer>(*mpEnv.get());
	
	if(!mpModuleContainer->Init())
		return false;
	
	mpEnv->ProvideModuleContainer(*mpModuleContainer.get());
	
	mpPluginManager = std::make_unique<CPluginManager>(*mpEnv.get());
	
	mpEnv->ProvidePluginManager(*mpPluginManager.get());
	
	// TODO: check that we should use plugins (read the config setting)
	// and if should then init plugin manager here
	if(!mpPluginManager->Init())
		return false;
	
	mpStatsPrinter = std::make_unique<CStatsPrinter>();
	
	mpPluginManager->LoadPlugin("TestPlugin");
	
	//mpLog->Debug("Config: [General] SubSystems: %s", mpConfig->GetString("General:SubSystems"));
	
	mpLog->Info("Update freq is %f / TimeStep is %.16f", GetUpdateFreq(), GetTimeStep());
	
	mbInitialized = true;
	return true;
};

void CCore::Shutdown()
{
	if(!mbInitialized)
		return;
	
	mpPluginManager->Shutdown();
	mpModuleContainer->Shutdown();
	
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
	
	//mpModuleContainer->Update();
	
	// NOTE: when the "exit" command received this loop will still be processing updates
	// So we check for a pending quit flag here to prevent that
	while(fLag >= GetTimeStep() && !mbWantQuit)
	{
		mpLog->Debug("Lag: %fs / FrameTime: %fs (%fms)", fLag, FrameTime.count(), FrameTimeMs.count());

		mpCmdProcessor->ExecBuffer();

		mpEventDispatcher->DispatchEvents(); //Update();

		mpModuleContainer->Update(); // FixedUpdate();
		
		fLag -= GetTimeStep();
	};
	
	//mpModuleContainer->PostUpdate();
	
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