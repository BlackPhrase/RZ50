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

#include "InputWin.hpp"

/*
LRESULT CALLBACK InputSystemWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return gInput->WindowProc(hWnd, uMsg, wParam, lParam);
};
*/

namespace rz::input
{

CInputWin *gInput{nullptr};

CInputWin::CInputWin()
{
	gInput = this;
};

LRESULT CALLBACK CInputWin::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_INPUT:
			break;
	};
	
	return 0;
};

void CInputWin::AttachToWindow(tWinHandle ahWindow)
{
	mhWindow = ahWindow;
	
	SetWindowLongPtr((HWND)mhWindow, GWLP_WNDPROC, (LONG_PTR)WindowProc);
};

}; // namespace rz::input