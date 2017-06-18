#include <conio.h>
#include "core/CoreTypes.hpp"
#include "core/ICore.hpp"
#include "input/IInput.hpp"
#include "fs/IFileSystem.hpp"
#include "graphics/IGraphics.hpp"
#include "network/INetwork.hpp"
#include "sound/ISound.hpp"
#include "physics/IPhysics.hpp"

#include "shiftutil/SharedLib.hpp"

#ifndef RZ_CORE_STATIC
	shiftutil::CSharedLib gCoreLib;
#endif

#ifndef RZ_INPUT_STATIC
	shiftutil::CSharedLib gInputLib;
#endif

#ifndef RZ_FS_STATIC
	shiftutil::CSharedLib gFSLib;
#endif

#ifndef RZ_GRAPHICS_STATIC
	shiftutil::CSharedLib gGraphicsLib;
#endif

#ifndef RZ_NETWORK_STATIC
	shiftutil::CSharedLib gNetworkLib;
#endif

#ifndef RZ_SOUND_STATIC
	shiftutil::CSharedLib gSoundLib;
#endif

#ifndef RZ_PHYSICS_STATIC
	shiftutil::CSharedLib gPhysicsLib;
#endif

// Indicates to hybrid graphics systems to prefer the discrete part by default
// Has to be .exe module to be correctly detected
extern "C"
{

// http://developer.download.nvidia.com/devzone/devcenter/gamegraphics/files/OptimusRenderingPolicies.pdf
// The following line is to favor the high performance NVIDIA GPU if there are multiple GPUs
// enable NVIDIA High Performance Graphics while using Integrated Graphics
EXPORT unsigned long NvOptimusEnablement = 0x00000001;

// enable AMD discrete card if both discrete and integrated are present
EXPORT int AmdPowerXpressRequestHighPerformance = 1;

};

// TODO: EngineCoreHelper class?

rz::ICore *LoadEngineCore()
{
#ifndef RZ_CORE_STATIC
	rz::pfnGetCore fnGetCore{nullptr};
	
	if(!gCoreLib.Open("RZCore"))
		return nullptr;
	
	fnGetCore = gCoreLib.GetExportFunc<rz::pfnGetCore>("GetCore");
	
	if(!fnGetCore)
		return nullptr;
#else
	extern rz::ICore *fnGetCore();
#endif

	return fnGetCore();
};

bool UnloadEngineCore(rz::ICore *apCore)
{
#ifndef RZ_CORE_STATIC
	// TODO: unload the core module
	// NOTE: Currently handled by shiftutil::CSharedLib which will 
	// free the lib at destruction
#endif
	
	apCore = nullptr;
	return true;
};

rz::ISubSystem *LoadInputModule(const rz::TCoreEnv &aCoreEnv)
{
#ifndef RZ_INPUT_STATIC
	rz::pfnGetInput fnGetInput{nullptr};
	
	if(!gInputLib.Open("RZInput"))
		return nullptr;
	
	fnGetInput = gInputLib.GetExportFunc<rz::pfnGetInput>("GetInput");
	
	if(!fnGetInput)
		return nullptr;
#else
	extern rz::ISubSystem *fnGetInput(const rz::TCoreEnv &aCoreEnv);
#endif

	return fnGetInput(aCoreEnv);
};

rz::ISubSystem *LoadFSModule(const rz::TCoreEnv &aCoreEnv)
{
#ifndef RZ_FS_STATIC
	rz::pfnGetFS fnGetFS{nullptr};
	
	if(!gFSLib.Open("RZFileSystem"))
		return nullptr;
	
	fnGetFS = gFSLib.GetExportFunc<rz::pfnGetFS>("GetFS");
	
	if(!fnGetFS)
		return nullptr;
#else
	extern rz::ISubSystem *fnGetFS(const rz::TCoreEnv &aCoreEnv);
#endif

	return fnGetFS(aCoreEnv);
};

rz::ISubSystem *LoadGraphicsModule(const rz::TCoreEnv &aCoreEnv)
{
#ifndef RZ_GRAPHICS_STATIC
	rz::pfnGetGraphics fnGetGraphics{nullptr};
	
	if(!gGraphicsLib.Open("RZGraphics"))
		return nullptr;
	
	fnGetGraphics = gGraphicsLib.GetExportFunc<rz::pfnGetGraphics>("GetGraphics");
	
	if(!fnGetGraphics)
		return nullptr;
#else
	extern rz::ISubSystem *fnGetGraphics(const rz::TCoreEnv &aCoreEnv);
#endif

	return fnGetGraphics(aCoreEnv);
};

rz::ISubSystem *LoadNetworkModule(const rz::TCoreEnv &aCoreEnv)
{
#ifndef RZ_NETWORK_STATIC
	rz::pfnGetNetwork fnGetNetwork{nullptr};
	
	if(!gNetworkLib.Open("RZNetwork"))
		return nullptr;
	
	fnGetNetwork = gNetworkLib.GetExportFunc<rz::pfnGetNetwork>("GetNetwork");
	
	if(!fnGetNetwork)
		return nullptr;
#else
	extern rz::ISubSystem *fnGetNetwork(const rz::TCoreEnv &aCoreEnv);
#endif

	return fnGetNetwork(aCoreEnv);
};

rz::ISubSystem *LoadSoundModule(const rz::TCoreEnv &aCoreEnv)
{
#ifndef RZ_SOUND_STATIC
	rz::pfnGetSound fnGetSound{nullptr};
	
	if(!gSoundLib.Open("RZSound"))
		return nullptr;
	
	fnGetSound = gSoundLib.GetExportFunc<rz::pfnGetSound>("GetSound");
	
	if(!fnGetSound)
		return nullptr;
#else
	extern rz::ISubSystem *fnGetSound(const rz::TCoreEnv &aCoreEnv);
#endif

	return fnGetSound(aCoreEnv);
};

rz::ISubSystem *LoadPhysicsModule(const rz::TCoreEnv &aCoreEnv)
{
#ifndef RZ_PHYSICS_STATIC
	rz::pfnGetPhysics fnGetPhysics{nullptr};
	
	if(!gPhysicsLib.Open("RZPhysics"))
		return nullptr;
	
	fnGetPhysics = gPhysicsLib.GetExportFunc<rz::pfnGetPhysics>("GetPhysics");
	
	if(!fnGetPhysics)
		return nullptr;
#else
	extern rz::ISubSystem *fnGetPhysics(const rz::TCoreEnv &aCoreEnv);
#endif

	return fnGetPhysics(aCoreEnv);
};

bool ProcessEvents()
{
#ifdef _WIN32
	static MSG Msg{};
	
	if(PeekMessage(&Msg, nullptr, 0, 0, PM_REMOVE))
	{
		if(Msg.message == WM_QUIT)
			return false;
		
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	};
#else
	// TODO
#endif
	
	return true;
};

static void atexit_handler()
{
	printf("Press any key to continue...\n");
	getch();
};

int main(int argc, char **argv)
{
	if(atexit(atexit_handler) != 0)
		return EXIT_FAILURE;
	
	rz::ICore *pCore = LoadEngineCore();
	
	// TODO: error handling (open an error message box?)
	
	if(!pCore)
	{
		printf("pCore is invalid! (%p)\n", pCore);
		return EXIT_FAILURE;
	};
	
	rz::TCoreInitParams InitParams{};
	
	strcpy(InitParams.sConfigName, "Default");
	
	// Init the core and all registered subsystems
	if(!pCore->Init(InitParams))
	{
		printf("Failed to init the core module!\n");
		return EXIT_FAILURE;
	};
	
	// TODO: fix this crap below
	
	const rz::TCoreEnv &CoreEnv = pCore->GetEnv();
	
	rz::ISubSystem *pInput = LoadInputModule(CoreEnv);
	rz::ISubSystem *pFS = LoadFSModule(CoreEnv);
	rz::ISubSystem *pGraphics = LoadGraphicsModule(CoreEnv);
	rz::ISubSystem *pNetwork = LoadNetworkModule(CoreEnv);
	rz::ISubSystem *pSound = LoadSoundModule(CoreEnv);
	rz::ISubSystem *pPhysics = LoadPhysicsModule(CoreEnv);
	
	// Engine subsystems should be registered from the config file
	// (EngineConfig.ini->[SubSystems] section or something)
	// Different config file names can be used for various configurations
	// (Example: dedicated server/headless mode)
	
	pCore->RegisterSubSystem(*pInput);
	pCore->RegisterSubSystem(*pFS);
	pCore->RegisterSubSystem(*pGraphics);
	pCore->RegisterSubSystem(*pNetwork);
	pCore->RegisterSubSystem(*pSound);
	pCore->RegisterSubSystem(*pPhysics);
	
	while(!pCore->IsCloseRequested()) //WantQuit())
	{
		//if(!ProcessEvents())
			//break;
		//else
			pCore->Frame(); // update the core and each registered subsystem
	};
	
	pCore->Shutdown(); // shutdown all
	
	UnloadEngineCore(pCore);
	
	return EXIT_SUCCESS;
};