#include "core/CoreTypes.hpp"
#include "Core.hpp"

#ifndef RZ_CORE_STATIC

C_EXPORT rz::ICore *GetCore()
{
	static std::unique_ptr<rz::CCore> Core = std::make_unique<rz::CCore>();
	return Core.get();
};

#endif