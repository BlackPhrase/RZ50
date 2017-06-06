#include <cstdlib>

#include "core/ICore.hpp"

#include "Core.hpp"
#include "sound/Sound.hpp"
#include "system/System.hpp"

rz::ICore *LoadEngineCore()
{
	return new rz::CCore();
};

bool UnloadEngineCore(rz::ICore *apCore)
{
	if(apCore)
		delete apCore;
	apCore = nullptr;
	return true;
};

int main(int argc, char **argv)
{
	// TODO: load the engine core module
	// Init it
	// Register subsystems and init them
	// Run it
	// Shutdown
	
	rz::ICore *pCore = LoadEngineCore();
	
	rz::ISubSystem *pSystem = new rz::CSystem();
	rz::ISubSystem *pSound = new rz::CSound();
	
	pCore->RegisterSubSystem(*pSystem);
	pCore->RegisterSubSystem(*pSound);
	
	rz::TCoreInitParams InitParams{};
	
	// Init the core and all registered subsystems
	if(!pCore->Init(InitParams))
		return EXIT_FAILURE;
	
	//while(!pCore->WantQuit())
		pCore->Frame(); // update the core and each registered subsystem
	
	pCore->Shutdown(); // shutdown all
	
	UnloadEngineCore(pCore);
	
	return EXIT_SUCCESS;
};