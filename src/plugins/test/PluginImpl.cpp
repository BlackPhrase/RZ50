#include "PluginImpl.hpp"

bool CPluginImpl::Init(const rz::IServiceLocator &aCoreEnv)
{
	mpCoreEnv = &aCoreEnv;
	
	mpCoreEnv->GetLog().TraceInit("TestPlugin");
	return true;
};

void CPluginImpl::Shutdown()
{
	mpCoreEnv->GetLog().TraceShutdown("TestPlugin");
};