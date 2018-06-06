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

// TODO: move them somewhere else
#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include <cassert>
#include <cstring>
#include <stdexcept>
#include <type_traits>

#include <string>
#include <chrono>
//#include <experimental/filesystem> // <filesystem>

#ifdef _WIN32
	#include <windows.h>
#else
	// TODO
#endif

#ifdef _MSC_VER
	#define EXPORT [[dllexport]]
#elif __GNUC__
	#define EXPORT [[visibility("default")]]
#else
	#error "Unsupported compiler!"
#endif

#define C_EXPORT extern "C" EXPORT

namespace rz
{

using uint = unsigned int;
using byte = unsigned char;

using string = std::string;

//namespace fs = std::experimental::filesystem; //std::filesystem;

#ifdef _WIN32
	using tWinHandle = HWND; // TODO: fix
#else
	using tWinHandle = void *;
#endif

}; // namespace rz