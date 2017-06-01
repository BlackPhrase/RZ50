#include "PluginImpl.hpp"

bool CPluginImpl::Init(const TCoreEnv &aCoreEnv)
{
	mpCoreEnv{&aCoreEnv};
	
	mpCoreEnv->GetLog()->TraceInit("Test Plugin");
	return true;
};

void CPluginImpl::Shutdown()
{
	mpCoreEnv->GetLog()->TraceShutdown("Test Plugin");
};