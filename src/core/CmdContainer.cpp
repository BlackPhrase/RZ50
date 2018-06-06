/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2018 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

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