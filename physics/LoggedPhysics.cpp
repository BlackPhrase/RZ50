#include "LoggedPhysics.hpp"

bool CLoggedPhysics::Init(const TCoreEnvironment &aCoreEnv)
{
	aCoreEnv.pLog->Write("Initializing the physics module...");
	return mpImpl->Init(aCoreEnv);
};

void CLoggedPhysics::Shutdown()
{
	aCoreEnv.pLog->Write("Shutting down the physics module...");
	mpImpl->Shutdown();
};

void CLoggedPhysics::Update()
{
	aCoreEnv.pLog->Write("Updating the physics module...");
	mpImpl->Update();
};