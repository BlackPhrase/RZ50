#include "LoggedSystem.hpp"

namespace rz
{

bool CLoggedSystem::Init(const TCoreEnvironment &aCoreEnv)
{
	aCoreEnv.pLog->Write("Initializing the system module...");
	return mpImpl->Init(aCoreEnv);
};

void CLoggedSystem::Shutdown()
{
	aCoreEnv.pLog->Write("Shutting down the system module...");
	mpImpl->Shutdown();
};

void CLoggedSystem::Update()
{
	aCoreEnv.pLog->Write("Updating the system module...");
	mpImpl->Update();
};

}; // namespace rz