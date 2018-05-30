#include <conio.h>
#include "core/CoreTypes.hpp"
#include "EngineWrapper.hpp"

/*
#include "input/IInput.hpp"
#include "fs/IFileSystem.hpp"
#include "graphics/IGraphics.hpp"
#include "network/INetwork.hpp"
#include "sound/ISound.hpp"
#include "physics/IPhysics.hpp"

#ifndef RZ_INPUT_STATIC
	shiftutil::shared_lib gInputLib;
#endif

#ifndef RZ_FS_STATIC
	shiftutil::shared_lib gFSLib;
#endif

#ifndef RZ_GRAPHICS_STATIC
	shiftutil::shared_lib gGraphicsLib;
#endif

#ifndef RZ_NETWORK_STATIC
	shiftutil::shared_lib gNetworkLib;
#endif

#ifndef RZ_SOUND_STATIC
	shiftutil::shared_lib gSoundLib;
#endif

#ifndef RZ_PHYSICS_STATIC
	shiftutil::shared_lib gPhysicsLib;
#endif
*/

// Indicates to hybrid graphics systems to prefer the discrete part by default
// Has to be .exe module to be correctly detected
extern "C"
{

// http://developer.download.nvidia.com/devzone/devcenter/gamegraphics/files/OptimusRenderingPolicies.pdf
// The following line is to favor the high performance NVIDIA GPU if there are multiple GPUs
// Enable NVIDIA High Performance Graphics while using Integrated Graphics
EXPORT unsigned long NvOptimusEnablement = 0x00000001;

// Prefer AMD discrete card if both discrete and integrated are present
EXPORT int AmdPowerXpressRequestHighPerformance = 1;

};

/*
rz::IModule *LoadInputModule(const rz::TCoreEnv &aCoreEnv)
{
#ifndef RZ_INPUT_STATIC
	rz::pfnGetInput fnGetInput{nullptr};
	
	if(!gInputLib.Open("RZInput"))
		return nullptr;
	
	fnGetInput = gInputLib.GetExportFunc<rz::pfnGetInput>("GetInput");
	
	if(!fnGetInput)
		return nullptr;
#else
	extern rz::IModule *fnGetInput(const rz::TCoreEnv &aCoreEnv);
#endif

	return fnGetInput(aCoreEnv);
};

rz::IModule *LoadFSModule(const rz::TCoreEnv &aCoreEnv)
{
#ifndef RZ_FS_STATIC
	rz::pfnGetFS fnGetFS{nullptr};
	
	if(!gFSLib.Open("RZFileSystem"))
		return nullptr;
	
	fnGetFS = gFSLib.GetExportFunc<rz::pfnGetFS>("GetFS");
	
	if(!fnGetFS)
		return nullptr;
#else
	extern rz::IModule *fnGetFS(const rz::TCoreEnv &aCoreEnv);
#endif

	return fnGetFS(aCoreEnv);
};

rz::IModule *LoadGraphicsModule(const rz::TCoreEnv &aCoreEnv)
{
#ifndef RZ_GRAPHICS_STATIC
	rz::pfnGetGraphics fnGetGraphics{nullptr};
	
	if(!gGraphicsLib.Open("RZGraphics"))
		return nullptr;
	
	fnGetGraphics = gGraphicsLib.GetExportFunc<rz::pfnGetGraphics>("GetGraphics");
	
	if(!fnGetGraphics)
		return nullptr;
#else
	extern rz::IModule *fnGetGraphics(const rz::TCoreEnv &aCoreEnv);
#endif

	return fnGetGraphics(aCoreEnv);
};

rz::IModule *LoadNetworkModule(const rz::TCoreEnv &aCoreEnv)
{
#ifndef RZ_NETWORK_STATIC
	rz::pfnGetNetwork fnGetNetwork{nullptr};
	
	if(!gNetworkLib.Open("RZNetwork"))
		return nullptr;
	
	fnGetNetwork = gNetworkLib.GetExportFunc<rz::pfnGetNetwork>("GetNetwork");
	
	if(!fnGetNetwork)
		return nullptr;
#else
	extern rz::IModule *fnGetNetwork(const rz::TCoreEnv &aCoreEnv);
#endif

	return fnGetNetwork(aCoreEnv);
};

rz::IModule *LoadSoundModule(const rz::TCoreEnv &aCoreEnv)
{
#ifndef RZ_SOUND_STATIC
	rz::pfnGetSound fnGetSound{nullptr};
	
	if(!gSoundLib.Open("RZSound"))
		return nullptr;
	
	fnGetSound = gSoundLib.GetExportFunc<rz::pfnGetSound>("GetSound");
	
	if(!fnGetSound)
		return nullptr;
#else
	extern rz::IModule *fnGetSound(const rz::TCoreEnv &aCoreEnv);
#endif

	return fnGetSound(aCoreEnv);
};

rz::IModule *LoadPhysicsModule(const rz::TCoreEnv &aCoreEnv)
{
#ifndef RZ_PHYSICS_STATIC
	rz::pfnGetPhysics fnGetPhysics{nullptr};
	
	if(!gPhysicsLib.Open("RZPhysics"))
		return nullptr;
	
	fnGetPhysics = gPhysicsLib.GetExportFunc<rz::pfnGetPhysics>("GetPhysics");
	
	if(!fnGetPhysics)
		return nullptr;
#else
	extern rz::IModule *fnGetPhysics(const rz::TCoreEnv &aCoreEnv);
#endif

	return fnGetPhysics(aCoreEnv);
};
*/

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

/*
bool Engine_Load();
void Engine_Unload(); // bool?

bool Engine_IsLoaded() const;
*/

bool Engine_Load()
{
#ifndef RZ_CORE_STATIC
	if(!CoreLib.Open("RZCore"))
		return false;
	
	rz::pfnGetCore fnGetCore{CoreLib.GetExportFunc<rz::pfnGetCore>("GetCore")};
	
	if(!fnGetCore)
		return false;
#else
	extern rz::ICore *fnGetCore();
#endif

	pCore = fnGetCore();
	
	if(!pCore)
	{
		printf("pCore is invalid! (%p)\n", pCore);
		return false;
	};
	
	return true;
};

/*
bool Engine_IsLoaded() const
{
	if(pCore)
		return true;
	
	return false;
};
*/

void Engine_Unload(rz::ICore &aEngine)
{
	if(!Engine_IsLoaded())
		return;
	
	//aEngine.Shutdown();
	
#ifndef RZ_CORE_STATIC
	// TODO: unload the core module
	// NOTE: Currently handled by shiftutil::shared_lib which will 
	// free the lib at destruction
#endif
	
	pCore = nullptr;
	
	//CoreLib.Free();
	
	//return true;
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
	
#ifndef RZ_CORE_STATIC
	shiftutil::shared_lib CoreLib;
#endif

	CEngineWrapper Engine;
	
	if(!Engine_Load())
		return EXIT_FAILURE;
	
	// TODO: error handling (open an error message box?)
	
	rz::ICore::TInitParams InitParams{};
	
	InitParams.sConfigName = "Default";
	
	// Init the core and all registered subsystems
	if(!Engine.Init(InitParams))
	{
		printf("Failed to init the core module!\n");
		return EXIT_FAILURE;
	};
	
	// TODO: fix this crap below
	
	const rz::IServiceLocator *CoreEnv = Engine.GetEnv();
	
	/*
	rz::IModule *pInput = LoadInputModule(*CoreEnv);
	rz::IModule *pFS = LoadFSModule(*CoreEnv);
	rz::IModule *pGraphics = LoadGraphicsModule(*CoreEnv);
	rz::IModule *pNetwork = LoadNetworkModule(*CoreEnv);
	rz::IModule *pSound = LoadSoundModule(*CoreEnv);
	rz::IModule *pPhysics = LoadPhysicsModule(*CoreEnv);
	*/
	
	// Engine subsystems should be registered from the config file
	// (EngineConfig.ini->[SubSystems] section or something)
	// Different config file names can be used for various configurations
	// (Example: dedicated server/headless mode)
	
	/*
	Engine.RegisterSubSystem(*pInput);
	Engine.RegisterSubSystem(*pFS);
	Engine.RegisterSubSystem(*pGraphics);
	Engine.RegisterSubSystem(*pNetwork);
	Engine.RegisterSubSystem(*pSound);
	Engine.RegisterSubSystem(*pPhysics);
	*/
	
	Engine.Run();
	
	Engine.Shutdown(); // shutdown all
	
	Engine.Unload();
	
	return EXIT_SUCCESS;
};