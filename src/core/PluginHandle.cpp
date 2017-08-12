#include "PluginHandle.hpp"
#include "PluginManager.hpp"
#include "core/IPlugin.hpp"

namespace rz
{

bool CPluginHandle::Init(const TCoreEnv &aCoreEnv)
{
	if(mpPlugin)
		return mpPlugin->Init(aCoreEnv);
	
	return false;
};

void CPluginHandle::Shutdown()
{
	if(mpPlugin)
		mpPlugin->Shutdown();
};

}; // namespace rz