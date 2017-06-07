#include "Memory.hpp"

namespace rz
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

}; // namespace rz