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

#include "LogFile.hpp"

namespace rz::core
{

CLogFile::CLogFile(const string &asName) : msName(asName + ".log"), mpHandle(std::fopen(msName.c_str(), "w+"))
{
	if(!mpHandle) // probably never happen
	{
		string sError{"Cannot open the file " + msName};
		throw std::runtime_error(sError);
	};
};

void CLogFile::Write(const string &asMsg, ...)
{
	//assert(mpHandle);
	
	char sMsg[256] = {};
	va_list lstArgs;
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg.c_str(), lstArgs);
	va_end(lstArgs);
	
	fputs(sMsg, mpHandle);
	fflush(mpHandle);
};

void CLogFile::Close()
{
	//assert(mpHandle);
	
	fputs("Closing the log file...", mpHandle);
	fflush(mpHandle);
	
	fclose(mpHandle);
};

}; // namespace rz::core