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

/// @file
/// @brief engine module wrapper

#pragma once

#include "shiftutil/shared_lib.hpp"
#include "core/ICore.hpp"

namespace rz
{
	struct ICore;
	struct IServiceLocator;
};

//CEngineCoreWrapper
class CEngineWrapper final
{
public:
	CEngineWrapper(rz::ICore *apCore) : mpCore(apCore){}
	~CEngineWrapper(){Shutdown();}
	
	operator bool(){return mpCore != nullptr;}
	
	bool Init(const rz::ICore::TInitParams &aInitParams);
	void Shutdown();
	
	void Run(); // TODO: return bool?
	//void Frame();
	
	const rz::IServiceLocator *GetEnv() const; // TODO: probably unused
private:
	rz::ICore *mpCore{nullptr};
};