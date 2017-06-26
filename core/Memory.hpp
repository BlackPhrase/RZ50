#pragma once

#include <list>
#include "core/IMemory.hpp"

namespace rz
{

using tMemPoolList = std::list<IMemPool*>;

class CMemory final : public IMemory
{
public:
	CMemory() = default;
	~CMemory() = default;
	
	void Init(TCoreEnv &aCoreEnv);
	
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

}; // namespace rz