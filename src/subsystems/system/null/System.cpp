#include "System.hpp"

namespace rz
{

bool CSystem::Init(const TCoreEnv &aCoreEnv)
{
	mpCoreEnv = &aCoreEnv;
	
	mpCoreEnv->pLog->TraceInit("System");
	return true;
};

void CSystem::Shutdown()
{
	mpCoreEnv->pLog->TraceShutdown("System");
};

void CSystem::Update()
{
	//mpCoreEnv->pUpdateLog->TraceUpdate("System");
};

}; // namespace rz