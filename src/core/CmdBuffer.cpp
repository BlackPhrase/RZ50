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

#include "CmdBuffer.hpp"
#include "CmdExecutor.hpp"

namespace rz
{

CCmdBuffer::CCmdBuffer(CCmdExecutor *apExecutor) : mpExecutor(apExecutor){}
CCmdBuffer::~CCmdBuffer() = default;

void CCmdBuffer::InsertText(const char *asCmd)
{
	// TODO: lock or atomic
	
	mCmdQue.emplace_front(asCmd);
};

void CCmdBuffer::AppendText(const char *asCmd)
{
	// TODO: lock or atomic
	
	mCmdQue.emplace_back(asCmd);
};

void CCmdBuffer::Exec()
{
	// TODO: lock or atomic?
	
	while(!mCmdQue.empty())
	{
		//mpExecutor->ExecText(mCmdQue.front().c_str());
		mCmdQue.pop_front();
	};
};

}; // namespace rz