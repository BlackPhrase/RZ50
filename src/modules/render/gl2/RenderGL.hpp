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

#include <GL/gl.h>

#ifdef _WIN32
#else
	// TODO
	#include <GL/glx.h>
#endif

#include "render/IRender.hpp"

namespace rz
{

class CRenderGL final : public IRender
{
public:
	CRenderGL() = default;
	~CRenderGL() = default;
	
	bool Init(tWinHandle aWinHandle, int anPosX, int anPosY, int anWidth, int anHeight) override; // TODO: pass IWindow interface and get all these params from it!
	void Shutdown() override;
	
	void FrameBegin() override;
	void FrameEnd() override;
	
	void SetClearColor(const TColor4 &aColor) override;
	
	void ClearScreen() override;
	
	//void SwapBuffers() override;
	
	ITexture *CreateTexture(int anWidth, int anHeight, int anBPP) override;
	void DestroyTexture(ITexture *apTexture) override;
private:
	bool CreateContext();
	void FreeContext();
	
	tWinHandle mWinHandle;
	
#ifdef _WIN32
	HDC mhDeviceContext{0};
	HGLRC mhGLRC{0};
#else
	Display *mpDisplay{nullptr};
	GLXContext mhGLRC;
#endif
};

}; // namespace rz