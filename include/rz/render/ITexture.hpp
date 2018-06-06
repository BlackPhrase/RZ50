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

struct ITexture
{
	///
	//virtual void Release() = 0;
	
	///
	virtual void Bind() = 0;
	
	///
	virtual void Unbind() = 0;
	
	///
	virtual unsigned int GetID() const = 0;
	
	///
	virtual int GetWidth() const = 0;
	
	///
	virtual int GetHeight() const = 0;
	
	///
	virtual int GetBPP() const = 0;
};

}; // namespace rz