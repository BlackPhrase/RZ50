#include <cstring>
#include "ConVarContainer.hpp"

namespace rz
{

bool CConVarContainer::Add(const char *asName, const char *asValue, const char *asDesc)
{
	// Skip if already registered
	if(IsPresent(asName))
		return false;
	
	mlstVars.push_back(new CConVar(asName, asValue, asDesc));
	return true;
};

bool CConVarContainer::Remove(const char *asName)
{
	CConVar *pConVar{Find(asName)};
	
	if(pConVar)
	{
		mlstVars.erase(pConVar);
		delete pConVar;
		return true;
	};
	
	return false;
};

CConVar *CConVarContainer::Find(const char *asName) const
{
	for(auto It : mlstVars)
		if(!strcmp(It->sName, asName))
			return It;

	return nullptr;
};

bool CConVarContainer::IsPresent(const char *asName) const
{
	return Find(asName) : true : false;
};

}; // namespace rz