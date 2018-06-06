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

#include "Graphics.hpp"
#include "IGraphicsImpl.hpp"
#include "render/IRender.hpp"

namespace rz
{

bool CGraphics::Init(const IServiceLocator &aCoreEnv)
{
	mCoreEnv.GetLog().TraceInit("Graphics");
	mCoreEnv.GetLog().Info("Graphics: Null");
	
	if(!OpenWindow())
	{
		mCoreEnv.GetLog().Error("Failed to open the rendering window!");
		return false;
	};
	
	mCoreEnv.GetEventDispatcher().AddListener(*this);
	
	// TODO: pass a window interface?
	//if(!mpRender->Init(0, 0, 1280, 600))
		//return false;
	
	return mpImpl->Init(aCoreEnv);
};

void CGraphics::Shutdown()
{
	mpRender->Shutdown();
	
	// BUG: this line is causing the window to freeze
	//mCoreEnv.pEventManager->RemoveListener(*this); // event manager will free all its listeners at shutdown
};

void CGraphics::Update()
{
};

void CGraphics::OnEvent(const TEvent &aEvent)
{
	switch(aEvent.eType)
	{
	case TEvent::Type::FrameBegin: // NOTE: start of the whole frame, not rendering
		ProcessEvents();
		mpRender->FrameBegin();
		break;
	case TEvent::Type::FrameEnd: // NOTE: end of the whole frame, not rendering
		mpRender->FrameEnd();
		break;
	};
};

bool CGraphics::OpenWindow()
{
	mCoreEnv.GetLog().Debug("Opening a rendering window...");
	return mpImpl->OpenWindow(mCoreEnv.GetConfig().GetInt("Graphics:WindowWidth", 1280), mCoreEnv.GetConfig().GetInt("Graphics:WindowHeight", 600));
};

void CGraphics::ProcessEvents()
{
	mpImpl->ProcessEvents();
};

}; // namespace rz