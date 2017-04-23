#include "LoggedInput.hpp"

bool CLoggedInput::Init()
{
	//CLog::Get()->Write("Initializing the input module...");
	return mpImpl->Init();
};

void CLoggedInput::Shutdown()
{
	//CLog::Get()->Write("Shutting down the input module...");
	mpImpl->Shutdown();
};

void CLoggedInput::Update()
{
	//CLog::Get()->Write("Updating the input module...");
	mpImpl->Update();
};