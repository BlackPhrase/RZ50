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

struct IConfig // IConfigReader
{
	virtual const char *GetString(const char *asKey, const char *asDefValue = "") const = 0;
	virtual int GetInt(const char *asKey, int anDefValue = 0) const = 0;
	virtual float GetFloat(const char *asKey, float afDefValue = 0.0f) const = 0;
	virtual bool GetBool(const char *asKey, bool abDefValue = true) const = 0;
};

}; // namespace rz