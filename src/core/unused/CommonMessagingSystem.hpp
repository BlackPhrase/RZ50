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

class CUnknown
{
public:
	CUnknown() = default;
	~CUnknown() = default;
	
	void Info(const char *asMsg, ...);
	void Debug(const char *asMsg, ...);
	void Warning(const char *asMsg, ...);
	void Error(const char *asMsg, ...);
	void Fatal(const char *asMsg, ...);
private:
};

}; // namespace rz