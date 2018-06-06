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

struct IModule;

struct IModuleContainer
{
	///
	//virtual void Register(const IModule &aSubSystem) = 0;
	
	///
	//virtual void Unregister(const IModule &aSubSystem) = 0;
	
	///
	//virtual IModule *GetByName(const char *asName) const = 0;
	
	///
	//template<typename T>
	//inline T *GetSubSystem() const {return GetSubSystem(T);}
};

}; // namespace rz