#include "PluginHandle.hpp"

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