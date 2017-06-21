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