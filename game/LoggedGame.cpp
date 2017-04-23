#include "LoggedGame.hpp"

bool CLoggedGame::Init(const TCoreEnvironment &aCoreEnv)
{
	aCoreEnv.pLog->Write("Initializing the game module...");
	return mpImpl->Init(aCoreEnv);
};

void CLoggedGame::Shutdown()
{
	aCoreEnv.pLog->Write("Shutting down the game module...");
	mpImpl->Shutdown();
};

void CLoggedGame::Update()
{
	aCoreEnv.pLog->Write("Updating the game module...");
	mpImpl->Update();
};