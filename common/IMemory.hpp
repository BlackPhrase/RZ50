#pragma once

#include <cstring>

// Internal core allocator shared between the modules
// Using it the we can improve portability of the dlls
// because we using the memory from the single crt of the core
// module

namespace rz
{

struct IMemory
{
	/// Alloc specified memory size
	virtual void *Alloc(size_t anSize) = 0;
	
	/// Free the allocated memory
	virtual void Free(void *apData) = 0;
};

}; // namespace rz