#include "LoggedSound.hpp"

bool CLoggedSound::Init()
{
	return mpImpl->Init();
};

void CLoggedSound::Shutdown()
{
	mpImpl->Shutdown();
};

void CLoggedSound::Update()
{
	mpImpl->Update();
};