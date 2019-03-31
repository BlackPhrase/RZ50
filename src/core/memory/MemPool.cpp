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

void *CMemPool::Alloc(size_t anSize)
{
	return nullptr;
};

void CMemPool::Free(void *apData)
{
};

void CMemPool::Clear()
{
};

size_t CMemPool::GetUsedSize() const
{
	return 0;
};

}; // namespace rz::core::memory