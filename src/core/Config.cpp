#include "Config.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

void CConfig::Init(TCoreEnv &aCoreEnv)
{
	aCoreEnv.pConfig = this;
};

void CConfig::SetString(const char *asKey, const char *asValue)
{
	mmapKeys[asKey] = asValue;
};

void CConfig::SetInt(const char *asKey, int anValue)
{
	mmapKeys[asKey] = anValue;
};

void CConfig::SetFloat(const char *asKey, float afValue)
{
	mmapKeys[asKey] = afValue;
};

void CConfig::SetBool(const char *asKey, bool abValue)
{
	mmapKeys[asKey] = abValue;
};

const char *CConfig::GetString(const char *asKey, const char *asDefault) const
{
	auto Key = mmapKeys.find(asKey);
	
	if(Key != mmapKeys.end())
		return Key->second.c_str();
	
	return asDefault;
};

int CConfig::GetInt(const char *asKey, int anDefault) const
{
	auto Key = mmapKeys.find(asKey);
	
	if(Key != mmapKeys.end())
		return atoi(Key->second.c_str());
	
	return anDefault;
};

float CConfig::GetFloat(const char *asKey, float afDefault) const
{
	auto Key = mmapKeys.find(asKey);
	
	if(Key != mmapKeys.end())
		return atof(Key->second.c_str());
	
	return afDefault;
};

bool CConfig::GetBool(const char *asKey, bool abDefault) const
{
	auto Key = mmapKeys.find(asKey);
	
	if(Key != mmapKeys.end())
		return (Key->second == "true") ? true : false; // TODO: fix
	
	return abDefault;
};

}; // namespace rz