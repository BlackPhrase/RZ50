#include "Game.hpp"

bool CGame::Init(const TCoreEnv &aCoreEnv)
{
	mpCoreEnv = &aCoreEnv;
	
	mpCoreEnv->pLog->TraceInit("Game");
	return true;
};

void CGame::Shutdown()
{
	mpCoreEnv->pLog->TraceShutdown("Game");
};

void CGame::Update()
{
	//mpCoreEnv->pUpdateLog->TraceUpdate("Game");
};