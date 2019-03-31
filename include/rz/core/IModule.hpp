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

namespace rz
{

struct IServiceLocator;

struct IModule
{
	/// Precondition for module init
	/// @return true if we should continue and init the module
	//virtual bool PreInit() = 0;
	
	/// Module initialization
	virtual bool Init(const IServiceLocator &aCoreEnv) = 0;
	
	/// Called after module was initialized
	//virtual void PostInit() = 0;
	
	/// This method will be called when the module gets shutdown
	virtual void Shutdown() = 0;
	
	/// @return module name
	virtual const char *GetModuleName() const = 0; // GetName?
	
	/// @return true if successfully initialized (purpose?)
	//virtual bool IsInitialized() const = 0;
};

using pfnGetModule = IModule *(*)(/*const IServiceLocator &aCoreEnv*/);

}; // namespace rz