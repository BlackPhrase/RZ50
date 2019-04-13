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

#include "graphics/IWindow.hpp"

namespace rz
{

// TODO: apply usage of vectors for pos/size
class CWindowWin : public IWindow
{
public:
	CWindowWin() = default;
	~CWindowWin();
	
	void Update() override;
	
	void AddEventListener(EventListener &aListener) override;
	void RemoveEventListener(EventListener &aListener) override;
	
	//tWinHandle GetHandle() const {return mHandle;}
	
	//static CGraphicsWin *pGraphicsWin;
private:
	static LRESULT WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	
	SWindowProps mProps{};
	
	tWinHandle mHandle{nullptr}; // HWND mhWnd{nullptr};
};

}; // namespace rz