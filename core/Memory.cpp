#include "Memory.hpp"

// TODO: Apply usage of mempools here

void *CMemory::Alloc(size_t anSize)
{
	return new anSize;
};

void CMemory::Free(void *apData)
{
	if(apData)
		delete apData;
	apData = nullptr;
};