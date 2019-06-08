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

#include "RenderDeviceGL.hpp"
#include "render/device/IGPUProgram.hpp"

namespace rz::render::device
{

bool CRenderDeviceGL::Init(tWinHandle aWinHandle, int anPosX, int anPosY, int anWidth, int anHeight)
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

IRenderContext *CRenderDeviceGL::CreateContext()
{
	return new CRenderContextGL();
};

void CRenderDeviceGL::DestroyContext(IRenderContext &aContext)
{
	auto pContext{std::addressof(aContext)};
	delete pContext;
	pContext = nullptr;
};

bool CRenderDeviceGL::MakeContextCurrent(IRenderContext *apContext)
{
	mpActiveContext = apContext;
	
#ifdef _WIN32
	wglMakeCurrent(hdc, hglrc);
#else
	//return glXMakeContextCurrent(mpDisplay, GLXDrawable draw, GLXDrawable read, mhGLRC))
	return glXMakeCurrent(mpDisplay, mXWindow, apContext ? dynamic_cast<CRenderContextGL*>(apContext)->mhGLRC : nullptr);
#endif
};

IRenderContext *CRenderDeviceGL::GetCurrentContext() const
{
	return mpActiveContext;
};

}; // namespace rz::render::device