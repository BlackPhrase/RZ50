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

#include "RenderGL.hpp"
#include "TextureGL.hpp"

namespace rz
{

bool CRenderGL::Init(tWinHandle aWinHandle, int anPosX, int anPosY, int anWidth, int anHeight)
{
	mWinHandle = aWinHandle;
	
	glViewport(anPosX, anPosY, anWidth, anHeight);
	
	if(!CreateContext())
		return false;
	
	//SetClearColor(Color::Black, 1.0f);
	
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	
	//glEnable(GL_FRAMEBUFFER_SRGB);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // GL_LINEAR
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); // GL_CLAMP_TO_EDGE
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); // GL_CLAMP_TO_EDGE
	
	return true;
};

void CRenderGL::Shutdown()
{
	FreeContext();
};

void CRenderGL::FrameBegin()
{
	glBegin(GL_TRIANGLES); // TODO: SetMode?
};

void CRenderGL::FrameEnd()
{
	glEnd();
};

void CRenderGL::SetClearColor(const TColor4 &aColor)
{
	glClearColor((GLfloat)aColor.r, (GLfloat)aColor.g, (GLfloat)aColor.b, (GLfloat)aColor.a);
};

void CRenderGL::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // | GL_STENCIL_BUFFER_BIT
};

/*
void CRenderGL::SwapBuffers()
{
};
*/

ITexture *CRenderGL::CreateTexture(int anWidth, int anHeight, int anBPP)
{
	return new CTextureGL();
};

void CRenderGL::DestroyTexture(ITexture *apTexture)
{
	if(apTexture)
	{
		delete apTexture;
		apTexture = nullptr;
	};
};

bool CRenderGL::CreateContext()
{
#ifdef _WIN32
	mhDeviceContext = GetDC(mWinHandle);
	mhGLRC = wglCreateContext(mhDeviceContext);
	
	wglMakeCurrent(mhDeviceContext, mhGLRC);
#else
	//mhGLRC = glXCreateContext(Display *dpy, XVisualInfo *vis, nullptr, True);

	//if(!mhGLRC)
		//return false;
	
	//if(!glXMakeContextCurrent(mpDisplay, GLXDrawable draw, GLXDrawable read, mhGLRC)) // glXMakeCurrent(mpDisplay, GLXDrawable drawable, mhGLRC);
		//return false;
#endif

	return true;
};

void CRenderGL::FreeContext()
{
#ifdef _WIN32
	wglMakeCurrent(nullptr, nullptr);
	wglDeleteContext(mhGLRC);
	ReleaseDC(mWinHandle, mhDeviceContext);
#else
	//glXDestroyContext(mpDisplay, mhGLRC);
#endif
};

}; // namespace rz