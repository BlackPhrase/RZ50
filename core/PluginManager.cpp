#include "PluginManager.hpp"
#include "core/TCoreEnv.hpp"
#include "core/ILog.hpp"

namespace rz
{

bool CPluginManager::Init(const TCoreEnv &aCoreEnv)
{
	mpCoreEnv = &aCoreEnv;
	
	mpCoreEnv->pLog->TraceInit("PluginManager");
	return true;
};

void CPluginManager::Shutdown()
{
	mpCoreEnv->pLog->TraceShutdown("PluginManager");
};

void CPluginManager::RegisterSubSystem(const ISubSystem &aSubSystem)
{
};

void CPluginManager::UnregisterSubSystem(const ISubSystem &aSubSystem)
{
};

void *CPluginManager::GetSubSystem(const char *asName) const
{
	return nullptr;
};

}; // namespace rz