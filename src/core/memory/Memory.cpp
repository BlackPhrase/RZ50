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

#include "Memory.hpp"

namespace rz::core::memory
{

// TODO: Apply usage of mempools here

void *CMemory::Alloc(size_t anSize)
{
	// TODO: revisit
	
	return new byte [anSize];
};

void CMemory::Free(void *apData)
{
	// TODO: revisit
	
	if(apData)
		delete [] apData;
	apData = nullptr;
};

IMemPool *CMemory::AllocPool(const char *asName, uint anBlockCount, size_t anSize)
{
	//return mlstPools.emplace_back(asName, anBlockCount, anSize);
	return nullptr;
};

void CMemory::FreePool(IMemPool &apPool)
{
	// TODO
	
	//for(auto It : mlstPools)
		//if(!strcmp(It->GetName(), apPool.GetName()))
		{
			//apPool.Clear();
			//SetPoolFree(apPool, true);
		};
};

}; // namespace rz::core::memory