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

#ifdef _MSC_VER
	#define EXPORT __declspec(dllexport)
#elif __GNUC__
	#define EXPORT __attribute__((visibility("default")))
#else
	#error "Unsupported compiler!"
#endif

#define C_EXPORT extern "C" EXPORT

namespace rz
{

using uint = unsigned int;
using byte = unsigned char;

using string = std::string;

}; // namespace rz