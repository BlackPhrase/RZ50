#include "LoggedSound.hpp"

namespace rz
{

bool CLoggedSound::Init(const TCoreEnvironment &aCoreEnv)
{
	aCoreEnv.pLog->Write("Initializing the sound module...");
	return mpImpl->Init(aCoreEnv);
};

void CLoggedSound::Shutdown()
{
	aCoreEnv.pLog->Write("Shutting down the sound module...");
	mpImpl->Shutdown();
};

void CLoggedSound::Update()
{
	aCoreEnv.pLog->Write("Updating the sound module...");
	mpImpl->Update();
};

}; // namespace rz