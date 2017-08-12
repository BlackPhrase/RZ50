#include <memory>
#include "ConfigFactory.hpp"
#include "IniConfig.hpp"

namespace rz
{

IConfig *CConfigFactory::LoadFromFile(const char *asName)
{
	//dictionary *pDict{iniparser_load(asName)};
	
	//if(!pDict)
		//return nullptr;
	
	std::unique_ptr<IConfig> pConfig = std::make_unique<CIniConfig>(asName);
	
	return pConfig.release();
};

}; // namespace rz