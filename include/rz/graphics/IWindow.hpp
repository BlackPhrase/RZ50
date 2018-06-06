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

/*
struct TWindowData
{
	const char *sTitle{""};
	
	int nPosX{0};
	int nPosY{0};
	
	int nWidth{0};
	int nHeight{0};
	
	tWinHandle hOSHandle{0};
};
*/

struct IWindow
{
	//constexpr auto InvalidHandle{-1};
	
	///
	//virtual void SetTitle(const char *asTitle) = 0;
	
	///
	//virtual const char *GetTitle() const = 0;
	
	///
	//virtual void SetX(int anX) = 0;
	
	/// @return window's current X position
	virtual int GetX() const = 0;
	
	///
	//virtual void SetY(int anY) = 0;
	
	/// @return window's current Y position
	virtual int GetY() const = 0;
	
	///
	//virtual void SetPos(const vec2 &avPos) = 0;
	
	///
	//virtual const vec2 &GetPos() const = 0;
	
	/// @return window's current width
	virtual int GetWidth() const = 0;
	
	/// @return window's current height
	virtual int GetHeight() const = 0;
	
	/// @return platform (OS) specific handle
	virtual tWinHandle GetHandle() const = 0;
};

}; // namespace rz