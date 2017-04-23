#include "Launcher.hpp"

ICore *CLauncher::Init()
{
	return nullptr;
};

void CLauncher::Run(ICore *apCore)
{
	while(!apCore->IsCloseRequested())
		apCore->Frame();
	
	apCore->Shutdown();
};