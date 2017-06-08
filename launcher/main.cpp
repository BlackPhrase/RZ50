#include "core/CoreTypes.hpp"
#include "core/ICore.hpp"

#ifndef RZ_CORE_STATIC
	#include "shiftutil/SharedLib.hpp"
	
	shiftutil::CSharedLib gEngineLib;
#else
	#include "Core.hpp"
#endif

#include "sound/Sound.hpp"
#include "system/System.hpp"

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
	
	if(!gEngineLib.Open("RZCore"))
		return nullptr;
	
	fnGetCore = gEngineLib.GetExportFunc<rz::pfnGetCore>("GetCore");
	
	if(!fnGetCore)
		return nullptr;
	
	return fnGetCore();
#else
	return new rz::CCore();
#endif
};

bool UnloadEngineCore(rz::ICore *apCore)
{
#ifndef RZ_CORE_STATIC
	// TODO: unload the core module
	// NOTE: Currently handled by shiftutil::CSharedLib which will 
	// free the lib at destruction
#else
	if(apCore)
		delete apCore;
#endif
	
	apCore = nullptr;
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
	
	// TODO: fix this crap below
	
	// Engine subsystems should be registered from the config file
	// (EngineConfig.ini->[SubSystems] section or something)
	// Different config file names can be used for various configurations
	// (Example: dedicated server/headless mode)
	
	//rz::ISubSystem *pSystem = new rz::CSystem();
	//rz::ISubSystem *pSound = new rz::CSound();
	
	//pCore->RegisterSubSystem(*pSystem);
	//pCore->RegisterSubSystem(*pSound);
	
	rz::TCoreInitParams InitParams{};
	
	strcpy(InitParams.sConfigName, "Default");
	
	// Init the core and all registered subsystems
	if(!pCore->Init(InitParams))
	{
		printf("Failed to init the core module!\n");
		return EXIT_FAILURE;
	};
	
	while(!pCore->IsCloseRequested()) //WantQuit())
		pCore->Frame(); // update the core and each registered subsystem
	
	pCore->Shutdown(); // shutdown all
	
	UnloadEngineCore(pCore);
	
	return EXIT_SUCCESS;
};