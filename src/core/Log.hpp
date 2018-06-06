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

#include "core/ILog.hpp"

namespace rz
{

class CLogFile;

class CLog final : public ILog
{
public:
	CLog();
	~CLog(); //= default;
	
	void Shutdown();
	
	void Write(const char *asMsg) override;
	
	void Info(const char *asMsg, ...) override;
	void Debug(const char *asMsg, ...) override;
	void Warning(const char *asMsg, ...) override;
	void Error(const char *asMsg, ...) override;
	void FatalError(const char *asMsg, ...) override;
	
	void TraceInit(const char *asMsg) override;
	void TraceShutdown(const char *asMsg) override;
private:
	//ILogWriter *mpWriter{nullptr}; // to be able to change the output target (file or something else)
	std::unique_ptr<CLogFile> mpFile;
};

}; // namespace rz