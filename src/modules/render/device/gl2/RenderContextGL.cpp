/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2019 BlackPhrase
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

#include <type_traits>

#include "RenderContextGL.hpp"
#include "TextureGL.hpp"

namespace rz::render
{

CRenderContextGL::CRenderContextGL()
{
#ifdef _WIN32
	mhDeviceContext = GetDC(mWinHandle);
	mhGLRC = wglCreateContext(mhDeviceContext);
	
	wglMakeCurrent(mhDeviceContext, mhGLRC);
#else
	//mhGLRC = glXCreateContext(Display *dpy, XVisualInfo *vis, nullptr, True);

	//if(!mhGLRC)
		//throw std::runtime_error("Failed to create GLX rendering context!");
#endif
};

CRenderContextGL::~CRenderContextGL()
{
#ifdef _WIN32
	wglMakeCurrent(nullptr, nullptr);
	wglDeleteContext(mhGLRC);
	ReleaseDC(mWinHandle, mhDeviceContext);
#else
	//glXDestroyContext(mpDisplay, mhGLRC);
#endif
};

void CRenderContextGL::FrameBegin()
{
	glBegin(GL_TRIANGLES); // TODO: SetMode?
};

void CRenderContextGL::FrameEnd()
{
	glEnd();
};

void CRenderContextGL::SetClearColor(const TColor4 &aColor)
{
	glClearColor((GLfloat)aColor.r, (GLfloat)aColor.g, (GLfloat)aColor.b, (GLfloat)aColor.a);
};

void CRenderContextGL::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // | GL_STENCIL_BUFFER_BIT
};

/*
void CRenderContextGL::SwapBuffers()
{
};
*/

IBuffer *CRenderContextGL::CreateBuffer(IBuffer::Type aeType)
{
	return new CDataBuffer();
};

void CRenderContextGL::DestroyBuffer(IBuffer &aBuffer)
{
	delete std::addressof(aBuffer);
	std::addressof(aBuffer) = nullptr;
};

ITexture *CRenderContextGL::CreateTexture(int anWidth, int anHeight, int anBPP)
{
	return new CTextureGL();
};

void CRenderContextGL::DestroyTexture(ITexture &aTexture)
{
	delete std::addressof(aTexture);
	std::addressof(aTexture) = nullptr;
};

void CRenderContextGL::BindTexture(ITexture *apTexture, unsigned int anSlot)
{
	glBindTexture(anSlot, apTexture ? apTexture->GetID() : 0);
};

IGPUProgram *CRenderContextGL::CreateGPUProgram()
{
	return new CGPUProgramGL();
};

void CRenderContextGL::DestroyGPUProgram(IGPUProgram &aProgram)
{
	delete std::addressof(aProgram);
	std::addressof(aProgram) = nullptr;
};

IShader *CRenderContextGL::CreateShader(IShader::Type aeType, const char *asData)
{
	return new CShaderGL();
};

void CRenderContextGL::DestroyShader(IShader &aShader)
{
	delete std::addressof(aShader);
	std::addressof(aShader) = nullptr;
};

void CRenderContextGL::UseGPUProgram(IGPUProgram *apProgram)
{
	glUseProgram(apProgram ? apProgram->GetID() : 0);
};

}; // namespace rz::render