/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2019 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <list>
#include "core/ICmdProcessor.hpp"

namespace rz::core
{

struct CCmd
{
	CCmd(const char *asName, pfnCmdCallback afnCallback, const char *asDesc)
		: sName(asName), sDesc(asDesc), fnCallback(afnCallback){}

	const char *sName{""};
	const char *sDesc{""};

	pfnCmdCallback fnCallback{nullptr};
};

using tCmdList = std::list<CCmd*>;

class CCmdContainer final
{
public:
	CCmdContainer() = default;
	~CCmdContainer() = default;

	bool Add(const char *asName, pfnCmdCallback afnCallback, const char *asDesc = "");
	bool Remove(const char *asName);

	CCmd *Find(const char *asName) const;

	bool IsPresent(const char *asName) const;
private:
	tCmdList mlstCmds;
};

}; // namespace rz::core