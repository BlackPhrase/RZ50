#include "Memory.hpp"

namespace rz
{

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

}; // namespace rz