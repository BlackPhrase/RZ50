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

#include <X11/X.h>
#include <X11/Xlib.h>

#include "graphics/IWindow.hpp"

namespace rz::graphics
{

// TODO: apply usage of vectors for pos/size
class CWindowX11 : public IWindow
{
public:
	CWindowX11() = default;
	~CWindowX11();
	
	void AddEventListener(EventListener &aListener) override;
	void RemoveEventListener(EventListener &aListener) override;
	
	//tWinHandle GetHandle() const {return mHandle;}
private:
	SWindowProps mProps{};
	
	Window mWindow{};
	XWindowAttributes mWinAttributes{};
	
#ifdef GLX
	GLXContext mGLContext{};
#endif
	
	Display *mpDisplay{nullptr};
	
	tWinHandle mHandle{nullptr};
};

}; // namespace rz::graphics