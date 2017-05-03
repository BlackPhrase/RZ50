ICore *LoadEngineCore()
{
	return new CCore();
};

bool UnloadEngineCore(ICore *apCore)
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
	
	ICore *pCore = LoadEngineCore();
	
	ISubSystem *pSystem = new CSystem();
	ISubSystem *pSound = new CSound();
	
	pCore->AddSubSystem(pSystem);
	pCore->AddSubSystem(pSound);
	
	// Init the core and all registered subsystems
	if(!pCore->Init())
		return EXIT_FAILURE;
	
	while(!pCore->WantQuit())
		pCore->Frame(); // update the core and each registered subsystem
	
	pCore->Shutdown(); // shutdown all
	
	UnloadEngineCore();
	
	return EXIT_SUCCESS;
};