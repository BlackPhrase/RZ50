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

#include <windows.h>
#include "TextConsole.hpp"

// TODO:
//	* Input support
//	* Input to command text
//	* Colored output support
//	* Control handler to properly shutdown the engine by closing the console window

namespace rz
{

class CTextConsoleWin final : public CTextConsole
{
public:
	CTextConsoleWin() = default;
	~CTextConsoleWin() = default;
	
	bool Init();
	void Shutdown();
	
	void Printf(const char *asMsg, ...);
	
	void Warning(const char *asMsg, ...);
	void Error(const char *asMsg, ...);
private:
	HANDLE mhScreenBuffer{INVALID_HANDLE_VALUE};
};

}; // namespace rz