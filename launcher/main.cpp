int main(int argc, char **argv)
{
	// TODO: load the engine core module
	// Init it
	// Register subsystems and init them
	// Run it
	// Shutdown
	
	ICore *pCore = new CCore();
	
	ISubSystem *pSystem = new CSystem();
	ISubSystem *pSound = new CSound();
	
	pCore->AddSubSystem(pSystem);
	pCore->AddSubSystem(pSound);
	
	pCore->Init(); // init the core and all registered subsystems
	
	while(!pCore->WantQuit())
		pCore->Frame(); // update the core and each registered subsystem
	
	pCore->Shutdown(); // shutdown all
	
	if(pCore)
		delete pCore;
	pCore = nullptr;
	
	return EXIT_SUCCESS;
};