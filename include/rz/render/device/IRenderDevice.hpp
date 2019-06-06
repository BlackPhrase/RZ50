/* 
 * This file is part of RZ Engine
 * Copyright (c) 2019 BlackPhrase
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

namespace rz::render::device
{

struct IRenderContext;

struct IRenderDevice
{
	// CONTEXT
	
	///
	virtual IRenderContext *CreateContext() = 0;
	
	/// Destroys the specified context instance if it's not set as current
	virtual void DestroyContext(IRenderContext &aContext) = 0;
	
	///
	virtual void MakeContextCurrent(IRenderContext *apContext) = 0;
	
	///
	virtual IRenderContext *GetCurrentContext() const = 0;
};

}; // namespace rz::render::device