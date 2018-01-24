#include "InputWin.hpp"

/*
LRESULT CALLBACK InputSystemWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return gInput->WindowProc(hWnd, uMsg, wParam, lParam);
};
*/

namespace rz
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

}; // namespace rz