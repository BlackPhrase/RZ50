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

#include "render/device/IRenderDevice.hpp"

namespace rz::render::device
{

class CRenderDeviceGL final : public IRenderDevice
{
public:
#ifdef _WIN32
	CRenderDeviceGL(HDC ahDeviceContext);
#else
	CRenderDeviceGL(Display *apXDisplay, Window aXWindow);
#endif
	
	bool Init(tWinHandle aWinHandle, int anPosX, int anPosY, int anWidth, int anHeight) override; // TODO: pass IWindow interface and get all these params from it!
	
	IRenderContext *CreateContext() override;
	void DestroyContext(IRenderContext &aContext) override;
	
	void MakeContextCurrent(IRenderContext *apContext) override;
	IRenderContext *GetCurrentContext() const override;
private:
	tWinHandle mWinHandle;
	
	IRenderContext *mpActiveContext{nullptr};
};

}; // namespace rz::render::device