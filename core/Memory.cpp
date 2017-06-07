#include "Memory.hpp"

namespace rz
{

// TODO: Apply usage of mempools here

void *CMemory::Alloc(size_t anSize)
{
	return new byte (anSize);
};

void CMemory::Free(void *apData)
{
	if(apData)
		delete apData;
	apData = nullptr;
};

IMemPool *CMemory::AllocPool(const char *asName, uint anBlockCount, size_t anSize)
{
	return nullptr;
};

void CMemory::FreePool(IMemPool &apPool)
{
};

}; // namespace rz