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