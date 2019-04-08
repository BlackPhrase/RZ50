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

#include "WindowX11.hpp"

namespace rz::graphics
{

CWindowX11::CWindowX11()
{
	mpDisplay = XOpenDisplay(nullptr);
	
	if(!mpDisplay)
		exit(EXIT_FAILURE);
	
	Window mRootWindow{DefaultRootWindow(mpDisplay)};
	
	XVisualInfo *mpVisualInfo{nullptr};
	
#ifdef GLX
	GLint GLAttributes[] = {GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None};
	mpVisualInfo = glXChooseVisual(mpDisplay, 0, GLAttributes);
	
	if(!mpVisualInfo)
		exit(EXIT_FAILURE);
#endif // GLX

	Colormap ColorMap{XCreateColormap(mpDisplay, mRootWindow, mpVisualInfo->visual, AllocNone)};
	
	XSetWindowAttributes WindowAttributes{};
	WindowAttributes.colormap = ColorMap;
	WindowAttributes.event_mask = ExposureMask | KeyPressMask;
	
	mWindow = XOpenWindow(mpDisplay, mRootWindow, 0, 0, 1280, 600, 0, mpVisualInfo->depth, InputOutput, mpVisualInfo->visual, CWColormap | CWEventMask, &WindowAttributes);
	
	XMapWindow(mpDisplay, mWindow);
	XStoreName(mpDisplay, mWindow, "Window Title");
	
#ifdef GLX
	mGLContext{glXCreateContext(mpDisplay, mpVisualInfo, nullptr, GL_TRUE)};
	glXMakeCurrent(mpDisplay, mWindow, mGLContext);
#endif // GLX
};

CWindowX11::~CWindowX11()
{
#ifdef GLX
	glXMakeCurrent(mpDisplay, None, nullptr);
	glXDestroyContext(mpDisplay, mGLContext);
#endif

	XDestroyWindow(mpDisplay, mWindow);
	XCloseDisplay(mpDisplay);
};

void CWindowX11::Update()
{
	static XEvent Event{};
	
	XNextEvent(mpDisplay, &Event);
	
	switch(Event.type)
	{
	case Expose:
#ifdef GLX
		glXGetWindowAttributes(mpDisplay, mWindow, &mWinAttributes);
		glViewport(0, 0, mWinAttributes.width, mWinAttributes. height);
		//RenderScene();
		glXSwapBuffers(mpDisplay, mWindow);
#endif
		break;
	case KeyPress;
		break;
	};
};

}; // namespace rz::graphics