#include "LoggedPhysics.hpp"

bool CLoggedPhysics::Init()
{
	return mpImpl->Init();
};

void CLoggedPhysics::Shutdown()
{
	mpImpl->Shutdown();
};

void CLoggedPhysics::Update()
{
	mpImpl->Update();
};