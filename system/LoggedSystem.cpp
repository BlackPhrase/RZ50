#include "LoggedSystem.hpp"

bool CLoggedSystem::Init()
{
	return mpImpl->Init();
};

void CLoggedSystem::Shutdown()
{
	mpImpl->Shutdown();
};

void CLoggedSystem::Update()
{
	mpImpl->Update();
};