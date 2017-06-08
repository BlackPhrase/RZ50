#include "PluginImpl.hpp"

bool CPluginImpl::Init(const rz::TCoreEnv &aCoreEnv)
{
	mpCoreEnv = &aCoreEnv;
	
	mpCoreEnv->pLog->TraceInit("TestPlugin");
	return true;
};

void CPluginImpl::Shutdown()
{
	mpCoreEnv->pLog->TraceShutdown("TestPlugin");
};