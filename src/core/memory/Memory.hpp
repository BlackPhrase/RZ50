/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2019 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <list>
#include "core/memory/IMemory.hpp"

namespace rz::core::memory
{

using tMemPoolList = std::list<IMemPool*>;

class CMemory final : public IMemory
{
public:
	CMemory() = default;
	~CMemory() = default;
	
	void *Alloc(size_t anSize) override;
	void Free(void *apData) override;
	
	IMemPool *AllocPool(const char *asName, uint anBlockCount, size_t anSize) override;
	void FreePool(IMemPool &apPool) override;
private:
	tMemPoolList mlstPools;
};

struct TMemBlock
{
	TMemBlock *mpNext{nullptr};
	TMemBlock *mpPrev{nullptr};
	
	void *mpData{nullptr};
	
	size_t mnSize{0};
	size_t mnUsedSize{0};
};

class CMemPool final : public IMemPool
{
public:
	CMemPool(const char *asName, size_t anSize)
		: msName(asName), mnSize(anSize){}
	~CMemPool(){Clear();}
	
	void *Alloc(size_t anSize) override;
	void Free(void *apData) override;
	
	void Clear() override;
	
	size_t GetUsedSize() const override;
	size_t GetTotalSize() const override {return mnSize;}
private:
	const char *msName{""};
	
	//void *mpData{nullptr};
	
	TMemBlock *mpFreeHead{nullptr};
	TMemBlock *mpInUseHead{nullptr};
	
	size_t mnSize{0};
};

}; // namespace rz::core::memory