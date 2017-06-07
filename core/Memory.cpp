#include "Memory.hpp"

namespace rz
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

}; // namespace rz