#pragma once

#include <cstring>

// Internal core allocator shared between the modules
// Using it the we can improve portability of the dlls
// because we using the memory from the single crt of the core
// module

namespace rz
{

struct IMemPool;

struct IMemory
{
	/// Alloc specified memory size
	virtual void *Alloc(size_t anSize) = 0;
	
	/// Free the allocated memory
	virtual void Free(void *apData) = 0;
	
	/// Allocate a memory pool with specified name and size
	virtual IMemPool *AllocPool(const char *asName, uint anBlockCount, size_t anBlockSize) = 0;
	
	/// Free the allocated memory pool
	virtual void FreePool(IMemPool &apPool) = 0;
};

struct IMemPool
{
	/// Alloc specified memory inside the pool
	virtual void *Alloc(size_t anSize) = 0;
	
	/// Free the mem from the pool
	virtual void Free(void *apData) = 0;
	
	///
	virtual void Clear() = 0;
	
	///
	virtual size_t GetUsedSize() const = 0;
	
	///
	virtual size_t GetTotalSize() const = 0;
};

}; // namespace rz