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

#include <iostream>
#include <memory>
#include "Log.hpp"
#include "LogFile.hpp"

// TODO: optimization
// TODO: remove dups

namespace rz
{

CLog::CLog()
{
	mpFile = std::make_unique<CLogFile>("RZ"); // timestamp?
	
	//TraceInit("Log"); // by the fact that it does output to the log file it's initialized; no need for that...
};

CLog::~CLog() = default;
//{
	//Shutdown();
//};

void CLog::Shutdown()
{
	//TraceShutdown("Log");
};

void CLog::Write(const char *asMsg)
{
	//char sMsg[strlen(asMsg) + 1] = {};
	//sMsg[sizeof(sMsg) - 1] = 0;
	char sMsg[512] = {};
	
	strcpy(sMsg, asMsg);
	strcat(sMsg, "\n");
	
	mpFile->Write(sMsg);
	
	// Output to debug console window too
	std::cout << sMsg << std::endl;
};

void CLog::Info(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	string sFullMsg("[INFO] ");
	sFullMsg.append(sMsg);
	
	Write(sFullMsg.c_str());
};

void CLog::Debug(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	string sFullMsg("[DEBUG] ");
	sFullMsg.append(sMsg);
	
	Write(sFullMsg.c_str());
};

void CLog::Warning(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	string sFullMsg("[WARNING] ");
	sFullMsg.append(sMsg);
	
	Write(sFullMsg.c_str());
};

void CLog::Error(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	string sFullMsg("[ERROR] ");
	sFullMsg.append(sMsg);
	
	Write(sFullMsg.c_str());
};

void CLog::FatalError(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	string sFullMsg("[FATAL] ");
	sFullMsg.append(sMsg);
	
	Write(sFullMsg.c_str());
};

void CLog::TraceInit(const char *asMsg)
{
	char sMsg[256] = {};
	
	sprintf(sMsg, "Initializing the %s...", asMsg);
	Write(sMsg);
};

void CLog::TraceShutdown(const char *asMsg)
{
	char sMsg[256] = {};
	
	sprintf(sMsg, "Shutting down the %s...", asMsg);
	Write(sMsg);
};

}; // namespace rz