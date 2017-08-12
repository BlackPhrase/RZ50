#pragma once

namespace rz
{

struct IConfig;

class CConfigFactory
{
public:
	CConfigFactory() = default;
	~CConfigFactory() = default;
	
	IConfig *LoadFromFile(const char *asName);
};

}; // namespace rz