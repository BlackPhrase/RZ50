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

/// @file

#include "core/IServiceLocator.hpp"
#include "GraphicsModule.hpp"
#include "Graphics.hpp"
#include "render/IRender.hpp"

#ifdef _WIN32
	#include "impl/win/GraphicsWin.hpp"
#else
	#include "impl/unix/GraphicsUnix.hpp"
#endif

namespace rz
{

IRender *LoadRenderModule(const char *name)
{
	IRender *pRender{nullptr};
	
	return pRender;
};

bool CGraphicsModule::Init(const IServiceLocator &aCoreEnv)
{
#ifdef _WIN32
	static rz::CGraphicsWin GraphicsImpl;
#elif
	static rz::CGraphicsUnix GraphicsImpl;
#endif
	
	IRender *pRender = LoadRenderModule("RZRender-GL2");
	static rz::CGraphics Graphics(aCoreEnv, &GraphicsImpl, pRender);
	
	return true;
};

void CGraphicsModule::Shutdown()
{
};

}; // namespace rz