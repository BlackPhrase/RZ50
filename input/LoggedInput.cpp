#include "LoggedInput.hpp"

bool CLoggedInput::Init(const TCoreEnvironment &aCoreEnv)
{
	aCoreEnv.pLog->Write("Initializing the input module...");
	return mpImpl->Init(aCoreEnv);
};

void CLoggedInput::Shutdown()
{
	aCoreEnv.pLog->Write("Shutting down the input module...");
	mpImpl->Shutdown();
};

void CLoggedInput::Update()
{
	aCoreEnv.pLog->Write("Updating the input module...");
	mpImpl->Update();
};