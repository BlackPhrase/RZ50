#include "TextConsoleWin.hpp"

namespace rz
{

bool CTextConsoleWin::Init()
{
	if(!AllocConsole())
		return false;
	
	if(!SetConsoleTitle("RZ Remote Console"))
		return false;
	
	mhScreenBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
	
	if(mhScreenBuffer == INVALID_HANDLE_VALUE)
		return false;
	
	if(!SetConsoleActiveScreenBuffer(mhScreenBuffer))
		return false;
	
	if(!SetConsoleMode(mhScreenBuffer, ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS))
		return false;
	
	return true;
};

void CTextConsoleWin::Shutdown()
{
	FreeConsole();
};

void CTextConsoleWin::Printf(const char *asMsg, ...) // NOTE: color support here?
{
};

void CTextConsoleWin::Warning(const char *asMsg, ...)
{
};

void CTextConsoleWin::Error(const char *asMsg, ...)
{
};

}; // namespace rz