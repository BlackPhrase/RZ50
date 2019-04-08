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

#include "WindowWin.hpp"

namespace rz::graphics
{

CWindowWin::~CWindowWin()
{
	if(mHandle)
		DestroyWindow(mHandle);
};

void CWindowWin::Update()
{
	
};

void CWindowWin::Open(int anWidth, int anHeight, const char *asTitle, bool abFullScreen)
{
	const char *sClassName = "ClassName";
	const char *sWindowsName = "RZ Engine";
	
	DWORD nWinStyle = WS_OVERLAPPEDWINDOW;
	DWORD nExStyle = 0;
	
	int nWinWidth = anWidth;
	int nWinHeight = anHeight;
	
	int nPosX = (GetSystemMetrics(SM_CXSCREEN) - nWinWidth) * 0.5;
	int nPosY = (GetSystemMetrics(SM_CYSCREEN) - nWinHeight) * 0.5;
	
	UINT nClassStyle = CS_DBLCLKS;
	
	//
	
	WNDCLASSEX WindowClass{};
	
	WindowClass.cbSize = sizeof(WNDCLASSEX);
	
	WindowClass.style = nClassStyle;
	WindowClass.lpfnWndProc = WindowProc;
	WindowClass.cbClsExtra = 0;
	WindowClass.cbWndExtra = 0;
	WindowClass.hInstance = nullptr;
	WindowClass.hIcon = nullptr;
	WindowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	WindowClass.hbrBackground = nullptr;
	WindowClass.lpszMenuName = "";
	WindowClass.lpszClassName = sClassName;
	WindowClass.hIconSm = nullptr;
	
	if(!RegisterClassEx(&WindowClass))
		return false;
	
	//
	
	mhWnd = CreateWindowEx(
						nExStyle,
						sClassName,
						sWindowsName,
						nWinStyle,
						nPosX, nPosY,
						nWinWidth, nWinHeight,
						nullptr, // parent window
						nullptr, // menu
						nullptr, // instance
						nullptr // lpparam
						);
	
	if(!mhWnd)
		return false;
	
	UpdateWindow(mhWnd);
	SetForegroundWindow(mhWnd);
	ShowWindow(mhWnd, SW_SHOWNORMAL);
	
	return true;
};

LRESULT WINAPI CWindowWin::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_MENUCHAR:
		return MAKELRESULT(0, MNC_CLOSE);
	case WM_ACTIVATE:
		// TODO: app active, minimized, window handle changes
		break;
	case WM_CLOSE: // user wants to close the window
		//pGraphicsWin->RequestClose();
		for(auto It : mlstEventListeners)
			It->OnEvent();
		break;
	case WM_MOVE:
		for(auto It : mlstEventListeners)
			It->OnEvent();
		break;
	case WM_GETMINMAXINFO:
		for(auto It : mlstEventListeners)
			It->OnEvent(PreResize);
		break;
	case WM_ENTERSIZEMOVE:
		for(auto It : mlstEventListeners)
			It->OnEvent();
		break;
	case WM_EXITSIZEMOVE:
		for(auto It : mlstEventListeners)
			It->OnEvent();
		break;
	case WM_SIZE:
		for(auto It : mlstEventListeners)
			It->OnEvent();
		break;
	};
	
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
};

}; // namespace rz::graphics