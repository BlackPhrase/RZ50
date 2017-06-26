#pragma once

namespace rz
{

class CPluginLoader
{
public:
	CPluginLoader() = default;
	~CPluginLoader() = default;
	
	tSharedLib *LoadPlugin(const char *asName);
private:
};

}; // namespace rz