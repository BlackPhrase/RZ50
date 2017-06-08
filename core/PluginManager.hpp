#pragma once

#include "core/IPluginManager.hpp"

namespace rz
{

struct TCoreEnv;

class CPluginManager : public IPluginManager
{
public:
	CPluginManager() = default;
	~CPluginManager() = default;
	
	bool Init(const TCoreEnv &aCoreEnv);
	void Shutdown();
	
	void RegisterSubSystem(const ISubSystem &aSubSystem);
	void UnregisterSubSystem(const ISubSystem &aSubSystem);
	
	void *GetSubSystem(const char *asName) const;
private:
	const TCoreEnv *mpCoreEnv{nullptr};
};

}; // namespace rz