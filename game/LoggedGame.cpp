#include "LoggedGame.hpp"

bool CLoggedGame::Init()
{
	return mpImpl->Init();
};

void CLoggedGame::Shutdown()
{
	mpImpl->Shutdown();
};

void CLoggedGame::Update()
{
	mpImpl->Update();
};