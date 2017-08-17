#pragma once

#include <list>

namespace rz
{

class CConVar;
using tConVarList = std::list<CConVar*>;

class CConVarContainer final
{
public:
	CConVarContainer() = default;
	~CConVarContainer() = default;

	bool Add(const char *asName, const char *asValue, const char *asDesc = "");
	bool Remove(const char *asName);
	
	CConVar *Find(const char *asName) const;
	
	bool IsPresent(const char *asName) const;
private:
	tConVarList mlstVars;
};

}; // namespace rz