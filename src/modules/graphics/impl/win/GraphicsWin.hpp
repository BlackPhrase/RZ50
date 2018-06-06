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

#include <windows.h>
#include "IGraphicsImpl.hpp"
#include "core/IServiceLocator.hpp"

namespace rz
{

class CGraphicsWin final : public IGraphicsImpl
{
public:
	CGraphicsWin() = default;
	~CGraphicsWin(); // = default;
	
	bool Init(const IServiceLocator &aCoreEnv) override;
	//void Shutdown() override;
	
	bool OpenWindow(int anWidth, int anHeight) override;
	
	void ProcessEvents() override;
	
	void RequestClose();
	
	static CGraphicsWin *pGraphicsWin;
private:
	static LRESULT WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	
	const IServiceLocator *mpCoreEnv{nullptr};
	
	HWND mhWnd{nullptr};
};

}; // namespace rz