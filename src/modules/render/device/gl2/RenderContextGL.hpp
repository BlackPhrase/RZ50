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

#pragma once

#include <GL/gl.h>

#ifdef _WIN32
#else
	#include <GL/glx.h>
#endif

#include "render/device/IRenderContext.hpp"

namespace rz::render::device
{

class CRenderContextGL final : public IRenderContext
{
	friend class CRenderDeviceGL;
public:
	CRenderContextGL() = default;
	~CRenderContextGL() = default;
	
	//void FrameBegin() override;
	//void FrameEnd() override;
	
	//void SetClearColor(const TColor4 &aColor) override;
	
	//void ClearScreen() override;
	
	//void SwapBuffers() override;
	
	IBuffer *CreateBuffer(IBuffer::Type aeType) override;
	void DestroyBuffer(IBuffer &aBufffer) override;
	
	ITexture *CreateTexture(int anWidth, int anHeight, int anBPP) override;
	void DestroyTexture(ITexture &aTexture) override;
	
	void BindTexture(ITexture *apTexture, unsigned int anSlot) override;
	
	IGPUProgram *CreateGPUProgram() override;
	void DestroyGPUProgram(IGPUProgram &aProgram) override;
	
	IShader *CreateShader(IShader::Type aeType, const char *asData) override;
	void DestroyShader(IShader &aShader) override;
	
	void UseGPUProgram(IGPUProgram *apProgram) override;
private:
#ifdef _WIN32
	HDC mhDeviceContext{0};
	HGLRC mhGLRC{0};
#else
	Display *mpDisplay{nullptr};
	GLXContext mhGLRC;
#endif
};

}; // namespace rz::render::device