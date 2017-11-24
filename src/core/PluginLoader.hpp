#pragma once

namespace shiftutil
{
	class CSharedLib;
};

namespace rz
{

struct IServiceLocator;

class CPluginLoader
{
public:
	CPluginLoader(const IServiceLocator &aCoreEnv);
	~CPluginLoader();
	
	shiftutil::CSharedLib *LoadPlugin(const char *asName);
private:
	const IServiceLocator &mCoreEnv;
};

}; // namespace rz