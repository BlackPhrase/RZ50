#pragma once

#include <windows.h>
#include "TextConsole.hpp"

// TODO:
//	* Input support
//	* Input to command text
//	* Colored output support
//	* Control handler to properly shutdown the engine by closing the console window

namespace rz
{

class CTextConsoleWin final : public CTextConsole
{
public:
	CTextConsoleWin() = default;
	~CTextConsoleWin() = default;
	
	bool Init();
	void Shutdown();
	
	void Printf(const char *asMsg, ...);
	
	void Warning(const char *asMsg, ...);
	void Error(const char *asMsg, ...);
private:
	HANDLE mhScreenBuffer{INVALID_HANDLE_VALUE};
};

}; // namespace rz