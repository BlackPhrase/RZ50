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

#include <deque>
#include <list>
#include "core/CoreTypes.hpp"

namespace rz
{

class CCmdExecutor;

using tCmdTextQue = std::deque<string>;

class CCmdBuffer final
{
public:
	CCmdBuffer(CCmdExecutor *apExecutor);
	~CCmdBuffer();
	
	void InsertText(const char *asCmd);
	void AppendText(const char *asCmd);
	
	void Exec();
private:
	tCmdTextQue mCmdQue; //mTextQue
	
	CCmdExecutor *mpExecutor{nullptr};
};

}; // namespace rz