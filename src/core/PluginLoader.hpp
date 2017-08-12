#pragma once

namespace shiftutil
{
	class CSharedLib;
};

namespace rz
{

class CPluginLoader
{
public:
	CPluginLoader(); //= default;
	~CPluginLoader(); //= default;
	
	shiftutil::CSharedLib *LoadPlugin(const char *asName);
private:
};

}; // namespace rz