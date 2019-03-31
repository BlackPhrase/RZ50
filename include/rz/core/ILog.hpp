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

namespace rz::core
{

struct ILog
{
	/// Writes a message into the log
	virtual void Write(const char *asMsg) = 0;
	
	/// Writes a formatted message into the log with "INFO" prepended
	virtual void Info(const char *asMsg, ...) = 0;
	
	/// Writes a formatted message into the log with "DEBUG" prepended
	virtual void Debug(const char *asMsg, ...) = 0;
	
	/// Writes a formatted message into the log with "WARNING" prepended
	virtual void Warning(const char *asMsg, ...) = 0;
	
	/// Writes a formatted message into the log with "ERROR" prepended
	virtual void Error(const char *asMsg, ...) = 0;
	
	/// Writes a formatted message into the log with "FATAL" prepended
	virtual void FatalError(const char *asMsg, ...) = 0;
	
	///
	virtual void TraceInit(const char *asMsg) = 0;
	
	///
	virtual void TraceShutdown(const char *asMsg) = 0;
};

}; // namespace rz::core