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

struct TProfileResult
{
	double fTime;
};

struct IProfileTimer
{
	//virtual void Start() = 0;
	virtual TProfileResult Stop() const = 0;
	
	virtual const char *GetName() const = 0;
};

struct IProfiler
{
	//virtual IProfileTimer &CreateTimer(const char *asName) = 0;
	virtual IProfileTimer &StartTiming(const char *asName) = 0;
};

}; // namespace rz