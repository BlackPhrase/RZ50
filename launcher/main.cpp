#include "core/CoreTypes.hpp"
#include "core/ICore.hpp"
#include "input/IInput.hpp"
#include "fs/IFileSystem.hpp"

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

rz::ISubSystem *LoadInputModule()
{
#ifndef RZ_INPUT_STATIC
	rz::pfnGetInput fnGetInput{nullptr};
	
	if(!gInputLib.Open("RZInput"))
		return nullptr;
	
	fnGetInput = gInputLib.GetExportFunc<rz::pfnGetInput>("GetInput");
	
	if(!fnGetInput)
		return nullptr;
#else
	extern rz::ISubSystem *fnGetInput();
#endif

	return fnGetInput();
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

int main(int argc, char **argv)
{
	rz::ICore *pCore = LoadEngineCore();
	
	// TODO: error handling (open an error message box?)
	
	if(!pCore)
	{
		printf("pCore is invalid! (%p)\n", pCore);
		return EXIT_FAILURE;
	};
	
	// TODO: fix this crap below
	
	// Engine subsystems should be registered from the config file
	// (EngineConfig.ini->[SubSystems] section or something)
	// Different config file names can be used for various configurations
	// (Example: dedicated server/headless mode)
	
	rz::TCoreInitParams InitParams{};
	
	strcpy(InitParams.sConfigName, "Default");
	
	// Init the core and all registered subsystems
	if(!pCore->Init(InitParams))
	{
		printf("Failed to init the core module!\n");
		return EXIT_FAILURE;
	};
	
	rz::ISubSystem *pInput = LoadInputModule();
	rz::ISubSystem *pFS = LoadFSModule();
	
	pCore->RegisterSubSystem(*pInput);
	pCore->RegisterSubSystem(*pFS);
	
	while(!pCore->IsCloseRequested()) //WantQuit())
		pCore->Frame(); // update the core and each registered subsystem
	
	pCore->Shutdown(); // shutdown all
	
	UnloadEngineCore(pCore);
	
	return EXIT_SUCCESS;
};