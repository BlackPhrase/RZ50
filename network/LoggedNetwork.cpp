#include "LoggedNetwork.hpp"

namespace rz
{

bool CLoggedNetwork::Init(const TCoreEnvironment &aCoreEnv)
{
	aCoreEnv.pLog->Write("Initializing the network module...");
	return mpImpl->Init(aCoreEnv);
};

void CLoggedNetwork::Shutdown()
{
	aCoreEnv.pLog->Write("Shutting down the network module...");
	mpImpl->Shutdown();
};

void CLoggedNetwork::Update()
{
	aCoreEnv.pLog->Write("Updating the network module...");
	mpImpl->Update();
};

}; // namespace rz