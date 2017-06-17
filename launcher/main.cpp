#include "core/CoreTypes.hpp"
#include "core/ICore.hpp"
#include "input/IInput.hpp"
#include "fs/IFileSystem.hpp"
#include "graphics/IGraphics.hpp"

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

rz::ISubSystem *LoadFSModule()
{
#ifndef RZ_FS_STATIC
	rz::pfnGetFS fnGetFS{nullptr};
	
	if(!gFSLib.Open("RZFileSystem"))
		return nullptr;
	
	fnGetFS = gFSLib.GetExportFunc<rz::pfnGetFS>("GetFS");
	
	if(!fnGetFS)
		return nullptr;
#else
	extern rz::ISubSystem *fnGetFS();
#endif

	return fnGetFS();
};

rz::ISubSystem *LoadGraphicsModule()
{
#ifndef RZ_GRAPHICS_STATIC
	rz::pfnGetGraphics fnGetGraphics{nullptr};
	
	if(!gGraphicsLib.Open("RZGraphics"))
		return nullptr;
	
	fnGetGraphics = gGraphicsLib.GetExportFunc<rz::pfnGetGraphics>("GetGraphics");
	
	if(!fnGetGraphics)
		return nullptr;
#else
	extern rz::ISubSystem *fnGetGraphics();
#endif

	return fnGetGraphics();
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

int main(int argc, char **argv)
{
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
	rz::ISubSystem *pFS = LoadFSModule();
	rz::ISubSystem *pGraphics = LoadGraphicsModule();
	
	// Engine subsystems should be registered from the config file
	// (EngineConfig.ini->[SubSystems] section or something)
	// Different config file names can be used for various configurations
	// (Example: dedicated server/headless mode)
	
	pCore->RegisterSubSystem(*pInput);
	pCore->RegisterSubSystem(*pFS);
	pCore->RegisterSubSystem(*pGraphics);
	
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