#pragma once

namespace rz
{

class CInputWin final
{
public:
	CInputWin();
	~CInputWin();
private:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	
	void AttachToWindow(tWinHandle ahWindow);
	
	tWinHandle mhWindow{0};
};

}; // namespace rz