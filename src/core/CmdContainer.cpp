#include <cstring>
#include "CmdContainer.hpp"

namespace rz
{

bool CCmdContainer::Add(const char *asName, pfnCmdCallback afnCallback, const char *asDesc)
{
	// Skip if already registered
	if(IsPresent(asName))
		return false;

	//mlstCmds.emplace_back(asName, afnCallback, asDesc);
	mlstCmds.push_back(new CCmd(asName, afnCallback, asDesc));
	return true;
};

bool CCmdContainer::Remove(const char *asName)
{
	CCmd *pCmd{Find(asName)};
	
	if(pCmd)
	{
		mlstCmds.remove(pCmd);
		delete pCmd;
		return true;
	};

	return false;
};

CCmd *CCmdContainer::Find(const char *asName) const
{
	for(auto It : mlstCmds)
		if(!strcmp(It->sName, asName))
			return It;

	return nullptr;
};

bool CCmdContainer::IsPresent(const char *asName) const
{
	return Find(asName) ? true : false;
};

}; // namespace rz