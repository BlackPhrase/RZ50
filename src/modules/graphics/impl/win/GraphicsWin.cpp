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

#include "GraphicsWin.hpp"

namespace rz
{

CGraphicsWin *CGraphicsWin::pGraphicsWin = nullptr;

CGraphicsWin::~CGraphicsWin() //Shutdown
{
	if(mhWnd)
		DestroyWindow(mhWnd);
};

bool CGraphicsWin::Init(const IServiceLocator &aCoreEnv)
{
	pGraphicsWin = this;
	mpCoreEnv = &aCoreEnv;
	
	return true;
};

bool CGraphicsWin::OpenWindow(int anWidth, int anHeight)
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

void CGraphicsWin::ProcessEvents()
{
	static MSG Msg{};
	
	while(PeekMessage(&Msg, mhWnd, 0, 0, PM_REMOVE))
	{
		if(Msg.message == WM_QUIT)
			break;
		
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	};
};

void CGraphicsWin::RequestClose()
{
	mpCoreEnv->GetCmdProcessor().ExecText("exit");
};

LRESULT WINAPI CGraphicsWin::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		pGraphicsWin->RequestClose();
		break;
	};
	
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
};

}; // namespace rz