#include "core/CoreTypes.hpp"
#include "Core.hpp"

#ifndef RZ_CORE_STATIC

C_EXPORT rz::ICore *GetCore()
{
	static rz::CCore Core;
	return &Core;
};

#endif