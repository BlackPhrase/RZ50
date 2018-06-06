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

namespace rz
{

using pfnCmdCallback = void (*)();

struct ICmdProcessor
{
	///
	virtual void AddCommand(const char *asName, pfnCmdCallback afnCallback, const char *asDesc = "") = 0;
	
	/// BufferText insert modes
	enum class InsertMode : int
	{
		Insert = 0, // TODO: front/head
		Append // TODO: back/tail
	};
	
	/// Insert the command text at the beginning of the buffer
	//virtual void InsertText(const char *asCmd) = 0;
	
	/// Append to the command text to the end of the buffer
	//virtual void AppendText(const char *asCmd) = 0;
	
	///
	virtual void BufferText(const char *asCmd, InsertMode aeMode) = 0;
	
	/// Execute the specified text immediately
	virtual void ExecText(const char *asText) = 0;
	
	/// Execute the command buffer immediately
	virtual void ExecBuffer() = 0;
};

}; // namespace rz