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