#include <stdexcept>
#include "IniConfig.hpp"
#include "iniparser/src/iniparser.h"

namespace rz
{

CIniConfig::CIniConfig(const char *asName)
{
	mpDict = iniparser_load(asName);
	
	if(!mpDict)
		throw std::runtime_error("Unable to load the ini config file!");
};

CIniConfig::~CIniConfig()
{
	iniparser_freedict(mpDict);
};

void CIniConfig::SetString(const char *asKey, const char *asValue)
{
	iniparser_set(mpDict, asKey, asValue);
};

void CIniConfig::SetInt(const char *asKey, int anValue)
{
	iniparser_set(mpDict, asKey, std::to_string(anValue).c_str());
};

void CIniConfig::SetFloat(const char *asKey, float afValue)
{
	iniparser_set(mpDict, asKey, std::to_string(afValue).c_str());
};

void CIniConfig::SetBool(const char *asKey, bool abValue)
{
	iniparser_set(mpDict, asKey, std::to_string(abValue).c_str());
};

const char *CIniConfig::GetString(const char *asKey, const char *asDefault) const
{
	return iniparser_getstring(mpDict, asKey, asDefault);
};

int CIniConfig::GetInt(const char *asKey, int anDefault) const
{
	return iniparser_getint(mpDict, asKey, anDefault);
};

float CIniConfig::GetFloat(const char *asKey, float afDefault) const
{
	return iniparser_getdouble(mpDict, asKey, afDefault);
};

bool CIniConfig::GetBool(const char *asKey, bool abDefault) const
{
	return iniparser_getboolean(mpDict, asKey, abDefault);
};

}; // namespace rz