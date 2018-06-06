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

#include "core/CoreTypes.hpp"

namespace rz
{

struct ITexture;

struct TColor4
{
	byte r;
	byte g;
	byte b;
	byte a;
};

struct IRender
{
	///
	virtual bool Init(tWinHandle aWinHandle, int anPosX, int anPosY, int anWidth, int anHeight) = 0;
	
	///
	virtual void Shutdown() = 0;
	
	///
	virtual void FrameBegin() = 0;
	
	///
	virtual void FrameEnd() = 0;
	
	///
	virtual void SetClearColor(const TColor4 &aColor) = 0;
	
	///
	virtual void ClearScreen() = 0;
	
	///
	//virtual void SwapBuffers() = 0;
	
	/// TEXTURES
	
	///
	virtual ITexture *CreateTexture(int anWidth, int anHeight, int anBPP) = 0;
	
	///
	virtual void DestroyTexture(ITexture *apTexture) = 0;
};

}; // namespace rz