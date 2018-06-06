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

#include "core/CoreTypes.hpp"
#include "TextConsoleWin.hpp"

#include <windows.h>
#include <cstdio>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <fstream>

using namespace std;

// maximum mumber of lines the output console should have
static const WORD MAX_CONSOLE_LINES{500};

BOOL CtrlHandler(DWORD fdwCtrlType) 
{
	switch(fdwCtrlType)
	{
	case CTRL_CLOSE_EVENT:
		return TRUE;
	default:
		break;
	};
	
	return FALSE;
};

void RedirectIOToConsole()
{
    int hConHandle;
    HANDLE lStdHandle;
    CONSOLE_SCREEN_BUFFER_INFO coninfo;
    FILE *fp;

// allocate a console for this app
    AllocConsole();

// set the screen buffer to be big enough to let us scroll text
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&coninfo);
    coninfo.dwSize.Y = MAX_CONSOLE_LINES;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),coninfo.dwSize);

// redirect unbuffered STDOUT to the console
    lStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    hConHandle = _open_osfhandle((intptr_t)lStdHandle, _O_TEXT);

    fp = _fdopen( hConHandle, "w" );

    *stdout = *fp;

    setvbuf( stdout, NULL, _IONBF, 0 );

// redirect unbuffered STDIN to the console

    lStdHandle = GetStdHandle(STD_INPUT_HANDLE);
    hConHandle = _open_osfhandle((intptr_t)lStdHandle, _O_TEXT);

    fp = _fdopen( hConHandle, "r" );
    *stdin = *fp;
    setvbuf( stdin, NULL, _IONBF, 0 );

// redirect unbuffered STDERR to the console
    lStdHandle = GetStdHandle(STD_ERROR_HANDLE);
    hConHandle = _open_osfhandle((intptr_t)lStdHandle, _O_TEXT);

    fp = _fdopen( hConHandle, "w" );

    *stderr = *fp;

    setvbuf( stderr, NULL, _IONBF, 0 );

// make cout, wcout, cin, wcin, wcerr, cerr, wclog and clog
// point to console as well
    ios::sync_with_stdio();
}

namespace rz
{

bool CTextConsoleWin::Init()
{
	//if(!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE))
		//return false;
	
	::RedirectIOToConsole();
	
	/*
	// Detach from the current console window
	// If launched from a console window, that will still run waiting for the new console (below) to close
	FreeConsole();

	// Create a separate new console window
	if(!AllocConsole())
		return false;

	// Attach the new console to this application's process
	AttachConsole(GetCurrentProcessId()); // ATTACH_PARENT_PROCESS
	
	if(!SetConsoleTitle("RZ Remote Console"))
		return false;
	
	mhScreenBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
	
	if(mhScreenBuffer == INVALID_HANDLE_VALUE)
		return false;
	
	if(!SetConsoleActiveScreenBuffer(mhScreenBuffer))
		return false;
	*/
	
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