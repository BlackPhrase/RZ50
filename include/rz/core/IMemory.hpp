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

#include <cstring>
#include "CoreTypes.hpp"

// Internal core allocator shared between the modules
// By using it we can improve portability of the dlls
// because we're using the memory from the single crt of the core
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