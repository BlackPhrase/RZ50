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

#pragma once

#include "graphics/IGraphics.hpp"
#include "core/IServiceLocator.hpp"
#include "core/IEventSystem.hpp"

namespace rz
{

struct IGraphicsImpl;
struct IRender;

class CGraphics final : public IGraphics, IEventListener
{
public:
	CGraphics(const IServiceLocator &aCoreEnv, IGraphicsImpl *apImpl, IRender *apRender)
		: mCoreEnv(aCoreEnv), mpImpl(apImpl), mpRender(apRender){}
	~CGraphics() = default;
	
	bool Init(const IServiceLocator &aCoreEnv); //override;
	void Shutdown(); //override;
	
	void Update(); //override;
	
	void OnEvent(const TEvent &aEvent) override;
	
	const char *GetModuleName() const /*override*/ {return "Graphics";}
private:
	bool OpenWindow();
	void ProcessEvents(); // process ui events (windows messages/x events)
	
	const IServiceLocator &mCoreEnv;
	
	IGraphicsImpl *mpImpl{nullptr};
	IRender *mpRender{nullptr};
};

}; // namespace rz