#pragma once

namespace shiftutil
{
	class CSharedLib;
};

namespace rz
{

struct TCoreEnv;

class CPluginLoader
{
public:
	CPluginLoader(const TCoreEnv &aCoreEnv);
	~CPluginLoader();
	
	shiftutil::CSharedLib *LoadPlugin(const char *asName);
private:
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz