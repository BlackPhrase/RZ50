#include "LoggedNetwork.hpp"

bool CLoggedNetwork::Init()
{
	return mpImpl->Init();
};

void CLoggedNetwork::Shutdown()
{
	mpImpl->Shutdown();
};

void CLoggedNetwork::Update()
{
	mpImpl->Update();
};